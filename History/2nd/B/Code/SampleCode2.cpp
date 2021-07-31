#include <iostream>
#include <stack>
using namespace std;

int main() {

    int n = 0;
    cin >> n;
    bool match;
    string str;
    getline(cin, str);

    for ( int i = 0 ; i < n ; i++ ) {
        getline(cin, str);
        stack<char> stk;
        match = true;

        for ( int i = 0 ; i < str.length() && match ; i++ ) {
            if ( str[i] == '(' || str[i] == '[' )
                stk.push( str[i] );
            else if ( !stk.empty() && (( str[i] == ')' && stk.top() == '(' ) || ( str[i] == ']' && stk.top() == '[') ) )
                stk.pop();
            else
                match = false;
        }
        cout << ( ( stk.empty() && match ) ? "Yes\n" : "No\n" );
    }
}
