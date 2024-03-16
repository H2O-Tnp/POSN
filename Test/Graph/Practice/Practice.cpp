#include <bits/stdc++.h>
using namespace std;

class Graph{
    int vertice;
    list<int> *adj;
    bool *visit;
    bool isCyclicUtil(int v, bool visit[], int par){
        list<int> adjlist = adj[v];
        list<int>::iterator it;
        visit[v] = true;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            if(!visit[*it]){
                if(isCyclicUtil(*it,visit,v)){
                    return true;
                }
            }
            else if(*it!=par){
                return true;
            }
        }
        return false;
    }
    public:
        Graph(int v){
            vertice = v;
            adj = new list<int>[v];
            visit = new bool[v];
            fill(visit,visit+v,false);
        }
        void addEdge(int src, int des){
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        bool isCyclic(){
            for(int u=0;u<vertice;u++){
                if(!visit[u])
                    if(isCyclicUtil(u,visit,-1)) return true;
            }
            return false;
        }
};

int main(){
    // Graph g1(5);
	// g1.addEdge(1, 0);
	// g1.addEdge(0, 2);
	// g1.addEdge(2, 1);
	// g1.addEdge(0, 3);
	// g1.addEdge(3, 4);
	// g1.isCyclic() ? cout << "Graph contains cycle\n"
	// 			: cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 0);

	g2.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";
	// cout<<loop<<endl;
	return 0;
}