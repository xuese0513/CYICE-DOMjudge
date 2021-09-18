# include <iostream>
# include <vector>
# include <algorithm>

using namespace std ;

vector<int> sati ;
vector<int> cost ;
int maxS = 0 ;
int maxC = 0 ;
int test ;

void track( int n, int s, int c ) {

    if ( c > maxC ) return ; //超過最大金額 回上一層

    if ( n == test ) { // 所有的物品都檢查過了
        if ( s > maxS ) maxS = s ;
        return ;
    }

    // 購買這個飼料
    track( n + 1, s + sati[n], c + cost[n] ) ;

    // 沒買這個飼料
    track( n + 1, s, c ) ;

}


int main () {

    int temp ;
    int s = 0, c = 0 ;
    cin >> maxC >> test ;
    vector<int> path(test) ;
    for ( int i = 0 ; i < test ; i ++ ) {
        cin >> temp ;
        cost.push_back(temp) ;
        cin >> temp ;
        sati.push_back(temp) ;
    }

    track( 0, 0, 0 ) ;


    cout << maxS << endl ;
}
