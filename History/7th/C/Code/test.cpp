#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int numSquares(int n);

int main()
{
    int num, ans;

    fstream input, output;
    input.open("3.in", ios::out);
    output.open("3.out", ios::out);
    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> unif(1, 10000);

    int t;
    cin>>t;
    while(t--){
        num = unif(generator);
        input<<num<<'\n';

        ans = numSquares(num);
        output << ans << '\n';
    }
}

int numSquares(int n)
{
    while (n % 4 == 0)
        n /= 4;
    if (n % 8 == 7)
        return 4;
    for (int a = 0; a * a <= n; ++a)
    {
        int b = sqrt(n - a * a);
        if (a * a + b * b == n)
        {
            return !!a + !!b;
        }
    }
    return 3;
}
