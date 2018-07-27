#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string modulo2Calculator(string divisor, string divident) {
  string temp = "";
  for (int i=0;i<divisor.length();i++) {
    int a, b;
    if (divident[i] == '0') a = 0;
    else a = 1;
    if (divisor[i] == '0') b = 0;
    else b = 1;
    a = a^b;
    temp += to_string(a);
  }
  for (int i = divisor.length(); i<divident.length();i++) {
    temp+=divident[i];
  }
  string s = "";
  int a = 0;
  while (temp[a] == '0') {
    a++;
  }
  for (int i=a;i<temp.length();i++) {
    s+=temp[i];
  }
  if (s.length()<divisor.length()) {
    if (s.length() == 0) return "0";
    return s;
  }
  return modulo2Calculator(divisor, s);
}

int main() {
  // generator
  string msg, poly;
  cout<<"Enter the message: "<<endl;
  cin>>msg;
  cout<<"Enter the polynomial key: ";
  cin>>poly;
  string msgTransmitted = modulo2Calculator(poly, msg);
  cout<<"Generated Message: "<<msg+msgTransmitted<<endl;
  cout<<"Polynomial Key: "<<poly<<endl;
  return 0;
}