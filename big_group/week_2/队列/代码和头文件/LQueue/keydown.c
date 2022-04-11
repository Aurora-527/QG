#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/����/�����ͷ�ļ�/head/LQueue.h"
LQueue L= {NULL,NULL}; /* L���ڳ��ض��� */
int test; /* test���ڼ�������Ƿ�Ϸ� */
void *e=NULL; /*���ڽ����û������������������ */

void keydown(int i)/* ���빦�� */
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
			if(L.front==NULL) /* ��ͷ��㣬֤�����л�δ���� */
				printf("����û�н������У����Ƚ���һ�����У�\n");
			else if(IsEmptyLQueue(&L))
				printf("�ö���Ϊ�ն���\n");
			else
				printf("�ö���Ϊ�ǿն���\n");
			break;
		}
		case 3:
		{
			if(L.front==NULL)
				printf("����û�н������У����Ƚ���һ�����У�\n");
			else if(L.front==L.rear&&L.front!=NULL) /* ����ͷָ���βָ��ָ��ͬһԪ�أ�֤����Ϊֻ��һ��ͷ���Ŀն��� */
				printf("�ö���Ϊ�ն���,��ͷ��Ԫ�أ�\n");
			else
			{
				int datasize; /* ͨ�������ֽڳ����ж��������� */
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
					printf("�ö�ͷԪ��Ϊ");
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
				printf("����û�н������У����Ƚ���һ�����У�\n");
			else if(L.rear==L.front)
				printf("�ö������ǿն��У������ٴν�����ղ�����\n");
			else
			{
				ClearLQueue(&L);
			}
			break;
		}
		case 5:
		{
			if(L.front==NULL)
				printf("����û�н������У����Ƚ���һ�����У�\n");
			else if(L.rear==L.front)
				printf("�ö����ǿն��У����ܽ��б���������\n");
			else
			{
				TraverseLQueue(&L,LPrint); /* ����Lprint������ָ�����ڱ��� */
			}
			break;
		}
		case 6:
		{
			if(L.front==NULL)
				printf("����û�н������У����Ƚ���һ�����У�\n");
			else
			{
				int length; /* length�����ж϶��г��� */
				length=LengthLQueue(&L);
				printf("���еĳ���Ϊ��%d\n",length);
			}
			break;
		}
		case 7:
		{
			void *data=NULL; /* dataΪ��������ݵĵ�ַ */
			if(L.front==NULL)
			{
				printf("����û�н������У����Ƚ���һ�����У�\n");
				break;
			}
			else
			{
				printf("�����������������ǰ����ĸ��(i.����\td.������\tc.�ַ���\tt.�ַ���)\n");
				test=scanf(" %c",&type); /* test���ڲ������������ݵĺϷ��ԣ�type��ʱ��������������� */
				while(!test||type!='i'&&type!='d'&&type!='c'&&type!='t')
				{
					printf("����ȷ���룡\n");
					fflush(stdin); /*������뻺�����Ĵ������� */
					test=scanf(" %c",&type);
				}
				datatype[L.length]=type; /* ��ȫ�ֱ���datatype�ַ����������ÿһ���������������� */
				if(type=='i')
				{
					printf("�������������\n");
					data=(int*)malloc(sizeof(int)); /*֪�����ͺ���������Ҫ�Ŀռ� */
					while(scanf("%d", (unsigned int*)data) != 1||*(unsigned int*)data>32768) /* 32768Ϊ���α߽�ֵ���������볤����  */
					{
						printf("��������ȷ����\n");
						fflush(stdin); /*������뻺�����Ĵ������� */
					}
					EnLQueue(&L,data);
					printf("����������ݣ�%d�ѳɹ���ӣ�\n",*(int*)data); /* ǿ��ת����int����� */
				}
				else if(type=='d')
				{
					printf("�������������\n");
					data=(double*)malloc(sizeof(double)); /*֪�����ͺ���������Ҫ�Ŀռ� */
					while(scanf("%lf", (double*)data) != 1)
					{
						printf("��������ȷ����\n");
						fflush(stdin); /*������뻺�����Ĵ������� */
					}
					EnLQueue(&L,data);
					printf("����������ݣ�%lf�ѳɹ���ӣ�\n",*(double*)data); /* ǿ��ת����double����� */
				}
				else if(type=='c')
				{
					printf("�������������\n");
					data=(char*)malloc(sizeof(char)); /*֪�����ͺ���������Ҫ�Ŀռ� */
					while(scanf("%c",(char*)data)!= 1)
					{
						printf("��������ȷ����\n");
						fflush(stdin); /*������뻺�����Ĵ������� */
					}
					EnLQueue(&L,data);
					printf("����������ݣ�%c�ѳɹ���ӣ�",*(char*)data); /* ǿ��ת�����ַ������ */
				}
				else if(type=='t')
				{
					printf("�������������\n");
					data=(char**)malloc(sizeof(datatype)); /*֪�����ͺ���������Ҫ�Ŀռ� */
					while(scanf("%s",*(char**)data) != 1)
					{
						printf("��������ȷ����\n");
						fflush(stdin); /*������뻺�����Ĵ������� */
					}
					EnLQueue(&L,data);
					printf("����������ݣ�%s�ѳɹ���ӣ�",*(char**)data); /* ǿ��ת�����ַ�������� */
				}

			}
			break;
		}
		case 8:
		{
			int data;
			if(L.front==NULL)
			{
				printf("����û�н������У����Ƚ���һ�����У�\n");
				break;
			}
			else if(L.rear==L.front)
				printf("�ö����ǿն��У��޷����г��Ӳ�����\n");
			else if(DeLQueue(&L))
				printf("��ͷԪ�س��ӳɹ���\n");
			else
				printf("����ʧ�ܣ�\n");
			break;
		}
		case 9:
		{
			if(L.front==NULL)
				printf("����û�н������У����Ƚ���һ�����У�\n");
			else
			{
				DestoryLQueue(&L);
			}
			break;
		}
		case 10:
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



