#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/ջ�Լ�ջ��Ӧ��/ջ/�����ͷ�ļ�/head/LinkStack.h"
LinkStack *L=NULL; /* LΪһ��ջָ�� */
ElemType test; /* test���ڼ�������Ƿ�Ϸ� */
void keydown(int i)/* ���빦�� */
{
	switch(i)
	{
		case 1:
		{
			L = (LinkStackPtr) malloc(sizeof(LinkStack)); /* Ϊջ��̬����ռ� */
			if(initLStack(L))
			{
				printf("��ջ�����ɹ���\n");
			}
			else
			{
				printf("��ջ����ʧ�ܣ�\n");
			}
			break;
		}
		case 2:
		{
			if(L==NULL)
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
			else if(isEmptyLStack(L))
				printf("��ջΪ��ջ\n");
			else
				printf("��ջΪ�ǿ�ջ\n");
			break;
		}
		case 3:
		{
			ElemType e; /* e���ڶ�ȡ���� */
			if(L==NULL)
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
			else if(getTopLStack(L,&e))
				printf("ջ��Ԫ��Ϊ��%d\n",e);
			else
				printf("��ջΪ��ջ,���Ƚ�һЩ������ջ\n");
			break;
		}
		case 4:
		{
			if(L==NULL)
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
			else if(L->top==NULL)
				printf("��ջ���ǿ�ջ�������ٴν�����ղ�����\n");
			else
			{
				if(clearLStack(L))
					printf("ջ��ճɹ���\n");
				else
					printf("ջ���ʧ�ܣ�\n");
			}
			break;
		}
		case 5:
		{
			if(L==NULL)
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
			else
			{
				if(destroyLStack(L))
				{
					printf("ջ���ٳɹ���\n");
					L=NULL;
				}
				else
					printf("ջ����ʧ�ܣ�\n");
			}
			break;
		}
		case 6:
		{
			if(L==NULL)
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
			else
			{
				ElemType length; /* length���ڽ��ܷ��صĳ���ֵ */
				LStackLength(L,&length);
				printf("ջ�ĳ���Ϊ��%d\n",length);
			}
			break;
		}
		case 7:
		{
			unsigned int data; /* dataΪ��ջ���� */
			if(L==NULL)
			{
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
				break;
			}
			else
			{

				printf("��������Ҫ��ջ�����ݣ�\n");
				data=input_detection(test);
				if(pushLStack(L,data))
					printf("��ջ�ɹ���\n");
				else
					printf("��ջʧ�ܣ�\n");
			}
			break;
		}
		case 8:
		{
			unsigned int data; /* ���ܳ�ջ���� */
			if(L==NULL)
			{
				printf("����û�н���ջ�����Ƚ���һ����ջ��\n");
				break;
			}
			else if(popLStack(L,&data))
				printf("���γ�ջ��Ԫ��Ϊ%d\n",data);
			else
				printf("��ջ��Ϊ��ջ���޷����г�ջ������\n");
			break;
		}
		case 9:
		{
			printf("�˳��ɹ���\n");
			exit(0);//�ر���������
		}
		default:
		{
			printf("���������������\n����������1-9������֣�");
		}

	}
}


