#include<iostream>

using namespace std;

const int N = 1e3+2,MOD = 1e9+7;

int dp[N];

int countSquare(int n){
    if(n == 1 || n == 2 || n == 3 || n == 0)
        return n;

    if(dp[n] != MOD) return dp[n];

    for (int i = 1; i*i <=n; i++)
    {   
        dp[n] = min(dp[n],1+countSquare(n-i*i));    
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<N; i++){
        dp[i] = MOD;
    }

    cout<<countSquare(n)<<endl;
}