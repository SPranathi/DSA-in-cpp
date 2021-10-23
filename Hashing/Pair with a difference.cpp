/*
You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Best solution takes O(n) time. And take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
1 <= n <= 5000
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void diffpairs(int n,int arr[],int diff){
    unordered_map<int,int> m;

    //Unusual case of zero
    if(diff==0){
        for(int i=0;i<n;i++){
            if(m.count(arr[i]))
                m[arr[i]]+=1;
            else
                m[arr[i]]=0;

            if(m[arr[i]]){
                int t=m[arr[i]];
                for(int j=1;j<=t;j++)
                    cout<<(arr[i])<<" "<<(arr[i])<<endl;
            }
        }
    }

    else{
        for(int i=0;i<n;i++){

            if(m.count(arr[i]))
                m[arr[i]]+=1;
            else 
                m[arr[i]]=1;

            if(m.count(arr[i]+diff)){
                int t=m[arr[i]+diff];
                for(int j=1;j<=t;j++)
                    cout<<(arr[i])<<" "<<(arr[i]+diff)<<endl;
            }
            if(m.count(arr[i]-diff)){
                int t=m[arr[i]-diff];
                for(int j=1;j<=t;j++)
                    cout<<(arr[i]-diff)<<" "<<(arr[i])<<endl;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int diff;
    cin>>diff;
    diffpairs(n,arr,diff);
} 
