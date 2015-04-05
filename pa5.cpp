/*************************************************************************
	> File Name: pa5.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Sun 15 Jun 2014 09:30:37 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#define NUM 200
int w[NUM+1][NUM+1];
int dist[NUM+1];
int pre[NUM+1];
int vis[NUM+1];

void dijk(int n,int src){
      for(int i=0; i<n; i++){
          dist[i]=w[src][i];
          pre[i]=-1;
      }
      
    dist[src]=0;
    vis[src]=1;

    for(int j=0; j<n; j++){

        int minDst=0x7fffffff;
        int minIdx=-1;
        
        for(int i=0; i<n; i++){
            if(!vis[i] && dist[i] < minDst){
                minDst=dist[i];
                minIdx= i;
            }
        }


        vis[minIdx]=1;

        //relaxation
        for(int i=0; i<n; i++){
           if(!vis[i] && w[minIdx][i]<0x7fffffff && dist[i] >=(dist[minIdx]+w[minIdx][i])){
                dist[i]=dist[minIdx]+w[minIdx][i];
                if (dist[i] < 0){
                    cout<<"wminIdx "<<w[minIdx][i]<<" "<<dist[minIdx]<<" "<<minIdx;
                }
                pre[i]=minIdx;
            }
        }
        //for(int i=0; i< NUM; i++)
        //{
        //    cout<<i+1<<": "<<dist[i]<<" ";
        //}
        //cout<<"haha"<<endl<<endl;
    }   
}

int main()
{
    freopen("dijkstraData.txt","r",stdin);

    for(int i=0; i<NUM; i++)
    {
        for(int j=0;j<NUM;j++)
        {
            if(i!=j)
               w[i][j]=0x7fffffff;
        }
    }

    
    for(int i=0; i< NUM; i++)
    {
        string str;
        getline(cin,str);
        const char *split = " ,\t";
        char *p;
        p=strtok((char*)str.c_str(),split);
        int vertex = atoi(p);
        while(p){
            p = strtok(NULL,split);
            if(p==NULL || *p == '\r')
               break;
            int v2 = atoi(p);
            
            p= strtok(NULL,split);
            int weight = atoi(p);
            w[vertex-1][v2-1]=weight;
        }
    
    }

    dijk(NUM,0);

    for(int i=0; i< NUM; i++)
    {
       cout<<i+1<<": "<<dist[i]<<" ";
    }


}

