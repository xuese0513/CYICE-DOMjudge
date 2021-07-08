# include <bits/stdc++.h>
using namespace std;

# define MAXN 200000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    long long a[3][3];
    long long result;
    int T,x,y;
    fstream input, output;
    random_device rd;
    mt19937 generator( rd() );
    uniform_int_distribution<long long> unif(-999999, 999999);


    input.open("3.in",ios::out);
    output.open("3.ans",ios::out);

    cin>>T;
    input<<T<<'\n';
    while(T--){
        for(x = 0 ; x<3 ; x++){
            a[x][0] = unif(generator);
            input<<a[x][0];
            for(y = 1 ; y<3 ; y++){
                a[x][y] = unif(generator);
                input<<' '<<a[x][y];
            }
            input<<'\n';
        }

        result = a[0][0] * (a[1][1]*a[2][2] - a[2][1]*a[1][2]) +
                 a[0][1] * (a[1][2]*a[2][0] - a[2][2]*a[1][0]) +
                 a[0][2] * (a[1][0]*a[2][1] - a[2][0]*a[1][1]);

        output<<result<<'\n';
    }
}
