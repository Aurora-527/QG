#include"linkedList.h"
LinkedList L=NULL; /* LΪһ�ձ��ͷ */ 
ElemType g_e,test; /* test���ڼ�������Ƿ�Ϸ� */
void keydown(int i)/* ���빦�� */
{
	void (*visit)(ElemType g_e) = NULL;
	switch(i)
	{
		case 1:
		{
			if(InitList(&L))
			{
				int g,h,data; /* g����ȷ����������hȷ��λ�ã�data������� */
				LinkedList s,r;
				printf("�ձ����ɹ���\n");
				printf("��������Ҫ�����Ľڵ�ĸ�����");
				test=scanf("%d",&g);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
					fflush(stdin);//������뻺�����Ĵ�������
					test = scanf("%d",&g);
				}
				r=L;
				for(h=1; g>=h; h++)
				{
					printf("�������%d���ڵ�����",h);
					test=scanf("%d",&data);
					while(test==0)
					{
						printf("���벻�Ϸ��������밢�������֣�\n");
						fflush(stdin);/* ������뻺�����Ĵ������� */
						test = scanf("%d",&data);
					}
					s = (LNode*)malloc(sizeof(LNode));
					s ->data = data;
					r ->next = s;	/* s��ָ�½���ָ����nextָ��L�еĿ�ʼ��� */
					r = s;			/* ͷ����ָ����nextָ��s��㣬ʹ��s��Ϊ�µĿ�ʼ���a */
				}
				r->next=NULL;
				printf("���ڵ��Ѵ����ɹ���");
			}
			else
			{
				printf("�ձ���ʧ�ܣ�");
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
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				int e1; /* e1����ȷ��λ�� */
				printf("��������Ҫ���뵽��λ�õ�ǰһ����������");
				test=scanf("%d",&e1);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
					fflush(stdin);/* ������뻺�����Ĵ������� */
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
						printf("�������޴����ݣ�");
						break;
					}
					if(e1 == p->data)
					{
						if(InsertList(p,q)==SUCCESS)
						{
							printf("��ӳɹ���");
							break;
						}
						else
						{
							printf("���ʧ�ܣ�");
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
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				int data2; /* ���ڴ���λ�� */
				printf("��������Ҫȡ����λ�õ�ǰһ����������");
				test=scanf("%d",&data2);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
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
						printf("�������޴����ݣ�");
						break;
					}
					if(data2 == p->data)
					{
						if(DeleteList(p, &g_e)==SUCCESS)
						{
							printf("ȡ���ɹ���");
							break;
						}
						else
						{
							printf("ȡ��ʧ�ܣ�");
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
				printf("����δ���������Ƚ�������\n\n");
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
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				int c;
				printf("������Ҫ��ѯ�����ݣ�\n");
				test=scanf("%d",&c);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
					fflush(stdin);
					test = scanf("%d",&c);
				}
				if(SearchList(L,c))
					printf("���ҵ� �ڵ�%d���ڵ�\n",SearchList(L,c));
				else printf("δ�ҵ�\n");
			break;
			}
		}
		case 7:
		{
			if(L==NULL)
			{
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				ReverseEvenList(&L);
				printf("������ż�����ɹ���");
			}
			break;
		}
		case 8:
		{
			if(L==NULL)
			{
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				LinkedList L0;
				L0=FindMidNode(&L);
				printf("�м���Ϊ��%d",L0->data);
			}
			break;
		}
		case 9:
		{
			if(L==NULL)
			{
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				if(IsLoopList(L))
					printf("���ڳɻ�\n");
				else
					printf("û�гɻ�\n");
			}
			break;
		}
		case 10:
		{
			if(L==NULL)
			{
				printf("����δ���������Ƚ�������\n\n");
				break;
			}
			else
			{
				if(ReverseList(&L))printf("��ת���\n");
				else printf("�������ɷ�ת\n");
			}
			break;
		}
		case 11:
		{
			printf("�˳��ɹ���\n");
			exit(0);//�ر���������
		}
		default:
		{
			printf("���������������\n����������1-11������֣�");
		}
	}
}

