/*
Given a linked list and a key in it, the task is to move all occurrences of given key to end of linked list, keeping order of all other elements same.
Return the updated head of LL.
Input Format :
Line 1 : Elements of the linked list ending with -1 (-1 not included)
Line 2 : Key n, Element which has to shifted
Output Format :
Updated linked list
Constraints :
1 <= size of list <= 100
Sample Input 1:
1 2 2 3 4 5 -1
2
Sample Output 1:
1 3 4 5 2 2 
Sample Input 2:
1 1 2 3 4 -1
1
Sample Output 2:
2 3 4 1 1
*/
#include<iostream>
using namespace std;
template<typename T>
class node{
public:
    T data;
    node *next;
    node(T data){
        this->data=data;
        next=NULL;
    } 
    ~node(){
        if(next!=NULL)
            delete next;
    }   
};
node<int> *movetolast(node<int> *head,int n ){
    node<int> *last=head;
    while(last->next!=NULL)
        last=last->next;
    node <int> *origlast=last;
    node<int> *temp=head;
    node<int> *prev=NULL;
    while(temp!=origlast){
        if(temp->data==n){
            if(prev==NULL){
                last->next=temp;
                head=temp->next;
                temp->next=NULL;
                last=temp;
                temp=head;
            }
            else{
                temp=temp->next;
                node <int> *t=prev->next;
                prev->next=t->next;
                last->next=t;
                t->next=NULL;
                last=t;
            }
            continue;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
node<int> *takeinput(){
    int data;
    cin>>data;
    node<int> *head=NULL,*tail=NULL;
    while(data!=-1){
    node<int>*newnode=new node<int>(data);
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
void print(node<int> *head){
    node<int> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node<int> *head=takeinput();
    int n;
    cin>>n;
    head=movetolast(head,n);
    print(head);
    delete head;
}
 
 
 
