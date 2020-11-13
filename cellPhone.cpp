#include<iostream>
#include "cellPhone.h" 

using namespace std; 

void cellPhone::myprint() const {
    cout << "----------------------------" << endl;
    cout << "brandname = " << brandName << endl;
    cout << "Series = "<< series << endl;
    cout << "Color = "<< color << endl;
    cout << "Year = "<< year << endl;
}
