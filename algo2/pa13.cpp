/*************************************************************************
	> File Name: pa13.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Thu 10 Jul 2014 10:45:45 AM CST
 ************************************************************************/
#include <cstdio>
#include <iostream>
using namespace std;

int weight[501][501];
bool vis[501];
int dist[501];// dist[i] record the distance from visited vertices group as a whole vertex to the vertex i which is in unvisited group.

int prim(int n)
{
    int i,j,pos,min;

    int sum=0;

    for(int i=1; i<=n; i++)
    {
        dist[i]=weight[1][i];
    }

    vis[1]=1;

    dist[1]=0;

    for(i=1; i<n; i++){
        min=0x7fffffff;

        pos =-1;

        for(j=1;j<=n; j++){
            if(!vis[j] && dist[j] <min){
                min=dist[j];
                pos=j;
            }
        }

        sum+=min;
        vis[pos] = 1;

        for(j=1;j<=n;j++){
            if(!vis[j] && dist[j] > weight[pos][j]){
                dist[j]=weight[pos][j];
            }
        }
    }

    return sum;
}
int main()
{
    freopen("edges.txt","r",stdin);
    int n,m;
    cin>>n>>m;

    for(int i=1; i<501 ;i++){
        for(int j=1; j<501; j++){
            if(i!=j){
                weight[i][j]=0x7fffffff;
            }
        }
    }

    while(m--){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        weight[n1][n2]=w;
        weight[n2][n1]=w;
    }

    
    cout<<prim(n)<<endl;    
}
