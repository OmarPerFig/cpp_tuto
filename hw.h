// Hello world and much more... // Line comment in C++
/* 
Block comment 
*/ 

#include <iostream> // Input/Output stream 
#include <string> // Not a fundamental type
#include <fstream> // Read and write files 

using namespace std; 


// Hello world program, first steps...
void print_stuff () {
// Std output
std::cout << "Hello world!!!\n";
std::cout << "Testing some strings: \\ \"  \n";
//cout << "Tus mamadas pa...\n";
// Variables
std::string fs = "Nanapancha";
std::cout << "A " << fs << " le gusta el chachachá\n";
}


// Check C++ convention...
void version_cpp() {
   if (__cplusplus == 201703L)
      std::cout << "C++17" << std::endl;
   else if (__cplusplus == 201402L)
      std::cout << "C++14" << std::endl;
   else if (__cplusplus == 201103L)
      std::cout << "C++11" << std::endl;
   else if (__cplusplus == 199711L)
      std::cout << "C++98" << std::endl;
   else
      std::cout << "pre-standard C++" << std::endl;
}


// A void function call passing values by reference
void duplicate(int& a, int& b, int& c) { // Pass values by reference
  a*=2;
  b*=2;
  c*=2;
}

int ref_ex() {
  int x=1, y=3, z=7;
  duplicate (x, y, z); // These get modified by the function call 
  std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
  return 0;
}


// Pointers stuff...
int pointers_ex() { // pointers example 
 int firstvalue, secondvalue;
 int * mypointer; // Declare a pointer

 mypointer = &firstvalue; // mypointer contains the address of the variable firstvalue
 *mypointer = 10; // Modify the value at which mypointer points to 
 mypointer = &secondvalue;
 *mypointer = 20;
 
 cout << "firstvalue is " << firstvalue << '\n';
 cout << "secondvalue is " << secondvalue << '\n';
 
 return 0;
}


// Arrays are kind of pointers... 
int pointer_to_array() {
 int numbers[5];
 int * p;
 p = numbers;  *p = 10; // Arrays can be used as pointers to their first element
 p++;  *p = 20;
 p = &numbers[2];  *p = 30;
 p = numbers + 3;  *p = 40;
 p = numbers;  *(p+4) = 50;
 for (int n=0; n<5; n++) 
  cout << numbers[n] << ", ";
 cout << endl; 
 return 0;
}


// Pointers as function arguments...
void increment_all(int* start, int* stop) {
  int * current = start;
  while (current != stop) {
    ++(*current);  // increment value pointed
    ++current;     // increment pointer
  }
}

void print_all(const int* start, const int* stop) { // With "const" values cannot be modified
//const int * const start // Would forbid modification of the pointer (address) 
  const int * current = start;
  while (current != stop) {
    cout << *current << '\n';
    ++current;     // increment pointer
  }
}

int point_args()
{
  int numbers[] = {10,20,30};
  increment_all (numbers,numbers+3);
  print_all (numbers,numbers+3);
  return 0;
}


// Void pointers example...
void increase(void* data, int psize) { // Defines arbitrary type pointer
//int * p = 0; int * q = nullptr; // Do not confuse with null pointers (points nowhere) 
  if ( psize == sizeof(char) )
  { char* pchar; pchar=(char*)data; ++(*pchar); } // Type specification required for dereferencing
  else if (psize == sizeof(int) )
  { int* pint; pint=(int*)data; ++(*pint); }
}

int void_pointer_ex()
{
  char a = 'x';
  int b = 1602;
  increase(&a,sizeof(a));
  increase(&b,sizeof(b));
  cout << a << ", " << b << '\n';
  return 0;
}


// Pointers to functions
int addition1(int a, int b) { return (a+b); }

int subtraction1(int a, int b) { return (a-b); }

// Allow to pass a function to another function as an argument 
int operation1(int x, int y, int (*functocall)(int,int)) { 
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int function_pointers()
{
  int m,n;
  int (*minus1)(int,int) = subtraction1;

  m = operation1(7, 5, addition1);
  n = operation1(20, m, minus1);
  cout << n << endl;
  return 0;
}


// Dynamic memory examples... 
int dynamic_ex() {
  int i,n;
  int * p;
  cout << "How many numbers would you like to type? ";
  cin >> i;
  p= new (nothrow) int[i]; // User defined array size (at runtime)
  if (p == nullptr)
    cout << "Error: memory could not be allocated";
  else
  {
    for (n=0; n<i; n++)
    {
      cout << "Enter number: ";
      cin >> p[n];
    }
    cout << "You have entered: ";
    for (n=0; n<i; n++)
      cout << p[n] << ", ";
    cout << endl; 
    delete[] p;
  }
  return 0;
}


// Classes...
class Rectangle { // classes example
 int width, height; // Private by default 
 public:
  //void set_values (int,int);
  Rectangle(); // Default constructor
  Rectangle(int,int); // Constructor, notice no return value
  int area() {return width*height;}
};

//void Rectangle::set_values (int x, int y) { // method defined externally 
Rectangle::Rectangle(int a, int b) { // class constructor 
 width = a; //x
 height = b; //y
}

Rectangle::Rectangle() { // Overloading constructors
 width = 5; 
 height = 5; 
}

int rect_class() {
 Rectangle rect(3,4); // Initializing an object calls the constructor
 Rectangle rectb;
 //rect.set_values (3,4);
 cout << "rect area: " << rect.area() << endl;
 cout << "rectb area: " << rectb.area() << endl;
 
 return 0;
}


// A constructor that calls another constructor... 
class Circle {
    double radius;
  public:
    Circle(double r) : radius(r) { } // Member initialization
    double area() { return radius*radius*3.14159265; }
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base(r), height(h) {} // Requires memeber initialization
    double volume() { return base.area() * height; }
};

int twoclass_ex() {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}


// Pointers to classes... 
int point_class() {
  Rectangle obj (3, 4);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  // Dynamic memory examples... 
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} }; // You can use a variable for the array size!!!
  
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << (*foo).area() << '\n';//foo->area() is equivalent
  cout << "*bar's area: " << (*bar).area() << '\n';//bar->area()
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';       
  
  delete bar;
  delete[] baz;
  
  return 0;
}	



