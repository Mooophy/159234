#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Movie {
public:
    Movie();
    virtual ~Movie(){}
    void setTitle(const string& t);
    void setDirector(const string& d);
    void setTime(int t = 0);
    void setQuality(int q = 0);
    virtual void display() const;
    virtual void getData(ifstream& fin);
    static bool readFromFile(string fname, Movie* Movies[], int n);
private:
    string title;
    string director;
    int time;
    // in minutes
    int quality; // 0 (bad) to 4 (tops)
};

void Movie::setTitle(string const& t){ title = t; }
void Movie::setDirector(string const& d){ director = d; }
void Movie::setTime(int t){ time = t; }
void Movie::setQuality(int q){ quality = q; }
void Movie::display() const
{
    cout << "Title: " << title << endl;
    cout << "Director: " << director << endl;
    cout << "Time: " << time << endl;
    cout << "Quality: " << string('*', quality) << endl;
}

void Movie::getData(ifstream& fin)
{

}

class Revised : public Movie
{
public:
private:

};

class Forieign : public Movie
{

};
