#include <iostream>
using namespace std;

int find_max(int arr[])//kaselt a5leha le kaza  size
{         
    int largest=arr[0];                                   

    for(int i=0;i<5;i++)    
    {
        if(arr[i]>largest)  
        {
            largest=arr[i]; 
        }      
    }

    return largest;
    



}

int main()
{
    int l[]={0,1,4,3,7};
    cout<<find_max( l)<<endl;

   
}

