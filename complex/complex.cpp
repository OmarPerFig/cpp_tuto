#include <complex>
#include <iostream>
#include <vector>

using namespace std; 


complex<double> func(complex<double> x) { 
 return x*x; 
}



int main() { 
	//vector<complex<double>> v();
	
/* complex<double> s; 
 s = (1,1); 
 cout << s + 1.0 << endl;
 return 0; 
*/
 complex<double> z(0.0, 1.0);

 cout << "Real part: " << z.real() << endl; 
 cout << "Imaginary part: " << z.imag() << endl; 
 
 cout << "Squared : " << func(z) << endl; 
 cout << "Argument : " << arg(z) << endl; 
 cout << "Module : " << norm(z) << endl; 
 
 // Complex momenta tests ...
 const complex<double> imu(0.0, 1.0);
 vector<complex<double>> V(5, 1.0 + 2.0*imu); 
 vector<complex<double>>::iterator jter = V.begin();
 cout << "Complex vector V = \n";
 for (jter; jter < V.end(); jter++) {
  cout << *jter << '\n';
 }
 
 //cout << "Real momenta p^2 = " << 1;
 //cout << "\tGives k^2 = " << QEqs.k2(1, 1, 0) << endl; 
 //cout << "And complex momenta p^2 = " << 1.0 + imu; 
 //cout << "\tGives k^2 = " << QEqs.k2(1.0 + imu, 1, 0) << endl; 

 return 0; 
}



