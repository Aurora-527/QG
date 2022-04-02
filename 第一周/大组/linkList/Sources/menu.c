#include"linkedList.h"
void menu(int i)//显示菜单
{
	printf("\n\n");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
	printf("\t\t\t\t-------系统功能菜单-----------\n\n");
	printf("\t\t1-----创建新链表\t\t\t");
	printf("2-----删除链表\n\n");
	printf("\t\t3-----插入新节点\t\t\t");
	printf("4-----删除单个节点\n\n");
	printf("\t\t5-----输出链表\t\t\t");
	printf("\t6-----查询数据\n\n");
	printf("\t\t7-----单链表奇偶调换\t\t\t");
	printf("8-----获得中间结点\t\t\t\n\n");
	printf("\t\t9-----判断成环\t\t\t\t");
	printf("10-----反转链表\t\t\t\n\n");
	printf("\t\t11-----退出系统\t\t\t\t\n");
	printf("\n\t\t\t\t请输入您需要使用的功能编号（1-11）\n\n");
	printf("\n\n");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
}

