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

    if ( c > maxC ) return ; //�W�L�̤j���B �^�W�@�h

    if ( n == test ) { // �Ҧ������~���ˬd�L�F
        if ( s > maxS ) maxS = s ;
        return ;
    }

    // �ʶR�o�ӹ}��
    track( n + 1, s + sati[n], c + cost[n] ) ;

    // �S�R�o�ӹ}��
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
