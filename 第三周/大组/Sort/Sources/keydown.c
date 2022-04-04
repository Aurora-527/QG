#include"C:/Users/AURORA/Desktop/QG/训练营第三周/QG工作室2022训练营第三周/第三周/Sort/Headers/sort.h"
clock_t start,diff; /* 用于计数 */
void keydown(int i)
{
	switch(i)
	{
		case 1:
		{
			int a[10000],temp[10000];
			save(10000);
			output(a);
			start =clock(); /* 开始计时 */
			MergeSort(a,0,9999,temp);
			diff = clock() -start; /* 结束计时 */
			printf("归并排序对10000个数据进行排序用时为%d ms\n",diff);
			save(10000);
			output(a);
			start =clock(); /* 开始计时 */
			QuickSort_Recursion(a,0,9999);
			diff = clock() -start; /* 结束计时 */
			printf("快速排序对10000个数据进行排序用时为%d ms\n",diff);
			save(10000);
			output(a);
			int max=0,i;
			for(i=0; i<10000; i++)
				if(max<a[i])
					max=a[i];
			start =clock(); /* 开始计时 */
			CountSort(a,10000,max);
			diff = clock() -start; /* 结束计时 */
			printf("计数排序对10000个数据进行排序用时为%d ms\n",diff);
			save(10000);
			output(a);
			start =clock(); /* 开始计时 */
			insertSort(a,10000);
			diff = clock() -start; /* 结束计时 */
			printf("插入排序对10000个数据进行排序用时为%d ms\n",diff);
			save(10000);
			output(a);
			start =clock(); /* 开始计时 */
			RadixCountSort(a,10000);
			diff = clock() -start; /* 结束计时 */
			printf("基数排序对10000个数据进行排序用时为%d ms\n",diff);
			break;
		}
		case 2:
		{
			int a[50000],temp[50000];
			save(50000);
			output(a);
			start =clock();
			MergeSort(a,0,49999,temp);
			diff = clock() -start;
			printf("归并排序对50000个数据进行排序用时为%d ms\n",diff);
			save(50000);
			output(a);
			start =clock();
			QuickSort_Recursion(a,0,49999);
			diff = clock() -start;
			printf("快速排序对50000个数据进行排序用时为%d ms\n",diff);
			save(50000);
			output(a);
			int max=0,i;
			for(i=0; i<50000; i++)
				if(max<a[i])
					max=a[i];
			start =clock();
			CountSort(a,50000,max);
			diff = clock() -start;
			printf("计数排序对50000个数据进行排序用时为%d ms\n",diff);
			save(50000);
			output(a);
			start =clock();
			insertSort(a,50000);
			diff = clock() -start;
			printf("插入排序对50000个数据进行排序用时为%d ms\n",diff);
			save(50000);
			output(a);
			start =clock();
			RadixCountSort(a,50000);
			diff = clock() -start;
			printf("基数排序对50000个数据进行排序用时为%d ms\n",diff);
			break;
		}
		case 3:
		{
			int a[200000],temp[200000];
			save(200000);
			output(a);
			start =clock();
			MergeSort(a,0,199999,temp);
			diff = clock() -start;
			printf("归并排序对200000个数据进行排序用时为%d ms\n",diff);
			save(200000);
			output(a);
			start =clock();
			QuickSort_Recursion(a,0,199999);
			diff = clock() -start;
			printf("快速排序对200000个数据进行排序用时为%d ms\n",diff);
			save(200000);
			output(a);
			int max=0,i;
			for(i=0; i<200000; i++)
				if(max<a[i])
					max=a[i];
			start =clock();
			CountSort(a,200000,max);
			diff = clock() -start;
			printf("计数排序对200000个数据进行排序用时为%d ms\n",diff);
			save(200000);
			output(a);
			start =clock();
			RadixCountSort(a,200000);
			diff = clock() -start;
			printf("基数排序对200000个数据进行排序用时为%d ms\n",diff);
			save(200000);
			output(a);
			start =clock();
			insertSort(a,200000);
			diff = clock() -start;
			printf("插入排序对200000个数据进行排序用时为%d ms\n",diff);
			break;
		}
		case 4:
		{
			int a[100],temp[100],i;
			start =clock(); /* 开始计时 */
			for(i=0; i<100000; i++) /* 进行100k次排序 */
			{
				for (i = 0; i < 100; i++)
				{

					int randNum = rand() % 100;
					a[i] = randNum;
				}
				MergeSort(a,0,99,temp);
			}
			diff = clock() -start; /* 结束计时 */
			printf("归并排序对100个数据进行100k次排序用时为%d ms\n",diff);
			start =clock();
			for(i=0; i<100000; i++)
			{
				for (i = 0; i < 100; i++)
				{

					int randNum = rand() % 100;
					a[i] = randNum;
				}
				QuickSort_Recursion(a,0,99);
			}
			diff = clock() -start;
			printf("快速排序对100个数据进行100k次排序用时为%d ms\n",diff);
			int max=0;
			for(i=0; i<100; i++)
				if(max<a[i])
					max=a[i];
			start =clock();
			for(i=0; i<100000; i++)
			{
				for (i = 0; i < 100; i++)
				{

					int randNum = rand() % 100;
					a[i] = randNum;
				}
				CountSort(a,100,max);
			}
			diff = clock() -start;
			printf("计数排序对100个数据进行100k次排序用时为%d ms\n",diff);
			for(i=0; i<100000; i++)
			{
				for (i = 0; i < 100; i++)
				{

					int randNum = rand() % 100;
					a[i] = randNum;
				}
				start =clock();
			}
			RadixCountSort(a,100);
			diff = clock() -start;
			printf("基数排序对100个数据进行100k次排序用时为%d ms\n",diff);
			for(i=0; i<100000; i++)
			{
				for (i = 0; i < 100; i++)
				{

					int randNum = rand() % 100;
					a[i] = randNum;
				}
				start =clock();
				insertSort(a,100);
			}
			diff = clock() -start;
			printf("插入排序对100个数据进行100k次排序用时为%d ms\n",diff);
			break;
		}
		case 5:
		{
			FILE* fp;
			if((fp = fopen("sort.txt", "w")) == NULL)
			{
				printf("打开文件失败！");
				exit(0);
			}
			int a[100],i;
			for (i = 0; i < 100; i++)
			{
				int randNum = rand() % 3; /* 随机生成0，1，2数字 */
				a[i] = randNum;
			}
			ColorSort(a,100);
			for(i=0; i<100; i++)
			{
				fprintf(fp,"%-8d\t\t",a[i]);
			}
			if(fclose(fp))
			{
				printf("关闭文件失败");
				exit(0);
			}
			else
			{
				printf("对100个数据排序成功！详情请到文件查看......\n");
			}
			break;
		}
		case 6:
		{
			int a[100],i,n,test;
			save(100);
			output(a);
			printf("这里有100个数，请输入你要查找的数的位置\n");
			n=input_detection(test);
			find_k(a,100,n);
			break;
		}
		case 7:
		{
			printf("退出成功！\n");
			exit(0);//关闭整个程序
		}
		default:
		{
			printf("您输入的数字有误！\n请重新输入1-7间的数字：");
			break;
		}
	}
}
