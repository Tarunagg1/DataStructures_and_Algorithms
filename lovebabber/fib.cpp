#include <iostream>

using namespace std;

int fibb(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    int ans = fibb(num - 1) + fibb(num - 2);
    return ans;
}

main()
{
    fibb(10);
}