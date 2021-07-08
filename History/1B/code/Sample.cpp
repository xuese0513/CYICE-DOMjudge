# include <iostream>
using namespace std;

int main(){
    int T,n,m;
    long long f[21];  // factorial, f[n] = n!

    // building factorial table
    f[0] = 1;
    for(n = 1 ; n<21 ; n++)
        f[n] = f[n-1]*n;

    cin>>T;
    while(T--){
        cin>>n>>m;
        --m, --n;
        cout<<"1/"<<(n+1)*(f[n]/f[m]/f[n-m])<<'\n';
    }
}
