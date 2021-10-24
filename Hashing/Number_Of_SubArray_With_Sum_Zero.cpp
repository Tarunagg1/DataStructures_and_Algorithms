#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;



int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    map<int,int> freq;
    int prefixsum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixsum += v[i];
        freq[prefixsum]++;
    }
    
    int ans =0;
    map<int,int> ::iterator it;

    for(it = freq.begin(); it != freq.end(); it++) {
        int c = it->second;
        ans += (c*(c-1)) / 2;
        if(it->first == 0){
            ans += it->second;
        }
    }
    cout<<ans;    
}



