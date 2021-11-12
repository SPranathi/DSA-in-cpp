#include<iostream>
#include<string>
#include"TrieNode.h"
using namespace std;
class Trie{
    TrieNode *root;
    public:

    Trie(){
        root=new TrieNode('\0');
    }

    void insertword(TrieNode *root,string word){
        //Base case
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        //small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursive call
        insertword(child,word.substr(1));
    }

    //For user
    void insertword(string word){
        insertword(root,word);
    }

    bool search(TrieNode *root,string word){
        //Base case
        if(word.size()==0){
            return root->isTerminal;
        }
        //small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        //recursion
        return search(child,word.substr(1));
    }

    //For User
    bool search(string word){
        return search(root,word);
    }

    void removeword(TrieNode *root,string word){
        //base case
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        //small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //word not found
            return ;
        }
        //recursion
        removeword(child,word.substr(1));

        //Remove child node if it is useless
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }

    //For User
    void removeword(string word){
        removeword(root,word);
    }

};


int main(){
    int choice;
    cin>>choice;
    Trie t;

    while(choice!=-1){
        string word;
        bool ans;
        switch (choice){
        case 1://insert
            cin>>word;
            t.insertword(word);
            break;
        case 2://search
            cin>>word;
            ans=t.search(word);
            if(ans)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
            break;
        case 3://remove
            cin>>word;
            t.removeword(word);
            break;
        default:
            return 0;
        }
        cin>>choice;
    }
    
}
