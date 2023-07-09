#include <iostream> // Input/Output stream 

using namespace std; 



double x_eq(double x) { return (-1-x*x)/2; }



void iter_meth() {
 // Solve x^2 + 2x + 1= 0
 double s = 1; 
 int Nmax = 50;
 double olds, ds;  
 
 for (int i = 0; i < Nmax; i++) {
  if ((i+1)%10 == 0) { 
   cout << "Iteration " << i+1 << endl; 
  }
  olds = s; 
  s = x_eq(s);
  ds = abs((s - olds)/olds);
  if (ds < 1e-3) {
   cout << "Solution is x = " << s << endl;
   return; 
  } 
 }
 
 cout << "Last iteration x = " << s << endl;
 
}



int main() { 
 iter_meth(); 
}



