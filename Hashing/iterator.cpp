#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    unordered_map<string,int> umap;
    umap["abc"]=1;
    umap["abc1"]=2;
    umap["abc2"]=3;
    umap["abc3"]=4;
    umap["abc4"]=5;
    umap["abc5"]=6;

    unordered_map<string,int> ::iterator it=umap.begin();
    while(it!=umap.end()){
        cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
        it++;
    }

    //find
    unordered_map<string,int>::iterator it2=umap.find("abc");
    umap.erase(it2);

    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int>::iterator it1=v.begin();
    while(it1!=v.end()){
        cout<<*it1<<endl;
        it1++;
    }
} 
