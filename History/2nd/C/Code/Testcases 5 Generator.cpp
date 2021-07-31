# include <bits/stdc++.h>
using namespace std;

# define MAXN 1000000
double pos[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    fstream input, output;
    input.open("6.in",ios::out);
    output.open("6.out",ios::out);

    int N,D,d,bp;
    double dis;
    double minidis = 1e+18;

    cin>>N>>D;
    //N = nd(generator);
    //D = 50000/nd(generator);
    input<<N<<' '<<D<<'\n';

    while(N--){
        dis = 0;
        input<<(pos[0] = -10000);
        for(d = 1 ; d<D ; d++)
            input<<' '<<(pos[d] = -10000); //cin>>pos[d];

        input<<'\n';

        input<<(bp = 10000);
        pos[0] -= bp;
        dis += pos[0]*pos[0];

        for(d = 1 ; d<D ; d++){
            input<<' '<<(bp = 10000); //cin>>bp;
            pos[d] -= bp;
            dis += pos[d]*pos[d];
        }
        if(dis < minidis)
            minidis = dis;

        input<<'\n';
    }
    output<<fixed<<setprecision(4)<<sqrt(abs(minidis));

}
