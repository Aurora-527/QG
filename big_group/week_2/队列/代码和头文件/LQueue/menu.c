#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/队列/代码和头文件/head/LQueue.h"
void menu(int i)//显示菜单
{
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
	printf("\t\t\t\t-------系统功能菜单-----------\n\n");
	printf("\t\t1-----初始化队列\t\t\t");
	printf("2-----判断队列是否为空\n\n");
	printf("\t\t3-----得到队头元素\t\t\t");
	printf("4-----清空队列\n\n");
	printf("\t\t5-----遍历队列\t\t\t");
	printf("\t6-----检测队列长度\n\n");
	printf("\t\t7-----入队\t\t\t\t");
	printf("8-----出队\t\t\t\n\n");
	printf("\t\t9-----销毁队列\t\t\t\t");
	printf("10-----退出系统\t\t\t\n\n");
	printf("\n\t\t\t\t请输入您需要使用的功能编号（1-10）\n\n");
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
}
