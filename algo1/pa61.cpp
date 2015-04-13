/*************************************************************************
	> File Name: pa61.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Thu 19 Jun 2014 07:48:27 PM CST
 ************************************************************************/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int Sum[200001];
int main()
{
    freopen("algo1-programming_prob-2sum.txt","r",stdin);
    
    set<long long> myset;

    long long a;

    while(cin>>a){
        myset.insert(a);
    }

    size_t count = 0;

    set<long long>::iterator iter = myset.begin();
    for(;iter!=myset.end();iter++){
        long long max=10000 - *iter;
        long long min=-10000 - *iter;

        set<long long>::iterator itlow = myset.lower_bound(min);
        set<long long>::iterator itup = myset.upper_bound(max);

        for(set<long long>::iterator ite = itlow; ite != itup; ite++){
            if(!Sum[10000+*ite+*iter] && *iter != *ite)
            {
                count++;
                Sum[10000+*iter+*ite]=1;
            }
        }
    }
    cout<<count<<endl;
}
