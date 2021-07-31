# include <bits/stdc++.h>
using namespace std;

# define MAXN 1000000
double pos[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    fstream input, output;
    input.open("9.in",ios::out);
    output.open("9.out",ios::out);

    int N,D,d,bp;
    double dis;
    double minidis = 1e+18;
    mt19937 generator( time(NULL) );
    uniform_int_distribution<int> nd(2, 1000000);
    uniform_int_distribution<int> unif(-10000, 10000);

    cin>>N>>D;
    //N = nd(generator);
    //D = 50000/nd(generator);
    input<<N<<' '<<D<<'\n';

    while(N--){
        dis = 0;
        input<<(pos[0] = unif(generator));
        for(d = 1 ; d<D ; d++)
            input<<' '<<(pos[d] = unif(generator)); //cin>>pos[d];

        input<<'\n';

        input<<(bp = unif(generator));
        pos[0] -= bp;
        dis += pos[0]*pos[0];

        for(d = 1 ; d<D ; d++){
            input<<' '<<(bp = unif(generator)); //cin>>bp;
            pos[d] -= bp;
            dis += pos[d]*pos[d];
        }
        if(dis < minidis)
            minidis = dis;

        input<<'\n';
    }
    output<<fixed<<setprecision(4)<<sqrt(abs(minidis));

}
