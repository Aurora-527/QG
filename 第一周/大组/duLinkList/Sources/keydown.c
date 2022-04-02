#include"duLinkedList.h"
DuLinkedList L=NULL;
ElemType g_e,test; /* test用于作输入异常检测 */
void keydown(int i)/* 进入功能 */
{
	void (*visit)(ElemType e) = NULL;
	switch(i)
	{
		case 1:
		{
			if(InitList_DuL(&L))
			{
				int g,h,data;
				DuLinkedList s,r;
				printf("空表创建成功！\n");
				printf("请输入需要创建的节点的个数：");
				test = scanf("%d",&g);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);/* 清除输入缓冲区的错误数据 */
					test = scanf("%d",&g);
				}
				r=L;
				for(h=1; g>=h; h++)
				{
					printf("请输入第%d个节点数据",h);
					test=scanf("%d",&data);
					while(test==0)
					{
						printf("输入不合法，请输入阿拉伯数字！\n");
						fflush(stdin);//清除输入缓冲区的错误数据
						test = scanf("%d",&data);
					}
					s = (DuLNode*)malloc(sizeof(DuLNode));
					s ->data = data;
					r ->next = s;	/* s所指新结点的指针域next指向L中的开始结点 */
					s ->prior = r;	/* 连接前驱 */
					r = s;			/* 头结点的指针域next指向s结点，使得s成为新的开始结点r */
				}
				r->next=NULL;
				printf("各节点已创建成功！");
			}
			else
			{
				printf("空表创建失败！");
			}
			break;
		}
		case 2:
		{
			DestroyList_DuL(&L);
			break;
		}
		case 3:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				int e1;
				printf("请输入你要插入到的位置的前一个结点的数据");
				test=scanf("%d",&e1);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);
					test = scanf("%d",&e1);
				}
				DuLinkedList q;
				q=(DuLinkedList)malloc(sizeof(DuLNode));
				DuLinkedList p;
				p=L;
				while(p ->next)
				{
					p = p ->next;
					if(e1!=p->data&&p->next==NULL)
					{
						printf("表中暂无此数据！");
						break;
					}
					if(e1 == p->data)
					{
						if(InsertAfterList_DuL(p,q)==SUCCESS)
						{
							printf("添加成功！");
							break;
						}
						else
						{
							printf("添加失败！");
							break;
						}
					}

				}
				break;
			}
		}
		case 4:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				int data2;
				printf("请输入你要取出的位置的前一个结点的数据");
				test=scanf("%d",&data2);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);
					test = scanf("%d",&data2);
				}
				DuLinkedList p;
				p=L;
				while(p ->next)
				{
					p = p ->next;
					if(data2!=p->data&&p->next==NULL)
					{
						printf("表中暂无此数据！");
						break;
					}
					if(data2 == p->data)
					{
						if(DeleteList_DuL(p, &g_e)==SUCCESS)
						{
							printf("取出成功！");
							break;
						}
						else
						{
							printf("取出失败！");
							break;
						}
					}

				}
			}
			break;
		}
		case 5:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				TraverseList_DuL(L, (*visit));
				break;
			}
			break;
		}
		case 6:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				int e1;
				printf("请输入你要插入到的位置的后一个结点的数据");
				test=scanf("%d",&e1);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);
					test = scanf("%d",&e1);
				}
				DuLinkedList q;
				q=(DuLinkedList)malloc(sizeof(DuLNode));
				DuLinkedList p;
				p=L;
				while(p ->next)
				{
					p = p ->next;
					if(e1!=p->data&&p->next==NULL)
					{
						printf("表中暂无此数据！");
						break;
					}
					if(e1 == p->data)
					{
						if(InsertBeforeList_DuL(p,q)==SUCCESS)
						{
							printf("添加成功！");
							break;
						}
						else
						{
							printf("添加失败！");
							break;
						}
					}

				}
				break;
			}
		}
		case 7:
		{
			printf("退出成功！\n");
			exit(0);//关闭整个程序
		}
		default:
		{
			printf("您输入的数字有误！\n请重新输入1-11间的数字：");
		}
	}
}


