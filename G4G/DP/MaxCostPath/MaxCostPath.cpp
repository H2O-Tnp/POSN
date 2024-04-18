//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int max(int x,int y,int z){
    if(x>y){
        if(x>z){
            return x;
        } else {
            return z;
        }
    } else {
        if(y>z){
            return y;
        } else {
            return z;
        }
    }
}

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                if(j==0){
                    Matrix[i][j]+=max(Matrix[i-1][j],
                                      Matrix[i-1][j+1]);
                }
                else if(j==N-1){
                    Matrix[i][j]+=max(Matrix[i-1][j],
                                      Matrix[i-1][j-1]);
                }
                else {
                    Matrix[i][j]+=max(Matrix[i-1][j],
                                      Matrix[i-1][j+1],
                                      Matrix[i-1][j-1]);
                }
            }
        }
        int max_sum = 0;
        for(auto i:Matrix[N-1]){
            max_sum = max(max_sum,i);
        }
        return max_sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends