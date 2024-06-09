#
#ifndef _MEMORY_H
#define _MEMORY_H

class CMemory
{
public:
    CMemory();
    void initialize(const int nTotal_pf);
    void FIFO(const int nTotal_pf);
    void LRU(const int nTotal_pf);
    void NUR(const int nTotal_pf);
    void OPT(const int nTotal_pf);

private:
    vector<CPage> _vDiscPages;
    vector<CPageControl> _vMemoryPages;
    CPageControl *_pFreepf_head, *_pBusypf_head, *_pBusypf_tail;
    vector<int> _vMain, _vPage, _vOffset;
    int _nDiseffect;
};

CMemory::CMemory() : _vDiscPages(TOTAL_VP),
                     _vMemoryPages(TOTAL_VP),
                     _vMain(TOTAL_INSTRUCTION),
                     _vPage(TOTAL_INSTRUCTION),
                     _vOffset(TOTAL_INSTRUCTION)
{
    int S, i, nRand;
    srand(getpid() * 10);
    nRand = rand() % 32767;

    S = (float)319 * nRand / 32767 + 1;
    for (i = 0; i < TOTAL_INSTRUCTION; i += 4)
    {
        _vMain[i] = S;
        _vMain[i + 1] = _vMain[i] + 1;
        nRand = rand() % 32767;
        _vMain[i + 2] = (float)_vMain[i] * nRand / 32767;
        _vMain[i + 3] = _vMain[i + 2] + 1;
        nRand = rand() % 32767;
        S = (float)nRand * (318 - _vMain[i + 2]) / 32767 + _vMain[i + 2] + 2;
    }
    for (i = 0; i < TOTAL_INSTRUCTION; i++)
    {
        _vPage[i] = _vMain[i] / 10;
        _vOffset[i] = _vMain[i] % 10;
        _vPage[i] %= 32;
    }
}

void CMemory::initialize(const int nTotal_pf)
{
    int ix;
    _nDiseffect = 0;
    for (ix = 0; ix < _vDiscPages.size(); ix++)
    {
        _vDiscPages[ix].m_nPageNumber = ix;
        _vDiscPages[ix].m_nPageFaceNumber = INVALID;
        _vDiscPages[ix].m_nCounter = 0;
        _vDiscPages[ix].m_nTime = -1;
    }
    for (ix = 1; ix < nTotal_pf; ix++)
    {
        _vMemoryPages[ix - 1].m_pNext = &_vMemoryPages[ix];
        _vMemoryPages[ix - 1].m_nPageFaceNumber = ix - 1;
    }
    _vMemoryPages[nTotal_pf - 1].m_pNext = NULL;
    _vMemoryPages[nTotal_pf - 1].m_nPageFaceNumber = nTotal_pf - 1;
    _pFreepf_head = &_vMemoryPages[0];
}

void CMemory::FIFO(const int nTotal_pf)
{
    int i;
    CPageControl *p;
    initialize(nTotal_pf);
    _pBusypf_head = _pBusypf_tail = NULL;
    for (i = 0; i < TOTAL_INSTRUCTION; i++)
    {
        if (_vDiscPages[_vPage[i]].m_nPageFaceNumber == INVALID)
        {
            _nDiseffect += 1;
            if (_pFreepf_head == NULL) // no empty pages
            {
                p = _pBusypf_head->m_pNext;

                _vDiscPages[_pBusypf_head->m_nPageNumber].m_nPageFaceNumber = INVALI

                    D;
                _pFreepf_head = _pBusypf_head;
                _pFreepf_head->m_pNext = NULL;
                _pBusypf_head = p;
            }
            p = _pFreepf_head->m_pNext;
            _pFreepf_head->m_pNext = NULL;
            _pFreepf_head->m_nPageNumber = _vPage[i];

            _vDiscPages[_vPage[i]].m_nPageFaceNumber = _pFreepf_head->m_nPageFaceNu mber;
            if (_pBusypf_tail == NULL)
                _pBusypf_head = _pBusypf_tail = _pFreepf_head;
            else
            {
                _pBusypf_tail->m_pNext = _pFreepf_head;
                _pBusypf_tail = _pFreepf_head;
            }
            _pFreepf_head = p;
        }
    }
    cout << "FIFO: " << 1 - (float)_nDiseffect / 320;
}

void CMemory::LRU(const int nTotal_pf)
{
    int i, j, nMin, minj, nPresentTime(0);
    initialize(nTotal_pf);
    for (i = 0; i < TOTAL_INSTRUCTION; i++)
    {
        if (_vDiscPages[_vPage[i]].m_nPageFaceNumber == INVALID)
        {
            _nDiseffect++;
            if (_pFreepf_head == NULL)
            {
                nMin = 32767;
                for (j = 0; j < TOTAL_VP; j++) // get the subscribe of the least used page
                    // after the recycle iMin is the number of times

                    // used of the least used page while minj is its subscribe

                    if (nMin > _vDiscPages[j].m_nTime && _vDiscPages[j].m_nPageFaceNumber != IN VALID)
                    {
                        nMin = _vDiscPages[j].m_nTime;
                        minj = j;
                    }

                _pFreepf_head = &_vMemoryPages[_vDiscPages[minj].m_nPageFaceNumber];
                _vDiscPages[minj].m_nPageFaceNumber = INVALID;
                _vDiscPages[minj].m_nTime = -1;
                _pFreepf_head->m_pNext = NULL;
            }

            _vDiscPages[_vPage[i]].m_nPageFaceNumber = _pFreepf_head->m_nPageFaceNu mber;
            _vDiscPages[_vPage[i]].m_nTime = nPresentTime;
            _pFreepf_head = _pFreepf_head->m_pNext;
        }
        else
            _vDiscPages[_vPage[i]].m_nTime = nPresentTime;

        nPresentTime++;
    }
    cout << "LRU: " << 1 - (float)_nDiseffect / 320;
}

void CMemory::NUR(const int nTotal_pf)
{
    int i, j, nDiscPage, nOld_DiscPage;
    bool bCont_flag;
    initialize(nTotal_pf);
    nDiscPage = 0;
    for (i = 0; i < TOTAL_INSTRUCTION; i++)
    {
        if (_vDiscPages[_vPage[i]].m_nPageFaceNumber == INVALID)
        {

            _nDiseffect++;
            if (_pFreepf_head == NULL)
            {
                bCont_flag = true;
                nOld_DiscPage = nDiscPage;
                while (bCont_flag)
                {

                    if (_vDiscPages[nDiscPage].m_nCounter == 0 && _vDiscPages[nDiscPage].m_nPage FaceNumber != INVALID)
                        bCont_flag = false;
                    else
                    {
                        nDiscPage++;
                        if (nDiscPage == TOTAL_VP)
                            nDiscPage = 0;
                        if (nDiscPage == nOld_DiscPage)
                            for (j = 0; j < TOTAL_VP; j++)
                                _vDiscPages[j].m_nCounter = 0;
                    }
                }

                _pFreepf_head = &_vMemoryPages[_vDiscPages[nDiscPage].m_nPageFaceNumber];
                _vDiscPages[nDiscPage].m_nPageFaceNumber = INVALID;
                _pFreepf_head->m_pNext = NULL;
            }

            _vDiscPages[_vPage[i]].m_nPageFaceNumber = _pFreepf_head->m_nPageFaceNu mber;
            _pFreepf_head = _pFreepf_head->m_pNext;
        }
        else
            _vDiscPages[_vPage[i]].m_nCounter = 1;
        if (i % CLEAR_PERIOD == 0)
            for (j = 0; j < TOTAL_VP; j++)
                _vDiscPages[j].m_nCounter = 0;
    }
    cout << "NUR:" << 1 - (float)_nDiseffect / 320;
}

void CMemory::OPT(const int nTotal_pf)
{
    int i, j, max, maxpage, nDistance, vDistance[TOTAL_VP];

    initialize(nTotal_pf);
    for (i = 0; i < TOTAL_INSTRUCTION; i++)
    {
        if (_vDiscPages[_vPage[i]].m_nPageFaceNumber == INVALID)
        {
            _nDiseffect++;
            if (_pFreepf_head == NULL)
            {
                for (j = 0; j < TOTAL_VP; j++)
                    if (_vDiscPages[j].m_nPageFaceNumber != INVALID)
                        vDistance[j] = 32767;
                    else
                        vDistance[j] = 0;
                nDistance = 1;
                for (j = i + 1; j < TOTAL_INSTRUCTION; j++)
                {

                    if ((_vDiscPages[_vPage[j]].m_nPageFaceNumber != INVALID) && (vDistance[_vP age[j]] == 32767))
                        vDistance[_vPage[j]] = nDistance;
                    nDistance++;
                }
                max = -1;
                for (j = 0; j < TOTAL_VP; j++)
                    if (max < vDistance[j])
                    {
                        max = vDistance[j];
                        maxpage = j;
                    }

                _pFreepf_head = &_vMemoryPages[_vDiscPages[maxpage].m_nPageFaceNumber];
                _pFreepf_head->m_pNext = NULL;

                _vDiscPages[maxpage].m_nPageFaceNumber = INVALID;
            }

            _vDiscPages[_vPage[i]].m_nPageFaceNumber = _pFreepf_head->m_nPageFaceNu mber;
            _pFreepf_head = _pFreepf_head->m_pNext;
        }
    }
    cout << "OPT:" << 1 - (float)_nDiseffect / 320;
}
#endif
