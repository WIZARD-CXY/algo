#!/usr/bin/env python
# coding=utf-8
from time import clock
from heapq import heappush,heappop

start = clock()

f=open('Median.txt','r')
temp=f.read()
f.close()
data=[int(val) for val in temp.split()]
out=[0 for x in range(len(data))]

def brutalway(data,out):
    for ind in range(len(data)):
        b=data[0:ind+1]
        b.sort()
        out.append(b[(len(b)+1)/2-1])
    return sum(out)%10000

print(brutalway(data,out))

def heapway(data,out):
    lheap=[]
    hheap=[]
    out[0]=data[0]
    tmp=sorted(data[0:2])
    out[1]=tmp[0]
    heappush(lheap,-tmp[0])
    heappush(hheap,tmp[1])

    for ind in range(2,len(data)):
        if data[ind] > hheap[0]:
            heappush(hheap,data[ind])
        else:
            heappush(lheap,-data[ind])

        if len(hheap) > len(lheap):
            heappush(lheap,-heappop(hheap))
        if len(lheap) > len(hheap)+1:
            heappush(hheap,-heappop(lheap))
        
        out[ind]=-lheap[0]
    
    return sum(out)%10000


finish=clock()
#print heapway(data,out)
print finish-start

