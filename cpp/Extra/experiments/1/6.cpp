#include <iostream>
#include <string>
using namespace std;
int MAX = 10; // 科目数
class CSStudent
{
    string name, sex, ID, object, time;
    int age;
    int *mark = new int[MAX];
    string *sbj = new string[MAX];
    int retry, redo;
    string t_chose, s_chose;
    int *m_point = new int[MAX], *m_mark = new int[MAX];
    int *marker = new int[MAX];
    int *marker2 = new int[MAX];

public:
    CSStudent()
    {
        cout << "开始录入基本信息" << endl;
        cout << "姓名:";
        cin >> name;
        cout << "学号:";
        cin >> ID;
        cout << "性别:";
        cin >> sex;
        cout << "年龄:";
        cin >> age;
        cout << "专业:";
        cin >> object;
        cout << "入学时间:";
        cin >> time;
        cout << "多少科目:";
        cin >> MAX;
        cout << "请输入科目及分数:" << endl;
        for (int i = 0; i < MAX; i++)
        {
            cout << "科目:";
            cin >> sbj[i];
            cout << "分数:";
            cin >> mark[i];
        }
    }
    void baseprint() // 输出基本信息
    {
        cout << "基本信息：" << endl;
        cout << "学生姓名：" << name << "\t学号：" << ID << "\t年龄：" << age << "\t性别" << sex << endl;
        cout << "入学时间：" << time << "\t专业：" << object << endl;
        cout << "成绩：" << endl;
        for (int i = 0; i < MAX; i++)
        {
            cout << sbj[i] << "：" << mark[i] << "\t";
        }
        cout << endl;
    }
    void chose() //设置选课函数
    {
        cout << "选课名称：";
        cin >> s_chose;
        cout << "选课时间：";
        cin >> t_chose;
    }
    void Point()
    {
        for (int i = 0; i < MAX; i++)
        {
            cout << "请设置" << sbj[i] << "的学分：";
            cin >> m_mark[i];
        }
        cout << endl;
        cout << endl;
        int score = 0, j = 0;
        retry = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (mark[i] >= 60)
                score += m_mark[i];
            else
            {
                retry++;
                marker[j++] = i;
            }
        } //记录重修科目
        float s = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (m_mark == 0)
            {
                m_point[i] = 0;
                cout << sbj[i] << "学分绩点均为0" << endl;
                continue;
            }
            float(m_point[i] = 4 - (100 - (float)mark[i]) * (100 - (float)mark[i]) / 1600); //绩点计算
            s += m_point[i];
            cout << sbj[i] << "所获学分：" << m_mark[i] << "\t绩点：" << m_point[i] << endl;
        }
        cout << "平均绩点为：" << s / MAX << endl;
        cout << endl;
    }

    void check()
    {
        if (retry == 0)
            cout << "无重考科目";
        else
        {
            cout << "重考数目为：" << retry << "包括" << endl;
            for (int i = 0; i < retry; i++)
                cout << sbj[marker[i]] << "\t";
            cout << endl;
            redo = 0;
            cout << endl;
            int temp, j = 0;
            cout << "输入重考分数" << endl;
            for (int i = 0; i < retry; i++)
            {
                cout << sbj[marker[i]] << ":";
                cin >> temp;
                if (temp < 60)
                {
                    redo++;
                    marker2[j++] = marker[i];
                }
            }
            cout << endl;
            if (redo == 0)
                cout << "无重修科目";
            else
            {
                cout << "重修数目为：" << redo << "包括" << endl;
                for (int i = 0; i < redo; i++)
                    cout << sbj[marker2[i]] << "\t";
                cout << endl;
            }
        }
    }
};
int main(void)
{
    CSStudent a;
    a.baseprint();
    a.chose();
    a.Point();
    a.check();
    return 0;
}