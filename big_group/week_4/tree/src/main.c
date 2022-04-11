#include"C:/Users/AURORA/Desktop/QG/训练营第四周/QG训练营第四周大组/代码和头文件/inc/binary_sort_tree.h"

int main()
{
	int i;
	while(1)
	{
		unsigned int test;/* test用于检测输入是否合法 */
		menu(i);/* 显示菜单 */
		i=input_detection(test);
		keydown(i);/* 功能跳转 */
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
