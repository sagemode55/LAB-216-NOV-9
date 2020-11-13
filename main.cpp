//
//  main.cpp
//  LAB 5 Inheritance
//
//  Created by Sitthiphol Yuwanaboon on 10/12/20.
//

#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
    string name{};
    int age{};
    //protected can be seen by class and all subclasses
protected :
    int SSN = 123456789;
    
    Person (const string& n = "", int a =0): name{ n }, age{ a }{
        
        cout << "inside constructor Person" << endl;
    }
    
    Person (int a) :age{a}{
        cout << "inside constructor Person" << endl;
        
    }
    const string & getName() const{return name;}
    int getAge() const { return age; }
    
    ~ Person(){
        cout << "inside destructor Person" << endl;
    }
};

// child derived or sub class
// child class inherits both behavior and propertires from parent



class Employee : public Person
{
public :
    double salary{};
    int empID{};
    Employee(double s =0.0, int ID = 0): salary{s}, empID{ID}{
    
        cout << "inside contructor Employee" << endl;
    // cout << "SSN = " << SSN << endl;
    }
    ~ Employee(){
        cout << "inside destructor Employee" << endl;
    }
    Employee(double s ,int id , int a ): Person{a}, salary{s}, empID{id}{
        
    }
    
    
public:
    int getSSN(){return SSN;}
    
    
};
class Student : public Person{
public:
    double gpa{};
    int stID{};
    Student(double g = 0.0 , int id = 0) : gpa{g},stID {id}
    {
        cout << "inside constructor student" << endl;
    }
    ~ Student(){
        cout << "inside destructor student" << endl;
    }
};


class Faculty : public Employee
{

public:
    string Displine{};
    string Degree{};
    
    Faculty(string dis  = "", string deg = "") : Displine{dis}, Degree{deg}{
        cout << "inside contructor Faculty" << endl;
        //cout << "SSN =" << SSN << endl;
        //cout << "Faculty SSN= " << getSSN() << endl;
    }
    ~ Faculty(){
        cout << "inside destructor Faculty" << endl;
    }

public:
    int getSSN(){
        // get parent SSN
        cout << Employee::getSSN() <<endl;
        return SSN%10000;
    }
    
};








int main() {
    
    // First the most base class at the top of the inheritance tree is contructed  first
    // then each child class is contructed in order
    
    Employee emp1;
    emp1.name ="Mary";
    emp1.age = 30;
    cout << emp1.name <<" " << emp1.age << endl;
    
    Employee emp2(1000.00,101,29);
    cout << emp2.salary<<" "<< emp2.empID <<" "<< emp2.age  <<endl;
    
    
    Faculty prof1;
    // the destrutor work the reverse order
    // cannot access protected

    //cout << "SSN =" << emp1.SSN << endl;
    
    cout << "SSN =" << emp1.getSSN() <<endl;
    cout << "Fac SSN =" << prof1.getSSN() << endl;
    
    
    
    
    return 0;
}
/*
 inside constructor Person
 inside contructor Employee
 Mary 30
 */
