#include<iostream>
#include<vector>
#include<complex>

using namespace std;

int main() {
 
 vector<vector<double>> M;
 M = vector<vector<double>>(4,vector<double>(2)); 

 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 2; j++) {
   //M[i][j] = i + 1;
   M[i][j] = 2*i + j + 1;
   cout << M[i][j] << '\n';
  }
 }
 
 cout << '\n';

 for (int i = 0; i < 4; i++) {
  vector<double> m = M[i];
  for (int j = 0; j < 2; j++) {
   cout << m[j] << '\n';
  }
 }
 
 return 0; 
}
