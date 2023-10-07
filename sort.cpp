#include <iostream>
using namespace std;

void sort(int arr[],int arr_size){

    for (int i=0;i<arr_size;i++){
        for (int j=i+1;j<arr_size;j++){
            if (arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int i=0;i<arr_size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){

    int arr4[]={3,2,10,12,15,1,4,5,6,7,8,9,11,13,14};
    int arr_size=sizeof(arr4)/sizeof(arr4[0]);
    sort(arr4,arr_size);
    
   
    

    return 0;






}