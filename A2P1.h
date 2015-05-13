//
//  @author : Liu kuan 12086075,  Yuxiang Zhang 13158665 
//
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//
//  The base class
//
class Movie 
{
public:
    //
    //  default constructor
    //
    Movie() 
        : title{}, director{}, time{ 0 }, quality{ 0 }
    {}
    //
    //  virtual destructor
    //
    virtual ~Movie(){}
    //
    //  public interfaces
    //
    void setTitle(const string& t){ title = t; }
    void setDirector(const string& d){ director = d; }
    void setQuality(int q = 0){ quality = q; }
    string toString() const 
    {
        return "\nTitle: " + title + "\nDirector: " + director + "\nTime: " + to_string(time) + " mins\nQuality: " + string(quality, '*');
    }
    //
    //  virtual members
    //
    virtual void display() const{ cout << toString() << endl; }
    virtual void getData(ifstream& fin)
    { 
        getline(fin, title);
        getline(fin, director);
        
        auto buffer = string();
        getline(fin, buffer);
        time = stoi(buffer);
        buffer.clear();
        getline(fin, buffer);
        quality = stoi(buffer);
    }
    //
    //  static member
    //
    static bool readFromFile(string fname, Movie* Movies[], int n);

private:
    //
    //  data member
    //
    string title;
    string director;
    int time;
    int quality; // 0 (bad) to 4 (tops)
};

//
//  Revised
//
class Revised : public Movie
{
public:
    //
    //  public interfaces
    //
    void setRevisedTime(int rt) { revised_time = rt; }
    void setChanges(string const& c){ changes = c; }
    virtual void display() const  override
    {
        Movie::display();
        cout << "Revised time: " << to_string(revised_time) << "\nChanges: " << changes << endl;
    }
    virtual void getData(ifstream& fin) override
    { 
        Movie::getData(fin);
        auto buffer = string{};
        getline(fin, buffer);
        revised_time = stoi(buffer);
        getline(fin, changes);
    }
    //
    //  virtual destructor
    //
    virtual ~Revised(){}
private:
    int revised_time;
    string changes;
};


//
//  Foreign
//
class Foreign : public Movie
{
public:
    //
    //  public interfaces
    //
    void setLanguage(string const& l) { language = l; }
    virtual void display() const override
    {
        Movie::display();
        cout << "Language: " << language << endl;
    }
    virtual void getData(ifstream& fin) override
    {
        Movie::getData(fin);
        getline(fin, language);
    }
    //
    //  virtual destructor
    //
    virtual ~Foreign(){}
private:
    //
    //  data member
    //
    string language;
};

//
//  readFromFile 
//      using polymorphism
//
bool Movie::readFromFile(string fname, Movie* Movies[], int n)
{
    ifstream fin{ fname };
    if (!fin.good()) return false;
    for (auto idx = size_t{ 0 }; idx != n; ++idx)
    {
        auto line = std::string{};
        getline(fin, line);
        if (line == "Movie") 
            Movies[idx] = new Movie();
        if (line == "Revised") 
            Movies[idx] = new Revised();
        if (line == "Foreign") 
            Movies[idx] = new Foreign();
        Movies[idx]->getData(fin);
    }
    return true;
}