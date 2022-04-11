#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QGѵ��Ӫ�����ܴ���/�����ͷ�ļ�/inc/binary_sort_tree.h"
BinarySortTreePtr *L=NULL; /* ����һ���� */
int test; /* ���ڲ����������� */
void keydown(int i)
{
	switch(i)
	{
		case 1:
		{
			L=(BinarySortTreePtr*)malloc(sizeof(BinarySortTree)); /* ��ʼ���� */
			if(BST_init(*L))
			{
				printf("��ʼ���ɹ���");
			}
			else
				printf("��ʼ��ʧ��!");
			break;
		}
		case 2:
		{
			unsigned int data; /* ���ղ������� */
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("��������Ҫ��������ݣ�\n");
			data=input_detection(test);
			if(BST_insert(*L,data))
				printf("����ɹ�\n");
			else
				printf("����ʧ��!\n");
			break;
		}
		case 3:
		{
			unsigned int data; /* ����Ҫɾ�������� */
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("��������Ҫɾ�������ݣ�\n");
			data=input_detection(test);
			if(!BST_delete(*L, data))
				printf("����%dδ�������ҵ���\n",data);
			else
				printf("����%d��ɾ����\n",data);
			break;
		}
		case 4:
		{
			unsigned int data; /* ����Ҫ���ҵ����� */
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("��������Ҫ���ҵ����ݣ�\n");
			data=input_detection(test);
			if(!BST_search(*L, data))
				printf("����%dδ�������ҵ���\n",data);
			else
				printf("����%d���������ҵ���\n",data);
			break;
		}
		case 5:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("ǰ�������......\n");
			Sleep(500);
			BST_preorderI(*L,printValue);
			printf("\n");
			break;
		}
		case 6:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("ǰ�������......\n");
			Sleep(500);
			BST_preorderR(*L,printValue);
			printf("\n");
			break;
		}
		case 7:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("���������......\n");
			Sleep(500);
			BST_inorderI(*L,printValue);
			printf("\n");
			break;
		}
		case 8:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("���������......\n");
			Sleep(500);
			BST_inorderR(*L,printValue);
			printf("\n");
			break;
		}
		case 9:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("���������......\n");
			Sleep(500);
			BST_postorderI(*L,printValue);
			printf("\n");
			break;
		}
		case 10:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("���������......\n");
			Sleep(500);
			BST_postorderR(*L,printValue);
			printf("\n");
			break;
		}
		case 11:
		{
			if (L== NULL)
			{
				printf("����û�г�ʼ���������ȳ�ʼ������\n");
				break;
			}
			printf("���������......\n");
			Sleep(500);
			BST_levelOrder(*L,printValue);
			printf("\n");
			break;
		}
		case 12:
		{
			printf("�˳��ɹ���\n");
			exit(0);/* �ر��������� */
		}
		default:
		{
			printf("���������������\n����������1-12������֣�");
			break;
		}
	}
}
