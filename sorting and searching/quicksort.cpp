#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei){
    int pivot=arr[ei];
    int pindex=si;//let set pindex i.e partition index to start index
    for(int i=si;i<ei;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pindex]);
            pindex+=1;
        }
    }
    swap(arr[pindex],arr[ei]);
    return pindex;
}
void quicksort(int arr[],int si,int ei){
    //si is start index and ei is end index
    if(si>=ei)
        return ;
    int pi=partition(arr,si,ei); //pi is partition index
    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
} 
int main(){
    int i,n;
    cout<<"Enter the size of the array :";
    cin>>n;
    cout<<"Enter the elements of the array :";
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);
    cout<<"Sorted array:";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
