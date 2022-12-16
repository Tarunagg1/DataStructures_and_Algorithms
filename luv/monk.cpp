#include <iostream>

using namespace std;

char upper(char c)
{
    return 'A' + (c - 'a');
}

char lower(char c)
{
    return 'a' + (c - 'A');
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = upper(s[i]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = lower(s[i]);
        }
    }
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            res -= s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
    }

    if (res < 0)
    {
        res = res * -1;
    }

    int flag = 0;
    for (int i = 2; i < res; i++)
    {
        if (res & i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}