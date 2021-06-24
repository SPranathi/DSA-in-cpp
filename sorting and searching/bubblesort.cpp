#include<iostream>
using namespace std;
//loop through each element in array
void bubblesort(int arr[],int n) {
    for(int i=0;i<n;i++){
        int swap=0 ; //keeping the track of swapping
        //loop for compare elements
        for(int j=0;j<n-i-1;j++){
            //compare adjacent elements
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                //if swapping occurs set swap to true
                swap=1;}
        }
        //no swap means array is sorted
        if(swap==0)
            break;       
    }
}
int main(){
    int n,i;
    cout<<"Enter the size of the arrray to be sorted:";
    cin>>n;
    cout<<"Enter the elements of the array"<<endl;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    cout<<"Sorted array in Ascending order using Bubble Sort:"<<endl;
    for(i=0;i<n;i++){
        cout<<" "<<arr[i]<<" ";
    }
    cout<<"\n";
}
