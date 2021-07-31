#include <bits/stdc++.h>
using namespace std;
 
// Function to print permutations of string str
// using next_permutation
void permute(string str)
{
    // Sort the string in lexicographically
    // ascending order
    sort(str.begin(), str.end());
 
    // Keep printing next permutation while there
    // is next permutation
    do {
       cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}
 
// Driver code
int main()
{
    char a[10000] ;
    char temp ;
    int i = 0, n, all ;
    scanf( "%d\n", &all ) ; 
    for ( int j = 0 ; j < all ; j++ ) {
    	i = 0 ;
      for ( scanf( "%c", &temp ) ; temp != '\n' ; scanf( "%c", &temp ) ) {
      	a[i] = temp ;
      	i++ ;
      } // for
    
      a[i] = '\0' ;
    
      n = strlen(a);
      permute(a);
 } // for
}
