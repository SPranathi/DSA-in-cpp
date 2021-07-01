/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include<iostream>
#include<math.h>
using namespace std;
string printkeypad(int num){
    string dailer[]={"","","abc","def","ghi","jkl","mnop","qrs","tuv","wxyz"};
    return dailer[num];
}
void keypad(int num,string out){
    if(num==0){
       cout<<out<<endl;
       return;
    }
    string op=printkeypad(num%10);
    for(int i=0;i<op.size();i++){
        keypad(num/10,op[i]+out);
    }
    
}

int main(){
    int num;
    cin>>num;
    keypad(num,"");
    
}
