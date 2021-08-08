/*
Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
You don't need to print the elements, instead return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
1 11 3 6 8 0 9 -1
Sample Output 2 :
1 11 3 9 6 8 0
*/
#include<iostream>
#include<vector>
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
node *arrange_LL(node *head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    node *temp1=head;
    //find first even
    while(temp1->data%2!=0){
        if(!temp1->next)
            return head;
        temp1=temp1->next;
    }
    node *temp2=temp1->next;
    while(temp2){
        if(temp2->data%2!=0){
            vector<int> tmp;
            node *temp=temp1;
            while(temp!=temp2){
                tmp.push_back(temp->data);
                temp=temp->next;
            }
            temp1->data=temp2->data;
            temp=temp1->next;
            int k=0;
            while(temp!=temp2->next){
                temp->data=tmp[k];
                temp=temp->next;
                k++;
            }
            temp1=temp1->next;
        }
        temp2=temp2->next;
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
    head=arrange_LL(head);
    print(head);
}
 
