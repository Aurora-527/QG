#include"C:/Users/AURORA/Desktop/QG/训练营第四周/QG训练营第四周大组/代码和头文件/inc/binary_sort_tree.h"
BinarySortTreePtr *L=NULL; /* 创建一棵树 */
int test; /* 用于测试输入数据 */
void keydown(int i)
{
	switch(i)
	{
		case 1:
		{
			L=(BinarySortTreePtr*)malloc(sizeof(BinarySortTree)); /* 初始化树 */
			if(BST_init(*L))
			{
				printf("初始化成功！");
			}
			else
				printf("初始化失败!");
			break;
		}
		case 2:
		{
			unsigned int data; /* 接收插入数据 */
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("请输入你要插入的数据；\n");
			data=input_detection(test);
			if(BST_insert(*L,data))
				printf("插入成功\n");
			else
				printf("插入失败!\n");
			break;
		}
		case 3:
		{
			unsigned int data; /* 接受要删除的数据 */
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("请输入你要删除的数据；\n");
			data=input_detection(test);
			if(!BST_delete(*L, data))
				printf("数据%d未在树上找到！\n",data);
			else
				printf("数据%d已删除！\n",data);
			break;
		}
		case 4:
		{
			unsigned int data; /* 接受要查找的数据 */
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("请输入你要查找的数据；\n");
			data=input_detection(test);
			if(!BST_search(*L, data))
				printf("数据%d未在树上找到！\n",data);
			else
				printf("数据%d已在树上找到！\n",data);
			break;
		}
		case 5:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("前序遍历中......\n");
			Sleep(500);
			BST_preorderI(*L,printValue);
			printf("\n");
			break;
		}
		case 6:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("前序遍历中......\n");
			Sleep(500);
			BST_preorderR(*L,printValue);
			printf("\n");
			break;
		}
		case 7:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("中序遍历中......\n");
			Sleep(500);
			BST_inorderI(*L,printValue);
			printf("\n");
			break;
		}
		case 8:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("中序遍历中......\n");
			Sleep(500);
			BST_inorderR(*L,printValue);
			printf("\n");
			break;
		}
		case 9:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("后序遍历中......\n");
			Sleep(500);
			BST_postorderI(*L,printValue);
			printf("\n");
			break;
		}
		case 10:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("后序遍历中......\n");
			Sleep(500);
			BST_postorderR(*L,printValue);
			printf("\n");
			break;
		}
		case 11:
		{
			if (L== NULL)
			{
				printf("您还没有初始化树，请先初始化树！\n");
				break;
			}
			printf("层序遍历中......\n");
			Sleep(500);
			BST_levelOrder(*L,printValue);
			printf("\n");
			break;
		}
		case 12:
		{
			printf("退出成功！\n");
			exit(0);/* 关闭整个程序 */
		}
		default:
		{
			printf("您输入的数字有误！\n请重新输入1-12间的数字：");
			break;
		}
	}
}
