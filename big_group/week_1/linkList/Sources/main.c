#include"linkedList.h"
int main(int argc, char *argv[])
{
	int i;
	while(1)
	{
		int test;/* test用于检测输入是否合法 */
		menu(i);/* 显示菜单 */
		test=scanf("%d",&i);
		while(test==0)
		{
			printf("输入不合法，请输入阿拉伯数字！\n");
			fflush(stdin); /*清除输入缓冲区的错误数据 */
			test = scanf("%d",&i);
		}
		keydown(i);/* 功能跳转 */
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
