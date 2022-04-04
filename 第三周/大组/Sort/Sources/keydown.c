#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QG������2022ѵ��Ӫ������/������/Sort/Headers/sort.h"
clock_t start,diff; /* ���ڼ��� */
void keydown(int i)
{
	switch(i)
	{
		case 1:
		{
			int a[10000],temp[10000];
			save(10000);
			output(a);
			start =clock(); /* ��ʼ��ʱ */
			MergeSort(a,0,9999,temp);
			diff = clock() -start; /* ������ʱ */
			printf("�鲢�����10000�����ݽ���������ʱΪ%d ms\n",diff);
			save(10000);
			output(a);
			start =clock(); /* ��ʼ��ʱ */
			QuickSort_Recursion(a,0,9999);
			diff = clock() -start; /* ������ʱ */
			printf("���������10000�����ݽ���������ʱΪ%d ms\n",diff);
			save(10000);
			output(a);
			int max=0,i;
			for(i=0; i<10000; i++)
				if(max<a[i])
					max=a[i];
			start =clock(); /* ��ʼ��ʱ */
			CountSort(a,10000,max);
			diff = clock() -start; /* ������ʱ */
			printf("���������10000�����ݽ���������ʱΪ%d ms\n",diff);
			save(10000);
			output(a);
			start =clock(); /* ��ʼ��ʱ */
			insertSort(a,10000);
			diff = clock() -start; /* ������ʱ */
			printf("���������10000�����ݽ���������ʱΪ%d ms\n",diff);
			save(10000);
			output(a);
			start =clock(); /* ��ʼ��ʱ */
			RadixCountSort(a,10000);
			diff = clock() -start; /* ������ʱ */
			printf("���������10000�����ݽ���������ʱΪ%d ms\n",diff);
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
			printf("�鲢�����50000�����ݽ���������ʱΪ%d ms\n",diff);
			save(50000);
			output(a);
			start =clock();
			QuickSort_Recursion(a,0,49999);
			diff = clock() -start;
			printf("���������50000�����ݽ���������ʱΪ%d ms\n",diff);
			save(50000);
			output(a);
			int max=0,i;
			for(i=0; i<50000; i++)
				if(max<a[i])
					max=a[i];
			start =clock();
			CountSort(a,50000,max);
			diff = clock() -start;
			printf("���������50000�����ݽ���������ʱΪ%d ms\n",diff);
			save(50000);
			output(a);
			start =clock();
			insertSort(a,50000);
			diff = clock() -start;
			printf("���������50000�����ݽ���������ʱΪ%d ms\n",diff);
			save(50000);
			output(a);
			start =clock();
			RadixCountSort(a,50000);
			diff = clock() -start;
			printf("���������50000�����ݽ���������ʱΪ%d ms\n",diff);
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
			printf("�鲢�����200000�����ݽ���������ʱΪ%d ms\n",diff);
			save(200000);
			output(a);
			start =clock();
			QuickSort_Recursion(a,0,199999);
			diff = clock() -start;
			printf("���������200000�����ݽ���������ʱΪ%d ms\n",diff);
			save(200000);
			output(a);
			int max=0,i;
			for(i=0; i<200000; i++)
				if(max<a[i])
					max=a[i];
			start =clock();
			CountSort(a,200000,max);
			diff = clock() -start;
			printf("���������200000�����ݽ���������ʱΪ%d ms\n",diff);
			save(200000);
			output(a);
			start =clock();
			RadixCountSort(a,200000);
			diff = clock() -start;
			printf("���������200000�����ݽ���������ʱΪ%d ms\n",diff);
			save(200000);
			output(a);
			start =clock();
			insertSort(a,200000);
			diff = clock() -start;
			printf("���������200000�����ݽ���������ʱΪ%d ms\n",diff);
			break;
		}
		case 4:
		{
			int a[100],temp[100],i;
			start =clock(); /* ��ʼ��ʱ */
			for(i=0; i<100000; i++) /* ����100k������ */
			{
				for (i = 0; i < 100; i++)
				{

					int randNum = rand() % 100;
					a[i] = randNum;
				}
				MergeSort(a,0,99,temp);
			}
			diff = clock() -start; /* ������ʱ */
			printf("�鲢�����100�����ݽ���100k��������ʱΪ%d ms\n",diff);
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
			printf("���������100�����ݽ���100k��������ʱΪ%d ms\n",diff);
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
			printf("���������100�����ݽ���100k��������ʱΪ%d ms\n",diff);
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
			printf("���������100�����ݽ���100k��������ʱΪ%d ms\n",diff);
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
			printf("���������100�����ݽ���100k��������ʱΪ%d ms\n",diff);
			break;
		}
		case 5:
		{
			FILE* fp;
			if((fp = fopen("sort.txt", "w")) == NULL)
			{
				printf("���ļ�ʧ�ܣ�");
				exit(0);
			}
			int a[100],i;
			for (i = 0; i < 100; i++)
			{
				int randNum = rand() % 3; /* �������0��1��2���� */
				a[i] = randNum;
			}
			ColorSort(a,100);
			for(i=0; i<100; i++)
			{
				fprintf(fp,"%-8d\t\t",a[i]);
			}
			if(fclose(fp))
			{
				printf("�ر��ļ�ʧ��");
				exit(0);
			}
			else
			{
				printf("��100����������ɹ��������뵽�ļ��鿴......\n");
			}
			break;
		}
		case 6:
		{
			int a[100],i,n,test;
			save(100);
			output(a);
			printf("������100��������������Ҫ���ҵ�����λ��\n");
			n=input_detection(test);
			find_k(a,100,n);
			break;
		}
		case 7:
		{
			printf("�˳��ɹ���\n");
			exit(0);//�ر���������
		}
		default:
		{
			printf("���������������\n����������1-7������֣�");
			break;
		}
	}
}
