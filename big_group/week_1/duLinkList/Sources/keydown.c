#include"duLinkedList.h"
DuLinkedList L=NULL;
ElemType g_e,test; /* test�����������쳣��� */
void keydown(int i)/* ���빦�� */
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
				printf("�ձ����ɹ���\n");
				printf("��������Ҫ�����Ľڵ�ĸ�����");
				test = scanf("%d",&g);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
					fflush(stdin);/* ������뻺�����Ĵ������� */
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
						fflush(stdin);//������뻺�����Ĵ�������
						test = scanf("%d",&data);
					}
					s = (DuLNode*)malloc(sizeof(DuLNode));
					s ->data = data;
					r ->next = s;	/* s��ָ�½���ָ����nextָ��L�еĿ�ʼ��� */
					s ->prior = r;	/* ����ǰ�� */
					r = s;			/* ͷ����ָ����nextָ��s��㣬ʹ��s��Ϊ�µĿ�ʼ���r */
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
			DestroyList_DuL(&L);
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
				int e1;
				printf("��������Ҫ���뵽��λ�õ�ǰһ����������");
				test=scanf("%d",&e1);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
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
						printf("�������޴����ݣ�");
						break;
					}
					if(e1 == p->data)
					{
						if(InsertAfterList_DuL(p,q)==SUCCESS)
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
				int data2;
				printf("��������Ҫȡ����λ�õ�ǰһ����������");
				test=scanf("%d",&data2);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
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
						printf("�������޴����ݣ�");
						break;
					}
					if(data2 == p->data)
					{
						if(DeleteList_DuL(p, &g_e)==SUCCESS)
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
				TraverseList_DuL(L, (*visit));
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
				int e1;
				printf("��������Ҫ���뵽��λ�õĺ�һ����������");
				test=scanf("%d",&e1);
				while(test==0)
				{
					printf("���벻�Ϸ��������밢�������֣�\n");
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
						printf("�������޴����ݣ�");
						break;
					}
					if(e1 == p->data)
					{
						if(InsertBeforeList_DuL(p,q)==SUCCESS)
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
		case 7:
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


