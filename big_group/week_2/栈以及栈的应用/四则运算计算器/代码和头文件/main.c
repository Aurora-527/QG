#include "C:/Users/AURORA/Desktop/QG/ѵ��Ӫ�ڶ���/QG������2022ѵ��Ӫ�ڶ���/ջ�Լ�ջ��Ӧ��/�������������/�����ͷ�ļ�/LinkStack.h"
int main()
{
	char opt[100]; /* opt���ڴ�ű��ʽ */
	LinkStack_num* stack_num=(LinkStack_num*)malloc(sizeof(LinkStack_num)); /* ��������ջ */
	LinkStack_opt* stack_opt=(LinkStack_opt*)malloc(sizeof(LinkStack_opt)); /* ��������ջ */
	stack_num->top=NULL;
	stack_num->count=0;
	stack_opt->top=NULL;
	stack_opt->count=0; /* ��ʼ������ջ */
	int i=0,tmp=0;/* i����ȷ���Ž�ȥ��λ�ã�tmp������ʱ�������ݴ�������ջ*/
	char option; /* option���ڴ�ŷ��� */
	int num1,num2;
	printf("please input : \n");
	scanf("%s",opt);
	while(opt[i]!='\0'||stack_opt->top!=NULL)
	{
		if(opt[i]>='0'&&opt[i]<='9') /* ������ */
		{
			tmp = tmp*10+opt[i]-'0';
			i++;
			if(opt[i]<'0'||opt[i]>'9')
			{
				Push_num(stack_num,tmp);
				tmp = 0;
			}
		}
		else /* �Ƿ���*/
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
