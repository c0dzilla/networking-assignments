#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

string intToHex(int oct) {
  map <int, char> m;
  m[10] = 'a';
  m[11] = 'b';
  m[12] = 'c';
  m[13] = 'd';
  m[14] = 'e';
  m[15] = 'f';
  string res = "";
  while (oct) {
    if (oct%16 < 10)
      res = to_string(oct%16) + res;
    else
      res = m[oct%16] + res;
    oct/=16;
  }
  while (res.length() < 2) {
    res = "0" + res;
  }
  return res;
}

string ipToHex(string ipv4Input) {
  int oct = 0;
  string res = "";
  for  (int i=0;i<ipv4Input.length();i++) {
    if (ipv4Input[i] == '.' || i == ipv4Input.length() - 1) {
      if (i == ipv4Input.length() - 1) {
        oct = oct*10 + (int)ipv4Input[i] - '0';
      }
      res += intToHex(oct);
      if (res.length() == 4) res += ":";
      oct = 0;
    } else {
      oct = oct*10 + (int)ipv4Input[i] - '0';
    }
  }
  return res;
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout<<"Please supply the ipv4 address for conversion"<<endl;
    return 0;
  }
  string ipv4Input = argv[1];
  string ipv6Result = "0000:0000:0000:0000:0000:ffff:";
  ipv6Result += ipToHex(ipv4Input);
  cout<<"Corresponding ipv6: ";
  cout<<ipv6Result<<endl;
  return 0;
}