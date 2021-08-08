/*
Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
You need to return true if it is balanced, false otherwise.
Note: This problem was asked in initial rounds in Facebook
Sample Input 1 :
{ a + [ b+ (c + d)] + (e + f) }
Sample Output 1 :
true
Sample Input 2 :
{ a + [ b - c } ]
Sample Output 2 :
false
*/

#include<iostream>
#include<stack>
using namespace  std;
bool check_Paranthesis(char *in){
    stack<char> st;
    for(int i=0;in[i]!='\0';i++){
        if(in[i]=='(' || in[i]=='{' || in[i]=='[')
            st.push(in[i]);
        if(in[i]==')'){
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                return false;
        }
        if(in[i]=='}'){
            if(!st.empty() && st.top()=='{')
                st.pop();
            else
                return false;
        }
        if(in[i]==']'){
            if(!st.empty() && st.top()=='[')
                st.pop();
            else
                return false;
        }
    }
    if(!st.empty())
        return false;
    return true;
}
int main(){
    char input[100000];
    cin>>input;
    if(check_Paranthesis(input)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
