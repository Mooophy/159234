//Possible solution to the problem about Date-Deitel&Deitel
//Analyse and try to extend/break ther following solution

#include<cstdio>
#include<cstdlib>
#include<iostream>

using std ::cout;
using std ::endl;
using std ::cin;

//-----------------------
//class declaration
//-----------------------

class MyDate{ 
public :
	MyDate(int, int, int);
	// get and set functions for month/day/year 
	int getDay ();
	void setDay(int); 
	int getMonth ();
	void setMonth (int); 
	int getYear ();
	void setYear(int);
	void displayDate();	// display date as: day-month-year
	void guessBirthday(int);
private : 
	int day;
	int month; 
	int year;
};
//------------------------
//Class implementation
//------------------------

//initialization with constructor 
MyDate ::MyDate(int d, int m, int y) {
    if(m < 1 || m > 12) {
      setMonth(1);
		cout << "Month set as 1" << endl;
    } else{
      setMonth(m );
	 }		 
	 setDay(d);
    setYear(y);
}
//-----------------------------------
int MyDate ::getDay()  {return day;}
//------------------------------------- 
int MyDate ::getMonth() { return month ;}
//----------------------------------
 int MyDate ::getYear(){return year;}
//-----------------------------------
void MyDate ::setDay(int d) { day = d;}
//--------------------------------------
void MyDate ::setMonth(int m) { month = m;}
//--------------------------------------
void MyDate ::setYear(int y){ year = y; }
//-------------------------------------
 void MyDate ::displayDate() { 
	 cout << getDay() <<" - "
	      << getMonth()<< " - " <<getYear()<<endl; 
}
//---------------------------------------- 
void MyDate::guessBirthday(int res){
    int x = res - 250;
	 setDay(x / 100); 
	 setMonth(x%100);
    cout << "Your birthday: Day: " << getDay()
		   << " Month: " <<  getMonth()<<  endl;
}

//---------------------------------------
//Using objects of MyDate type
//---------------------------------------

int main(){
	//create MyDate objects
	MyDate today(4, 3, 2015 );

	//display initial date 
	today.displayDate();

	// demonstrates class Date's capabilities
 
	cout <<"\nI can guess your birthday .\n"
	     << "Please complete following steps and enter final number.\n"
	     <<"1. Multiply the DAY of month	in which you were born by 2.\n"
        << "2.Add 5 to new number.\n"
        << "3.Multiply new number by 50.\n"
        << "4.Add the number that represents the month \n(l-January, 2-February etc) to new number.\n"
	     << "5. Enter the result:"; 
   int result;
   cin >> result;
   today.guessBirthday(result);
   
    return 0;
}