#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QG������2022ѵ��Ӫ������/������/Sort/Headers/sort.h"
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
	int i;
	for (i=0; i < n - 1; ++i)
	{
		/* ��¼�����������һ��Ԫ�ص��±� */
		int end = i;
		/* �������Ԫ�� */
		int tem = a[end + 1];
		/* ������ */
		while (end >= 0)
		{
			/* �Ȳ�������������� */
			if (tem < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			/* �Ȳ������С������ѭ�� */
			else
			{
				break;
			}
		}
		/* tem�ŵ��Ȳ������С�����ĺ��� */
		a[end  + 1] = tem;
	}
}
/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int k = begin,i=begin,j=mid+1;
	while (i <= mid&&j <= end) /* ��a�ֳ�����Ƚϣ�С���ȴ���temp */
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) /* i����ʣ�µ�ȫ���ӵ�temp���� */
	{
		temp[k++] = a[i++];
	}
	while (j <= end) /* j����ʣ�µ�ȫ���ӵ�temp���� */
	{
		temp[k++] = a[j++];
	}
	for(k=begin; k<=end; k++) /* ����ʱ�����е�ֵ����a */
	{
		a[k]=temp[k];
	}
}
/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	if (begin >= end)
		return;
	int mid=begin+(end-begin)/2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a,begin,mid,end,temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int i,j,t,temp;
	if(begin>=end) /* ��ʱ���������� */
		return;
	temp=a[begin];
	i=begin;
	j=end;
	while(i!=j) /* i��jδ����ʱ*/
	{
		while(a[j]>=temp&&i<j) /*j�ȴ��ұ�������� */
			j--;
		while(a[i]<=temp&&i<j) /*i�ٴ�������ұ��� */
			i++;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[begin]=a[i];
	a[i]=temp; /* �����м�ֵ����ʼֵ */
	QuickSort_Recursion(a, begin,i);
	QuickSort_Recursion(a, i+1,end);
	return;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
	long* count =(long*)malloc(200000 * sizeof(long) );
	long i ;
	for(i = 0; i < max + 1; i++) /* ��ʼ�� */
	{
		count[i] = 0;
	}
	for(i = 0; i < size; i++) /*������Ӧ���ֵ�Ͱ�� */
	{
		count[a[i]]++;
	}

	long indexOfA = 0;
	for(i = 0; i < max + 1; i++)
	{
		while(count[i] > 0) /* ������ȡ */
		{
			a[indexOfA++] = i;
			count[i]--;
		}
	}
	free(count);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
		long bucket[][50200] = {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};

		long count[10] = {0};
		/* �ҵ����ֵ */
		long max=0,i,j,k;
		for(i  =0; i < size; i++)
		{
			if(a[i] > max)
			{
				max=a[i];
			}
		}
		long maxNumLength = 0;
		while(max)
		{
			max /= 10;
			maxNumLength++;
		}
		/* ѭ������,�������� */
		long n = 1;
		for ( i = 0; i < maxNumLength; i++)
		{
			/* װͰ */
			for ( j = 0; j < size; j++)
			{
				long digitOfElement = a[j] / n % 10;

				bucket[digitOfElement][count[digitOfElement]] = a[j];
				count[digitOfElement] ++;
			}
			n = n * 10;
			/* ��Ͱ��ȡ������ */
			int index = 0;
			for ( j = 0; j < 10; j++)
			{
				for ( k = 0; k < count[j]; k++)
				{
					if (count[j] > 0)   /* ������,ȡ�� */
					{
						a[index] = bucket[j][k];
						index++;
					}
				}
				count[j] = 0;
			}
		}
	}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
	int i = 0,j = 0,r = size - 1;
	/* ����ָ��ͺ��ָ����ײ,��ֹͣ */
	while (i <= r)
	{
		/* 0�Ļ���ǰ�����һ������ */
		if( a[i] == 0 )
		{
			swap(a,i,j);
			i++;
			j++;
			/* ���ǵĻ�,�ͼ����� */
		}
		else if(a[i] == 1)
		{
			i++;
			/* 2�Ļ��ͺ������һ�����н��� */
		}
		else
		{
			swap(a,i,r);
			r--;
		}
	}
}

/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int find_k(int *a, int size, int k)
{
	int minIndex; /* ���ַ� */
	int i = 0;
	int j = 0;
	for (i = 0; i < k; ++i)
	{
		minIndex = i;
		for (j = i + 1; j < size; ++j)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		swap(a,i,minIndex);
	}
	if(a[k-1]==0)
		printf("����û������Ҫ���ҵ����֣��������룡\n");
	else
		printf("�����ڵ�%d��λ��\n", a[k - 1]);
}
