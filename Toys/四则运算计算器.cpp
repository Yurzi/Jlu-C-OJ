#include <iostream>
#include <stack>

using namespace std;

stack<int> num;
stack<int> oper;

bool cmpPriority(char a, char b)
{
    if (b == '*' || b == '/')
    {
        if (a == '+' || a == '-' || a == '(')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (b == '+' || b == '-')
    {
        if (a == '*' || a == '/')
        {
            return false;
        }
        else
        {
            if (a == '(')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (a == '(')
    {
        return true;
    }
    return true;
}

void poponeOpe(char ope)
{
    int a = 0;
    int b = 0;
    switch (ope)
    {
    case '+':
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(b + a);
        break;
    case '-':
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(b - a);
        break;
    case '*':
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a * b);
        break;
    case '/':
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        if (a == 0)
        {
            printf("NaN");
            exit(0);
        }
        num.push(b / a);
        break;
        break;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    stack<int> &tosee = num;
    stack<int> &app = oper;
    char ctemp = 0;
    char ope = 0;
    int res = 0;
    int itemp = 0;
    bool flag = true;
    while (flag)
    {
        res = -1;
        itemp = 0;
        while (1)
        {
            ctemp = getchar();
            if (ctemp >= '0' && ctemp <= '9')
            {
                itemp = itemp * 10 + int(ctemp - 48);
                res = itemp;
            }
            else
            {

                if (ctemp == '=')
                {
                    flag = false;
                }
                break;
            }
        }

        if (res > -1)
        {
            num.push(res);
        }
        if (oper.empty())
        {
            oper.push(ctemp);
        }
        else
        {
            if (ctemp == '(')
            {
                oper.push(ctemp);
            }
            else if (ctemp == ')')
            {
                while ('(' != oper.top())
                {
                    ope = oper.top();
                    poponeOpe(ope);
                    oper.pop();
                }
                oper.pop();
            }
            else if (cmpPriority(oper.top(), ctemp))
            {
                oper.push(ctemp);
            }
            else if (!cmpPriority(oper.top(), ctemp))
            {

                while (!cmpPriority(oper.top(), ctemp))
                {

                    ope = oper.top();
                    poponeOpe(ope);
                    oper.pop();
                    if (oper.empty())
                        break;
                }
                oper.push(ctemp);
            }
        }
    }
    while (!oper.empty())
    {
        ope = oper.top();
        poponeOpe(ope);
        oper.pop();
    }

    printf("%d", num.top());
    return 0;
}
