#include<bits/stdc++.h>
using namespace std ;

bool PredictTheWinner( vector<int> nums ) ;
int findAns( vector<int>, int i, int j) ;

int main() {

    mt19937 generator( time(NULL) );
    uniform_int_distribution<long long> untimes(1, 20);
    uniform_int_distribution<long long> unif(1, 10000000); // 可自行替換1和100 (最小和最大)
    //uniform_int_distribution<long long> unif(1, 100); // 可自行替換1和100 (最小和最大)

    int times;
    for(int t = 12 ; t<=14 ; t++){
        times = 18+t-12;
        fstream input, output;
        input.open(to_string(t)+".in",ios::out);
        output.open(to_string(t)+".out",ios::out);

        long long num ; // 取得亂數
        bool ans = false ;
        vector<int> list ;

        input<<times<<'\n';


        num = 1;
        //num = unif(generator) ;
        list.push_back( num ) ;
        input<<num;
        for( int i = times ; i > 1 ; i-- ) {
            //num = unif(generator) ;
            num = 1;
            list.push_back( num ) ;
            input<<' '<<num;
        } // for

        output << (PredictTheWinner( list ) ? "true\n" : "false\n");
    }
} // main()

bool PredictTheWinner(vector<int> nums) {
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

