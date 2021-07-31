# include <bits/stdc++.h>

using namespace std ;

int main() {
    int m, n, k, temp ;
    int i, j ;
    cin>>m>>n>>k;
    vector<vector<int>> a ;
    for ( i = 0 ; i < m ; i ++ ) {
        vector<int> t;
        for ( j = 0 ; j < n ; j ++ ) {
            cin>>temp;
            t.push_back(temp) ;
        }
        a.push_back(t) ;
    }


    int mid = 0, l = 0, h = m * n - 1 ;

    while ( l <= h ) {
        mid = ( l + h ) / 2 ;
        i = mid / n ;
        j = mid % n ;
        if ( a[i][j] == k )
            break;
        else if ( a[i][j] < k )
            l = mid+1 ;
        else
            h = mid-1 ;
    }

    if ( a[i][j] != k ) cout << "Target cannot be found." << endl ;
    else{
        int x = i,y = j;
        do{
            mid--;
            x = mid/n;
            y = mid%n;
        }while(a[x][y] == k);
        mid++;
        i = mid/n;
        j = mid%n;
        cout << (i+1) << " " << (j+1) << endl ;
    }
}
