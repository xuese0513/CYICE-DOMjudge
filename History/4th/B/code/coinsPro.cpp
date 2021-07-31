#include<bits/stdc++.h>
#include<random>
#include"coincount.h"
using namespace std;


int main() {
    srand(time(NULL));
    long long t ,a = rand();
    std::mt19937_64 ge ( a ) ;
    std::uniform_int_distribution<int> unif(1,99999999) ; // high test
    //std::normal_distribution<double> norm(57000.0,22000.0); // normal test
    //std::cauchy_distribution<double> cau(300.0,259.8) ; // low test
    fstream input,output;
    input.open("4.in", ios::out) ;
    output.open("4.out", ios::out) ;

    cin >> t;
    input << t << endl ;
    while(t--) {
        long long a ;
        a = unif(ge);
        //if(t%3==0) a = unif(ge) ;
        //if(t%3==1) a = cau(ge) ;
        //if(t%3==2) a = norm(ge) ;
        input << abs(a) << endl;
        output << abs((int)ans::solve(a)) << endl;
    }

}
