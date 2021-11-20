/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/ 
#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

int BalancedBSTs(int h){
    vector<long long> v(h+1);
    v[0]=1;
    v[1]=1;
    v[2]=2;
    if(h==1 || h==2)
        return v[h];
    for(int i=3;i<=h;i++){
        for(int j=0;j<=i-1;j++)
            v[i]=((v[i]%mod)+((int)v[j]*(int)v[i-1-j])%mod)%mod;
    }
    return v[h]%mod;
}

int main(){
    int n;
    cin>>n;
    cout<<BalancedBSTs(n)<<endl;
}