/*
Given an integer n, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer n
Output Format :
No. of 0s
Sample Input :
10204
Sample Output
2
*/
#include<iostream>
using namespace std;
int countzeros(int n){
    if(n==0)
        return 0;
    if(n%10==0)
        return 1+countzeros(n/10);
    else
    {
        return countzeros(n/10);
    }
    
} 
int main(){
    int n;
    cin>>n;
    cout<<countzeros(n)<<endl;
}