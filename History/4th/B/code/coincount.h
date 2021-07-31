#include<iostream>
using namespace std;

namespace ans{
    
    int solve(int n) {
        long long l=1,r=n,m,s;
        while(l<=r){
            m=l+((r-l)/2) ;
            s=(m*(m+1))/2;
            if(s<n) {
                if(n-s<m+1) return m;
                else l = m+1 ;
            }
            else if(s>n)
                r = m-1;
            else   
                return m ;
        }
        return m;
    }
}