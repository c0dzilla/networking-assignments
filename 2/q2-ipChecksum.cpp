#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int hexToInt(string s) {
  map<char, int> m;
  m['0'] = 0;
  m['1'] = 1;
  m['2'] = 2;
  m['3'] = 3;
  m['4'] = 4;
  m['5'] = 5;
  m['6'] = 6;
  m['7'] = 7;
  m['8'] = 8;
  m['9'] = 9;
  m['a'] = 10;
  m['A'] = 10;
  m['b'] = 11;
  m['B'] = 11;
  m['c'] = 12;
  m['C'] = 12;
  m['d'] = 13;
  m['D'] = 13;
  m['e'] = 14;
  m['E'] = 14;
  m['f'] = 15;
  m['F'] = 15;
  int ans = 0;
  for (int i = 0;i<s.length();i++) {
    ans = ans*16 + m[s[i]];
  }
  return ans;
}

int main() {
  unsigned int ipv4Int;
  stringstream ipv4;
  string s;
  cout<<"Enter the IP address packet: "<<endl;
  cin>>s;
  ipv4 << std::hex << s;
  ipv4 >> ipv4Int;
  long long int a1 = (long long int)pow(2, 16) - 1 - ipv4Int;
  cout<<ipv4<<endl;
  cout<<a1<<endl;
  cout<<"Enter the IP address packet: "<<endl;
  cin>>s;
  ipv4 << std::hex << s;
  ipv4 >> ipv4Int;
  long long int b1 = (long long int)pow(2, 16) - 1 - ipv4Int;
  cout<<"Enter the IP address packet: "<<endl;
  cin>>s;
  ipv4 << std::hex << s;
  ipv4 >> ipv4Int;
  long long int c1 = (long long int)pow(2, 16) - 1 - ipv4Int;
  cout<<"Enter the IP address packet: "<<endl;
  cin>>s;
  ipv4 << std::hex << s;
  ipv4 >> ipv4Int;
  long long int d1 = (long long int)pow(2, 16) - 1 - ipv4Int;
  long long int ans = a1+b1+c1+d1;
  ans = (long long int)pow(2, 16) - 1 - ans;
  cout<<"Checksum: "<<ans<<endl;
  return 0;
}