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
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++; 
    }
    
    map<int,int> ::iterator it;
    for(it = freq.begin(); it != freq.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}



