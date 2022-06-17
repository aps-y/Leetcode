#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    struct heapNode {
        long prime;
        int index;
        long indexVal;
        
        heapNode(int prime, int index, int indexVal) : prime(prime), index(index), indexVal(indexVal) {}
    };
    
    struct Comp {
    bool operator()(heapNode a, heapNode b) {
        return (a.indexVal) > (b.indexVal);
    }
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNos(n, INT_MAX);
        uglyNos[0] = 1;
        
        priority_queue<heapNode, vector<heapNode>, Comp> pq;
        
        for(int prime : primes) {
            pq.push(heapNode(prime, 0, prime));
        }
        
        for(int i=1; i<n; i++) {
            heapNode h = pq.top();
            
            uglyNos[i] = h.indexVal;
            
            while(h.indexVal == pq.top().indexVal) {
                heapNode t = pq.top();
                pq.pop();
                t.index = t.index+1;
                t.indexVal = t.prime * uglyNos[t.index];
                pq.push(t);
            }
        }
        
        return uglyNos[n-1];
        
    }
};