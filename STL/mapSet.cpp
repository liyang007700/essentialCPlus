#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<iterator>
#include"functionObject.h"

using namespace std;

int main() {
  map<string, int> words;
  set<string> word_exclusion;
  typedef pair < string, int > Int_Pair;

  words["1"] = 1;
  words.insert(Int_Pair("2", 2));
  map<string, int>::iterator it = words.begin();
  for(; it != words.end(); ++it) {
    cout << "key: " << it->first
         << "value: " << it->second << endl;
  }

  int ia[10] = {1, 3, 5, 8, 5, 3, 1, 5, 8, 1};
  vector<int> vec(ia, ia + 10);

  set<int> iset(vec.begin(), vec.end());
  set<int>::iterator its = iset.begin();
  for (; its != iset.end(); ++its) {
    cout << *its << "   ";
  }

  vector<int> ivec2;
  filter(vec.begin(), vec.end(), back_inserter(ivec2), 8, greater<int>());
  cout << 11 << ivec2.size() << endl;
}