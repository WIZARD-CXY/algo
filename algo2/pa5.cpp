#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct city{
	double mx,my;
};

uint_t nextnum(uint_t x)
{
 
  uint_t rightOne;
  uint_t nextHigherOneBit;
  uint_t rightOnesPattern;
 
  uint_t next = 0;
 
  if(x)
  {
 
    // right most set bit
    rightOne = x & -(signed long)x;
 
    // reset the pattern and set next higher bit
    // left part of x will be here
    nextHigherOneBit = x + rightOne;
 
    // nextHigherOneBit is now part [D] of the above explanation.
 
    // isolate the pattern
    rightOnesPattern = x ^ nextHigherOneBit;
 
    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/rightOne;
 
    // correction factor
    rightOnesPattern >>= 2;
 
    // rightOnesPattern is now part [A] of the above explanation.
 
    // integrate new pattern (Add [D] and [A])
    next = nextHigherOneBit | rightOnesPattern;
  }
 
  return next;
}
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

	double w[n+1][n+1];

	for(int i=0; i<n;i++){
		for(int j=i+1; j<n; j++){
			if(i==j){
				w[i][i]=0;
			}else{
				w[i][j]=w[j][i]=sqrt(pow(city[i].mx-city[j].mx,2)+pow(city[i].my-city[j].my,2));
			}
		}
	}
	
}