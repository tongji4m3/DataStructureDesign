#include<iostream>
#include <string>
#include "Stack.h"
#include <unordered_map>
#include <math.h>

using namespace std;
/*
 表达式判断
 1.出现了除了+-* % / ^  ()=,数字以外的其他字符
 2.()匹配不全 或者()里面为空
 3.表达式没有结束之前出现了=,或者表达式最后不是=
 4.+-不是开头,或者前方不是(  一目运算符
 5.运算符前方或者后方无数字或者(),左边为),右边为(,避免(+)  二目运算符
 */
bool isValid(const string & expr)
{
    int N = expr.length();
    for (int i = 0; i < N; ++i)
    {
        if(expr[i]!='+'&&expr[i]!='-'&&expr[i]!='*'&&expr[i]!='/'&&expr[i]!='%'&&expr[i]!='^'&&
                expr[i]!='('&&expr[i]!=')'&&expr[i]!='='&& !(expr[i]<='9'&&expr[i]>='0'))
        {
            cout<<"表达式含有非法字符"<<endl;
            return false;
        }
        if(expr[i]=='(')
        {
            if(expr.find(')', i)==-1)
            {
                cout<<"没有足够的右括号匹配左括号"<<endl;
                return false;
            }
        }
        if(expr[i]==')')
        {
            int leftCount = 0, rightCount = 0;//()的个数
            for (int j = 0; j <= i; ++j)
            {
                if(expr[j]=='(')
                {
                    ++leftCount;
                }
                else if(expr[j]==')')
                {
                    ++rightCount;
                }
            }
            if(leftCount<rightCount)
            {
                cout<<"没有足够的左括号匹配右括号"<<endl;
                return false;
            }
        }
        if(expr[i]=='(' &&i+1<N && expr[i+1]==')')
        {
            cout<<"出现了空()"<<endl;
            return false;
        }
        if(i==N-1 && expr[i]!='=')
        {
            cout << "不以=结尾"<<endl;
            return false;
        }
        if(i!=N-1 && expr[i]=='=')
        {
            cout << "表达式中出现了="<<endl;
            return false;
        }
        if(expr[i]=='+' || expr[i]=='-')
        {
            if(i==0 || expr[i-1]=='(')//满足第四点 单目运算符
            {
                if(i+1<N && ((expr[i+1]=='(')||(expr[i+1]<='9'&&expr[i+1]>='0')))//合理了的
                {
                }
                else
                {
                    cout<<"+-后面没有数字或者("<<endl;
                    return false;
                }
            }
            //i+1存在,并且左边是)或者数字,并且右边是(或者数字
            else if(i+1<N && (expr[i-1]==')' || (expr[i-1]<='9'&&expr[i-1]>='0'))&& ((expr[i+1]=='(')||(expr[i+1]<='9'&&expr[i+1]>='0')))//i-1肯定>=0,因为上面的条件
            {

            }
            else
            {
                cout<<"不合理的+-"<<endl;
                return false;
            }
        }
        if(expr[i]=='^'||expr[i]=='%'||expr[i]=='*'||expr[i]=='/')
        {
            if(i-1>=0 && i+1<N && ((expr[i-1]==')' || (expr[i-1]<='9'&&expr[i-1]>='0'))&& ((expr[i+1]=='(')||(expr[i+1]<='9'&&expr[i+1]>='0'))))
            {
                //合格
            }
            else
            {
                cout<<"不合理的*/^%"<<endl;
                return false;
            }
        }
    }
	return true;
}

/*
 * 运算顺序
 * ^
 * %
 * 乘除
 * +-
 * ()
 * =
 */

/*
 * 把数字直接放入后缀表达式,操作符,按照优先级的顺序,如果优先级还是不断增加的,就再栈里面
 * 如果优先级相等或者更小,就把栈中的按次序拿出来,放入后缀表达式中
 * 特殊的,如果是(),则先压入(,遇到)时把栈中,(前面的取出
 * 如果是正负=-的话,+忽略掉,-变成,例如-5  ->  05-
 */
string toPostOrder(const string & expr)
{
    unordered_map<char,int> priority;//存储运算符的优先级
    priority['='] = 1;
    priority['('] = 2;
    priority[')'] = 2;
    priority['+'] = 3;
    priority['-'] = 3;
    priority['*'] = 4;
    priority['/'] = 4;
    priority['%'] = 5;
    priority['^'] = 6;
    string postOrderedExpr;
    Stack<char> ops;//存储运算符的
    for (int i = 0; i < expr.length(); ++i)
    {
        //处理一目运算符
        if((expr[i]=='+' || expr[i]=='-')&&(i == 0 || expr[i - 1] == '('))//当作正负来使用时
        {
            if(expr[i]=='+')
            {
                //忽略他
            }
            else
            {
                postOrderedExpr += "0 ";
                ++i;//将-后面的读入
                postOrderedExpr += expr[i];
                postOrderedExpr += " - ";
            }

        }
        else if(expr[i]<='9'&&expr[i]>='0')//这里需要处理下,就是如果输入大于0-9的数字也能正确处理
        {
			int hi = i+1;
			while (true)
			{
				if (hi < expr.length() && expr[hi] <= '9'&&expr[hi] >= '0')
				{
					++hi;
				}
				else
				{
					break;
				}

			}
			//hi指向的是数字后面的第一个非数字字符
			//expr.substr(i, hi - i); 得到了数字的字符串
            postOrderedExpr += expr.substr(i, hi - i);
            postOrderedExpr += " ";//避免出现10+5->105+的问题
			i = hi - 1;
        }
        else if(expr[i]=='(')
        {
            ops.push(expr[i]);
        }
        else if(expr[i]!=')')//除)外的运算符都压入
        {
            if(ops.empty())//栈为空,简单压入即可
            {
                ops.push(expr[i]);
            }
            else
            {
                //需要与栈顶运算符比较优先级
                int topStackPriority = priority[ops.top()];
                if(priority[expr[i]]>topStackPriority)
                {
                    ops.push(expr[i]);
                }
                else
                {
                    //优先级相同,必将弹出之前所有大于等于他优先级的运算符,再加入这个运算符
                    while(!ops.empty() && priority[expr[i]]<=topStackPriority)
                    {
                        postOrderedExpr += ops.top();
                        postOrderedExpr += " ";
                        ops.pop();
                        if(!ops.empty())
                        {
                            topStackPriority = priority[ops.top()];
                        }
                    }

                    ops.push(expr[i]);
                }
            }
        }
        else if(expr[i]==')')
        {
            //表达式检验过,一定正确,所以可以直接这样用
            while(ops.top()!='(')
            {
                postOrderedExpr += ops.top();
                postOrderedExpr += " ";//避免出现10+5->105+的问题
                ops.pop();
            }
            ops.pop();//把(弹出去
        }
    }
    //剩下的运算符一起加上
    while(!ops.empty())
    {
        if(ops.top()!='=')//不要=
        {
            postOrderedExpr += ops.top();
			postOrderedExpr += " ";
        }
        ops.pop();
    }
    return postOrderedExpr;
}

int caculatePostOrder(const string & postOrderedExpr)
{
    Stack<int> nums;
    for (int i = 0; i < postOrderedExpr.length(); ++i)
    {
        if(postOrderedExpr[i]<='9'&&postOrderedExpr[i]>='0')
        {
			//还要考虑处理大于10的数字

			int hi = i + 1;
			while (true)
			{
				if (hi < postOrderedExpr.length() && postOrderedExpr[hi] <= '9'&&postOrderedExpr[hi] >= '0')
				{
					++hi;
				}
				else
				{
					break;
				}

			}
			//hi指向的是数字后面的第一个非数字字符
			//postOrderedExpr.substr(i, hi - i); 得到了数字的字符串
			

            nums.push(atoi(postOrderedExpr.substr(i, hi - i).c_str()));

			i = hi - 1;
        }
        else if(postOrderedExpr[i]=='^')
        {
            //num1为左,num2为右
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(pow(num1, num2));
        }
        else if(postOrderedExpr[i]=='%')
        {
            //num1为左,num2为右
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1%num2);
        }
        else if(postOrderedExpr[i]=='/')
        {
            //num1为左,num2为右
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1/num2);
        }
        else if(postOrderedExpr[i]=='*')
        {
            //num1为左,num2为右
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1*num2);
        }
        else if(postOrderedExpr[i]=='-')
        {
            //num1为左,num2为右
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1-num2);
        }
        else if(postOrderedExpr[i]=='+')
        {
            //num1为左,num2为右
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            nums.push(num1+num2);
        }

    }
    return nums.top();
}

int main()
{
    while(true)
    {
        string expr,isContinue;
        cout << "输入表达式：" << endl;
        getline(cin,expr);
        if(isValid(expr))
        {
            string postOrderedExpr=toPostOrder(expr);
            cout <<"后序表达式为:"<<  postOrderedExpr<<endl;
            int result = caculatePostOrder(postOrderedExpr);
            cout<<result<<endl;
        }
        cout<<"任意键继续,n退出？";
        getline(cin,isContinue);
        if(isContinue=="n")
        {
            break;
        }
    }
    return 0;
}