/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(n).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
 */
#include<iostream>
using namespace std;

//DP
int knapsack_DP(int *weights,int *values,int n,int maxweight){
    int arr[maxweight+1]={0};
    for(int i=0;i<n;i++){
        for(int j=maxweight;j>=weights[i];j--){
            arr[j]=max(arr[j],values[i]+arr[j-weights[i]]);
        }
    }
    return arr[maxweight];
}

//Brute Force
int knapsack(int *weights,int *values,int n,int maxweight){
    //Base case
    if(n==0 || maxweight==0)
        return 0;
    //Recursive calls

    if(weights[0]>maxweight){
        return  knapsack(weights+1,values+1,n-1,maxweight);
    }
    int x=knapsack(weights+1,values+1,n-1,maxweight-weights[0])+values[0];
    int y=knapsack(weights+1,values+1,n-1,maxweight);

    return max(x,y);
}
int main(){
    int n,maxw;
    cin>>n;
    int *w=new int[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    int *v=new int[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    cin>>maxw;
    cout<<knapsack(w,v,n,maxw)<<endl;
    cout<<knapsack_DP(w,v,n,maxw)<<endl;
} 
