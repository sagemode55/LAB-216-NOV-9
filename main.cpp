//
//  main.cpp
//  newlab november 9
//
//  Created by Sitthiphol Yuwanaboon on 11/2/20.
//

#include <iostream>
using namespace std;
class dist{
private:
    
    int meter;
    int kMeter;
    void simplify();
    
public:
    dist(int k = 0 , int m = 0){
        kMeter = k;
        meter= m;
    }
    void setDist(int k , int m){
        kMeter= k;
        meter= m;
        
    }
    
    /*friend bool operator>(const dist& leftDist, const dist & rightDist);
    friend bool operator<(const dist& leftDist, const dist & rightDist);
    friend bool operator>=(const dist& leftDist, const dist & rightDist);
    friend bool operator<=(const dist& leftDist, const dist & rightDist);
    friend bool operator==(const dist& leftDist, const dist & rightDist);
    friend bool operator!=(const dist& leftDist, const dist & rightDist);
    */
    bool operator > (const dist& rightDist)const;
    
    bool operator < (const dist& rightDist)const;
    
    bool operator >= (const dist& rightDist)const;
    
    bool operator <= (const dist& rightDist)const;
    
    bool operator == (const dist& rightDist)const;
    
    bool operator != (const dist& rightDist)const;
    
    
    // *=
    // -=
    // /=
    // %=
    // >>
    //--i
    //i--

    dist operator *=(const int n);
    dist operator -=(const int n);
    dist operator /=(const int n);
    dist operator %=(const int n);
    
    friend dist operator--(dist& d, int u);
    friend dist operator--(dist& d);
    
    void print();
    int getMeter()const{return meter;}
    int getKMeter()const{return kMeter;}
    
    dist operator += (const int n);
    //friend dist operator +(const dist& , const dist& );
    dist operator+ (const dist&)const;
                
    friend ostream& operator << (ostream& stream, const dist&);
    friend istream& operator >> (istream& stream,  dist& d);
    
    //const dist & operator = (const dist&);
    //dist operator++(int);
    friend dist operator++(dist& d, int u);
   friend dist operator++(dist& d);
};
// *=
// -=
// /=
// %=
// >>
//--i
//i--


istream& operator >> (istream& stream, dist & d){
    
    
    stream >> d.kMeter;
    cout << " Kmeter ";
    stream >> d.meter;
    cout << " meter" << endl;
    return stream;
}




dist operator--(dist& d, int u){
    dist dd = d;
    d.meter--;
    d.simplify();
    return dd;
}
dist operator--(dist& d){
    
    --d.meter;
    d.simplify();
    return d;
}


dist dist::operator*=(const int n ){
    meter*=n;
    simplify();
    return *this;
    
}
dist dist::operator-=(const int n ){
    meter-=n;
    simplify();
    return *this;
    
}
dist dist::operator/=(const int n ){
    meter/=n;
    simplify();
    return *this;
    
}
dist dist::operator%=(const int n ){
    meter%=n;
    simplify();
    return *this;
    
}

/*bool operator>(const dist& leftDist, const dist& rightDist)
 {
     if (leftDist.kMeter > rightDist.kMeter)
         return true;
     if (leftDist.kMeter == rightDist.kMeter && leftDist.meter > rightDist.meter)
         return true;
     return false;
 }

 bool operator<(const dist& leftDist, const dist& rightDist)
{
    if (leftDist.kMeter < rightDist.kMeter)
        return true;
    if (leftDist.kMeter == rightDist.kMeter && leftDist.meter < rightDist.meter)
        return true;
    return false;
}
bool operator>=(const dist& leftDist, const dist& rightDist)
{
    if (leftDist.kMeter >= rightDist.kMeter)
        return true;
    if (leftDist.kMeter == rightDist.kMeter && leftDist.meter >= rightDist.meter)
        return true;
    return false;
}

bool operator<=(const dist& leftDist, const dist& rightDist)
{
    if (leftDist.kMeter <= rightDist.kMeter)
        return true;
    if (leftDist.kMeter == rightDist.kMeter && leftDist.meter <= rightDist.meter)
        return true;
    return false;
}

bool operator==(const dist& leftDist, const dist& rightDist)
{
    if (leftDist.kMeter == rightDist.kMeter&& leftDist.meter == rightDist.meter)
        return true;
    else
    return false;
}
bool operator!=(const dist& leftDist, const dist& rightDist)
{
    if (leftDist.kMeter != rightDist.kMeter&& leftDist.meter != rightDist.meter)
        return true;
    else
    return false;
}
*/



bool dist::operator > (const dist& rightDist)const{
    if(kMeter> rightDist.kMeter)
        return true;
    else if(kMeter==rightDist.kMeter&&meter>rightDist.meter)
        return true;
    else
        return false;
}
bool dist::operator == (const dist& rightDist)const{
    if(kMeter==rightDist.kMeter&&meter==rightDist.meter)
        return true;
    else
        return false;
}
bool dist::operator < (const dist& rightDist)const{
    if(kMeter< rightDist.kMeter)
        return true;
    else if(kMeter==rightDist.kMeter&&meter<rightDist.meter)
        return true;
    else
        return false;
}
bool dist::operator >= (const dist& rightDist)const{
    if(kMeter>= rightDist.kMeter)
        return true;
    else if(kMeter==rightDist.kMeter&&meter>=rightDist.meter)
        return true;
    else
        return false;
}
bool dist::operator <= (const dist& rightDist)const{
    if(kMeter<= rightDist.kMeter)
        return true;
    else if(kMeter==rightDist.kMeter&&meter>rightDist.meter)
        return true;
    else
        return false;
}
bool dist::operator != (const dist& rightDist)const{
    
    if(kMeter!=rightDist.kMeter&&meter!=rightDist.meter)
        return true;
    else
        return false;
}


// *=
// -=
// /=
// %=
// >>
//--i
//i--



dist operator++(dist& d, int u){
    dist dd = d;
    d.meter++;
    d.simplify();
    return dd;
}
dist operator++(dist& d){
    
    ++d.meter;
    d.simplify();
    return d;
}
/*dist dist:: operator++(int u){ //postfix
    dist d(kMeter,meter);
    // dist d = * this; // same as above line
    meter++;
    simplify();
    return d;
}*/

ostream& operator << (ostream& stream, const dist & d){
    stream << d.kMeter << "K meter and " << d.meter << " meter";
    return stream;
}





dist dist::operator+(const dist &rightDis)const{
        dist d;
        d.meter = meter+rightDis.meter;
        d.kMeter = kMeter+rightDis.kMeter;
        d.simplify();
    return d;
    }
                   
/*dist operator +(const dist& d1, const dist& d2){
    dist d;
    d.meter = d1.meter+d2.meter;
    d.kMeter = d1.kMeter+d2.kMeter;
    d.simplify();
    return d;
}*/


dist dist::operator+=(const int n ){
    meter+=n;
    simplify();
    return *this;
    
    
}


void dist::simplify(){
    meter = 1000 * kMeter+ meter;
    kMeter = meter/1000;
    meter= meter % 1000;
}


void dist::print(){
    cout << kMeter << " kmeter and " << meter <<" meter" <<  endl;
}











int main() {
    
    
    dist d1(2,900);
    dist d2(1,999);
    dist d3,d4;
    d4 =d3;
    
    d1.print();
    d2.print();
    d3.print();
    d4.print();
    
    cout << "------overload +--------="<< endl;
    d1 += 999;
    
    d1.print();
    
    d3 =d1+d2;
    d3. print();
    cout << d3 << endl;
    d4= d3++;
    d3++;
    d3++;
    cout << d3 << endl;
    
    dist d5(2, 900);
    dist d6(3,200);
    
   if(d6>d5)
       cout << "d6 greater d5" << endl;
    else
       cout << "d5 is greater than d6" << endl;
    
    dist d7(3,1);
    dist d8 (3,1);
    dist d9(4,500);
    
    if(d7==d8)
        cout << "d7 is equal d8" << endl;
     else
        cout << "d7 is not equal to d8" << endl;
     
    if(d7!=d8)
        cout << "d7 is not equal d8" << endl;
     else
        cout << "d7 is equal d8" << endl;
    
    if (d9 >= d8)
        cout << "d9 greater d8" << endl;
    else
        cout << "d9 is less than d 8 " << endl;
    
    if (d9<=d8)
        cout << "d9 is less than d 8 " << endl;
    else
        cout<< "d9 greater d8" << endl;
    if (d9<d8)
        cout << "d9 is less than d 8 " << endl;
    else
        cout<< "d9 greater d8" << endl;
    
    dist d10(3,11);
    dist d11(4,12);
    
    if(d10!=d11)
        cout << "d10 is not equal d11" << endl;
     else
        cout << "d10 is equal d11" << endl;
    
   
    
    d10 += 10;
    
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    d10 /=2;
    
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    d10*=4;
    
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    d10-=200;
    
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    d10 %=10;
    
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    
    --d10;
    
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    d10--;
  
    cout <<"D_10 is equal to = "<< d10 << endl;
    
    d11++;
    cout <<"D_11 is equal to = "<< d11 << endl;
    
    d11++;
    cout <<"D_11 is equal to = "<< d11 << endl;
    
    d11++;
    cout <<"D_11 is equal to = "<< d11 << endl;
    
    ++d11;
    cout <<"D_11 is equal to = "<< d11 << endl;
    
    
    
    return 0;
}

/*
 2 kmeter and 900 meter
 1 kmeter and 999 meter
 0 kmeter and 0 meter
 0 kmeter and 0 meter
 ------overload +--------=
 3 kmeter and 899 meter
 5 kmeter and 898 meter
 5K meter and 898 meter
 5K meter and 901 meter
 d6 greater d5
 d7 is equal d8
 d7 is equal d8
 d9 greater d8
 d9 greater d8
 d9 greater d8
 d10 is not equal d11
 D_10 is equal to = 3K meter and 21 meter
 D_10 is equal to = 3K meter and 10 meter
 D_10 is equal to = 3K meter and 40 meter
 D_10 is equal to = 2K meter and 840 meter
 D_10 is equal to = 2K meter and 0 meter
 D_10 is equal to = 1K meter and 999 meter
 D_10 is equal to = 1K meter and 998 meter
 D_11 is equal to = 4K meter and 13 meter
 D_11 is equal to = 4K meter and 14 meter
 D_11 is equal to = 4K meter and 15 meter
 D_11 is equal to = 4K meter and 16 meter
 Program ended with exit code: 0
 */
