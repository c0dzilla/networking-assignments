#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1 || argc ==2) {
    cout<<"Please supply the data file and MTU as arguments!"<<endl;
    return 0;
  }
  ifstream dataFile;
  dataFile.open(argv[1]);
  string data;
  getline(dataFile, data);
  dataFile.close();
  int mtu = 0;
  string mtuString = argv[2];
  for (int i=0;i<mtuString.length();i++) {
    mtu = mtu*10 + ((int)mtuString[i] - '0');
  }
  int numOfFragments = data.length()/mtu;
  if (data.length()%mtu) {
    numOfFragments++;
  }
  string fragments[numOfFragments];
  int i = 0;
  int len = 0;
  while (i<data.length()) {
    fragments[len] = "";
    for (int j=0;j<mtu;j++) {
      if (i >= data.length()) {
        break;
      }
      fragments[len]+=data[i++];
    }
    len++;
  }
  cout<<"Number of fragments: "<<numOfFragments<<endl;
  cout<<"Fragments::"<<endl;
  int sum = 0;
  for (int i=0;i<numOfFragments;i++) {
    cout<<"Fragment "<<i<<":"<<endl;
    cout<<"   Length -> "<<fragments[i].length()<<" bits"<<endl;
    sum+=fragments[i].length();
    if (i != numOfFragments-1) {
      cout<< "   Flag -> 1"<<endl;
    } else {
      cout<<"   Flag -> 0"<<endl;
    }
    cout<<"   Offset -> "<<sum<<endl;
    cout<<"   Data -> "<<fragments[i]<<endl;
  }
  cout<<"\nReassembly: "<<data<<endl;
  return 0;
}
