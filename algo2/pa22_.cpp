#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

void getInt(char *a, int n, int *val1, int *val2)
{
     int i,j;
     char ab[10];
     for(i=0; a[i]!=' '; i++) ab[i]=a[i];
     ab[i]='\0';
     *val1=atoi(ab);
     for(j=0, i++; a[i]!='\n'; i++,j++) ab[j]=a[i];
     ab[j]='\0';
     *val2=atoi(ab);
}

int main(int argc, char *argv[])
{
    int no_nodes,bits;
    char a[15];
    FILE *f=fopen("clustering_big.txt","r");
    fgets(a,15,f);
    getInt(a,strlen(a),&no_nodes,&bits);
    char** nodes=new char*[no_nodes];
    int *node_clus=new int[no_nodes];
    int *node_ones=new int[no_nodes];
    for(int i=0; i<no_nodes; i++)
    {
            node_clus[i]=i;
            node_ones[i]=0;
            nodes[i]=new char[55];
            fgets(nodes[i],55,f);
            for(int j=0; j<strlen(nodes[i]); j+=2) if(nodes[i][j]=='1') node_ones[i]++;
    }
    fclose(f);
    int no_of_clus=no_nodes;
    for(int i=0; i<no_nodes; i++)
    {
            int curr_clus=node_clus[i], ones=node_ones[i];
            for(int j=0; j<no_nodes; j++)
            if(node_clus[j]!=curr_clus && ( ( (ones-node_ones[j]>=0) && (ones-node_ones[j]<3) ) || ( (node_ones[j]-ones>=0) && (node_ones[j]-ones<3) ) ) )
            {
                   int count=0;
                   for(int k=0; (k<bits*2) && (count<3); k+=2)
                   if(nodes[i][k]!=nodes[j][k]) count++;
                   if(count<3)
                   {
                              int old_clus=node_clus[j];
                              for(int t=0; t<no_nodes; t++)
                              if(node_clus[t]==old_clus)
                              node_clus[t]=curr_clus;
                              no_of_clus--;
                   }
            }
    }
    cout<<"Largest value of k: "<<no_of_clus<<endl;
   
    return EXIT_SUCCESS;
}
