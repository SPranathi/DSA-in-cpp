/*Longest common subsequence Problem*/
#include<iostream>
using namespace std;


//DP
int lcs_DP(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
    }
    //First row
    for(int j=0;j<=n;j++){
        ans[0][j]=0;
    }
    //First col
    for(int i=0;i<=m;i++){
        ans[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=1+ans[i-1][j-1];
            }
            else{
                ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans[m][n];
}

//Memorization
int lcs_better(string s,string t,int **ans){
    //Base case
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    int m=s.size();
    int n=t.size();
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    
    //Recursion calls
    if(s[0]==t[0]){
        ans[m-1][n-1]=lcs_better(s.substr(1),t.substr(1),ans);
        ans[m][n]=ans[m-1][n-1]+1;
    }
    else{
        ans[m][n-1]=lcs_better(s,t.substr(1),ans);
        ans[m-1][n]=lcs_better(s.substr(1),t,ans);
        ans[m][n]=max(ans[m][n-1],ans[m-1][n]);
        
    }
    return ans[m][n];
}

int lcs_better(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            ans[i][j]=-1;
        }
    }
    return lcs_better(s,t,ans);
}

//Brute force
int lcs(string s,string t){
    //Base case
    if(s.size()==0 || t.size()==0)
        return 0;

    //Recursive calls
    if(s[0]==t[0])
        return 1+lcs(s.substr(1),t.substr(1));
    else{
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        int c=lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<lcs_DP(s,t)<<endl;
    cout<<lcs(s,t)<<endl;
    cout<<lcs_better(s,t)<<endl;
}
