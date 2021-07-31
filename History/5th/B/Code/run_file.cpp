# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>
using namespace std ;

string DecodeString(string str) {
  stack<char> st;
  int time ;
  for(int i = 0; i < str.size(); i++){
    if(str[i] != ']') {
      st.push(str[i]);
    }
    else{
      string curr_str = "";

      while(st.top() != '[') {
        curr_str = st.top() + curr_str ;
        st.pop();
      }

      st.pop();   // for '['
      string number = "";

      while(!st.empty() && isdigit(st.top())) { // for calculating number
        number = st.top() + number;
        st.pop();
      }

      time = atoi( number.c_str() );    // convert string to number

      while(time--) {
        for(int i = 0; i < curr_str.size() ; i++)
          st.push(curr_str[i]);
      }
    }
  }

  str = "";
  while(!st.empty()) {
    str = st.top() + str;
    st.pop();
  }

  return str;
}


int main() {
    freopen("6.in","r",stdin);
    freopen("6.out","w",stdout);

   string str,answer ;
   cin >> str ;
   answer = DecodeString( str ) ;
   cout << answer << endl ;
}
