#include <stack>
#include <unordered_map>

using namespace std;
unordered_map<char, int> symbols = {
    {'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3}};

bool isBalanced(string s)
{
    stack<char> st;
    for (char braket : s)
    {
        if (symbols[braket] < 0)
        {
            st.push(braket);
        }
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if (symbols[top] + symbols[braket] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
}
