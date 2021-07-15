/*
Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Line 2 : k
Sample Input 1 :
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
1 2 3 4 5 -1
2
Sample Output 2 :
2 1 4 3 5 
Sample Input 3 :
1 2 3 4 5 6 7 -1
3
Sample Output 3 :
3 2 1 6 5 4 7
*/
#include<iostream>
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
node *takeinput(){
    int data;
    cin>>data;
    node *head=NULL,*tail=NULL;
    while(data!=-1){
    node *newnode=new node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
    cin>>data;
    }
    return head;
}

void print(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node *reverseList(node *head){
    if(head==NULL)
     return NULL;
    if(head->next==NULL)
        return head;
    node *prev=head;
    node *cur=head->next;
    prev->next=NULL;
    while(cur){
        node *temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}
node *Kreverse(node *head,int n){
    if(head==NULL)
        return NULL;
    int count=0;
    node *front=head;
    node *tail=head;
    node *newhead;
    for(int i=1;i<n;i++){
        if(tail->next==NULL)
            break;
        else
        {
            tail=tail->next;
        }
        
    }
    node *newtail=front;
    node *temp=tail->next;
    tail->next=NULL;
    newhead=reverseList(front);
    node *ans=Kreverse(temp,n);
    newtail->next=ans;
    return newhead;
}
int main(){
    node *head=takeinput();
    int n;
    cin>>n;
    head=Kreverse(head,n);
    print(head);
}
