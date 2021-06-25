#include<iostream>
using namespace std;
void increment(int& i){
    i++;
}

int main(){
    int i;
    i=10;

    increment(i);
    cout<<i<<endl;
    int& j=i;
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    int k=100;
    j=k;
    cout<<i<<endl;
} 
