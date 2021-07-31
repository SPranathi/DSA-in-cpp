/*
Sort a given linked list using Merge Sort.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format :
Linked list elements (separated by space and terminated by -1)
Output format :
Updated LL elements (separated by space)
Constraints :
1 <= Length of LL <= 1000
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
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
node *merge(node *head1,node *head2){
    node *head,*tail;
    if(head1->data<=head2->data){
        head=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        head=head2;
        tail=head2;
        head2=head2->next;
    }
    while(head1 && head2){
        if(head1->data<=head2->data){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
        }
        else{
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
    }
    while(head1){
        tail->next=head1;
        head1=head1->next;
        tail=tail->next;
    }
    while(head2){
        tail->next=head2;
        head2=head2->next;
        tail=tail->next;
    }
    return head;
}
node*  midpoint_LL(node *head){
    if (head==NULL)
     return NULL;
    if(head->next==NULL)
     return head;
    node *slow=head;
    node *fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; 
}
node *mergesort(node *head){
    if(head->next!=NULL){
        node *mid=midpoint_LL(head);
        node *mid1=mid->next;
        mid->next=NULL;
        node *left=mergesort(head);
        node *right=mergesort(mid1);
        node *ans=merge(left,right);
        return ans;
    }
    return head;
}

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
int main(){
    node *head=takeinput();
    head=mergesort(head);
    print(head);
    return 0;
}  
  

