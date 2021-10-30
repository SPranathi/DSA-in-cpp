#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *arr,int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]]=true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> output=removeDuplicates(arr,n);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
}