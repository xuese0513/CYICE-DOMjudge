#include <bits/stdc++.h>
#define _for(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
using namespace std;

int main(){
    srand(time(NULL));
    fstream input, output;
    input.open("3.in",ios::out);
    output.open("3.out",ios::out);
    mt19937 generator( time(NULL) );
    uniform_int_distribution<int> unif(90, 10000000); // 可自行替換1和100 (最小和最大)
    int n{rand()%500+10};
    //int n{5000};
    for (int i{};i<n;i++){
        int t = unif(generator); // 取得亂數
        input<<t << '\n';
    }
}
