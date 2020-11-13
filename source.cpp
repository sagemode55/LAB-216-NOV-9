#include<iostream>
#include "cellPhone.h"
using namespace std; 
int genID(){
    int temp;
    // static int phone_id {0};
    static int phone_id =0; // it keeps its values in between the call
    // int phone_id{0};
    return ++phone_id;
}
int cellPhone :: count{ 0 };
int cellPhone ::publicCount{ 0 };

int main(){
    
    for(int i = 0; i < 10; i++){
        cout << "new ID" << genID()<< endl;
    }
    cellPhone phoneA;
    phoneA.setBrandName("Iphone");
    phoneA.setColor ("Grey");
    phoneA.setSeries("XI");
    phoneA.setYear(2020);
    cout << "Public count = " << cellPhone :: publicCount <<endl;
    cout << "Count = " << phoneA.getCount() << endl;
    
    
    cellPhone phoneB ("Sumsung","Yellow","X",2020);
    cellPhone phoneC ("Zenphone", "Grey", "XP", 2019);
    cellPhone PhoneD("Iphone");
    cellPhone phoneF("Nokia","Blue");
    

    
    cout << "Public count = " << phoneA.publicCount <<endl;
    cout << "Count = " << phoneA.getCount() << endl;
    
    
    // the above call will be called by complier as setYear(& phoneA, 4)
    // therefore void setYaer(in y){year= y}will be like 
    // void setYear( cellPhone * const this, int y){this->year= y;}
    // The this prinetg is a hidden const pointer that holds
    // The address of the object the member function was called on. 
   phoneA.myprint();
    phoneA.myprint();
    phoneB.myprint();
    phoneC.myprint();    
    PhoneD.myprint();
    phoneF.myprint();
    
    return 0; 

}
/*
new ID1                                                                                                                       
new ID2                                                                                                                       
new ID3                                                                                                                       
new ID4                                                                                                                       
new ID5                                                                                                                       
new ID6                                                                                                                       
new ID7                                                                                                                       
new ID8                                                                                                                       
new ID9                                                                                                                       
new ID10                                                                                                                      
Public count = 1                                                                                                              
Count = 1                                                                                                                     
Public count = 3                                                                                                              
Count = 3  
----------------------------                                                         
brandname = Iphone                                                                   
Series = XI                                                                          
Color = Grey                                                                         
Year = 2020                                                                          
----------------------------                                                         
brandname = Iphone                                                                   
Series = XI                                                                          
Color = Grey                                                                         
Year = 2020                                                                          
----------------------------                                                         
brandname = Sumsung                                                                  
Series = X                                                                           
Color = Yellow                                                                       
Year = 0                                                                             
----------------------------                                                         
brandname = Zenphone                                                                 
Series = XP                                                                          
Color = Grey                                                                         
Year = 0                                                                             
----------------------------                                                         
brandname = Iphone                                                                   
Series =                                                                             
Color =                                                                              
Year = 4200909                                                                       
----------------------------    
brandname = Nokia                                                                    
Series =                                                                             
Color = Blue                                                                         
Year = 4197152                                                                       
inside destructor.                                                                   
inside destructor.                                                                   
inside destructor.                                                                   
inside destructor.                                                                   
inside destructor.  */
