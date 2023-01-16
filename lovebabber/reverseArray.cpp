#include<iostream>

using namespace std;


void reverseArr(int arr[], int len){
    int start  = 0;
    int end = len - 1;

    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}
