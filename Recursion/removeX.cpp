#include<iostream>
#include<string.h>
using namespace std;
void removex(char s[]){
    if(s[0]=='\0')
        return ;
    if(s[0]!='x')
        removex(s+1);
    else{
        int i;
        for(i=1;s[i]!='\0';i++)
            s[i-1]=s[i];
        s[i-1]=s[i];
        removex(s);
    }
}
int main(){
    char str[100];
    cin>>str;
    cout<<strlen(str)<<endl;
    removex(str);
    cout<<str<<endl;
    cout<<strlen(str)<<endl;
} 
