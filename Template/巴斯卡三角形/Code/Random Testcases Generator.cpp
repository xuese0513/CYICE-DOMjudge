# include <bits/stdc++.h>
using namespace std;

int main(){
    int T,n,m;
    long long f[20];  // factorial, f[n] = n!

    // building factorial table
    f[0] = 1;
    for(n = 1 ; n<20 ; n++)
        f[n] = f[n-1]*n;

    fstream input, output;
    input.open("3.in",ios::out);
    output.open("3.ans",ios::out);
    srand(time(NULL));

    cin>>T;
    input<<T<<'\n';
    while(T--){
        n = rand()%20+1;    // 1~20
        m = rand()%n+1;     // 1~n
        input<<n<<' '<<m<<'\n';
        --n, --m;
        output<<(f[n]/f[m]/f[n-m])<<'\n';
    }

}
