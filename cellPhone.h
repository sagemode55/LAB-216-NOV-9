
#include<iostream>
using namespace std; 
#define cellPhone_H

const string blank = " ";
class cellPhone {
    private:
        string brandName;
        string color;
        string series; 
        int year;
        static int count;
    
    public:   
    static int publicCount;
    // if overloADING this constructor then default must be defined 
   /* cellPhone(){
        brandName= " ";
        color = " ";
        series= " ";
        year = 0;*/
    // not the prefer way

    cellPhone() : brandName(" "),color(" "),series(" "),year(0){
      ++count;
      ++publicCount;  
    };
    
    cellPhone(string b, string c, string s, int y=0){ // you can not have the default paramater after default
        brandName = b;
        color = c;
        series= s;
        year = 0; 
        ++count;
        ++publicCount;  
    }

    cellPhone(string b){
        brandName= b;
    }
    cellPhone(string b,string c){
        brandName= b;
        color = c; 
    }
    //cellPhone(string c,string b) :cellPhone { b } { // constructor delegating
    //    color = c; 
    //}
        
    ~cellPhone(){
        cout << "inside destructor. " << endl;
    }

friend void resetYear(cellPhone& phone);
// 1. constructor does have a return value not even void
// 2. it is public
// 3. can not call construct directly, automatically
// 4. deflaut constructor will be created implicitly
// 5. to initialize num var we need to overload constructor

void setBrandName(string b){ brandName = b; }
string getBrandName()const {return brandName; }

void setColor(string c){color = c; }
string getColor()const {return color; }

void setSeries(string s){ series= s; }
string getSeries()const {return series; }

void setYear(int y){ year=y;}
int getYear() const {return year;}

int getCount() const {return count;}
static int getCountStatic(){return count;}

void myprint() const;
/*void print() const {
    cout <<"brandname = " << brandName << endl;
    cout<< "Series = "<< series << endl;
    cout<< "Color = "<< color << endl;
    cout<< "Year = "<< year << endl;
}*/
};
