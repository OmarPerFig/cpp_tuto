#include<iostream>
#include<vector>
#include<complex>

using namespace std;

void realmatrix() {
 
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
 
}



int main() {
 
 vector<vector<complex<double>>> M;
 M = vector<vector<complex<double>>>(4,vector<complex<double>>(2)); 
 
 complex<double> imu(0,1); 
 
 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 2; j++) {
   //M[i][j] = i + 1;
   M[i][j] = 2.0*i + j + 1.0 + j*1.0*imu;
   cout << M[i][j] << '\n';
  }
 }
 
 cout << '\n';

 for (int i = 0; i < 4; i++) {
  vector<complex<double>> m = M[i];
  vector<double> mreal(2); 
  for (int k= 0; k < 2; k++) {
	mreal[k] = m[k].real();
	//*iter = m[k].real();
  }
  for (int j = 0; j < 2; j++) {
   cout << mreal[j] << '\n';
  }
 }
 
 return 0; 
}
