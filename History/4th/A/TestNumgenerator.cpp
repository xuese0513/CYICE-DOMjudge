# include <bits/stdc++.h>

using namespace std ;

int main() {
    std::mt19937_64 ge ( time(NULL) ) ;
    std::uniform_int_distribution<int> unif(1,10000) ;
    int m, n, k, temp ;
    int i, j ;
    cin>>m>>n;

    for(int q = 7 ; q<=9 ; q++){
        fstream input,output;
        input.open(to_string(q)+".in", ios::out) ;
        output.open(to_string(q)+".out", ios::out) ;

        k = unif(ge);
        input<<m<<' '<<n<<' '<<k<<'\n';

        vector<int> r(m*n);
        for(i = 0 ; i<m*n ; i++)
            r[i] = unif(ge);
        sort(r.begin(),r.end());

        vector<vector<int>> a ;
        for ( i = 0 ; i < m ; i ++ ) {
            vector<int> t ;
            for ( j = 0 ; j < n ; j ++ ) {
                temp = r[i*n+j];
                if(j != 0)
                    input<<' ';
                input<<temp;

                t.push_back(temp) ;
            }
            input<<'\n';
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

        if ( a[i][j] != k ) output << "Target cannot be found." << endl ;
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
            output << (i+1) << " " << (j+1) << endl ;
        }
    }
}
