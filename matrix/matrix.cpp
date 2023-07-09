#include<iostream>
#include<vector>
#include<complex>

using namespace std;

int main() {
 
 vector<vector<double>> M;
 M = vector<vector<double>>(4,vector<double>(4)); 

 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 4; j++) {
   cout << M[i][j] << '\n';
   M[i][j] = 4*i + j + 1;
  }
 }
 
 cout << '\n';

 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 4; j++) {
   cout << M[i][j] << '\n';
  }
 }
 
 return 0; 
}
