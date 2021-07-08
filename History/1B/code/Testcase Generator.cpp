# include <bits/stdc++.h>
using namespace std;

int main(){
    int T,n,m;
    long long f[21];  // factorial, f[n] = n!
    random_device rd;
    mt19937 generator( rd() );
    uniform_int_distribution<long long> unif(1, 100000);

    // building factorial table
    f[0] = 1;
    for(n = 1 ; n<21 ; n++)
        f[n] = f[n-1]*n;

    fstream input, output;
    input.open("3.in",ios::out);
    output.open("3.out",ios::out);

    cin>>T;
    input<<T<<'\n';
    while(T--){
        n = unif(generator)%21+1;    // 1~21
        m = unif(generator)%n+1;     // 1~n
        input<<n<<' '<<m<<'\n';
        --n, --m;
        output<<"1/"<<(n+1)*(f[n]/f[m]/f[n-m])<<'\n';
    }
}
