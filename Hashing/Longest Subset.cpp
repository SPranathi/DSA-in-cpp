/*
Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
Input Format :
Line 1 : Integer N, size of array
Line 2 : Array elements (separated by space)
Output Format :
Length of longest subarray
Contraints :
1<= N <=10^6
Sample Input 1 :
6 
1 0 0 1 1 1
Sample Output 1 :
4    
Sample Input 2 :
10 
1 1 1 0 0 0 1 1 0 0
Sample Output 2 :
10
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxlength(int arr[],int n){
    unordered_map<int,int> m;
    m[0]=-1;
    int c_0=0,c_1=0;
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            c_0++;
        else
            c_1++;

        if(m.find(c_1-c_0)!=m.end())
            res=max(res,i-m[c_1-c_0]);
        else
            m[c_1-c_0]=i;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxlength(arr,n);
}
