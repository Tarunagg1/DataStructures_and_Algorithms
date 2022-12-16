#include <iostream>

using namespace std;

main()
{
    int s;
    cin >> s;

    while (s--)
    {
        int k;
        cin >> k;
        long long mul = 0;

        while (k--)
        {
            int num;
            cin >> num;

            mul *= num;
        }

        if (mul % 10 == 2 || mul % 10 == 3 || mul % 10 == 5)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}