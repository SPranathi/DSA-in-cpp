/*
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k smallest elements
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
5
3
2
1
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Ksmallest(int *v,int n,int k){
    priority_queue<int> pq;
    vector<int> ans;
    for(int i=0;i<k;i++)
        pq.push(v[i]);
    for(int i=k;i<n;i++){
        if(v[i]<pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main(){
    int n,k,s;
    cin>>n;
    int *v=new int[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    vector<int> arr=Ksmallest(v,n,k);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}  
