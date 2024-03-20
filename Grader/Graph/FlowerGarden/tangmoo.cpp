#include<bits/stdc++.h>
using namespace std;
vector<int> x[1000007],y[1000007];
map<pair<int,int>,bool> vis;
pair<int,int> arr[100007];
double group=0;

void dfs(int u,int v)
{
    vis[make_pair(u,v)]=true;
    for(int w:x[u])
    {
        if(!vis[make_pair(u,w)])
            dfs(u,w);
    }
    for(int w:y[v])
    {
        if(!vis[make_pair(w,v)])
            dfs(w,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[i]={u,v};
        x[u].push_back(v);
        y[v].push_back(u);
    }

    for(int i=0;i<n;i++)
    {
        int u,v;
        tie(u,v)=arr[i];
        if(!vis[make_pair(u,v)])
        {
            group++;
            dfs(u,v);
        }
    }

    cout<<ceil(group/2);
    return 0;
}

/*
324 545
320 563
*/