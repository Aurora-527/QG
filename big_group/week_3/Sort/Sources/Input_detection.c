#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QG������2022ѵ��Ӫ������/������/Sort/Headers/sort.h"
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
