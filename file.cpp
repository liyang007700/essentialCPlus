#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
  const string usr_name = "eric";
  const int num_tries = 11;
  const int num_right = 10;
  ofstream outfile("seq_data.txt", std::ios_base::app);
  if (!outfile) {
    cerr << "oops!";
  } else {
    outfile << usr_name << "\n"
            << num_tries << "\n"
            << num_right << endl;
  }  
  // std::ifstream infile("seq_data.txt");
}