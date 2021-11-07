#include<iostream>

using namespace std;

const int N = 1e3+2,MOD = 1e9+7;


int main(){
    int n;
    cin>>n;

    int dp[n];

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n]<<endl;
}