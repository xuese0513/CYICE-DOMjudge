#include <iostream>
#define _for(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define _rep(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
using namespace std;

int gcd(int x,int y){
	for (;;)
	{
		int c= x%y;
		if (c == 0)	return y;
		else {
			x=y;
			y=c;
		}
	}
}

int main ()
{
	int n;
	while (cin >> n)
	{
		if (n ==0) break;
		int g=0;
		_for(i,1,n){
			_rep(j,i+1,n){
				g += gcd(i,j);
			}
		}
		printf("%d\n",g);
	} 
	
}
