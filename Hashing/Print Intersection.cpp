/*
Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
Note : Order of elements are not important
Input format :
Line 1 : Integer N, Array 1 Size
Line 2 : Array 1 elements (separated by space)
Line 3 : Integer M, Array 2 Size
Line 4 : Array 2 elements (separated by space)
Output format :
Print intersection elements in different lines
Constraints :
1 <= M, N <= 10^6
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1
*/

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void intersection(int arr1[],int arr2[],int n,int si){
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        if(m.count(arr1[i])==0)
            m[arr1[i]]=1;
        else 
            m[arr1[i]]+=1;
    }

    for(int i=0;i<si;i++){
        if(m.count(arr2[i])==1){
            if(m[arr2[i]]==0)
                continue;
            cout<<arr2[i]<<endl;
            m[arr2[i]]-=1;
        }
    }
}

int main(){
    int n,m;
    cin>>n;
    int *arr1=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    cin>>m;
    int *arr2=new int[m];
    for(int i=0;i<m;i++)
        cin>>arr2[i];
    intersection(arr1,arr2,n,m);
}
