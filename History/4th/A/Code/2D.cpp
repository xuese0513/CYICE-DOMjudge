# include <vector>
# include <iostream>

using namespace std ;

int main() {
	int m, n, target, temp ;
	int i, j ;
	vector<vector<int>> a ;
	for ( i = 0 ; i < m ; i ++ ) {
		vector<int> t ;
		for ( j = 0 ; j < n ; j ++ ) {
			cin>>temp ;
			t.push_back(temp) ;
		}
		a.push_back(t) ;
	}

	int mid = 0, l = 0, h = m * n - 1 ;

	while ( l <= h ) {
		mid = l + ( l + h ) / 2 ;
		i = mid / n ;
		j = mid % n ;
		if ( a[i][j] == target ) break ;
		else if ( a[i][j] > target ) l = mid ;
		else if ( a[i][j] < target ) h = mid ;
	}

	if ( l > h ) cout << "Target cannot be found." << endl ;

	else cout << i << " " << j << endl ;

}
