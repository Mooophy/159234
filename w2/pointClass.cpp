//Demo for a very simple class
//TO DO:
//a) Read and make sure you understand what the cde does
//b) Add methods to set / get the variables of a Point object
//c) Extand the Point class to deal with a sD point, 
//i.e having coordonates (x, y, z)

#include <iostream>
using namespace std;

class Point {
 public:
  	 
   void init(int u, int v){
      x = u;y = v;
   }
	void print();		
   void print(string s) ;

 private:
   int x,y;
};
void print() {
   cout << "Hello from the global print function!\n";
}

void Point::print() {
   cout << "(" << x << "," << y 
        << ")";
}

void Point::print(string s) {
   cout << s;
   Point::print();
	cout<<endl;
	::print();
}


int main(){
  Point origin, somePt;
  origin.init(0,0);
  somePt.init(-34,8);
  cout <<"The origin is  at ";
  origin.print();


  cout <<"\n\nAnd the center is  at ";

  somePt.print();
  cout <<endl;
	
  somePt.print("\nCenter again is at: ");
	cout <<endl;
	cout<<"\nGlobal function called here:\n";
	print();

  return 0;
}

