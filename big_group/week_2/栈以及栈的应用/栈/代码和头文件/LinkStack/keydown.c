#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/栈/代码和头文件/head/LinkStack.h"
LinkStack *L=NULL; /* L为一空栈指针 */
ElemType test; /* test用于检测输入是否合法 */
void keydown(int i)/* 进入功能 */
{
	switch(i)
	{
		case 1:
		{
			L = (LinkStackPtr) malloc(sizeof(LinkStack)); /* 为栈动态申请空间 */
			if(initLStack(L))
			{
				printf("空栈创建成功！\n");
			}
			else
			{
				printf("空栈创建失败！\n");
			}
			break;
		}
		case 2:
		{
			if(L==NULL)
				printf("您还没有建立栈，请先建立一个链栈！\n");
			else if(isEmptyLStack(L))
				printf("该栈为空栈\n");
			else
				printf("该栈为非空栈\n");
			break;
		}
		case 3:
		{
			ElemType e; /* e用于读取数据 */
			if(L==NULL)
				printf("您还没有建立栈，请先建立一个链栈！\n");
			else if(getTopLStack(L,&e))
				printf("栈顶元素为：%d\n",e);
			else
				printf("该栈为空栈,请先将一些数据入栈\n");
			break;
		}
		case 4:
		{
			if(L==NULL)
				printf("您还没有建立栈，请先建立一个链栈！\n");
			else if(L->top==NULL)
				printf("该栈已是空栈，不用再次进行清空操作！\n");
			else
			{
				if(clearLStack(L))
					printf("栈清空成功！\n");
				else
					printf("栈清空失败！\n");
			}
			break;
		}
		case 5:
		{
			if(L==NULL)
				printf("您还没有建立栈，请先建立一个链栈！\n");
			else
			{
				if(destroyLStack(L))
				{
					printf("栈销毁成功！\n");
					L=NULL;
				}
				else
					printf("栈销毁失败！\n");
			}
			break;
		}
		case 6:
		{
			if(L==NULL)
				printf("您还没有建立栈，请先建立一个链栈！\n");
			else
			{
				ElemType length; /* length用于接受返回的长度值 */
				LStackLength(L,&length);
				printf("栈的长度为：%d\n",length);
			}
			break;
		}
		case 7:
		{
			unsigned int data; /* data为入栈数据 */
			if(L==NULL)
			{
				printf("您还没有建立栈，请先建立一个链栈！\n");
				break;
			}
			else
			{

				printf("请输入您要入栈的数据：\n");
				data=input_detection(test);
				if(pushLStack(L,data))
					printf("入栈成功！\n");
				else
					printf("入栈失败！\n");
			}
			break;
		}
		case 8:
		{
			unsigned int data; /* 接受出栈数据 */
			if(L==NULL)
			{
				printf("您还没有建立栈，请先建立一个链栈！\n");
				break;
			}
			else if(popLStack(L,&data))
				printf("本次出栈的元素为%d\n",data);
			else
				printf("链栈已为空栈，无法进行出栈操作！\n");
			break;
		}
		case 9:
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


