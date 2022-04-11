#include"C:/Users/AURORA/Desktop/QG/训练营第三周/QG工作室2022训练营第三周/第三周/Sort/Headers/sort.h"
void output(int *a)
{
	FILE* fp;
	if((fp = fopen("sort.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp)/10,i;/* 计算文件大小 */
	fseek(fp,0,SEEK_SET);
	for(i=0; i<fileSize; i++) /* 从文件中读出数据 */ 
	{
		fscanf(fp,"%d",&a[i]);
	}
	if(fclose(fp))
	{
		printf("关闭文件失败");
		exit(0);
	}
}
