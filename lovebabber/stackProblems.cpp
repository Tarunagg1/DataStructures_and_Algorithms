#include <iostream>
#include <stack>

using namespace std;

string reverseStringUsingStack(stack<char> s, string str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    return ans;
}

void deleteMiddleElementFromStack(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();

    // recursive call
    deleteMiddleElementFromStack(s, count, size);
    s.push(num);
}

bool isParenthesisBalanced(string x)
{
    // Your code here
    stack<char> s;

    for (int i = 0; i < x.length(); i++)
    {
        char ch = x[i];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {

                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}



int main()
{
}