#include<iostream>
using namespace std;
#include<queue>
void KSortedArray(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        arr[j]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while(!pq.empty()){
        arr[j]=pq.top();
        pq.pop();
    }
}
int main(){
    int n;
    cin>>n;
    int k;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    KSortedArray(arr,n,k);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
