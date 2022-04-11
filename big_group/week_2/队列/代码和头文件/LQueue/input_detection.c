#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/队列/代码和头文件/head/LQueue.h"
int input_detection(int test) /* 输入检测函数 */
{
	unsigned int i; /* 避免输入长整型 */
	test=scanf("%d",&i);
	while(test==0||i>32768) /* 32768为整形边界值 */
	{
		printf("输入不合法，请输入规范数字！\n");
		fflush(stdin); /*清除输入缓冲区的错误数据 */
		test = scanf("%d",&i);
	}
	return i;
}

