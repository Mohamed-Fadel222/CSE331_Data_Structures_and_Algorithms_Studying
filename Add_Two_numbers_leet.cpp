#include  <iostream>
#include <cmath>
using namespace std;

int addtwonumbers(int l1[],int l2[]){

    int l1_size=sizeof(l1)/sizeof(l1[0]);
    int l2_size=sizeof(l2)/sizeof(l2[0]);
    int num1=0;
    int num2=0;
    
    for(int i=0;i<=l1_size;i++){
        num1+=pow(10,i)*l1[i];
    }
     for(int j=0;j<=l2_size;j++){
        num2+=pow(10,j)*l2[j];
    }

    return num1+num2;

}


int main(){
    int l1[] = {2,4,3};
    int l2[] = {5,6,4};
    cout<<addtwonumbers(l1, l2)<<endl;
}