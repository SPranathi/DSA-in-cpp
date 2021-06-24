#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
} 
int main(){
    int i,n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionsort(arr,n);
    cout<<"Sorted array in Ascending order by using Selction Sort:";
    for(i=0;i<n;i++){
        cout<<" "<<arr[i]<<" ";
    }
    cout<<"\n";
}