/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,pair<int,int> > pi;
vector<int> mergeArrays(vector<vector<int>*> v){
    
    vector<int> ans;

    priority_queue<pi,vector<pi>,greater<pi>> pq;

    int maxsize=0;
    for(int i=0;i<v.size();i++){
        int x=v[i]->size();
        maxsize=max(maxsize,x);
    }

    for(int i=0;i<v.size();i++){
        vector<int> *vec=v[i];
        pq.push(make_pair(vec->at(0),make_pair(i,0)));
    }
    while(!pq.empty()){
        pair<int,pair<int,int>> p=pq.top();
        pq.pop();
        ans.push_back(p.first);

        int minIndexrow=p.second.first;
        int eleIndex=p.second.second;

        eleIndex++;
        vector<int> *vec=v[minIndexrow];

        if(eleIndex<vec->size())
            pq.push(make_pair(vec->at(eleIndex),make_pair(minIndexrow,eleIndex)));
    }
    return ans;
}
int main(){
    int k;
    cin>>k;
    vector<vector<int>*> arr;
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        vector<int> *input=new vector<int>;
        for(int j=0;j<size;j++){
            int s;
            cin>>s;
            input->push_back(s);
        }
        arr.push_back(input);
    }
    vector<int> output=mergeArrays(arr);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}  

 
