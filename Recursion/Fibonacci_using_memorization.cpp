#include<iostream>
using namespace std;
int F[51];//taking some constant as max input size
int fib(int n) {
    if(n<=1)
        return n;
    if(F[n]!=-1)
        return F[n];
    F[n]=fib(n-1)+fib(n-2);
    
    return F[n];
}
int main(){
    
    int n;
    cin>>n;
    for(int i=0;i<51;i++){
        F[i]=-1;
    }
    int r=fib(n);
    cout<<r;
}