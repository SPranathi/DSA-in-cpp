#include<iostream>
using namespace std;

//using dynamic programming or bottom-up
int fib_DP(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++)
        ans[n]=ans[n-1]+ans[n-2];
    return ans[n];
}

int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

//using memorization or top-down
int fib_better(int n,int *ans){
    if(n<=1){
        ans[n]=n;
        return n;
    }
    if(ans[n-1]==0)
        ans[n-1]=fib_better(n-1,ans);
    if(ans[n-2]==0)
        ans[n-2]=fib_better(n-2,ans);
    ans[n]=ans[n-1]+ans[n-2];
    return ans[n];
}
int fib_better(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=0;
    return fib_better(n,ans);
}
int main(){
    int n;
    cin>>n;
    cout<<fib_DP(n)<<endl;
} 
