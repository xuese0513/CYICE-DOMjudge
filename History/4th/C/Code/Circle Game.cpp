# include <iostream>

using namespace std ;

/*
	f(n)
		1 2 3 4 5 6 ... n-1 n  => ��k�ӤH�^�O

	f(n-1)
		k+1 k+2 k+3 ... n 1 2 3 4 ... k-1  // f(n)���s��
		 1   2   3  ...               n-1 => ��k�ӤH�^�O // f(n-1)���s��

		�Ĥ@���ĤG�檺���Y
	 	k+1 = (1+k-1) % n +1 // k+1�i�H�ѷs���s��1�g�L�p��o�X��
		k+2 = (2+k-1) % n +1
		k+3 = (3+k-1) % n +1
		.
		.
		.
		k-1= (n-1+k) % n

	f(n-2)���� f(n)�� f(n-1)
		k+1 k+2 k+3 ... n-1 1 2 3 4 ... k-1  // f(n-1)���s��
		 1   2   3  ...                 n-2 => ��k�ӤH�^�O

		�Ĥ@���ĤG�檺���Y
	 	k+1 = (1+k-1) % (n-1)
		k+2 = (2+k-1) % (n-1)
		k+3 = (3+k-1) % (n-1)
		.
		.
		.
		k-1= (n-2+k-1) % (n-1)


	=>�p�Gf(n-1)���Ĥ@��O f(n)�����G
	f(n) = ( f(n-1) + k-1 ) % n +1  // �qf(n-1)�ѤU���H���of(n)�̫�Ĺ���H
	n = 1 �C���u��1�ӤH �^�ǽs��1

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
