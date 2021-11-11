/*
Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).
Input Format :
Line 1 : Integer n, Array size
Line 2 : Array elements, separated by space
Output Format :
Array elements after sorting
Constraints :
1 <= n <= 10^6
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
8 6 5 4 3 2
 */
#include<iostream>
using namespace std;
void inplaceHeapSort(int input[],int n){
    //Build the heap in input array
    for(int i=1;i<n;i++){
        int childindex=i;
        while(childindex>0){
            int parentindex=(childindex-1)/2; 
            if(input[childindex]<input[parentindex]){
                int temp=input[childindex];
                input[childindex]=input[parentindex];
                input[parentindex]=temp;
            }
            else{
                break;
            }
            childindex=parentindex;
        } 
    }
    //Remove elements
    int size=n;

    while(size>1){
    int temp=input[0];
    input[0]=input[size-1];
    input[size-1]=temp;

    size--;

    //down-heapify
    int parentindex=0;
    int leftchildindex=2*parentindex+1;
    int rightchildindex=2*parentindex+2;

    while(leftchildindex<size){
        int minindex=parentindex;
        if(input[minindex]>input[leftchildindex]){
            minindex=leftchildindex;
        }
        if(rightchildindex<size && input[rightchildindex]<input[minindex]){
            minindex=rightchildindex;
        }
        if(minindex==parentindex){
            break;
        }
        int temp=input[minindex];
        input[minindex]=input[parentindex];
        input[parentindex]=temp;

        parentindex=minindex;
        leftchildindex=2*parentindex+1;
        rightchildindex=2*parentindex+2;
    }
    }
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    inplaceHeapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


 
