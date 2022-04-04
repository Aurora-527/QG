#include"C:/Users/AURORA/Desktop/QG/训练营第三周/QG工作室2022训练营第三周/第三周/Sort/Headers/sort.h"
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
	int i;
	for (i=0; i < n - 1; ++i)
	{
		/* 记录有序序列最后一个元素的下标 */
		int end = i;
		/* 待插入的元素 */
		int tem = a[end + 1];
		/* 单趟排 */
		while (end >= 0)
		{
			/* 比插入的数大就向后移 */
			if (tem < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			/* 比插入的数小，跳出循环 */
			else
			{
				break;
			}
		}
		/* tem放到比插入的数小的数的后面 */
		a[end  + 1] = tem;
	}
}
/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int k = begin,i=begin,j=mid+1;
	while (i <= mid&&j <= end) /* 将a分成两块比较，小的先存入temp */
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
	while (i <= mid) /* i中有剩下的全部接到temp后面 */
	{
		temp[k++] = a[i++];
	}
	while (j <= end) /* j中有剩下的全部接到temp后面 */
	{
		temp[k++] = a[j++];
	}
	for(k=begin; k<=end; k++) /* 将临时数组中的值传回a */
	{
		a[k]=temp[k];
	}
}
/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
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
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int i,j,t,temp;
	if(begin>=end) /* 此时排序无意义 */
		return;
	temp=a[begin];
	i=begin;
	j=end;
	while(i!=j) /* i和j未相遇时*/
	{
		while(a[j]>=temp&&i<j) /*j先从右边往左边走 */
			j--;
		while(a[i]<=temp&&i<j) /*i再从左边往右边走 */
			i++;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[begin]=a[i];
	a[i]=temp; /* 交换中间值和起始值 */
	QuickSort_Recursion(a, begin,i);
	QuickSort_Recursion(a, i+1,end);
	return;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
	long* count =(long*)malloc(200000 * sizeof(long) );
	long i ;
	for(i = 0; i < max + 1; i++) /* 初始化 */
	{
		count[i] = 0;
	}
	for(i = 0; i < size; i++) /*放入相应数字的桶中 */
	{
		count[a[i]]++;
	}

	long indexOfA = 0;
	for(i = 0; i < max + 1; i++)
	{
		while(count[i] > 0) /* 依次提取 */
		{
			a[indexOfA++] = i;
			count[i]--;
		}
	}
	free(count);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
		long bucket[][50200] = {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};

		long count[10] = {0};
		/* 找到最大值 */
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
		/* 循环遍历,进行排序 */
		long n = 1;
		for ( i = 0; i < maxNumLength; i++)
		{
			/* 装桶 */
			for ( j = 0; j < size; j++)
			{
				long digitOfElement = a[j] / n % 10;

				bucket[digitOfElement][count[digitOfElement]] = a[j];
				count[digitOfElement] ++;
			}
			n = n * 10;
			/* 从桶中取出数据 */
			int index = 0;
			for ( j = 0; j < 10; j++)
			{
				for ( k = 0; k < count[j]; k++)
				{
					if (count[j] > 0)   /* 有数据,取出 */
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
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
	int i = 0,j = 0,r = size - 1;
	/* 遍历指针和后的指针相撞,就停止 */
	while (i <= r)
	{
		/* 0的话和前面的那一个交换 */
		if( a[i] == 0 )
		{
			swap(a,i,j);
			i++;
			j++;
			/* 不是的话,就继续走 */
		}
		else if(a[i] == 1)
		{
			i++;
			/* 2的话和后面的那一个进行交换 */
		}
		else
		{
			swap(a,i,r);
			r--;
		}
	}
}

/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int find_k(int *a, int size, int k)
{
	int minIndex; /* 二分法 */
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
		printf("这里没有你想要查找的数字，请检查输入！\n");
	else
		printf("该数在第%d个位置\n", a[k - 1]);
}
