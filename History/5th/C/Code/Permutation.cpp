# include <stdio.h>
# include <string.h>
# include <iostream>

using namespace std ;

typedef char str30[30] ;

str30 ans[50000] ;
str30 k = "\0" ;
int p = 0 ;

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
} // swap

void permute(char *a, int h, int r) {
  int i, n ;
  char temp ;
  if (h == r)  {
  	strcpy( ans[p], a ) ;
  	p++ ;
  } // if
  else {
    for (i = h; i <= r; i++) {
        swap((a+h), (a+i));
        permute(a, h+1, r);
        swap((a+h), (a+i)); //backtrack
    } // for

  } // else

} // permute

int main() {
    char a[50000] ;
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
      permute(a, 0, n-1);
      strcpy( ans[p], k ) ;
      for ( i = 0 ; i < p ; i++ ) {
        for ( int h = i ; h < p ; h++ ) {
        	if ( strcmp( ans[i], ans[h] ) > 0 ) {
        		strcpy( a, ans[h] ) ;
        		strcpy( ans[h], ans[i] ) ;
        		strcpy( ans[i], a ) ;
        	} // if
        } // for

      } // for

      for ( i = 0 ; i < p ; i++ ) {
      	printf( "%s\n", ans[i] ) ;
      } // for

      p = 0 ;
    } // for


} // main()
