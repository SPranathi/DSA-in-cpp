/*
Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
Anagram of a string is a string which is its permutation.
For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
Input Format :
Line 1 : String1
Line 2 : String2
Output Format :
Number of deletions required
Contraints :
1<= Length of string <=10^4
Sample Input 1 :
cde 
abc
Sample Output 1 :
4
Sample Input 2 :
aab
aba
Sample Output 2 :
0
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int anagram(char str1[],char str2[]){
    unordered_map<char,int> m;
    for(int i=0;str1[i]!='\0';i++){
        if(!m.count(str1[i]))
            m[str1[i]]=1;
        else
            m[str1[i]]+=1;
    }
    int delc=0;
    
    for(int i=0;str2[i]!='\0';i++){
        if(m.count(str2[i])){
            if(m[str2[i]]==0){
                //extra same char in str2
                delc+=1;
                continue;
            }
            m[str2[i]]-=1;
        }
        else{
            delc+=1;
        }
    }
    unordered_map<char,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        delc+=it->second;
    }
    return delc;
}
int main(){
    char str1[1000],str2[1000];
    cin>>str1;
    cin>>str2;
    cout<<anagram(str1,str2)<<endl;
}
