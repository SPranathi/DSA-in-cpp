/*
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1
*/
#include<iostream>
#include<stack>
using namespace std;
int brackets(char input[]){
    stack<char> s;
    int c=0;
    for(int i=0;input[i]!='\0';i++){
        if(input[i]=='{')
            s.push(input[i]);
        if(input[i]=='}'){
            if(!s.empty() && s.top()=='{')
                s.pop();
            else
                s.push(input[i]);
        }
    }
    c=s.size();
    if(c%2==0)
        return c/2;
    return -1;
}
int main(){
    char input[1000];
    cin>>input;
    cout<<brackets(input)<<endl;
} 
