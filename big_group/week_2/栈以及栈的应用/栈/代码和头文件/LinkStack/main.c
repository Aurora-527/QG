#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/栈/代码和头文件/head/LinkStack.h"
int main(int argc, char *argv[])
{
	int i;
	while(1)
	{
		int test;/* test用于检测输入是否合法 */
		menu(i);/* 显示菜单 */
		i=input_detection(test);
		keydown(i);/* 功能跳转 */
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
