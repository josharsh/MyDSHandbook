#include <stdio.h>
using namespace std;

int main(){
    int arr[]={ 1,2,3,4,5,6 }; //Input Array which has to be reversed.
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;++i){
        if(arr[i]>=0 && arr[i] !=i){
            arr[arr[i]]=(arr[arr[i]]+arr[i])-(arr[i]=arr[arr[i]]);
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;++i){
        cout<<arr[i];
    }
}