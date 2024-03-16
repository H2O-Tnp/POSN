#include <bits/stdc++.h>
using namespace std;

class Graph{
    int ver;
    list<int> *adj;
    bool *visited;

    bool recurisCyclic(int v,bool visited[],int parent){
        visited[v] = true;
        list<int> adjlist = adj[v];
        // cout<<v<<' ';
        list<int>::iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            if(!visited[*it]){
                if(recurisCyclic(*it,visited,v)){
                    return true;
                }
            }
            else if(*it != parent){
                return true;
            }
        }
        return false;
    }
public:
    Graph(int V){
        ver = V;
        adj = new list<int>[ver];
    }
    void addEdge(int src, int des){
        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    
    bool isCyclic(){
        visited = new bool[ver];
        fill(visited,visited+ver,false);

        for(int u=0;u<ver;u++){
            if(!visited[u]){
                if(recurisCyclic(u,visited,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int v,e;
    cin>>v>>e;

    Graph G1(v);
    while(--e){
        int src,des;
        cin>>src>>des;
        G1.addEdge(src,des);
    }
    if(G1.isCyclic()) cout<<"Y";
    else cout<<"N";
    // G1.addEdge(2,3);    
}