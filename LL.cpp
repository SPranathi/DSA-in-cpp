#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* Insert(node* head){
    
}
int main(){
    int n,i;
    cout<<"Enter the operation to be performed: \n1.Insert the node 2.Delete the node\n3.Dispaly\n4.Exit\n";
    cin>>n;
    node* head=new node();
    head=NULL;
    switch(n){
        case 1:Insert(head);
        break;
        case 2:Delete(head);
        break;
        case 3:Display(head);
        break;
        case 4:exit();
    }
    
} 
