/*
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 */
#include<iostream>
using namespace std;

//DP
int editDistance_DP(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
    }
    for(int j=0;j<=n;j++){
        ans[0][j]=j;
    }
    for(int i=0;i<=m;i++){
        ans[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=ans[i-1][j-1];
            }
            else{
                ans[i][j]=min(ans[i-1][j],min(ans[i][j-1],ans[i-1][j-1]))+1;
            }
        }
    }
    return ans[m][n];
}

//Memorization or top-down
int editDistance_better(string s,string t,int **ans){
    if(s.size()==0 || t.size()==0)
        return max(s.size(),t.size());

    int m=s.size();
    int n=t.size();
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    if(s[0]==t[0]){
        ans[m][n]=editDistance_better(s.substr(1),t.substr(1),ans);
    }
    else{
        ans[m-1][n]=editDistance_better(s.substr(1),t,ans);
        ans[m][n-1]=editDistance_better(s,t.substr(1),ans);
        ans[m-1][n-1]=editDistance_better(s.substr(1),t.substr(1),ans);

        ans[m][n]=1+min(ans[m-1][n-1],min(ans[m-1][n],ans[m][n-1]));
    }
    return ans[m][n];
}

int editDistance_better(string s,string t){
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            ans[i][j]=-1;
    }
    return editDistance_better(s,t,ans);
}

//Brute Force
int editDistance(string s,string t){
    //Base case
    if(s.size()==0 || t.size()==0){
        return max(s.size(),t.size());
    }
    if(s[0]==t[0]){
        return editDistance(s.substr(1),t.substr(1));
    }
    else{
        //insert
        int x=editDistance(s.substr(1),t)+1;
        //Delete
        int y=editDistance(s,t.substr(1))+1;
        //Replace
        int z=editDistance(s.substr(1),t.substr(1))+1;
        return min(x,min(y,z));
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t)<<endl;
    cout<<editDistance_better(s,t)<<endl;
    cout<<editDistance_DP(s,t)<<endl;
}
