/*  Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.  */

#include <iostream>
#include <string>
#include <vector>
#define arrsize 20
using namespace std;

template <class T>
class stack
{
public:
    T arr[arrsize];
    int top = -1;

    bool isempty()
    {
        return (top <= -1) ? true : false;
    }

    bool isfull()
    {
        return (top == arrsize - 1) ? true : false;
    }

    void push(T elmt)
    {
        if (not isfull())
        {
            top++;
            arr[top] = elmt;
        }
    }

    T peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
    }

    T pop()
    {
        if (not isempty())
        {
            T temp = arr[top];
            top--;
            return temp;
        }
    }
};

int priority(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    else
        return 0;
}

string in_post(string exp)
{
    string ans;
    stack<char> s;
    char ch;

    for (int i = 0; i < exp.size(); i++)
    {
        ch = exp[i];
        if (ch == '(')
        {
            s.push('(');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!s.isempty() && priority(ch) <= priority(s.peek()))
            {
                ans += s.pop();
            }
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.peek() != '(')
            {
                ans += s.pop();
            }
            s.pop();
        }
        else
        {
            ans += ch;
        }
    }
    while (not s.isempty())
    {
        ans += s.pop();
    }
    return ans;
}

int calculate(string exp)
{
    int c = 0, v1, v2, temp;
    stack<int> val;
    char ch;
    int value[10];

    cout << "Enter values for variable :" << endl;
    for (int i = 0; i < exp.size(); i++)
    {
        ch = exp[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            cout << "Enter value for " << ch << " :";
            cin >> value[c];
            c++;
        }
    }

    string post = in_post(exp);
    c = 0;

    for (int i = 0; i < post.size(); i++)
    {
        switch (post[i])
        {
        case '+':
            v2 = val.pop();
            v1 = val.pop();
            temp = v2 + v1;
            val.push(temp);
            break;

        case '-':
            v2 = val.pop();
            v1 = val.pop();
            temp = v2 - v1;
            val.push(temp);
            break;

        case '*':
            v2 = val.pop();
            v1 = val.pop();
            temp = v2 * v1;
            val.push(temp);
            break;

        case '/':
            v2 = val.pop();
            v1 = val.pop();
            temp = v2 / v1;
            val.push(temp);
            break;

        case ' ':
            break;

        default:
            val.push(value[c]);
            c++;
            break;
        }
    }
    return val.pop();
}

int main()
{
    string exp;
    bool flag = true;
    int ch;

    while (flag)
    {
        cout << "------MENU------\n1.Infix to Postfix Conversion\n2.Evaluate Expression\n3.Exit\n----------------" << endl;
        cout << "Enter choice :";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter expression for conversion : ";
            cin >> exp;
            cout << "Postfix conversion of expression :" << in_post(exp) << endl;
            break;

        case 2:
            cout << "Enter expression for evaluation : ";
            cin >> exp;
            cout << "Evaluation of expression :" << calculate(exp) << endl;
            break;

        case 3:
            flag = false;
            cout << "Exitting Program !!" << endl;
            break;

        default:
            cout << "Enter valid choice !!" << endl;
            break;
        }
    }
    return 0;
}