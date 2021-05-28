# include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T,n,m;
    long long f[20];  // factorial, f[n] = n!

    // building factorial table
    f[0] = 1;
    for(n = 1 ; n<20 ; n++)
        f[n] = f[n-1]*n;

    cin>>T;
    while(T--){
        cin>>n>>m;
        --n, --m;
        cout<<(f[n]/f[m]/f[n-m])<<'\n';
    }

}
