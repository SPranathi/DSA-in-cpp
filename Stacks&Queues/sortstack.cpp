/*
Given a stack, sort the elements inside that stack in ascending order using only push and pop operation. You can use one additional stack only.
    For eg.
Input Stack :  5 (top)
               4
               3
               2
               1
Output Stack : 1 (top)
               2
               3
               4
               5
Input format :
Line 1 : No. of elements in stack
Line 2 : Stack elements (separated by space)
Sample Input
5
1 2 3 4 5
Sample Output
1 2 3 4 5
*/
#include<iostream>
#include<stack>
using namespace std;
void sortstack(stack<int> &s){
    stack<int> t;
    while(!s.empty()){
        if(t.empty()){
            t.push(s.top());
            s.pop();
            continue;
        }    
        if(!t.empty() && t.top()>=s.top()){
            t.push(s.top());
            s.pop();
        }
        else{
            int temp=s.top();
            s.pop();
            while(!t.empty() && temp>t.top()){
                s.push(t.top());
                t.pop();
            }
            t.push(temp);
        }
    }
    s=t;
}
int main(){
    int size;
    cin>>size;
    int value;
    stack<int> s;
    for(int i=0;i<size;i++){
        cin>>value;
        s.push(value);
    }
    sortstack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
