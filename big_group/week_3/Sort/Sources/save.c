#include"C:/Users/AURORA/Desktop/QG/训练营第三周/QG工作室2022训练营第三周/第三周/Sort/Headers/sort.h"
void save(count)
{
	FILE* fp;
	if((fp = fopen("sort.txt", "w")) == NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	int a[count],i;
	for (i = 0; i < count; i++) /* 随机生成指定个数字 */
	{
		int randNum = rand() % count;
		a[i] = randNum;
	}
	for(i=0; i<count; i++) /* 将数据写入文件 */
	{
		fprintf(fp,"%-8d\t\t",a[i]);
	}
	if(fclose(fp))
	{
		printf("关闭文件失败");
		exit(0);
	}
}
