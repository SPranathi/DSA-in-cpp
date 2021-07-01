/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/
#include<iostream>
using namespace std;
int allindexes(int arr[],int n,int x,int output[]){
    //base case
    if(n==0)
        return 0;
    int ans=allindexes(arr,n-1,x,output);
    if(arr[n-1]!=x)
        return ans;
    else{
        output[ans]=n-1;
        return ans+1;
    }
} 
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int *output=new int[n];
    int outputsize=allindexes(arr,n,x,output);
    for(int i=0;i<outputsize;i++){
        cout<<output[i]<<" ";
    }
    delete [] arr;
    delete [] output;
}
