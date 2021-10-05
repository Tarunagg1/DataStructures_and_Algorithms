// Kadane's Algorithm
// O(n)

#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxContiguousSubarray_1(int arr[],int n){
    int curSum=0,max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<curSum+arr[i]){
            curSum+=arr[i];
        }
        else{
            curSum=arr[i];
        }
        max_sum=max(curSum,max_sum);
    }
    return max_sum;
}

int maxContiguousSubarray_2(int arr[],int n){
    int curSum=0,max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        curSum+=arr[i];
        if(curSum<0){
            curSum=0;
        }
        else if(curSum>max_sum){
            max_sum=curSum;
        }
    }
    return max_sum;
}

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxContiguousSubarray_1(arr,n);
}