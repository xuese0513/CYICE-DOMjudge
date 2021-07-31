# include <bits/stdc++.h>
using namespace std ;

int findTheWinner(int n, int k) {
	if (n <= 1)
        return 0 ;
    else
        return (findTheWinner(n - 1, k) + k ) % n ;
}

int main() {
    mt19937 generator(time(NULL));
    uniform_int_distribution<long long> unif(1, 500);

    int n, k, test ;
    cin >> test ;

    for(int t = 3 ; t<=5 ; t++){
        fstream input,output;
        input.open(to_string(t) + ".in",ios::out);
        output.open(to_string(t) + ".out",ios::out);

        input<<test<<'\n';

        for ( int i = 0 ; i < test ; i ++ ) {
            n = unif(generator);
            k = unif(generator)%n+1;

            if(i != 0)
                input<<'\n';
            input<<n<<' '<<k;

            int ans = findTheWinner( n, k )+1 ;
            output << ans << endl ;
        }
    }
}
