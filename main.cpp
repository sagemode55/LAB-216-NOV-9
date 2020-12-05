////
////  main.cpp
////  NOV 30 Lab Assignment
////
////  Created by Sitthiphol Yuwanaboon on 11/30/20.
////

#include <iostream>
#include<string>
using namespace std;
//Create a class timeoff
class NumDays {
//Instance variables
private:
   double hours;
   double days;
//Member functions
public:
   NumDays() {
       hours = 0;
       days = 0;
   }
   //Constructor
   NumDays(double hrs) {
       hours = hrs;
       days = hrs / 8;
   }
   //Getter
   double gethours() {
       return hours;
   }
   double getDays() {
       return days;
   }
   //Operator+ overload
   friend NumDays operator+(const NumDays &n1, const NumDays &n2) {
       NumDays numdays(n1.hours + n2.hours);
       numdays.days = numdays.hours / 8;
       return numdays;
   }
   //Operator - overload
   friend NumDays operator-(const NumDays &n1, const NumDays &n2) {
       NumDays numdays(n1.hours - n2.hours);
       numdays.days = numdays.hours / 8;
       return numdays;
   }
   //Operator++ overload
   void operator ++() {
       hours++;
       days = hours / 8;
   }
   //Operator --overload
   void operator --() {
       hours--;
       days = hours / 8;
   }
};
//create a class TimeOff
class TimeOff {
//Instance variables
private:
   string empName;
   int empId;
   NumDays   maxSickDays;
   NumDays   sickTaken;
   NumDays   maxVacation;
   NumDays   vacTaken;
   NumDays   maxUnpaid;
   NumDays   unpaidTaken;
//Member functions
public:
   //defualt constructor
   TimeOff(){
       empName = "";
       empId = 0;
       maxSickDays = 0;
       sickTaken = 0;
       maxVacation = 0;
       vacTaken = 0;
       maxUnpaid = 0;
       unpaidTaken = 0;
   }
   //Parameterized constructor
   TimeOff(string name, int id, NumDays maxSick, NumDays sick, NumDays maxVocn, NumDays vocn, NumDays maxUpaid, NumDays uPaid) {
       if ((sick.gethours() + vocn.gethours()) <= 240) {
           empName = name;
           empId = id;
           maxSickDays = maxSick;
           if (sick.gethours() <= maxSick.gethours()) {
               sickTaken = sick;
           }
           maxVacation = maxVocn;
           if (vocn.gethours() <= maxVacation.gethours()) {
               vacTaken = vocn;
           }
           maxUnpaid = maxUpaid;
           if (uPaid.gethours() <= maxUnpaid.gethours()) {
               unpaidTaken=uPaid;
           }
       }
   }
   //Accessors
   string getName() {
       return empName;
   }
   int getId() {
       return empId;
   }
   NumDays getMaxSick() {
       return maxSickDays;
   }
   NumDays getSick() {
       return sickTaken;
   }
   NumDays getMaxVocation() {
       return maxVacation;
   }
   NumDays getVocation() {
       return vacTaken;
   }
   NumDays getMaxUnPaid() {
       return maxUnpaid;
   }
   NumDays getUnPaid() {
       return unpaidTaken;
   }
   //Mutators
   void setName(string name) {
       empName=name;
   }
   void setId(int id) {
       empId=id;
   }
   void setMaxSick(NumDays s) {
       maxSickDays=s;
   }
   void setSick(NumDays s) {
       if (maxSickDays .gethours()>= s.gethours()) {
           sickTaken = s;
       }
   }
   void setMaxVocation(NumDays v) {
       maxVacation = v;
   }
   void setVocation(NumDays v) {
       if (maxVacation.gethours() >= v.gethours()) {
           vacTaken = v;
       }
   }
   void setMaxUnPaid(NumDays un) {
       maxUnpaid = un;
   }
   void setUnpaid(NumDays un) {
       if (maxUnpaid.gethours() >= un.gethours()) {
           unpaidTaken = un;
       }
   }
   friend ostream& operator<<(ostream& out,TimeOff &toff) {
       cout << " EmployeeName: " << toff.empName << endl;
       cout << " Id: " << toff.empId <<endl;
       cout <<" SickLeave: " << toff.sickTaken.getDays() << endl;
       cout << " Vocation: " << toff.vacTaken.getDays() << endl;
       cout << " Unpaid:" << toff.unpaidTaken.getDays() << endl;
       return out;
   }
};
int main()
{
    
   //create an object of time off class
   TimeOff toff("Lebron James", 1123, NumDays(120), NumDays(60), NumDays(120), NumDays(60), NumDays(120), NumDays(40));
   //Print using overload
   cout << toff << endl;
   //Increamet days
   NumDays num(60);
   for (int i = 0; i < 10; i++) {
       ++num;;
   }
   //Add into time off sick days
   toff.setSick(num);
   //Display
   cout << toff<< endl;
   //Create second object and assign first
   TimeOff toff2;
   toff2 = toff;
   //Display
   cout << toff2 << endl;
    
    TimeOff toff3("Justin bieber", 1126, NumDays(120), NumDays(70), NumDays(120), NumDays(80), NumDays(120), NumDays(80));
    TimeOff toff4("Naruto Km", 100, NumDays(120), NumDays(80), NumDays(120), NumDays(82), NumDays(120), NumDays(80));
    TimeOff toff5("Kim Jeong", 3311, NumDays(120), NumDays(90), NumDays(120), NumDays(82), NumDays(120), NumDays(80));
    TimeOff toff6("JOOPER", 2002, NumDays(120), NumDays(100), NumDays(120), NumDays(81), NumDays(120), NumDays(80));
    TimeOff toff7("KENNy D", 2019, NumDays(120), NumDays(55), NumDays(120), NumDays(80), NumDays(120), NumDays(80));
    TimeOff toff8("Marshall D", 1002, NumDays(120), NumDays(45), NumDays(120), NumDays(83), NumDays(120), NumDays(80));
    TimeOff toff9("White bread", 1111, NumDays(120), NumDays(23), NumDays(120), NumDays(83), NumDays(120), NumDays(80));
    TimeOff toff10("Jonny Danny", 1114, NumDays(120), NumDays(60), NumDays(120), NumDays(83), NumDays(120), NumDays(80));
    TimeOff toff11("LOVE CRAZY", 2040, NumDays(120), NumDays(67), NumDays(120), NumDays(83), NumDays(120), NumDays(80));
    
    cout << toff3 << endl;
    cout << toff4 << endl;
    cout << toff5 << endl;
    cout << toff6 << endl;
    cout << toff7 << endl;
    cout << toff8 << endl;
    cout << toff9 << endl;
    cout << toff10 << endl;
    cout << toff11 << endl;
    return 0;
}

//EmployeeName: Lebron James
//Id: 1123
//SickLeave: 7.5
//Vocation: 7.5
//Unpaid:5
//
//EmployeeName: Lebron James
//Id: 1123
//SickLeave: 8.75
//Vocation: 7.5
//Unpaid:5
//
//EmployeeName: Lebron James
//Id: 1123
//SickLeave: 8.75
//Vocation: 7.5
//Unpaid:5
//
//EmployeeName: Justin bieber
//Id: 1126
//SickLeave: 8.75
//Vocation: 10
//Unpaid:10
//
//EmployeeName: Naruto Km
//Id: 100
//SickLeave: 10
//Vocation: 10.25
//Unpaid:10
//
//EmployeeName: Kim Jeong
//Id: 3311
//SickLeave: 11.25
//Vocation: 10.25
//Unpaid:10
//
//EmployeeName: JOOPER
//Id: 2002
//SickLeave: 12.5
//Vocation: 10.125
//Unpaid:10
//
//EmployeeName: KENNy D
//Id: 2019
//SickLeave: 6.875
//Vocation: 10
//Unpaid:10
//
//EmployeeName: Marshall D
//Id: 1002
//SickLeave: 5.625
//Vocation: 10.375
//Unpaid:10
//
//EmployeeName: White bread
//Id: 1111
//SickLeave: 2.875
//Vocation: 10.375
//Unpaid:10
//
//EmployeeName: Jonny Danny
//Id: 1114
//SickLeave: 7.5
//Vocation: 10.375
//Unpaid:10
//
//EmployeeName: LOVE CRAZY
//Id: 2040
//SickLeave: 8.375
//Vocation: 10.375
//Unpaid:10
