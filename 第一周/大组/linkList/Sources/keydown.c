#include"linkedList.h"
LinkedList L=NULL; /* L为一空表表头 */ 
ElemType g_e,test; /* test用于检测输入是否合法 */
void keydown(int i)/* 进入功能 */
{
	void (*visit)(ElemType g_e) = NULL;
	switch(i)
	{
		case 1:
		{
			if(InitList(&L))
			{
				int g,h,data; /* g用于确定结点个数，h确定位置，data存放数据 */
				LinkedList s,r;
				printf("空表创建成功！\n");
				printf("请输入需要创建的节点的个数：");
				test=scanf("%d",&g);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);//清除输入缓冲区的错误数据
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
						fflush(stdin);/* 清除输入缓冲区的错误数据 */
						test = scanf("%d",&data);
					}
					s = (LNode*)malloc(sizeof(LNode));
					s ->data = data;
					r ->next = s;	/* s所指新结点的指针域next指向L中的开始结点 */
					r = s;			/* 头结点的指针域next指向s结点，使得s成为新的开始结点a */
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
			DestroyList(&L);
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
				int e1; /* e1用于确定位置 */
				printf("请输入你要插入到的位置的前一个结点的数据");
				test=scanf("%d",&e1);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);/* 清除输入缓冲区的错误数据 */
					test = scanf("%d",&e1);
				}
				LinkedList q;
				q=(LinkedList)malloc(sizeof(LNode));
				LinkedList p;
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
						if(InsertList(p,q)==SUCCESS)
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
				int data2; /* 用于创建位置 */
				printf("请输入你要取出的位置的前一个结点的数据");
				test=scanf("%d",&data2);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);
					test = scanf("%d",&data2);
				}
				LinkedList p;
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
						if(DeleteList(p, &g_e)==SUCCESS)
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
				TraverseList(L, (*visit));
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
				int c;
				printf("请输入要查询的数据：\n");
				test=scanf("%d",&c);
				while(test==0)
				{
					printf("输入不合法，请输入阿拉伯数字！\n");
					fflush(stdin);
					test = scanf("%d",&c);
				}
				if(SearchList(L,c))
					printf("已找到 在第%d个节点\n",SearchList(L,c));
				else printf("未找到\n");
			break;
			}
		}
		case 7:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				ReverseEvenList(&L);
				printf("链表奇偶调换成功！");
			}
			break;
		}
		case 8:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				LinkedList L0;
				L0=FindMidNode(&L);
				printf("中间结点为：%d",L0->data);
			}
			break;
		}
		case 9:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				if(IsLoopList(L))
					printf("存在成环\n");
				else
					printf("没有成环\n");
			}
			break;
		}
		case 10:
		{
			if(L==NULL)
			{
				printf("链表还未建立，请先建立链表。\n\n");
				break;
			}
			else
			{
				if(ReverseList(&L))printf("反转完成\n");
				else printf("该链表不可反转\n");
			}
			break;
		}
		case 11:
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

