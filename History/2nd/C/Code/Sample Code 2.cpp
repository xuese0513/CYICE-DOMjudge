# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;

# define MAXN 1000000
double pos[MAXN];

int main(){
    int N,D,d,bp;
    double dis;
    double minidis = 1e+18;

    cin>>N>>D;
    while(N--){
        dis = 0;
        for(d = 0 ; d<D ; d++)
            cin>>pos[d];

        for(d = 0 ; d<D ; d++){
            cin>>bp;
            pos[d] -= bp;
            dis += pos[d]*pos[d];
        }
        minidis = min(minidis,sqrt(dis));
    }
    cout<<fixed<<setprecision(4)<<minidis;

}
