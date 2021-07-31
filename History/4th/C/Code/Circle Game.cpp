# include <iostream>

using namespace std ;

/*
	f(n)
		1 2 3 4 5 6 ... n-1 n  => 第k個人淘汰

	f(n-1)
		k+1 k+2 k+3 ... n 1 2 3 4 ... k-1  // f(n)的編號
		 1   2   3  ...               n-1 => 第k個人淘汰 // f(n-1)的編號

		第一行到第二行的關係
	 	k+1 = (1+k-1) % n +1 // k+1可以由新的編號1經過計算得出來
		k+2 = (2+k-1) % n +1
		k+3 = (3+k-1) % n +1
		.
		.
		.
		k-1= (n-1+k) % n

	f(n-2)重複 f(n)到 f(n-1)
		k+1 k+2 k+3 ... n-1 1 2 3 4 ... k-1  // f(n-1)的編號
		 1   2   3  ...                 n-2 => 第k個人淘汰

		第一行到第二行的關係
	 	k+1 = (1+k-1) % (n-1)
		k+2 = (2+k-1) % (n-1)
		k+3 = (3+k-1) % (n-1)
		.
		.
		.
		k-1= (n-2+k-1) % (n-1)


	=>如果f(n-1)的第一行是 f(n)的結果
	f(n) = ( f(n-1) + k-1 ) % n +1  // 從f(n-1)剩下的人推得f(n)最後贏的人
	n = 1 遊戲只有1個人 回傳編號1

*/
int findTheWinner(int n, int k) {
	if (n <= 1)
        return 0 ;
    else
        return (findTheWinner(n - 1, k) + k ) % n ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("2.out","w",stdout);

	int n, k, test ;
	cin >> test ;
	for ( int i = 0 ; i < test ; i ++ ) {
		cin >> n >> k ;
		int ans = findTheWinner( n, k )+1 ;
		cout << ans << endl ;
	}
}
