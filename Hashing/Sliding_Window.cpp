#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;



int main(){
    int n,k;
    cin>>n>>k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int s = 0,ans = INT_MAX;

    
    for (int i = 0; i < n; i++)
    {
        s+=v[i];
    }

    ans = min(ans,s);

    for(int i=1; i<n-k+1; i++){
        s -= v[i-1];
        s+= v[i+k-1];
        ans = min(ans,s);
    }   

    cout<<ans<<endl;
}



