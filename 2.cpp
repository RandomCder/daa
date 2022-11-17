#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int u,int v,int wt)
    {
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};
int main()
{
    int n,m;
    cout<<"Enter number of vertices "<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>m;
    int u,v,wt;
    vector<node> edges;
    cout<<"Enter source,vertex,weight"<<endl;
    cout<<"u v wt"<<endl;
    for(int i=0;i<m;i++)
    {
     cin>>u>>v>>wt;
     edges.push_back(node(u,v,wt));
    }
    int src;
    cout<<"Enter source "<<endl;
    cin>>src;
    int inf=10000;
    vector<int> dist(n,inf);
    dist[src]=0;

    for(int i=0;i<n-1;i++)
    {
        for(auto it:edges)
        {
            if(dist[it.u]+it.wt<dist[it.v])
            {
                dist[it.v]=dist[it.u]+it.wt;
            }
        }
    }

int f=0;
for(auto it:edges)
{
    if(dist[it.u]+it.wt<dist[it.v])
    {
        cout<<"Negative weight cycle forms"<<endl;
        f=1;
        break;
    }
}
if(!f)
{
    for(int i=1;i<=n;i++)
    {
        cout<<"Vertexc "<<i<<"  Distance from source"<< src <<"  "<<dist[i]<<endl;
    }
}
return 0;

}
