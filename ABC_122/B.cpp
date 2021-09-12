#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int ans = 0, k = 0;
  for(int i; i < str.length(); i++){
    if (str.at(i)=='A'||str.at(i)=='T'||str.at(i)=='G'||str.at(i)=='C') {
      k++;
    } else {
      k = 0;
    }
    if (k > ans) ans = k;
  }
  cout << ans << endl;
  return 0;
}
