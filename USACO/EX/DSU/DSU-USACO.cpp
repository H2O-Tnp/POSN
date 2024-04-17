#include <bits/stdc++.h>
using namespace std;

class DisjointSets
{
private:
    vector<int> parents;
    vector<int> sizes;

public:
    DisjointSets(int size) : parents(size), sizes(size, 1){
        // init parent
        for (int i = 0; i < size; i++){
            parents[i] = i;
        }
    }

    /** @return the "representative" node in x's component */
    int find(int x){
        if(parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }

    /** @return whether the merge changed connectivity */
    bool unite(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root){
            return false;
        }
        
        if (sizes[x_root] < sizes[y_root]){
            swap(x_root, y_root);
        }

        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y) { return find(x) == find(y); }

    /** @return sizes vector */
    void printSizes(){
        for(auto i:sizes){
            cout<<i<<' ';
        }
        cout<<"\n";
    }
};

int main(){
    DisjointSets DS(5);
    DS.printSizes();
}