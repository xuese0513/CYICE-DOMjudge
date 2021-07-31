#include<iostream>
#include<vector>
#include<math.h>
using namespace std ;

bool PredictTheWinner( vector<int> nums ) ;
int findAns( vector<int>, int i, int j) ;

int main() {
    int times ;
    long long num ;
	bool ans = false ;
    vector<int> list ;

	cin >> times ;
	for( int i = times ; i > 0 ; i-- ) {
        cin >> num ;
		list.push_back( num ) ;
	} // for

	if ( PredictTheWinner( list ) ) cout << "true\n" ;
	else  cout << "false\n" ;
} // main()

bool  PredictTheWinner(vector<int> nums) {
    return findAns(nums, 0, nums.size()-1) >= 0;
}

int findAns(vector<int> nums, int i, int j) {
    if (i == j) return nums[i];
    else {
        int first = nums[i] - findAns(nums, i+1, j);
        int last = nums[j] - findAns(nums, i, j-1);
        return max(first, last);
    }
}

