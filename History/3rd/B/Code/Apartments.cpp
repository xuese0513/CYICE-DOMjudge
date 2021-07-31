# include <iostream>
# include <algorithm>
using namespace std;

int a[200000], b[200000];

int main(){
    int N,M,k,n,m,ans = 0;
    cin>>N>>M>>k;

    for(n = 0 ; n<N ; n++)
        cin>>a[n];
    for(n = 0 ; n<M ; n++)
        cin>>b[n];

    sort(a,a+N);
    sort(b,b+M);

    n = m = 0;
    while(n<N && m<M){
        if(abs(a[n]-b[m])<=k)
            ans++, m++, n++;
        else if(b[m] < a[n])
            m++;
        else
            n++;
    }

    cout<<ans;
}
