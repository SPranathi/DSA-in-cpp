/*
Givan n number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word itself is a palindrome.
Return true or false.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Output Format :
true or false
Sample Input 1 :
4
abc def ghi cba
Sample Output 2 :
true
Sample Output 1 Expalanation :
"abc" and "cba" forms a palindrome
Sample Input 2 :
4
abc def ghi hg
Sample Output 2 :
true
Sample Output 2 Expalanation :
"ghi" and "hg" forms a palindrome
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
    int childCount;

    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
        childCount=0;
    }
};

class Trie{
    TrieNode *root;
    int count;
    public:
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
        //Small Claculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
            root->childCount++;
        }
        //Recursive call
        return insertword(child,word.substr(1));
    }

    //For user
    void insertword(string word){
        if(insertword(root,word)){
            this->count++;
        }
    }

    string reverse(string in){
        string out="";
        for(int i=in.size()-1;i>=0;i--)
            out+=in[i];
        return out;
    }

    bool search(TrieNode *root,string word){
        if(word.size()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        bool ans;
        if(root->children[index]!=NULL)
            ans=search(root->children[index],word.substr(1));
        else
        {
            ans=false;
        }
        return ans;
    }

    bool PalindromePair(vector<string> arr){
        for(int i=0;i<arr.size();i++){
            this->insertword(arr[i]);
        }
        bool ans;
        for(int i=0;i<arr.size();i++){
            string out=reverse(arr[i]);

            ans=search(root,out) || search(root,out.substr(1));
            if(ans)
                break;
        }
        return ans;
    }
};
int main(){
    Trie t;
    int n;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        arr.push_back(word);
    }
    bool ans=t.PalindromePair(arr);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
}

