/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
 */

#include<bits/stdc++.h>
using namespace std;

int minc(int n,vector<int> v){
    int sq=floor(sqrt(n));

    if(sq*sq==n)
        return 1;
    if(v[n]!=0)
        return v[n];
    int temp=INT_MAX;
    for(int i=sq;i>=1;i--)
        temp=min(temp,minc(n-(i*i),v));

    v[n]=1+temp;
    return v[n];
}

int minc(int n){
    vector<int> v(n+1);
    return minc(n,v);
}

int main(){
    int n;
    cin>>n;
    cout<<minc(n)<<endl;
} 
