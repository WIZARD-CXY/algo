/*************************************************************************
	> File Name: pa11.cpp
	> Author: Wizard
	> Mail: wizard_cxy@hotmail.com 
	> Created Time: Wed 09 Jul 2014 10:29:07 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct record{
    int weight;
    int length;
    int diff;
};

bool cmp(const record &a, const record &b)
{
    if(a.diff > b.diff) return  true;
    else if( a.diff == b.diff) return a.weight > b.weight;
    else return false;
}

int main()
{
    freopen("jobs.txt","r",stdin);

    int num;
    cin>>num;

    vector<record> recs;
    int weight,length;

    while(num--)
    {
        record rec;
        cin>>rec.weight;
        cin>>rec.length;
        rec.diff=rec.weight-rec.length;
        recs.push_back(rec);
    }

    sort(recs.begin(),recs.end(),cmp);

    long long sum=0;
    int now=0;

    for(vector<record>::iterator it = recs.begin(); it != recs.end(); it++)
    {
        now = it->length+now;
        sum+=(it->weight)*(now);
    }
    cout<<now<<" "<<sum<<endl;
}

    
