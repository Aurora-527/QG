#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/栈/代码和头文件/head/LinkStack.h"
void menu(int i)//显示菜单
{
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
	printf("\t\t\t\t-------系统功能菜单-----------\n\n");
	printf("\t\t1-----初始化栈\t\t\t\t");
	printf("2-----判断栈是否为空\n\n");
	printf("\t\t3-----得到栈顶元素\t\t\t");
	printf("4-----清空栈\n\n");
	printf("\t\t5-----销毁栈\t\t\t");
	printf("\t6-----检测栈长度\n\n");
	printf("\t\t7-----入栈\t\t\t\t");
	printf("8-----出栈\t\t\t\n\n");
	/*
	printf("\t\t9-----判断成环\t\t\t\t");
	printf("10-----反转链表\t\t\t\n\n");
	*/
	printf("\t\t9-----退出系统\t\t\t\t\n");
	printf("\n\t\t\t\t请输入您需要使用的功能编号（1-9）\n\n");
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
}
