/*
Given a two Linked Lists, find out union of both given input lists and return the new Linked List.
Order of elements are not important.
Note : You don't need to print the linked list, just return the head. It will be printed internally.
Input format :
Line 1 : Linked list 1 elements (separated by space and terminated by -1)
Line 2 : Linked list 2 elements (separated by space and terminated by -1)
Sample Input 1 :
1 2 3 4 -1
8 7 5 3 -1
Sample Output 1 :
1
2
3
4
8
7
5
Sample Input 2 :
1 2 1 1 -1
8 -1
Sample Output 2 :
1
2
1
1
8
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
template <typename T>
class Listnode{
public:
    T data;
    Listnode<T> *next;
    Listnode<T>(T data){
        this->data=data;
        next=NULL;
    } 
     
};

Listnode<int> *unionof2LL(Listnode<int> *head1,Listnode<int> *head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;

    Listnode<int> *union1=head1;
    unordered_map<int,int> m;
    vector<int> v;
    Listnode<int> *cur=head1;
    
    while(cur->next){
        m[cur->data]+=1;
        cur=cur->next;
    }
    m[cur->data]+=1;

    Listnode<int> *cur2=head2;
    while(cur2){
        if(m[cur2->data]!=0)
            m[cur2->data]--;
        else
            v.push_back(cur2->data);
        cur2=cur2->next;
    }
    if(v.empty())
        return union1;
    Listnode<int> *newnode=new Listnode<int>(v[0]);
    Listnode<int> *tail=newnode;
    for(int i=1;i<v.size();i++){
        Listnode<int> *t=new Listnode<int>(v[i]);
        tail->next=t;
        tail=t;
    }
    cur->next=newnode;
    return union1;

}
Listnode<int> *takeinput(){
    int data;
    cin>>data;
    Listnode<int> *head=NULL,*tail=NULL;
    while(data!=-1){
    Listnode<int> *newnode=new Listnode<int>(data);
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

void print(Listnode<int> *head){
    Listnode<int> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Listnode<int> *head1=takeinput();
    Listnode<int> *head2=takeinput();
    Listnode<int> *head=unionof2LL(head1,head2);
    print(head);
    return 0;
}  
