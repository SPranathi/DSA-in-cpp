/*
You need to implement a Stack class using two queues as its data members.
Only 2 data members should be there inside the class - two queues, which should be created dynamically and both should be public. Use the inbuilt queue.
Implement the following public functions :
1. Constructor -
Initialises both the data members.
2. push :
This function should take one argument of type T and has return type void. This function should insert an element in the stack. Time complexity should be O(1).
3. pop :
This function takes no input arguments and has return type T. This should removes the last element which is entered and return that element as an answer.
4. top :
This function takes no input arguments and has return type T. This should return the last element which is entered and return that element as an answer.
5. getSize :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
 */
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class Stack{
    public:
    queue<T> *q1;
    queue<T> *q2;
    Stack(){
        q1=new queue<T>();
        q2=new queue<T>();
    }
    void push(T ele){
        q1->push(ele);
    }
    T pop(){
        if(q1->size()==0)
            return 0;
        T ans;
        if(q1->size()>1){
            q2->push(q1->front());
            q1->pop();
        }
        ans=q1->front();
        q1->pop();
        while(!q2->empty()){
            q1->push(q2->front());
            q2->pop();
        }
        return ans;
    }
    T top(){
        if(q1->size()>1){
            q2->push(q1->front());
            q1->pop();
        }
        T ans;
        ans=q1->front();
        q2->push(q1->front());
        q1->pop();
        while(!q2->empty()){
            q1->push(q2->front());
            q2->pop();
        }
        return ans;
    }
    int getsize(){
        return q1->size()+q2->size();
    }

};
int main(){
    Stack<int> s;
    int choice,input;
    while(1){
        cout<<"Enter the choice:\n1.Push\n2.Pop\n3.Top\n4.Getsize\n";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>input;
                s.push(input);
                break;
            case 2:
                cout<<s.pop()<<endl;
                break;
            case 3:
                cout<<s.top()<<endl;
                break;
            case 4:
                cout<<s.getsize()<<endl;
                break;
            default :
                return 0;
        }
    }
}
