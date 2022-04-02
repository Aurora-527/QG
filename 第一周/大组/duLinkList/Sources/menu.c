#include"duLinkedList.h"
void menu(int i)//显示菜单
{
	printf("\n\n");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
	printf("\t\t\t\t-------系统功能菜单-----------\n\n");
	printf("\t\t1-----创建新链表\t\t\t");
	printf("2-----删除链表\n\n");
	printf("\t\t3-----向后插入新节点\t\t\t");
	printf("4-----删除单个节点\n\n");
	printf("\t\t5-----输出链表\t\t\t");
	printf("\t6-----向前插入新节点\n\n");
	printf("\t\t7-----退出系统\t\t\t\t\n");
	printf("\n\t\t\t\t请输入您需要使用的功能编号（1-7）\n\n");
	printf("\n\n");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
}


