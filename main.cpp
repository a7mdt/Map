#include "bits/stdc++.h"
using namespace std;

int main()
{
    // Part1 :

    // Map ==> each item in it acts 2 things (Key/Value)
    // Map is Sorted. It's sorted by the Keys.
    // NOTE: Each key must have only 1 value, If u override a key u will get the new value.
    // Keys must be unique!! But if u want to use the same key u must use the (multimap) bet in this case u can't insert with random access.

    cout<<endl;
    map<int,string ,greater<int> >mm = { {123,"Ahmed"},{1234,"Tarek"},{12345,"Mohamed"} };
    cout<<"Items of Map (with greater<key>) High to Low : "<<endl;
    for(auto m : mm)
        cout<<m.first<<" - "<<m.second<<endl;
    cout<<"----------------------\n";

    map<int,string>m1 = { {123,"Ahmed"},{1234,"Tarek"},{12345,"Mohamed"} };
    // add Items :
    m1[1534]="Yasser"; // U can random access in the map.
    m1[2222]="Marawan"; // the old value.
    m1[2222]="3abas"; // the new value.
//    m1.at(1648)="Ali";
    // printing items :
    cout<<"Items of Map (without iterator) Low to High : "<<endl;
    for(auto m : m1)
        cout<<m.first<<" - "<<m.second<<endl;
    cout<<"----------------------\n";
    //printing items with iterator :
    cout<<"Items of Map (with iterator) Low to High : "<<endl;
    map<int,string>::iterator iM = m1.begin();
    for(iM ; iM!=m1.end() ; iM++)
        cout<<iM->first<<" => "<<iM->second<<endl;
    cout<<"----------------------\n";
    cout<<"Items of Map (with iterator) High to Low : "<<endl;
    map<int,string>::reverse_iterator iM1 = m1.rbegin();
    for(iM1 ; iM1!=m1.rend() ; iM1++)
        cout<<iM1->first<<" => "<<iM1->second<<endl;

    cout<<"----------------------\n";

    map<int,char>m2{{1,'A'},{2,'B'},{3,'C'}};

    // .count(key) => // it prints Bool value (if the key is exist == 1 , else == 0)
    cout<<"m2.count(4) : "<<m2.count(4)<<endl; // 0
    cout<<"m2.count(2) : "<<m2.count(2)<<endl; // 1

    cout<<"-------\n";

    // ADDING :

    // 1 :
    m2.insert({4,'D'});
    // 2 :
    m2.insert(make_pair(5,'E'));
    // 3 :
    m2.insert(pair<int,char>(6,'F'));
    // 4 :
    auto im2 = m2.begin();
    im2 = m2.insert(im2,{7,'G'});
    im2 = m2.insert(im2,{8,'H'});
    // 5 : ==> .emplace() Doesn't take iterator.
    m2.emplace(9,'I'); // its not a condition to put {}.
    // 6 : .emplace_hint() must Take iterator.
    m2.emplace_hint(im2,9,'I'); // its not a condition to put {}.
    cout<<"The Added map : "<<endl;
    for(im2=m2.begin() ; im2!=m2.end() ; im2++)
        cout<<im2->first<<" - "<<im2->second<<endl;

    cout<<"----------------------\n";

    // Deleting :

    map<int,string>m3= { {1,"AAA"},{2,"BBB"},{3,"CCC"},{4,"DDD"},
                         {5,"EEE"},{6,"FFF"},{7,"GGG"} };
    cout<<"The Deleted map before deleting : "<<endl;
    for(auto m : m3)
        cout<<m.first<<" - "<<m.second<<endl;

    cout<<"-------\n";

    m3.erase(2); // U only enter the key and it erase the value.
    auto im3 = m3.begin(); // 1
    ++++++im3; // 4
    m3.erase(im3,m3.end());
    cout<<"The Deleted map after deleting : "<<endl;
    for(im3=m3.begin();im3!=m3.end();im3++)
        cout<<im3->first<<" - "<<im3->second<<endl; // 1 3 4

    cout<<"----------------------\n";

    // .equal_range()

    map<char,int>m4 { {'A',1},{'B',2},{'C',3},{'D',4} };
    // iterator to point : ==> it must be pair (because u get 2 items -> key , value)
    pair<map<char,int>::iterator,map<char,int>::iterator>iP_AB = m4.equal_range('A'); // 1
    auto iP_CD = m4.equal_range('C'); // 2
    // 1 is the same of 2 :(

    // now FOCUS!

    //1
    cout<<"iP_AB.first->first : "<<iP_AB.first->first<<" || "<<"iP_AB.first->second : "<<iP_AB.first->second<<endl; // A || 1
    cout<<"iP_AB.second->first : "<<iP_AB.second->first<<" || "<<"iP_AB.second->second : "<<iP_AB.second->second<<endl; // B || 2
    //2
    cout<<"iP_CD.first->first : "<<iP_CD.first->first<<" || "<<"iP_CD.first->second : "<<iP_CD.first->second<<endl; // C || 3
    cout<<"iP_CD.second->first : "<<iP_CD.second->first<<" || "<<"iP_CD.second->second : "<<iP_CD.second->second<<endl; // D || 4

    cout<<"----------------------\n";

    // key_compare :

    map<char,int>m5;
    m5['A'] = 10;
    m5['B'] = 20;
    m5['C'] = 30;
    m5['D'] = 40;
    m5['E'] = 50;
    m5['F'] = 60;
    map<char,int>::key_compare comp = m5.key_comp(); // We create a ::key_compare iterator to use it.
    auto itComp = m5.begin();
    char cComp = 'D';
    cout<<"itComp->first || itComp->second : "<<endl;
    for(itComp ; comp(itComp->first , cComp) ; itComp++)
        cout<<itComp->first<<" || "<<itComp->second<<endl; // it will print items until it reach the cComp('D') => A B C

    cout<<"----------------------\n";

    // UPPER/LOWER :

    map<char,int>m6;
    m6['A'] = 10;
    m6['B'] = 20;
    m6['C'] = 30;
    m6['D'] = 40;
    m6['E'] = 50;
    m6['F'] = 60;
    m6['G'] = 70;
    auto itLow = m6.lower_bound('C');
    auto itUpp = m6.upper_bound('E');
    m6.erase(itLow,itUpp);
    cout<<"m.first || m.second (upper/lower) : "<<endl;
    for(auto m : m6)
        cout<<m.first<<" || "<<m.second<<endl;

    cout<<"----------------------\n";



    return 0;
}
