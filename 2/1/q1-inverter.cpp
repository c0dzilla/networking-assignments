#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout<<"No input provided"<<endl;
    return 0;
  }
  string first = argv[1];
  string inverted = "";
  for (int i=0;i<first.length()-1;i++) {
    inverted+=first[i];
  }
  if (first[first.length() - 1] == '0') inverted+='1';
  else inverted+='0';
  cout<<inverted<<endl;
  for (int i=2;i<argc;i++) {
    cout<<argv[i]<<endl;
  }
    return 0;
}