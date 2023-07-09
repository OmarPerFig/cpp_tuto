// Hellow world 2... 

#include <iostream> // Input/Output stream 
#include <string> // Not a fundamental type

using namespace std; 



// Overloding operators... (for classes and others) 
class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
    CVector& operator = (const CVector&);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}

CVector& CVector::operator= (const CVector& param)
{
  x=param.x;
  y=param.y;
  return *this;
}

int op_overload() {
  CVector foo (3,1);
  CVector bar (1,2);
  CVector result;
  result = foo + bar;
  cout << '(' << result.x << ',' << result.y << ')' << '\n';
  return 0;
}



// Keyword this is a pointer to the object... 
class Dummy {
  public:
    bool isitme (Dummy& param);
};

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}

int this_example() {
  Dummy a;
  Dummy* b = &a;
  if ( b->isitme(a) )
    cout << "yes, &a is b\n";
  return 0;
}



// Static members of a class... 
class Dummy1 {
  public:
    static int n; // Same number for all objects of this class
    Dummy1() { n++; };
};

int Dummy1::n=0; // Must be initialized outside the class

int static_example() {
  Dummy1 a;
  Dummy1 b[5];
  cout << a.n << '\n';
  Dummy1 * c = new Dummy1;
  cout << Dummy1::n << '\n';
  delete c;
  return 0;
}



// Copy constructor and destructor...
class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;} // Destructor, called at the end of objects lifetime
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
};

int deep_copy() {
  Example5 foo ("Example");
  Example5 bar = foo;

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}



// Inheritance 
class Polygon {
  protected: // Can be accessed from child classes
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b;}
 };

class Rectangle1: public Polygon {
  public:
    int area ()
      { return width * height; }
 };

class Triangle: public Polygon {
  public:
    int area ()
      { return width * height / 2; }
  };
  
int inher_ex() {
  Rectangle1 rect;
  Triangle trgl;
  rect.set_values (4,5);
  trgl.set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
}



// Pointers to base class...
class Polygon2 {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    //virtual int area () { return 0; } // Would allow to access (*ppoly1).area()
    //virtual int area (void) =0; // pure virtual function --> abstract base class
    //void printarea() { cout << this->area() << '\n'; } // Would be possible w the line above
};

class Rectangle2 : public Polygon2 {
  public:
    int area()
      { return width*height; }
};

class Triangle2 : public Polygon2 {
  public:
    int area()
      { return width*height/2; }
};

int polymorphism_ex() {
  Rectangle2 rect;
  Triangle2 trgl;
  Polygon2 * ppoly1 = &rect; // This!
  Polygon2 * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
}



// Complete dynamic allocation and polymorphism example... 
class Polygon3 {
  protected:
    int width, height;
  public:
    Polygon3 (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class Rectangle3 : public Polygon3 {
  public:
    Rectangle3(int a,int b) : Polygon3(a,b) {}
    int area()
      { return width*height; }
};

class Triangle3 : public Polygon3 {
  public:
    Triangle3(int a,int b) : Polygon3(a,b) {}
    int area()
      { return width*height/2; }
};

int dynallo_poly() {
  Polygon3 * ppoly1 = new Rectangle3(4,5);
  Polygon3 * ppoly2 = new Triangle3(4,5);
  ppoly1->printarea(); // (*ppoly1).printarea();
  ppoly2->printarea();
  delete ppoly1;
  delete ppoly2;
  return 0;
}



// type of expression
#include <typeinfo>

int type_id_ex() {
  int * a,b;
  a=0; b=0;
  if (typeid(a) != typeid(b))
  {
    cout << "a and b are of different types:\n";
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
  }
  return 0;
}



// typeid, polymorphic class
#include <exception>

class Base { virtual void f(){} };
class Derived : public Base {};

int tid_polyclass() {
  try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
  return 0;
}



