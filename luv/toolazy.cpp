#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int cthNum = 0;

    for (int i = 2; c > 0; i++)
    {
        // cout << c << "ss" <<i<< endl;
        if (i % a == 0 || i % b == 0)
        {
            c--;
            cthNum = i;
        }
    }

    int lcm;

    for (int i = 1; i <= a * b; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            lcm = i;
            break;
        }
    }

    int step;
    if (cthNum % a == 0 && cthNum % b == 0)
    {
        step = lcm;
    }
    else if (cthNum % a == 0)
    {
        step = a;
    }
    else
    {
        step = b;
    }

    for (int i = cthNum; i >= 0; i = i - step)
    {
        cout << i << " ";
    }
}