/*
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sub sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two arrays are of equal length return the array whose index of smallest element comes first.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 10^5
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
15 13 23 21 19 11 16
Sample Output 2 :
15 
16
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> longestSubsequence(int n,int *arr){
    unordered_map<int,int> umap;
    vector<int> v;
    for(int i=0;i<n;i++){
        umap[arr[i]]=i;
    }

    for(int i=0;i<n;i++){
        vector<int> temp;
        //Find the starting point for the increasing sequence
        if(umap.count(arr[i]-1)==0){
            temp.push_back(arr[i]);
            int t=1;

            while(umap.count(arr[i]+t)){
                temp.push_back(arr[i]+t);
                t++;
            }

            if(temp.size()>v.size()){
                v=temp;
            }
        }
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> output=longestSubsequence(n,arr);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
} 
