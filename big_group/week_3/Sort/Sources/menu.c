#include"C:/Users/AURORA/Desktop/QG/训练营第三周/QG工作室2022训练营第三周/第三周/Sort/Headers/sort.h"
void menu(int i)//显示菜单
{
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
	printf("\t\t\t\t-------排序菜单-----------\n\n");
	printf("\t\t1-----10000数据量排序\t\t\t");
	printf("2-----50000数据量排序\n\n");
	printf("\t\t3-----200000数据量排序\t\t\t");
	printf("4-----生成100数据量用于100k次排序\n\n");
	printf("\t\t5-----颜色排序\t\t\t");
	printf("\t6-----无序序列中找到某个数\n\n");
	printf("\t\t7-----退出\t\t");
	printf("\n\t\t\t\t请输入您需要使用的功能编号（1-7）\n\n");
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
}
