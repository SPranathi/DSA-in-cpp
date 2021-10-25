/*
Given an integer array, find and return the minimum distance between indexes of an element and its repetition.
Input Format :
Line 1 : Integer N, Size of array
Line 2 : Elements of the array (separated by space)
Output Format :
Print the minimum distance 
Contraints :
1<= N <=10^6
Sample Input 1:
6
1 3 1 5 4 3
Sample Output 1:
2
Sample Input 2:
7
5 47 82 4 4 6 2 
Sample Output 2:
1
*/
#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int MinDistance(int arr[],int n){
    unordered_map<int,int> m;
    int mind=INT_MAX;
    for(int i=0;i<n;i++){
        if(!m.count(arr[i]))
            m[arr[i]]=i;
        else{
            mind=min(mind,i-m[arr[i]]);
            m[arr[i]]=i;
        }
    }
    return mind;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<MinDistance(arr,n)<<endl;
} 
