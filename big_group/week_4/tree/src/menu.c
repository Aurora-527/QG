#include"C:/Users/AURORA/Desktop/QG/训练营第四周/QG训练营第四周大组/代码和头文件/inc/binary_sort_tree.h"
void menu(int i)//显示菜单
{
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
	printf("\t\t\t\t-------排序菜单-----------\n\n");
	printf("\t\t1-----二叉排序树初始化\t\t\t");
	printf("2-----插入数据\n\n");
	printf("\t\t3-----删除数据\t\t\t");
	printf("\t4-----搜索数据\n\n");
	printf("\t\t5-----前序遍历（非递归）\t\t");
	printf("6-----前序遍历（递归）\n\n");
	printf("\t\t7-----中序遍历（非递归）\t");
	printf("\t8-----中序遍历（递归）\t\t\t\n\n");
	printf("\t\t9-----后序遍历（非递归）\t\t");
	printf("10-----后序遍历（递归）\t\t\t\n\n");
	printf("\t\t11-----层序遍历\t\t\t\t");
	printf("12-----退出系统\t\t\t\n\n");
	printf("\n\t\t\t\t请输入您需要使用的功能编号（1-12）\n\n");
	printf("\n\n\t");
	for(i=0; i<80; i++)
		printf("#");
	printf("\n\n");
}
