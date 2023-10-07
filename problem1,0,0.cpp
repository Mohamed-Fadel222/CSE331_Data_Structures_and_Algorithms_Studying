#include <iostream>
using namespace std;

void returnaddressestotarget(int arr[],int arr_size,int target){

    for (int i=0;i<arr_size;i++){
        for (int j=i+1;j<arr_size;j++){
            if (arr[i]+arr[j]==target){
                cout<<i<<j<<endl;
            }
        }
    }
    

}
int main(){

   int num[]={2,7,3,15};
   int target=10;
   int arr_size= sizeof(num)/ sizeof(num[0]);
   
   
  returnaddressestotarget(num,arr_size,18);


  


    return 0;

   
}