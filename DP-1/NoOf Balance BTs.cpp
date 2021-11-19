/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 10^7
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
 */
#include<iostream>
#include<cmath>
#include<vector>
#define mod 1000000007
using namespace std;

//h>=0
int balancedBTs(int h){
    if(h<=1)
        return 1;
    int x=balancedBTs(h-1);
    int y=balancedBTs(h-2);

    int md=(int)(pow(10,9))+7;
    int t1=(int)(((long)(x)*x)%md);
    int t2=(int)(((long)(x)*2*y)%md);
    int ans=(t1+t2)%md;
    //int ans=x*x+2*x*y;
    return ans;
}

int balancedBTs_DP(int h){
    vector<long long> v(h+1);
    v[1]=1;
    v[2]=3;
    if(h==1 || h==2)
        return v[h];

    for(int i=3;i<=h;i++)
        v[i]=((v[i-1]%mod)*(v[i-1]%mod))%mod+((v[i-1]%mod)*(v[i-2]%mod)*2)%mod;
    return v[h]%mod;
}
int main(){
    int h;
    cin>>h;
    cout<<balancedBTs_DP(h)<<endl;
} 
