#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/����/�����ͷ�ļ�/head/LQueue.h"
int input_detection(int test) /* �����⺯�� */
{
	unsigned int i; /* �������볤���� */
	test=scanf("%d",&i);
	while(test==0||i>32768) /* 32768Ϊ���α߽�ֵ */
	{
		printf("���벻�Ϸ���������淶���֣�\n");
		fflush(stdin); /*������뻺�����Ĵ������� */
		test = scanf("%d",&i);
	}
	return i;
}

