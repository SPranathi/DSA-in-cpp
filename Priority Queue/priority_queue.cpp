#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
    vector<int> pq;

    public:
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }
    //Return the size of priorityQueue-no of elements present
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return 0; //Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;

            if(pq[childIndex]<pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty()){
            return 0; //Priority Queue is empty
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        //down-heapify
        int parentIndex=0;
        int leftchildIndex=2*parentIndex+1;
        int rightchildIndex=2*parentIndex+2;

        while(leftchildIndex<pq.size()){
            int minIndex=parentIndex;
            if(pq[minIndex]>pq[leftchildIndex]){
                minIndex=leftchildIndex;
            }
            if(rightchildIndex<pq.size() && pq[rightchildIndex]<pq[minIndex]){
                minIndex=rightchildIndex;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp=pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex=minIndex;
            leftchildIndex=2*parentIndex+1;
            rightchildIndex=2*parentIndex+2;

        }
        return ans;
    }
};


//Driver cod eto test PriorotyQueue class
int main(){
    PriorityQueue pq;
    int choice;
    cin>>choice;
    while(choice!=-1){
        switch(choice){
            case 1://insert
                int ele;
                cin>>ele;
                pq.insert(ele);
                break;
            case 2://getMin
                cout<<pq.getMin()<<endl;
                break;
            case 3://removeMax
                cout<<pq.removeMin()<<endl;
                break;
            case 4://size
                cout<<pq.getSize()<<endl;
                break;
            case 5://isEmpty
                if(pq.isEmpty()){
                    cout<<"true"<<endl;
                }
                else{
                    cout<<"false"<<endl;
                }
            default:
                return 0;
        }
        cin>>choice;
    }
}
