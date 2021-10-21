/*
You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
Write a program to return true if there exists a sub-array whose sum is zero else, return false.
Input Format :
Line 1 : An Integer N i.e. size of array 
Line 2 : N integers, elements of the array (separated by space)
Output Format :
true or false
Constraints :
1 <= N <= 10^5
Sample Input 1 :
6 
7 1 3 -4 5 1
Sample Output 1 :
true
Sample Input 2 :
5 
-6 7 6 2 1
Sample Output 2 :
false
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool subarrayzero(int arr[],int n){
    unordered_map<int,int> m;
    vector<int> v;

    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        v.push_back(v[i-1]+arr[i]);
    }

    for(int i=0;i<n;i++){
        if(m.count(v[i]))
            return true;
        else 
            m[v[i]]=i;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bool ans=subarrayzero(arr,n);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
}