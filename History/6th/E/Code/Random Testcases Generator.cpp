# include <random>
# include <iostream>
# include <fstream>
# include <vector>

using namespace std;

#define MAX 12

struct Point {
  int row;
  int column;
  Point ( int row = 0, int column = 0 ) : row(row), column(column) {}
};

int N = 0;
string ans;

void F( int row, int grid[MAX][MAX] ) {
  
  vector<Point> p;

  
  if ( row == N  ) {
    for ( int i = 0; i < N; i++ )
      for ( int j = 0; j < N; j++ )
        if ( grid[i][j] == 1 ) {
          cout << j + 1 << ' ';
          ans += to_string( j + 1 ) + " ";

        }
    ans +=  "\n";
    cout << endl;
    return ;
  }
  
  for ( int column = 0 ; column < N; column++ ) {
    
    if ( grid[row][column] == 0 ) {
      grid[row][column] = 1;
      p.push_back( Point( row, column ) );
      
      // delete
      for ( int i = row + 1, j = column + 1, k = column - 1; i < N ; i++, j++, k-- ) {
        if ( grid[i][column] != 2 ) { // column
          grid[i][column] = 2;
          p.push_back( Point( i, column ) );
        }
        
        if ( i < N && j < N && grid[i][j] != 2 ) { // right slash
          grid[i][j] = 2;
          p.push_back( Point(i, j ) );
        }
        
        if ( i < N && k >= 0 && grid[i][k] != 2 ) { // left slash
          grid[i][k] = 2;
          p.push_back( Point( i, k ) );
        }
      }
      
      F( row+1, grid );

      while ( !p.empty() ) {
        grid[p.back().row][p.back().column] = 0;
        p.pop_back();
      }
    }
    
  }
  
  
}

int main(){
  
  int grid[MAX][MAX] = {0};
  
  for ( int i = 4; i <= 12; i++ ) {
    ans = "";
    string input_file_name = to_string(i-3) + ".in";
    string output_file_name = to_string(i-3) + ".out";
  
    fstream input, output;
    input.open( input_file_name, ios::out );
    output.open( output_file_name, ios::out );

    input << to_string(i);
    N = i;
    cout << i << endl;
    F( 0, grid );
    output << ans;
  }


  return 0;
}
