#include "C:/Users/AURORA/Desktop/QG/训练营第二周/QG工作室2022训练营第二周/栈以及栈的应用/四则运算计算器/代码和头文件/LinkStack.h"
int Priority(char ch)
{
    switch(ch)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
 
