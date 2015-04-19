#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 2001
#define MAXW 2000001
long f[MAXW];

int main(){
	int n,x;
	freopen("knapsack_big.txt","r",stdin);

	cin>>x>>n;
	int v,w;

	for(int i=1; i<=n; i++){
		scanf("%d%d",&v,&w);
		for(int j=x; j>=0; j--){
			if(j>=w){
				if(f[j]<f[j-w]+v){
					f[j]=f[j-w]+v;
				}

			}
		}
	}
	cout<<f[x]<<endl;
}