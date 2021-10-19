#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class MapNode{
    public:
        string key;
        T value;
        MapNode* next;

        MapNode(string key,T value){
            this->key=key;
            this->value=value;
            next=NULL;
        }
        ~MapNode(){
            delete next;
        }
};

template<typename T>
class ourmap{
    int count;
    int numBuckets;
    MapNode<T>** buckets;
    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets=new MapNode<T>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }

    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete []buckets;
    }

    int size(){
        return count;
    }

    T getValue(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<T> *head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }

    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int currentCoeff=1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*currentCoeff;
            hashCode=hashCode%numBuckets;
            currentCoeff*=37;
            currentCoeff=currentCoeff%numBuckets;
        }
        return hashCode%numBuckets;
    }

    void rehash(){
        MapNode<T> **temp=buckets;
        buckets=new MapNode<T>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=NULL;
        }
        int oldBucketcount=numBuckets;
        numBuckets*=2;
        count=0;

        for(int i=0;i<oldBucketcount;i++){
            MapNode<T> *head=temp[i];
            while(head){
                string key=head->key;
                T value=head->value;
                insert(key,value);
                head=head->next;
            }
        }

        for(int i=0;i<oldBucketcount;i++){
            MapNode<T> *head=temp[i];
            delete head;
        }
        delete []temp;
    }

    public:
    double Loadfactor(){
        return (1.0*count)/numBuckets;
    }
    void insert(string key,T value){
        int BucketIndex=getBucketIndex(key);
        MapNode<T> *head=buckets[BucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=buckets[BucketIndex];
        MapNode<T>* node=new MapNode<T>(key,value);
        node->next=head;
        buckets[BucketIndex]=node;
        count++;
        double Loadfactor=(1.0*count)/numBuckets;
        if(Loadfactor>0.7){
            rehash();
        }
    }

    T remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<T>* head=buckets[bucketIndex];
        MapNode<T> *prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;
                }
                else{
                    prev->next=head->next;
                }
                T value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }
};


int main(){
    ourmap<int> map;
    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.Loadfactor()<<endl;
    }
    cout<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc7");
    cout<<map.size()<<endl;

    for(int i=0;i<10;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":"<<map.getValue(key)<<endl;
    }
    cout<<map.size()<<endl;
}
