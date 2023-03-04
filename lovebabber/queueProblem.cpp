#include <iostream>
#include <queue>

using namespace std;

queue<int> reverseQueue(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
    // add code here.
}





int main()
{
    queue<int> q;
}