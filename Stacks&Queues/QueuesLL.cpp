/*
You need to implement a Queue class using linked list.
All the required data members should be private.
Implement the following public functions :
1. Constructor -
Initialises the data members.
2. enqueue :
This function should take one argument of type T and has return type void. This function should insert an element in the queue. Time complexity should be O(1).
3. dequeue :
This function takes no input arguments and has return type T. This should removes the first element which is entered and return that element as an answer. Time complexity should be O(1).
4. front :
This function takes no input arguments and has return type T. This should return the first element which is entered and return that element as an answer. Time complexity should be O(1).
5. size :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
6. isEmpty :
Checks if the queue is empty or not. Return true or false.
*/

#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        next=NULL;
    }
};
template<typename T>
class Queue{
    public:
    node<T> *head;
    node<T> *tail;
    int size;
    public:
    Queue(){
        size=0;
        head=new node<T>(0);
        tail=head;
    }
    void enqueue(T ele){
        if(size==0){
            head->data=ele;
            tail->data=ele;
            size++;
        }
        else{
            node<T> *newnode=new node<T>(ele);
            tail->next=newnode;
            tail=newnode;
            size++;
        }
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size==0;
    }
    T front(){
        if(size==0)
            return 0;
        return head->data;
    }
    T dequeue(){
        if(size==0)
            return 0;
        T temp=head->data;
        node<T> *tnode=head->next;
        head->next=NULL;
        head=tnode;
        size--;
        return temp;
    }

};

int main(){
    Queue<int> q;
    int choice=0;
    cout<<"Queue"<<endl;
    while(choice!=-1){
        cout<<"1.Enqueue\n2.Dequeue\n3.Front\n4.size\n5.Empty"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                int ele;
                cout<<"enter element:";
                cin>>ele;
                q.enqueue(ele);
            }
            break;
            case 2:{
                int ans=q.dequeue();
                if(ans!=0)
                    cout<<ans<<endl;
                else
                    cout<<"-1"<<endl;}
            break;
            case 3:{int ans=q.front();
                if(ans!=0)
                    cout<<ans<<endl;
                else
                    cout<<"-1"<<endl;}
            break;
            case 4:cout<<q.getsize()<<endl;
            break;
            case 5:{
                if(q.isempty())
                    cout<<"True"<<endl;
                else
                    cout<<"False"<<endl;
            }break;
            }
        }
}
