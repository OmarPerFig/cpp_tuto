// Hellow world 3... 

#include <iostream> // Input/Output stream 
#include <string> // Not a fundamental type
#include <fstream> // Read and write files 
#include <exception> // Standard exceptions

#include <cmath>

using namespace std; 



void print_name() {
  cout << __FILE__ << endl;
}



// Exceptions... 
int thrw20() {
  try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
  return 0;
}



// My exception
class myexception: public exception {
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int some_excep() {
  try
  {
    throw myex;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}



// Standard exceotions...
int badallocation_ex() {
  try {
    int* myarray= new int[1000];
  }
  catch (exception& e) {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}



// Writing output to a file... 
int write_to_file(){

std::ofstream f("test_file.txt"); 
// f.open("test_file.txt"); 
if (f.is_open()) {
  f << "This is a line. LOL.\n";
  f << "This is another line.\n";
  f.close();
}

else std::cout << "Unable to open file.\n";

return 0; 
}



// Read file 
int read_lines() {
  string line;
  ifstream myfile ("test_file.txt");
  if (myfile.is_open()) {
    while ( getline(myfile,line) ) {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file.\n"; 

  return 0;
}



void strings_test() {
 string print_file_path = "/home/omar/Results/first_task/1/"; 
 string file_name = "first_out.txt"; 
 
 cout << print_file_path + file_name << endl; 
 
 cout << scientific << exp(-1) << endl;
}



