#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=2)
        return 1;

    return fib(n-1)+fib(n-2);
}

int main() {

    mt19937 generator(time(NULL));
    uniform_int_distribution<int> bin(0,3);

    for(int t = 1 ; t <= 10 ; t++){
        fstream input,output;
        input.open(to_string(t)+".in",ios::out);
        output.open(to_string(t)+".out",ios::out);

        int n;
        n = 4*t-3 + bin(generator);
        input<<n;
        output << fib(n);
    }
}
