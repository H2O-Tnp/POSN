#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int, list<int>> vertices;

    void addEdge(int parent, int child){
        vertices[parent].push_back(child);
        vertices[child].push_back(parent);
    }
    
    void DFS(){

    }
};

int main(){

}