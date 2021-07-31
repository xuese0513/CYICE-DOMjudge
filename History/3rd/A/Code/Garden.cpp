# include <iostream>
using namespace std;

int main(){
    int N,n,L,R,ans = 0;
    char m[1001];

    cin>>N;
    m[0] = m[N+1] = 1;
    for(n = 1 ; n<=N ; n++)
        cin>>m[n];

    L = 1, R = N;
    while(L<N && m[L] != '1')
        L++;
    while(R>-1 && m[R] != '1')
        R--;

    while(L<=R){
        if(m[L] == '0' && m[L-1] != '9' && m[L+1] != '9')
            ans++;
        L++;
    }

    cout<<ans;
}
