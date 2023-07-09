#include <iostream> 
#include <cmath>
#include <vector> 

using namespace std; 


double max_element(vector<double> &x) {
	double maxe = x[0];
	vector<double>::iterator iter = x.begin();
	for (iter; iter < x.end(); iter++) {
		if (*iter > maxe) maxe = *iter; 
	}
	return maxe; 
} 



void vect_it() {
	vector<double> x = {1,2,3,4,5,12,-2,4,11,11.999};
	vector<double>::iterator iter = x.begin();
	cout << "My vector is x = ("; 
	for (iter; iter < x.end(); iter++) {
		cout << *iter << " ";
	       	(*iter)++; 
	}
	cout << ")" << '\n'; 
	cout << "My vector is now x = ("; 
	for (iter = x.begin(); iter < x.end(); iter++) {
		cout << *iter << " ";
	}
	cout << ")" << '\n'; 
	cout << "Max value in the vector = " << max_element(x) << '\n';
	//double maxv = max_element(x.begin(), x.end());
	//vector<double>::iterator maxv; 	
	//maxv = max_element(x.begin(), x.end());
	//vector<double>::const_iterator it; 
	//it = max_element(x.begin(), x.end());	
	//cout << "Max value in the vector = " << *maxv << '\n';
	
}



int main() {	
	vector<double> x = {1,2,3,4,5};
	vector<double>::iterator iter = x.begin();
	
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < x.size(); i++) {
			x[i] += j;
		}
		cout << "x = {"; 
		for (iter = x.begin(); iter < x.end(); iter++) {
			cout << *iter << " ";
		}
		cout << "}" << endl;
	}

	return 0; 
}



