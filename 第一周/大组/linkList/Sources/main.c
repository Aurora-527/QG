#include"linkedList.h"
int main(int argc, char *argv[])
{
	int i;
	while(1)
	{
		int test;/* test���ڼ�������Ƿ�Ϸ� */
		menu(i);/* ��ʾ�˵� */
		test=scanf("%d",&i);
		while(test==0)
		{
			printf("���벻�Ϸ��������밢�������֣�\n");
			fflush(stdin); /*������뻺�����Ĵ������� */
			test = scanf("%d",&i);
		}
		keydown(i);/* ������ת */
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
