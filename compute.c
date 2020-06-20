#include <stdio.h>

/**
 * 比较运算符的的优先级
 * 同优先级输出0
 * 第一个比第二个高输出1
 * 第一个比第二个低输出-1
 * */
int prior(char op1, char op2)
{
    switch (op1)
    {
    case '+':
        if (op2 == '-' || op2 == '+')
        {
            return 0;
        }
        else
        {
            return -1;
        } 
        break;
    case '-':
        if (op2 == '-' || op2 == '+')
        {
            return 0;
        }
        else
        {
            return -1;
        } 
        break;
    case '*':
        if (op2 == '-' || op2 == '+')
        {
            return 1;
        }
        else
        {
            return 0;
        } 
        break;
    case '/':
        if (op2 == '-' || op2 == '+')
        {
            return 1;
        }
        else
        {
            return 0;
        } 
        break;
    default:
        break;
    }
}

/**
 * 获取需要运算的数
 * */
double get_oprand()
{
    double evalue;
    printf("input evalue:");
    scanf("%lf%*c", &evalue);
    return evalue;
}

/**
 * 获取运算符
 * */
char get_operator()
{
    char op;
    printf("input operator:");
    scanf("%c", &op);
    return op;
}

/**
 * 根据运算法和数字计算结果
 * */
double evaluates(double value1, char op, double value2)
{
    double ret;
    switch (op)
    {
        case '+':
            ret = value1 + value2;
            break;
        case '-':
            ret = value1 - value2;
            break;
        case '*':
            ret = value1 * value2;
            break;
        case '/':
            ret = value1 / value2;
        break;
        default:
            break;
    }
    return ret;
}

/**
 * 
 * */
int main()
{
    // 获取第一个数
    double ev1 = get_oprand();
    // 获取第二个数
    double ev2 = get_oprand();
    // 获取运算符
    char op = get_operator();
    // 计算结果
    double ret = evaluates(ev1, op, ev2);
    // 终端输出结果
    printf("caculate result: %.2lf %c %.2lf = %.2lf\n", ev1, op, ev2, ret);
}
