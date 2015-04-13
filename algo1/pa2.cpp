#include <iostream>
#include <cstdio>
using namespace std;

int A[10005];
int cnt;

int partition(int A[], int low, int up)
{
    int pivot=A[low];
    int i=low+1;

    for(int j=low+1; j<=up; j++)
    {
        if(A[j]<pivot){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
        }
    }
    int temp=A[i-1];
    A[i-1]=A[low];
    A[low]=temp;
    
    return i-1;
}
void quicksort(int A[], int x, int y)
{
    if(y-x>0){ 
        //find the median ,and swap it with the first element
        int res;
        if((y-x)%2!=0) // array has even element
        {
            int middle=(y-x+1)/2+x-1;
            if (A[x]>A[middle])
            {
                if (A[middle] > A[y]){
                    res=middle;
                } else if ( A[x] > A[y]){
                    res=y;
                } else {
                    res=x;
                }
            }
            else 
            {
                if( A[middle] < A[y]){
                    res=middle;
                }
                else if ( A[x] > A[y]){
                    res=x;
                } else {
                    res=y;
                }
            }
        } else { //array has odd number of element
            int middle=(y-x)/2+x;
            if (A[x]>A[middle])
            {
                if (A[middle] > A[y]){
                    res=middle;
                } else if ( A[x] > A[y]){
                    res=y;
                } else {
                    res=x;
                }
            }
            else 
            {
                if( A[middle] < A[y]){
                    res=middle;
                }
                else if ( A[x] > A[y]){
                    res=x;
                } else {
                    res=y;
                }
            }
        }
        int temp=A[x];
        A[x]=A[res];
        A[res]=temp;

        int p = partition(A, x, y);
        cnt+=y-x;
        quicksort(A, x, p-1);
        quicksort(A, p+1, y);
    }
}
int main(){
    freopen("QuickSort.txt","r",stdin);
    int i=0;
    while(cin>>A[i++]){
    }

    quicksort(A,0,9999);
    for(int i=0; i<10000; i++){
        if(A[i]!= i+1)
           cout<<"ERROR";
    }
    cout<<cnt<<endl;
}
