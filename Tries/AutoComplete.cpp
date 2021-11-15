/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Line 3 : Word w
Output Format :
All possible words (in different lines)
Note : Order of words doesn't matter.
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
    }
};

class Trie{
    TrieNode *root;
    public:
    int count;

    Trie(){
        this->count=0;
        root=new TrieNode('\0');
    }

    bool insertword(TrieNode *root,string word){
        //Base case
        if(word.size()==0){
            if(!root->isTerminal){
                root->isTerminal=true;
                return true;
            }
            else{
                return false;
            }
        }
        //Small Calculation
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
        return insertword(child,word.substr(1));
    }

    //For User
    void insertword(string word){
        if(insertword(root,word)){
            this->count++;
        }
    }

    void printwords(TrieNode *root,string word1){
        if(root->isTerminal)
            cout<<word1<<endl;
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL)
                printwords(root->children[i],word1+root->children[i]->data);
        }
    }
    bool search(TrieNode *root,string word,string word1){
        if(word.size()==0){
            printwords(root,word1);
            return root->isTerminal;
        }
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
            return search(root->children[index],word.substr(1),word1);
        else
        {
            return false;
        }
        
    }
    void autocomplete(vector<string> input,string p){
        for(int i=0;i<input.size();i++)
            insertword(input[i]);
        search(root,p,p);
    }

};
int main(){
    Trie t;
    int n;
    cin>>n;
    vector<string> arr;
    string w;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        arr.push_back(word);
    }
    cin>>w;
    t.autocomplete(arr,w);
}
