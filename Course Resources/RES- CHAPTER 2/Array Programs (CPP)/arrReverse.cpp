#include <iostream>
using namespace std;

int main(){
    int arr[]={ 1,2,3,4,5,6 }; //Input Array which has to be reversed.
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0])-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
   
        start++;
        end--;
    }
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);++i){
        cout<<arr[i];
    
}}