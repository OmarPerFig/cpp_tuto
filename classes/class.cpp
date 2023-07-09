#include <iostream>
#include <string>

using namespace std; 


class Msg {
 public : 
  string m1 = "Hola mundo!";
  Msg() {};
};



int main() {
	Msg msgs;
	cout << msgs.m1 << endl; 
}
