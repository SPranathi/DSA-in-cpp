/*
You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -
1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.
 */ 
#include<iostream>
using namespace std;
class Deque{
    int *deq;
    int front;
    int rear;
    int n;

    public:

    Deque(int size){
        deq=new int[size];
        front=-1;
        rear=-1;
        n=size;
    }

    void insertfront(int ele){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
            deq[front]=ele;
            return;
        }
        if((front+1)%n==rear){
            cout<<(-1)<<endl;
            return ;
        }
        front=(front+1)%n;
        deq[front]=ele;
    }

    void insertrear(int ele){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
            deq[rear]=ele;
            return;
        }
        if(front==rear-1 || rear==0 && front==n-1){
            cout<<(1)<<endl;
            return;
        }
        if(rear==0)
            rear=n-1;
        else
            rear--;
        deq[rear]=ele;
    }

    void deletefront(){
        if(front==-1 && rear==-1){
            cout<<(-1)<<endl;
            return;
        }
        if(rear==front){
            rear=-1;
            front=-1;
            return;
        }
        if(front==0)
            front=n-1;
        else
            front--;
    }

    void deleterear(){
        if(front==-1 && rear==-1){
            cout<<(-1)<<endl;
            return;
        }
        if(rear==front){
            rear=-1;
            front=-1;
            return;
        }
        rear=(rear+1)%n;
    }

    int getfront(){
        if(front==-1 && rear==-1)
            return -1;
        return deq[front];
    }

    int getrear(){
        if(front==-1 && rear==-1)
            return -1;
        return deq[rear];
    }
};

int main(){
    Deque dq(10);
    int choice,element;
    while(true){
        cout<<"Enter your choice:"<<endl;
        cout<<"1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.Getfront\n6.Getrear"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cin>>element;
                dq.insertfront(element);
                break;
            case 2:
                cin>>element;
                dq.insertrear(element);
                break;
            case 3:
                dq.deletefront();
                break;
            case 4:
                dq.deleterear();
                break;
            case 5:
                cout<<dq.getfront()<<endl;
                break;
            case 6:
                cout<<dq.getrear()<<endl;
                break;
            default:
                return 0;
        }
    }
}
