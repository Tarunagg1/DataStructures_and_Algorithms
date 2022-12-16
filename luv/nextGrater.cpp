#include <stack>
#include <vector>

using namespace std;

vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> st;

    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > st.top())
        {
            nge[st.top()] = i;
        }
        st.push(i);
    }

    while (!st.empty()){
        nge[st.top()] = -1;
    }
    return nge;
}

// st 3 

// 4 5 2 25 7 8
// 1 3 3 -1 5 -1