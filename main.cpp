//
//  main.cpp
//  CS216 NOV 23 LAb
//
//  Created by Sitthiphol Yuwanaboon on 11/23/20.
//

#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>

using namespace std;

void printVector(vector<int>v){
   // for(int i= 0; i <v.size();i++)
    //    cout << v.at(i) <<endl;
    
   // for (int item:v)
     //   cout << item <<endl;
    
    //cout<<"-----------------------------\n";
    
    for (auto item:v)
        cout << item <<endl;
    cout<<"-----------------------------\n";
    
}

void getVector(vector<int>& v){
    for(auto& vec: v){
        int i;
        cout << "enter the value of the vector:" ;
        cin >> i;
        vec = i;
    }
}


void printList (list<string> l){
    list<string>::iterator iter;
    for (iter=l.begin(); iter!=l.end(); ++iter) {
        cout << *iter <<endl;
    }
}

int main() {
    
    vector<int> vec1(10);
    vector<int> vec2 (10,-10);
    vector<int> vec3 = {5,10,15,20};
    vector<int> vec4(3);
    vec1.at(0)=10;
    vec1.at(1)= 11;
    
    for (int i= 0; i <vec1.size();i++)
    vec1.at(i) = i+10;
    
    printVector(vec1);
    
    /*for(auto& vec: vec4){
        int i;
        cout << "enter the value of the vector:" ;
        cin >> i;
        vec = i;
    }*/
    
    printVector(vec4);
    //getVector(vec4);
    
    vec1.push_back(20);
    cout << "last element of vector is " << vec1.back() << endl;
    printVector(vec1);
    
    //popback
    
    vec1.pop_back();
    printVector(vec1);
    
    vector<int > vec11 =vec1;
    if (vec1== vec11)
        cout << "vec 1 is equal to vec 11" << endl;
    
    sort (vec1.begin(),vec1.end());
    vec1 .resize(20);
    
    
    
    /*empty();
    clear();
    .begin
    erase(i)
    insert (4 ,100)
    sorting
  */
    list<string> myList;
    myList.push_back("a");
    myList.push_back("b");
    myList.push_back("c");
    myList.push_back("c");
    myList.push_back("c");

    for (auto n:myList){
        cout << n << endl;
    }
    
    cout << "------------" <<endl;
    
    myList.push_front("z");
    
    for (auto n:myList){
        cout << n << endl;
    }
    
    cout << "------------" <<endl;
    
    cout << "front :"  << myList.front()<< endl;
    cout<< "back" << myList.back()<< endl;
    cout << "size" << myList.size()<< endl;
    
    myList.pop_back();
    for (auto n:myList){
        cout << n << endl;
    }
    
    cout << "------------" <<endl;
    
    myList.pop_front();
    
    for (auto n:myList){
        cout << n << endl;
    }
    
    cout << "------------" <<endl;
    
    myList.remove("c");
    for (auto n:myList){
        cout << n << endl;
    }
    
    cout << "------------" <<endl;
    
//    list<string>::iterator iter;
//    for (iter=myList.begin(); iter!=myList.end(); ++iter) {
//        cout << *iter <<endl;
//    }
    
    printList(myList);
    
    pair<string, double> myPair;
    myPair = make_pair("Allen", 2.9);
    myPair.second= 3.45;
    
    
    map<string,int> myMap;
    myMap.emplace("Alleen",18);
    myMap.emplace("Mary",19);
    myMap.emplace("Bob",18);
    myMap.emplace("Alleen",20);
    
    cout << myMap.at("Alleen")<< endl;
    cout << myMap.count("Alleen") <<endl;
    
    set <int> mySet;
    mySet.insert(100);
    mySet.insert(200);
    mySet.insert(300);
    mySet.insert(400);
    mySet.insert(100);
    mySet.insert(300);
    
    for (auto n:mySet){
        cout <<"Sets is "<< n << endl;
    }
   
    
    cout << "------------" <<endl;
    cout << "count 100 " << mySet.count(100) << endl;
    cout <<"count 700" << mySet.count(700) << endl;
    cout << "Size" << mySet.size() << endl;
    
    mySet.erase(100);
    
    for (auto n:mySet){
        cout <<"Sets is "<< n << endl;
    }
    
    cout << "------------" <<endl;
    
    
    queue<string> myQue;
    myQue.push("a");
    myQue.push("b");
    myQue.push("c");
    
    cout << "front " << myQue.front() << endl;
    cout << "Back"<< myQue.back() << endl;
    cout << "Size" << myQue.size() <<endl;
    
    myQue.pop();
    
    cout << "front " << myQue.front() << endl;
    cout << "Back"<< myQue.back() << endl;
    
    deque<string> myQue1;
    
    myQue1.push_front("Q");
    myQue1.push_back("a");
    myQue1.push_back("b");
    myQue1.push_back("c");
    myQue1.push_front("A");
    
    cout << "front: " << myQue1.front() << endl;
    cout << "Back: "<< myQue1.back() << endl;
    cout << "Size: " << myQue1.size() <<endl;
    cout << "-------------------------" << endl;
    
    myQue1.pop_back();
    myQue1.pop_front();
    
    cout << "front: " << myQue1.front() << endl;
    cout << "Back: "<< myQue1.back() << endl;
    cout << "Size: " << myQue1.size() <<endl;
    cout << "--------------------------" << endl;
    
    
    return 0;
}




/*
 10
 11
 12
 13
 14
 15
 16
 17
 18
 19
 -----------------------------
 0
 0
 0
 -----------------------------
 last element of vector is 20
 10
 11
 12
 13
 14
 15
 16
 17
 18
 19
 20
 -----------------------------
 10
 11
 12
 13
 14
 15
 16
 17
 18
 19
 -----------------------------
 vec 1 is equal to vec 11
 a
 b
 c
 c
 c
 ------------
 z
 a
 b
 c
 c
 c
 ------------
 front :z
 backc
 size6
 z
 a
 b
 c
 c
 ------------
 a
 b
 c
 c
 ------------
 a
 b
 ------------
 a
 b
 18
 1
 Sets is 100
 Sets is 200
 Sets is 300
 Sets is 400
 ------------
 count 100 1
 count 7000
 Size4
 Sets is 200
 Sets is 300
 Sets is 400
 ------------
 front a
 Backc
 Size3
 front b
 Backc
 front: A
 Back: c
 Size: 5
 -------------------------
 front: Q
 Back: b
 Size: 3
 --------------------------
 Program ended with exit code: 0
 */
