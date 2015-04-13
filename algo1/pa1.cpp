#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100000 

long long inverseNum=0;
void find_InverseNum(int *A, int x, int y, int* T){
	if(y-x > 1){
		int m= (x+y)/2;
		int p=x,q=m, i=x;
		find_InverseNum(A,x,m,T);
		find_InverseNum(A,m,y,T);

		while(p<m || q<y){
			if( q>=y || (p<m && A[p] <= A[q])){
                T[i++]=A[p++];
			}
			else {
                T[i++]=A[q++];
                inverseNum+=(m-p);
            }
		}
        for(int i=x; i<y; i++ ) A[i]=T[i];
	}
}
int A[MAX];
int T[MAX];
int main(int argc, char const *argv[])
{
	freopen("/home/wizard/Desktop/algorithm/IntegerArray.txt","r",stdin);
	for (int i=0; i< MAX; i++){
		cin>>A[i];
	}
	find_InverseNum(A,0,MAX,T);
//	for(int i=0; i< MAX; i++)
  //     for(int j=i+1; j<MAX; j++){
    //    if(A[i]>A[j])
      //     inverseNum++;
    //   }
    //
    for(int i=0; i<MAX; i++)
       cout<<A[i]<<endl;

    cout<<inverseNum<<endl;
	return 0;
}
