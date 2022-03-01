#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int maxProfit(int arr[],int n){
    int maxProfit = 0;
    int minProfit = arr[0];

    for(int i=0; i<n; i++){
        minProfit = min(minProfit,arr[i]);
        int profit = arr[i]-minProfit;
        maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}   

int main(){
    int arr[] = {5,2,6,1,4};    
    cout<<maxProfit(arr,5);
}