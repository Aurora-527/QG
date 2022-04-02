#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/四则运算计算器/代码和头文件/LinkStack.h"
int main()
{
	char opt[100]; /* opt用于存放表达式 */
	LinkStack_num* stack_num=(LinkStack_num*)malloc(sizeof(LinkStack_num)); /* 创建数字栈 */
	LinkStack_opt* stack_opt=(LinkStack_opt*)malloc(sizeof(LinkStack_opt)); /* 创建符号栈 */
	stack_num->top=NULL;
	stack_num->count=0;
	stack_opt->top=NULL;
	stack_opt->count=0; /* 初始化两个栈 */
	int i=0,tmp=0;/* i用于确定放进去的位置，tmp用于临时接受数据传进数字栈*/
	char option; /* option用于存放符号 */
	int num1,num2;
	printf("please input : \n");
	scanf("%s",opt);
	while(opt[i]!='\0'||stack_opt->top!=NULL)
	{
		if(opt[i]>='0'&&opt[i]<='9') /* 是数字 */
		{
			tmp = tmp*10+opt[i]-'0';
			i++;
			if(opt[i]<'0'||opt[i]>'9')
			{
				Push_num(stack_num,tmp);
				tmp = 0;
			}
		}
		else /* 是符号*/
		{
			if(stack_opt->top==NULL||(stack_opt->top->opt=='('&&opt[i]!=')')||Priority(opt[i])>Priority(stack_opt->top->opt))
			{
				Push_opt(stack_opt,opt[i]);
				i++;
				continue;
			}
			if(stack_opt->top->opt=='('&&opt[i]==')')
			{
				char temp;
				Pop_opt(stack_opt,&temp);
				i++;
				continue;
			}
			if((opt[i]=='\0'&&stack_opt->top!=NULL)||opt[i]==')'&&stack_opt->top->opt!='('||Priority(opt[i])<=Priority(stack_opt->top->opt))
			{
				Pop_opt(stack_opt,&option);
				switch(option)
				{
					case '+':
						{
							Pop_num(stack_num,&num1);
							Pop_num(stack_num,&num2);
							Push_num(stack_num,(num1+num2));
							break;
						}
					case '-':
						{
							Pop_num(stack_num,&num1);
							Pop_num(stack_num,&num2);
							Push_num(stack_num,(num2-num1));
							break;
						}	
					case '*':
						{
							Pop_num(stack_num,&num1);
							Pop_num(stack_num,&num2);
							Push_num(stack_num,(num1*num2));
							break;
						}	
					case '/':
						{
							Pop_num(stack_num,&num1);
							Pop_num(stack_num,&num2);
							Push_num(stack_num,(num2/num1));
							break;
						}
				}
	
				 
			}
		}
	}
	printf("result : %d\n",stack_num->top->num);		
} 
