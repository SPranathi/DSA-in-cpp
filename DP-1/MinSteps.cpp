#include<iostream>
#include<climits>
using namespace std;

int minSteps_DP(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<=n;i++){
        int r=1+ans[i-1];
        if(i%2==0)
            r=min(r,1+ans[i/2]);
        if(i%3==0)
            r=min(r,1+ans[i/3]);
        ans[i]=r;
    }
    return ans[n];
}
int minSteps(int n){
    //Base case
    if(n==1)
        return 0;
    int x=minSteps(n-1);
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0)
        y=minSteps(n/2);
    if(n%3==0)
        z=minSteps(n/3);
    return min(x,min(y,z))+1;
}

//ans-intialize with -1
int minSteps_better(int n,int *ans){
    if(n==1){
        ans[n]=0;
        return 0;
    }
    if(ans[n-1]==-1){
        ans[n-1]=minSteps_better(n-1,ans);
    }
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0){
        if(ans[n/2]==-1)
            ans[n/2]=minSteps_better(n/2,ans);
        y=ans[n/2];
    }
    if(n%3==0){
        if(ans[n/3]==-1)
            ans[n/3]=minSteps_better(n/3,ans);
        y=ans[n/3];
    }
    ans[n]=min(ans[n-1],min(y,z))+1;
    return ans[n];
}

int minSteps_better(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;
    return minSteps_better(n,ans);
}
int main(){
    int n;
    cin>>n;
    cout<<minSteps_better(n)<<endl;
    cout<<minSteps_DP(n)<<endl;
}
