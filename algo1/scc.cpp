/*************************************************************************
	> File Name: scc.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: 2014年06月07日 星期六 17时13分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<list>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int sum;
vector<int> rec;

class Graph
{
    int n;
    list<int> *adj;

    void fillOrder(int v, int vis[],stack<int> &Stack);

    void DFS(int v, int vis[]);
public:
    Graph(int v);
    void addEdge(int v,int u);

    void printSCCs();
    Graph getTranspose();
};

Graph::Graph(int v)
{
    n=v;
    adj= new list<int>[n];
}

void Graph::DFS(int v,int vis[])
{
    vis[v]=true;
    sum++;
    cout<<v<<" ";

    list<int>::iterator i;
    for(i=adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!vis[*i])
        {
            DFS(*i,vis);
        }
    }
}

Graph Graph::getTranspose()
{
    Graph g(n);

    for(int v=1; v<n; v++)
    {
        list<int>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); i++)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::fillOrder(int v,int vis[], stack<int> &Stack)
{
    vis[v]=1;

    list<int>::iterator i;

    for(i=adj[v].begin(); i!=adj[v].end(); i++)
    {
        if(!vis[*i]){
            fillOrder(*i,vis,Stack);
        }

    }
    Stack.push(v);
}

void Graph::printSCCs()
{
    stack<int> Stack;

    int *vis = new int[n];

    memset(vis,0,sizeof(int)*n);
    
    for(int i=1; i<n; i++)
    {
        if(!vis[i]){
            fillOrder(i,vis,Stack);
        }
    }

    Graph gr = getTranspose();

    memset(vis,0,sizeof(int)*n);

    while(!Stack.empty()){
        int v = Stack.top();
        Stack.pop();
        
        if(!vis[v]){
            gr.DFS(v,vis);
            cout<<"sum is "<<sum<<" ";
            rec.push_back(sum);
            cout<<endl;
            sum=0;
        }
    }
}

int main()
{
    // Create a graph given in the above diagram

    Graph g(875715);

    freopen("SCC.txt","r",stdin);

    int v,w;
    while(cin>>v>>w){
        g.addEdge(v,w);
    }

    cout << "Following are strongly connected components in given graph \n";
    g.printSCCs();
    
    sort(rec.begin(),rec.end());
    for(int i=0; i!=rec.size(); ++i)
    {
        cout<<rec[i]<<endl;
    }
    return 0;
    
}
