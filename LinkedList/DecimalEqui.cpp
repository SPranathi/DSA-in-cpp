/*
Given a singly linked list of 0s and 1s, find and return its decimal equivalent.
Input Format :
Elements of the linked list ending with -1 (-1 not included)
Output Format:
Decimal equivalent of input LL
Constraints :
1 <= size of list <= 100
Sample Input 1:
1 0 -1
Sample Output 1:
2
Sample Input 2:
1 0 1 -1
Sample Output 2:
5
*/
#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
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
int dec(node<int> *head,int n){
    if(head==NULL)
        return 0;
    int sans=dec(head->next,n-1);
    int res=(head->data)*pow(2,n)+sans;
    return res;
}
int decimal(node<int> *head){
    node<int> *temp=head;
    int c=0;
    while(temp!=NULL){
        temp=temp->next;
        c++;
    }
    return dec(head,c-1);
}
node<int> *takeinput(){
    int data;
    cin>>data;
    node<int> *head=NULL,*tail=NULL;
    while(data!=-1){
    node<int> *newnode=new node<int>(data);
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
    cout<<decimal(head);
    return 0;
}  

