/*
A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.
For example, the following tree is nice,
                           n
                         /   \
                        l     n
                             / \
                            n   l
                           / \
                          l   l
and the following tree is not,
                          n
                         / \
                       n     n
                      /
                     l
The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.
Given the pre-order traversal of a nice binary tree as a string, you are required to find the depth of the tree.
Output one line for each test case, containing a single integer, the depth of tree.
Sample Input 1:
                nlnll
Sample Output 1:
                2
Sample Input 2:
                nll
Sample Output 2:
                1
*/
#include<iostream>
#include<string.h>
using namespace std;

int depth(char s[]){
    if(s[0]=='l')
        return 1;
    int dep=0;
    if(s[1]=='n' && s[2]=='n')
        dep=1+max(depth(s+1),depth(s+2));
    else if(s[1]=='n')
        dep=1+depth(s+1);
    else if(s[2]=='n')
        dep=1+depth(s+2);
    else
        dep=depth(s+1);
    return dep;
}
int main(){
    char *s=new char[1000];
    cin>>s;
    cout<<depth(s);
}
