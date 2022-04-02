#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/队列/代码和头文件/head/LQueue.h"
LQueue L= {NULL,NULL}; /* L用于承载队列 */
int test; /* test用于检测输入是否合法 */
void *e=NULL; /*用于接收用户输入或函数传出的数据 */

void keydown(int i)/* 进入功能 */
{
	switch(i)
	{
		case 1:
		{
			InitLQueue(&L);
			break;
		}
		case 2:
		{
			if(L.front==NULL) /* 无头结点，证明队列还未建立 */
				printf("您还没有建立队列，请先建立一个队列！\n");
			else if(IsEmptyLQueue(&L))
				printf("该队列为空队列\n");
			else
				printf("该队列为非空队列\n");
			break;
		}
		case 3:
		{
			if(L.front==NULL)
				printf("您还没有建立队列，请先建立一个队列！\n");
			else if(L.front==L.rear&&L.front!=NULL) /* 队列头指针和尾指针指向同一元素，证明其为只有一个头结点的空队列 */
				printf("该队列为空队列,队头无元素！\n");
			else
			{
				int datasize; /* 通过数据字节长度判断数据类型 */
				if(datatype[0]=='i')
					datasize=sizeof(int);
				else if(datatype[0]=='d')
					datasize=sizeof(double);
				else if(datatype[0]=='c')
					datasize=sizeof(char);
				else if(datatype[0]=='t')
					datasize=sizeof(datatype);
				e=(void*)malloc(sizeof(datasize));
				if(GetHeadLQueue(&L, e))
				{
					printf("该队头元素为");
					if(datasize==4)
						printf("%d\n",*(int*)e);
					if(datasize==1)
						printf("%c\n",*(char*)e);
					if(datasize==8)
						printf("%lf\n",*(double*)e);
					if(datasize==30)
						printf("%s\n",*(char**)e);
				}
			}
			break;
		}
		case 4:
		{
			if(L.front==NULL)
				printf("您还没有建立队列，请先建立一个队列！\n");
			else if(L.rear==L.front)
				printf("该队列已是空队列，不用再次进行清空操作！\n");
			else
			{
				ClearLQueue(&L);
			}
			break;
		}
		case 5:
		{
			if(L.front==NULL)
				printf("您还没有建立队列，请先建立一个队列！\n");
			else if(L.rear==L.front)
				printf("该队列是空队列，不能进行遍历操作！\n");
			else
			{
				TraverseLQueue(&L,LPrint); /* 传入Lprint函数的指针用于遍历 */
			}
			break;
		}
		case 6:
		{
			if(L.front==NULL)
				printf("您还没有建立队列，请先建立一个队列！\n");
			else
			{
				int length; /* length用于判断队列长度 */
				length=LengthLQueue(&L);
				printf("队列的长度为：%d\n",length);
			}
			break;
		}
		case 7:
		{
			void *data=NULL; /* data为输入的数据的地址 */
			if(L.front==NULL)
			{
				printf("您还没有建立队列，请先建立一个队列！\n");
				break;
			}
			else
			{
				printf("请输入入队数据类型前的字母：(i.整形\td.浮点型\tc.字符型\tt.字符串)\n");
				test=scanf(" %c",&type); /* test用于测试所输入数据的合法性，type临时用来存放数据类型 */
				while(!test||type!='i'&&type!='d'&&type!='c'&&type!='t')
				{
					printf("请正确输入！\n");
					fflush(stdin); /*清除输入缓冲区的错误数据 */
					test=scanf(" %c",&type);
				}
				datatype[L.length]=type; /* 用全局变量datatype字符数组来存放每一个传进的数据类型 */
				if(type=='i')
				{
					printf("请输入入队数据\n");
					data=(int*)malloc(sizeof(int)); /*知道类型后申请所需要的空间 */
					while(scanf("%d", (unsigned int*)data) != 1||*(unsigned int*)data>32768) /* 32768为整形边界值，避免输入长整型  */
					{
						printf("请输入正确类型\n");
						fflush(stdin); /*清除输入缓冲区的错误数据 */
					}
					EnLQueue(&L,data);
					printf("您输入的数据：%d已成功入队！\n",*(int*)data); /* 强制转换成int型输出 */
				}
				else if(type=='d')
				{
					printf("请输入入队数据\n");
					data=(double*)malloc(sizeof(double)); /*知道类型后申请所需要的空间 */
					while(scanf("%lf", (double*)data) != 1)
					{
						printf("请输入正确类型\n");
						fflush(stdin); /*清除输入缓冲区的错误数据 */
					}
					EnLQueue(&L,data);
					printf("您输入的数据：%lf已成功入队！\n",*(double*)data); /* 强制转换成double型输出 */
				}
				else if(type=='c')
				{
					printf("请输入入队数据\n");
					data=(char*)malloc(sizeof(char)); /*知道类型后申请所需要的空间 */
					while(scanf("%c",(char*)data)!= 1)
					{
						printf("请输入正确类型\n");
						fflush(stdin); /*清除输入缓冲区的错误数据 */
					}
					EnLQueue(&L,data);
					printf("您输入的数据：%c已成功入队！",*(char*)data); /* 强制转换成字符型输出 */
				}
				else if(type=='t')
				{
					printf("请输入入队数据\n");
					data=(char**)malloc(sizeof(datatype)); /*知道类型后申请所需要的空间 */
					while(scanf("%s",*(char**)data) != 1)
					{
						printf("请输入正确类型\n");
						fflush(stdin); /*清除输入缓冲区的错误数据 */
					}
					EnLQueue(&L,data);
					printf("您输入的数据：%s已成功入队！",*(char**)data); /* 强制转换成字符串型输出 */
				}

			}
			break;
		}
		case 8:
		{
			int data;
			if(L.front==NULL)
			{
				printf("您还没有建立队列，请先建立一个队列！\n");
				break;
			}
			else if(L.rear==L.front)
				printf("该队列是空队列，无法进行出队操作！\n");
			else if(DeLQueue(&L))
				printf("队头元素出队成功！\n");
			else
				printf("出队失败！\n");
			break;
		}
		case 9:
		{
			if(L.front==NULL)
				printf("您还没有建立队列，请先建立一个队列！\n");
			else
			{
				DestoryLQueue(&L);
			}
			break;
		}
		case 10:
		{
			printf("退出成功！\n");
			exit(0);//关闭整个程序
		}
		default:
		{
			printf("您输入的数字有误！\n请重新输入1-9间的数字：");
		}

	}
}



