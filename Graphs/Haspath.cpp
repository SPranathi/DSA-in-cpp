/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
 */
#include<iostream>
using namespace std;

void haspath(int **edges,int V,int v1,int v2,bool *visited){
    visited[v1]=true;
    if(v1==v2)
        return;
    for(int i=0;i<V;i++){
        if(i==v1)
            continue;
        if(edges[v1][i] && !visited[i])
            haspath(edges,V,i,v2,visited);
    }
    
}

int main(){
    int V,E;
    cin>>V>>E;
    int **edges=new int*[V];
    //intialization
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }

    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }

    int v1,v2;
    cin>>v1>>v2;

    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

    haspath(edges,V,v1,v2,visited);

    if(visited[v2])
        cout<<"true";
    else
        cout<<"false";
} 
