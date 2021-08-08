/*
You need to implement a Stack class using linked list.
The data members should be private.
Implement the following public functions :
1. Constructor -
Initialises the data member (i.e. head to null).
2. push :
This function should take one argument of type T and has return type void. This function should insert an element in the stack. Time complexity should be O(1).
3. pop :
This function takes no input arguments and has return type T. This should removes the last element which is entered and return that element as an answer. Time complexity should be O(1).
4. top :
This function takes no input arguments and has return type T. This should return the last element which is entered and return that element as an answer. Time complexity should be O(1).
5. size :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
6. isEmpty :
Checks if the stack is empty or not. Return true or false
*/

#include<iostream>
using namespace std;
template <typename T>

class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        next=NULL;
    }
};
template <typename T>
class Stack{
    node<T> *head;
    int size;//to keep track of the length of the linked list
    public:
    Stack(){
        size=0;
        head=new node<T>(0);
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size==0;
    }
    void push(T ele){
        node<T> *newnode=new node<T>(ele);
        newnode->next=head;
        head=newnode;
        size++;
    }
    T pop(){
        if(size==0)
            return 0;
        else{
            T ans=head->data;
            node<T> *temp=head->next;
            head->next=NULL;
            head=temp;
            size--;
            return ans;
        }
    }
    T top(){
        if(size==0)
            return 0;
        else{
            return head->data;
        }
    }
};

int main(){
    Stack<int> st;
    int choice=0;
    cout<<"Stack"<<endl;
    int ele;
    while(choice!=-1){
        cout<<"1.Push\n2.Pop\n3.Top\n4.Size\n5.IsEmpty"<<endl;
        cin>>choice;
        switch(choice){
            case 1:cout<<"Enter element to push into stack:";
            cin>>ele;
            st.push(ele);
            break;
            case 2:{int t=st.pop();
            if(t!=0)
                cout<<t<<endl;
            else
                cout<<"-1"<<endl;}
            break;
            case 3:{int t=st.top();
            if(t!=0)
                cout<<t<<endl;
            else
                cout<<"-1"<<endl;}
            break;
            case 4:{cout<<st.getsize()<<endl;}
            break;
            case 5:{if(st.isempty())
                    cout<<"True"<<endl;
                    else 
                        cout<<"False"<<endl;
                    }
            break;
            default:
            break;
        }
    }
}