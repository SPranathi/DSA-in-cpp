/*Min Cost Path Problem*/
#include<iostream>
#include<climits>
using namespace std;

//DP
int mincost_DP(int **input,int m,int n){
    int **ans=new int*[m];
    for(int i=0;i<m;i++)
        ans[i]=new int[n];
    
    ans[m-1][n-1]=input[m-1][n-1];

    //Last row
    for(int j=n-2;j>=0;j--){
        ans[m-1][j]=ans[m-1][j]+ans[m-1][j+1];
    }

    //Last col
    for(int i=m-2;i>=0;i--){
        ans[i][n-1]=ans[i][n-1]+ans[i+1][n-1];
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            ans[i][j]=input[i][j]+min(ans[i+1][j],min(ans[i+1][j+1],ans[i][j+1]));
        }
    }
    return ans[0][0];
}

//Memorization
int mincostpath_better(int **input,int m,int n,int i,int j,int **ans){
    //Base case
    if(i==m-1 && j==n-1)
        return input[i][j];
    if(i>=m || j>=n)
        return INT_MAX;
    if(ans[i][j]!=-1)
        return ans[i][j];
    
    //Recursive calls
    int x=mincostpath_better(input,m,n,i,j+1,ans);
    if(x<INT_MAX){
        ans[i][j]=x;
    }
    int y=mincostpath_better(input,m,n,i+1,j+1,ans);
    if(y<INT_MAX){
        ans[i][j]=y;
    }
    int z=mincostpath_better(input,m,n,i+1,j,ans);
    if(z<INT_MAX){
        ans[i][j]=z;
    }

    //Small calculation
    ans[i][j]=min(x,min(y,z))+input[i][j];
    return ans[i][j];
}

int mincostpath_better(int **input,int m,int n){
    int **ans=new int*[m];
    for(int i=0;i<m;i++){
        ans[i]=new int[n];
        for(int j=0;j<n;j++){
            ans[i][j]=-1;
        }
    }
    return mincostpath_better(input,m,n,0,0,ans);
}

//Brute Force
int mincostpath(int **input,int m,int n,int i,int j){
    //Base case
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }

    //Recursive calls
    int x=mincostpath(input,m,n,i,j+1);
    int y=mincostpath(input,m,n,i+1,j+1);
    int z=mincostpath(input,m,n,i+1,j);

    //Small Calculation
    int ans=min(x,min(y,z))+input[i][j];

    return ans;
}

int mincostpath(int **input,int m,int n){
    return mincostpath(input,m,n,0,0);
}

int main(){
    int m,n;
    cin>>m>>n;
    int **input=new int*[m];
    for(int i=0;i<m;i++){
        input[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>input[i][j];
    }
    cout<<mincostpath(input,m,n)<<endl;
    cout<<mincostpath_better(input,m,n)<<endl;
    cout<<mincost_DP(input,m,n)<<endl;
} 
