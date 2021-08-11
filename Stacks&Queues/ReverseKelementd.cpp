/*
Given a queue and an integer k, reverse first k elements. Return the updated queue.
Do the problem in O(n) complexity.
Input Format :
Line 1 : Integer N, Size of Queue
Line 2 : Queue Elements (separated by space)
Line 3 : Integer k
Output Format:
Updated Queue elements
Contraints :
1<= N <=10000
Sample Input 1:
5
1 2 3 4 5
3
Sample Output 1:
3 2 1 4 5
Sample Input 2:
7
3 4 2 5 6 7 8
7
Sample Output 2:
8 7 6 5 2 4 3
 */
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> reversekelements(queue<int> qt,int k){
    stack<int> st;
    queue<int> temp;
    int c=0;
    while(!qt.empty()){
        if(c<k){
            st.push(qt.front());
            c++;
        }
        else{
            temp.push(qt.front());
        }
        qt.pop();
    }
    queue<int> output;
    while(!st.empty()){
        output.push(st.top());
        st.pop();
    }
    while(!temp.empty()){
        output.push(temp.front());
        temp.pop();
    }
    return output;
}
int main(){
    int n,k;
    cin>>n;
    queue<int> qt;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        qt.push(temp);
    }
    cin>>k;
    queue<int> result=reversekelements(qt,k);
    while(!result.empty()){
        cout<<result.front()<<" ";
        result.pop();
    }

} 
