#include"C:/Users/AURORA/Desktop/QG/ѵ��Ӫ������/QG������2022ѵ��Ӫ������/������/Sort/Headers/sort.h"
void output(int *a)
{
	FILE* fp;
	if((fp = fopen("sort.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp)/10,i;/* �����ļ���С */
	fseek(fp,0,SEEK_SET);
	for(i=0; i<fileSize; i++) /* ���ļ��ж������� */ 
	{
		fscanf(fp,"%d",&a[i]);
	}
	if(fclose(fp))
	{
		printf("�ر��ļ�ʧ��");
		exit(0);
	}
}
