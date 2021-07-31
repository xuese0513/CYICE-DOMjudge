# include <bits/stdc++.h>
using namespace std;

int y;

double f(double x){
    return 6*x*x*x*x*x*x*x + 8*x*x*x*x*x*x + 7*x*x*x + 5*x*x - y*x;
}

int main(){

    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> unif(0, 99999999);

    fstream input,output;
    input.open("8.in",ios::out);
    output.open("8.out",ios::out);

    int T;
    double l,r,ml,mr;

    cin>>T;
    input<<T<<'\n';
    while(T--){
        l = 0, r = 100;
        //cin>>y;
        y = unif(generator);
        input<<y<<'\n';

        while(r-l > 0.000001){
            ml = l+(r-l)/3;
            mr = r-(r-l)/3;

            if(f(ml) < f(mr))
                r = mr;
            else
                l = ml;
        }
        output<<fixed<<setprecision(4)<<f((l+r)/2)<<'\n';

    }
}
