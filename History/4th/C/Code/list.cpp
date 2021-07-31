# include <iostream>
using namespace std ;

int findTheWinner(int n, int k) {
	if (n <= 1)
        return 0 ;
    else
        return (findTheWinner(n - 1, k) + k ) % n ;
}

int main() {


	int n, k, test ;
	cin >> test ;
	for ( int i = 0 ; i < test ; i ++ ) {
		cin >> n >> k ;
		int ans = findTheWinner( n, k ) ;
		cout << ans << endl ;
	}
}
