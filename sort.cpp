#include <iostream>
using namespace std;

void sort(int arr[],int arr_size){

    for (int i=0;i<arr_size;i++){
        if (arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i]=temp;

        }
    }
   
}

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr_size);
    for (int i=0;i<arr_size;i++){
        cout<<arr[i]<<endl;
    }

    return 0;






}