# include <iostream>
# include <iomanip>
using namespace std;

int y;

double f(double x){
    return 6*x*x*x*x*x*x*x + 8*x*x*x*x*x*x + 7*x*x*x + 5*x*x - y*x;
}

int main(){
    int T;
    double l,r,ml,mr;

    cin>>T;
    while(T--){
        l = 0, r = 100;
        cin>>y;

        while(r-l > 0.000001){
            ml = l+(r-l)/3;
            mr = r-(r-l)/3;

            if(f(ml) < f(mr))
                r = mr;
            else
                l = ml;
        }
        cout<<fixed<<setprecision(4)<<f((l+r)/2)<<'\n';
    }
}
