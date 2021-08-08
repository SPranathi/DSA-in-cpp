//Insert, delete and display in single linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node *head=NULL;
void insert_begin(int data){
    node *newnode=new node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void insert_pos(int data){
    int pos;
    cout<<"enter position to insert:"<<endl;
    cin>>pos;
    node *newnode=new node(data);
    node *temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        if(temp->next==NULL){
        cout<<"Invalid Position."<<endl;
        return;}}
    node *temp2=temp->next;
    temp->next=newnode;
    newnode->next=temp2;
    delete temp;
}
void insert_end(int data){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    node *newnode=new node(data);
    node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    delete temp;
}
void del_begin(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;}
    head=head->next;
    return;
}
void del_pos(){
    int pos;
    cout<<"enter position to delete:"<<endl;
    cin>>pos;
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;}
    node *temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        if(temp->next==NULL){
        cout<<"Invalid Position."<<endl;
        return;}}
    temp->next=temp->next->next;
    delete temp;
}
void del_end(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;}
    node *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    temp->next=NULL;
    delete temp;
}
void display(){
    node *newnode=head;
    if(head==NULL){
        cout<<"List is empty\n";
        return;
    }
    while(newnode->next!=NULL){
        cout<<newnode->data<<" ";
        newnode=newnode->next;
    }
    cout<<newnode->data<<endl;
}
int main(){
    int choice,num;
    while(1){
    cout<<"Which operation do you want to Perform:"<<endl;
    cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit"<<endl;
    cin>>choice;
    switch(choice){
    case 1:{
        cout<<"Where you want to insert\n1.Beginning\n2.At particular position\n3.End"<<endl;
        cin>>num;
        int data;
        cin>>data;
        switch(num){
            case 1:insert_begin(data);
            break;
            case 2:insert_pos(data);
            break;
            case 3:insert_end(data);
            break;
        }    
        break;}
    case 2:
        cout<<"Where you want to insert\n1.Beginning\n2.At particular position\n3.End"<<endl;
        cin>>num;
        switch(num){
            case 1:del_begin();
            break;
            case 2:del_pos();
            break;
            case 3:del_end();
            break;
        }   
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    }
    }

} 
