//
//  main.cpp
//  LAB216 November  2
//
//  Created by Sitthiphol Yuwanaboon on 11/2/20.
//

#include <iostream>
using namespace std;
class test{
    int value;

public:
   int  getValue(){return value;}
    void setValue(int v){value= v;}
};


class intArray{
private:
    int* aPtr;
    int arraySize;
public:
    intArray(int size, int value);
    void print();
    void setValue(int value);
    //overlaod copy constructor
    intArray(const intArray& exiArray);
    //overload assignment statement
    //void operator = (const intArray& rightArray);
    intArray operator = (const intArray& rightArray);
    
};
intArray intArray::operator=(const intArray &rightArray){

    if (arraySize > 0)
        delete [] aPtr;
    arraySize= rightArray.arraySize;
    aPtr =new int [arraySize];
    for(int i = 0; i < arraySize; i++){
        aPtr[i]=rightArray.aPtr[i];
    }
    return *this;
}

intArray::intArray(const intArray & exiArray){
    arraySize = exiArray.arraySize;
    aPtr= new int [arraySize];
    for(int i = 0; i < arraySize; i++)
        aPtr[i] = exiArray.aPtr[i];

}



intArray::intArray(int size, int value){
    arraySize = size;
    aPtr= new int[arraySize];
    setValue(value);
}
void intArray:: print() {
    for (int i = 0; i< arraySize;i++)
    cout << aPtr[i]<< " ";
    cout << endl;
}

void intArray::setValue(int value){
    for(int i= 0; i<arraySize;i++)
    aPtr[i]= value;
    
}

int main() {
    
    test t1;
    t1.setValue(10);
    test t2 = t1;
    
    cout << t1.getValue()<< endl;
    cout << t2.getValue()<< endl;
    
    t1.setValue(19);
    
    cout << t1.getValue()<< endl;
    cout << t2.getValue()<< endl;
    
    cout<< "--------------------------------" << endl;
    
    
    
    intArray intArray1(5,10);
    intArray intArray2= intArray1; //copy array1 object of class to object of array2
    intArray1.print();
    intArray2.print();
    
    cout << "-------" << endl;
    
    intArray2.setValue(20);
    
    intArray1.print();
    intArray2.print();
    
    cout << "------------------------------" << endl;
    
    
    intArray intArray3 (5,11);
    intArray1.print();
    intArray3.print();
    cout << "----------" << endl;
    intArray3 = intArray1;
    
    intArray1.print();
    intArray3.print();
    cout << "----------" << endl;
    intArray1.setValue(13);
    intArray1.print();
    intArray3.print();
    
    cout << "==========================" << endl;
    
    int a,b,c;
    a = b = c =10;
    cout << a << " "<< b << " " << c << endl;
    
    cout << "==========================" << endl;

    intArray3=intArray1= intArray2;
    
    intArray1.print();
    intArray2.print();
    intArray3.print();
    
    return 0;
}

/*
 10
 10
 19
 10
 --------------------------------
 10 10 10 10 10
 10 10 10 10 10
 -------
 10 10 10 10 10
 20 20 20 20 20
 ------------------------------
 10 10 10 10 10
 11 11 11 11 11
 ----------
 10 10 10 10 10
 10 10 10 10 10
 ----------
 13 13 13 13 13
 10 10 10 10 10
 ==========================
 10 10 10
 Program ended with exit code: 0
*/
