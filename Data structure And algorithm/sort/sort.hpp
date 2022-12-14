//quick sort 
void qsort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//快速排序并统计次数
{
	int i,j;
	char *p,*q,*temp;
	if(num>1)
	{
		p=(char *)base;
		q=(char *)base+(num-1)*width;
		temp=(char *)malloc(width);
		while(p<q)
		{
			while(compare(p,q)>0&&p<q)
			{
				q-=width;
				(*times)++;
			}
			if(p<q)
			{
				memcpy(temp,p,width);
				memcpy(p,q,width);
				memcpy(q,temp,width);
				p+=width;
			}
			while(compare(p,q)<0&&p<q)
			{
				p+=width;
				(*times)++;
			}
			if(p<q)
			{
				memcpy(temp,p,width);
				memcpy(p,q,width);
				memcpy(q,temp,width);
				q-=width;
			}
		}
		qsort(base,(p-(char *)base)/width,width,compare,times);
		qsort(p+width,(num-(p-(char *)base)/width-1),width,compare,times);
		free(temp);
	}
}
//bubble sort
void busort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//冒泡排序并统计次数
{
	int i,j;
	char *p,*q,*temp;
	if(num>1)
	{
		temp=(char *)malloc(width);
		for(i=0;i<num-1;i++)
		{
			for(j=0;j<num-1-i;j++)
			{
				p=(char *)base+j*width;
				q=(char *)base+(j+1)*width;
				if(compare(p,q)>0)
				{
					memcpy(temp,p,width);
					memcpy(p,q,width);
					memcpy(q,temp,width);
				}
				(*times)++;
			}
		}
		free(temp);
	}
}
//insert sort
void isort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//插入排序并统计次数
{
	int i,j;
	char *p,*q,*temp;
	if(num>1)
	{
		temp=(char *)malloc(width);
		for(i=1;i<num;i++)
		{
			memcpy(temp,(char *)base+i*width,width);
			for(j=i-1;j>=0;j--)
			{
				p=(char *)base+j*width;
				q=(char *)base+(j+1)*width;
				if(compare(p,temp)>0)
				{
					memcpy(q,p,width);
				}
				else
				{
					break;
				}
				(*times)++;
			}
			memcpy((char *)base+(j+1)*width,temp,width);
		}
		free(temp);
	}
}
//select sort
void ssort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//选择排序并统计次数
{
	int i,j;
	char *p,*q,*temp;
	if(num>1)
	{
		temp=(char *)malloc(width);
		for(i=0;i<num-1;i++)
		{
			for(j=i+1;j<num;j++)
			{
				p=(char *)base+i*width;
				q=(char *)base+j*width;
				if(compare(p,q)>0)
				{
					memcpy(temp,p,width);
					memcpy(p,q,width);
					memcpy(q,temp,width);
				}
				(*times)++;
			}
		}
		free(temp);
	}
}
//shell sort
void shsort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//希尔排序并统计次数
{
	int i,j,k;
	char *p,*q,*temp;
	if(num>1)
	{
		temp=(char *)malloc(width);
		for(k=num/2;k>0;k/=2)
		{
			for(i=0;i<k;i++)
			{
				for(j=i+k;j<num;j+=k)
				{
					memcpy(temp,(char *)base+j*width,width);
					for(p=(char *)base+j*width-k,q=(char *)base+j*width;p>=(char *)base+i*width;p-=k,q-=k)
					{
						if(compare(p,temp)>0)
						{
							memcpy(q,p,width);
						}
						else
						{
							break;
						}
						(*times)++;
					}
					memcpy(q,temp,width);
				}
			}
		}
		free(temp);
	}
}
//heap sort
void hsort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//堆排序并统计次数
{
	int i,j;
	char *p,*q,*temp;
	if(num>1)
	{
		temp=(char *)malloc(width);
		for(i=num/2-1;i>=0;i--)
		{
			for(j=i;j<num/2;)
			{
				p=(char *)base+j*width;
				q=(char *)base+2*j*width;
				if(2*j+1<num)
				{
					if(compare(q,q+width)<0)
					{
						q+=width;
					}
				}
				if(compare(p,q)<0)
				{
					memcpy(temp,p,width);
					memcpy(p,q,width);
					memcpy(q,temp,width);
					j=2*j+1;
				}
				else
				{
					break;
				}
				(*times)++;
			}
		}
		for(i=num-1;i>0;i--)
		{
			memcpy(temp,(char *)base,width);
			memcpy((char *)base,(char *)base+i*width,width);
			memcpy((char *)base+i*width,temp,width);
			for(j=0;j<i/2;)
			{
				p=(char *)base+j*width;
				q=(char *)base+2*j*width;
				if(2*j+1<i)
				{
					if(compare(q,q+width)<0)
					{
						q+=width;
					}
				}
				if(compare(p,q)<0)
				{
					memcpy(temp,p,width);
					memcpy(p,q,width);
					memcpy(q,temp,width);
					j=2*j+1;
				}
				else
				{
					break;
				}
				(*times)++;
			}
		}
		free(temp);
	}
}
//merge sort
void msort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//归并排序并统计次数
{
	int i,j,k;
	char *p,*q,*temp;
	if(num>1)
	{
		temp=(char *)malloc(width);
		for(i=1;i<num;i*=2)
		{
			for(j=0;j<num-i;j+=2*i)
			{
				for(k=0,p=(char *)base+j*width,q=(char *)base+(j+i)*width;k<i&&p<(char *)base+num*width&&q<(char *)base+num*width;k++)
				{
					if(compare(p,q)<0)
					{
						memcpy(temp+k*width,p,width);
						p+=width;
					}
					else
					{
						memcpy(temp+k*width,q,width);
						q+=width;
					}
					(*times)++;
				}
				for(;k<i&&p<(char *)base+num*width;k++)
				{
					memcpy(temp+k*width,p,width);
					p+=width;
				}
				for(;k<i&&q<(char *)base+num*width;k++)
				{
					memcpy(temp+k*width,q,width);
					q+=width;
				}
				memcpy((char *)base+j*width,temp,width*i);
			}
		}
		free(temp);
	}
}
//base sort
void bsort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *),int *times)//基数排序并统计次数
{
	int i,j,k;
	char *p,*q,*temp;
	int *count;
	if(num>1)
	{
		temp=(char *)malloc(width);
		count=(int *)malloc(sizeof(int)*num);
		for(i=0;i<width;i++)
		{
			memset(count,0,sizeof(int)*num);
			for(j=0;j<num;j++)
			{
				count[(*(char *)((char *)base+j*width+i))]++;
			}
			for(j=1;j<num;j++)
			{
				count[j]+=count[j-1];
			}
			for(j=num-1;j>=0;j--)
			{
				memcpy(temp,(char *)base+j*width,width);
				for(k=0,p=(char *)base+j*width,q=(char *)base+(count[(*(char *)(temp+i))]-1)*width;k<count[(*(char *)(temp+i))]-1&&p>=(char *)base+i*width;p-=width,q-=width)
				{
					memcpy(q,p,width);
					k++;
					(*times)++;
				}
				memcpy(q,temp,width);
			}
		}
		free(temp);
		free(count);
	}
}
