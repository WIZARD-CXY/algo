#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct node
{
       int n1,n2,cost;
       node *left;
       node *right;
};

void getInt(char *a, int n, int *val1, int *val2, int *val3)
{
     int i,j;
     char ab[10];
     for(i=0; a[i]!=' '; i++) ab[i]=a[i];
     ab[i]='\0';
     *val1=atoi(ab);
     for(j=0, i++; a[i]!=' '; i++,j++) ab[j]=a[i];
     ab[j]='\0';
     *val2=atoi(ab);
     for(j=0, i++; a[i]!='\n'; i++,j++) ab[j]=a[i];
     ab[j]='\0';
     *val3=atoi(ab);
}

int no_nodes, maxSpace;

void createCluster(node *root, int *node_clus)
{
     static int k=4;
     static int no_clus=no_nodes;
     static bool flag=false;
     if(root==NULL) return;
     createCluster(root->left, node_clus);
     int n1=root->n1, n2=root->n2, cost=root->cost;
     if(flag)
     {
             if(node_clus[n1] != node_clus[n2])
             {
              maxSpace=cost;
              flag=false;
             }
     }
     if(no_clus>k)
     if(node_clus[n1] != node_clus[n2])
     {
         int node_clus_n2=node_clus[n2];
         for(int i=1; i<=no_nodes; i++) if(node_clus[i]==node_clus_n2) node_clus[i]=node_clus[n1];
         no_clus--;
         if(no_clus==k) flag=true;
     }
     createCluster(root->right, node_clus);
}

int main(int argc, char *argv[])
{
    char a[15];
    FILE *f=fopen("clustering1.txt","r");
    fgets(a,15,f);
    no_nodes=atoi(a);
    int *node_clus=new int[no_nodes+1];
    for(int i=0; i<=no_nodes; i++) node_clus[i]=i;
    int n1,n2,cost;
    node *root=new node;
    fgets(a,50,f);
    getInt(a,strlen(a),&n1,&n2,&cost);
    root->n1=n1; root->n2=n2; root->cost=cost; root->left=NULL; root->right=NULL;
    while(fgets(a,50,f)!=NULL)
    {
            getInt(a,strlen(a),&n1,&n2,&cost);
            node *nn=new node;
            nn->n1=n1; nn->n2=n2; nn->cost=cost; nn->left=NULL; nn->right=NULL;
            node *temp=root,*t2;
            while(temp!=NULL)
            {
                   t2=temp;
                   if(nn->cost>temp->cost) temp=temp->right;
                   else temp=temp->left;
            }
            if(nn->cost>t2->cost) t2->right=nn;
            else t2->left=nn;
    }
    createCluster(root, node_clus);
    delete root;
    cout<<"Maximum Spacing of a 4-clustering: "<<maxSpace<<endl;
    fclose(f);
    return EXIT_SUCCESS;
}