/*
Given a Linked list, swap every pair of nodes to form a new linked list. That is, swap first two nodes, then 2nd two nodes and so on. If the size of linked list is odd, then leave the last node as it is.
You should not create new memory, instead change the references of already created nodes. And swap the entire node, not just their data.
Return the head of updated linked list.
-1 is the terminating number. That is, it just defines that your linked list has no more elements and it is not the part of LL.
Input format :
Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :
1 2 3 4 5 6 -1
Sample Output 1 :
2 1 4 3 6 5
Sample Input 2 :
1 2 3 -1
Sample Output 2 :
2 1 3
*/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node * next;
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~node() {
    	if(next) 
	    delete next;
    }
};

node *swapEveryPair(node *head){
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    node *temp=head->next;
    head->next=temp->next;
    temp->next=head;
    node *ans=swapEveryPair(head->next);
    head->next=ans;
    return temp;
}

node* takeinput() {
    int data;
    cin >> data;
    node* head = NULL, *tail = NULL;
    while(data != -1){
        node *newNode = new node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head) {
    node*temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    node* head = takeinput();
    head = swapEveryPair(head);
    print(head);
    delete head;
    return 0;
} 
