#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct city{
	double mx,my;
};

int main(){
	freopen("tsp.txt","r",stdin);
	int n;
	cin>>n;

	double x,y;
	city cities[n+1];

	for(int j=0; i<n; j++){
		cin>>x>>y;
		city[i].mx=x;
		city[i].my=y;

	}

	double length[n+1][n+1];

	for(int i=0; i<n;i++){
		for(int j=0; j<n; j++){
			if(i==j){
				length[i][i]=0;
			}else{
				length[i][j]=length[j][i]=sqrt(pow((city[i].mx-city[j].mx),2)+pow((city[i].my-city[j].my),2));
			}
		}
	}
	
}