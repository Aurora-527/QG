#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QG������2022ѵ��Ӫ������/������/Sort/Headers/sort.h"
void save(count)
{
	FILE* fp;
	if((fp = fopen("sort.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	int a[count],i;
	for (i = 0; i < count; i++) /* �������ָ�������� */
	{
		int randNum = rand() % count;
		a[i] = randNum;
	}
	for(i=0; i<count; i++) /* ������д���ļ� */
	{
		fprintf(fp,"%-8d\t\t",a[i]);
	}
	if(fclose(fp))
	{
		printf("�ر��ļ�ʧ��");
		exit(0);
	}
}
