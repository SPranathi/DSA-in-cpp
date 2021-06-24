#include<iostream>
using namespace std;
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            else
            {
                break;
            }
            
        }
    }

} 
int main(){
    int i,n;
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n);
    cout<<"Sorted array in Ascending order by using Insertion Sort:"<<endl;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
