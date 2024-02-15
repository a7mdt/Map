#include "bits/stdc++.h"
using namespace std;

// This is how to make a rule to print ur map. => mTemp1,mTemp2 .
template<typename type>
struct comp
        {
    bool operator()(const type &first , const type &second)const
    {
        return first > second;
    }
        };

int main()
{
    // Part2 :

    cout<<"Map before my printing rule : "<<endl;
    map<int,string>mTemp1;
    mTemp1[1] = "Menna";
    mTemp1[2] = "Ahmed";
    mTemp1[5] = "Tarek";
    mTemp1[3] = "Mohamed";
    mTemp1[4] = "Mahmoud";
    for(auto mT : mTemp1)
        cout<<mT.first<<" -> "<<mT.second<<endl;

    cout<<"-----------\n";

    cout<<"Map after my printing rule : "<<endl;
    map<int,string,comp<int>>mTemp2;
    mTemp2[1] = "Menna";
    mTemp2[2] = "Ahmed";
    mTemp2[5] = "Tarek";
    mTemp2[3] = "Mohamed";
    mTemp2[4] = "Mahmoud";
    for(auto mT : mTemp2)
        cout<<mT.first<<" -> "<<mT.second<<endl;

    cout<<"----------------------------\n";

    // Frequancy app -> How many times u type an item :

    // 1:
    cout<<"1) How many times u type an item? [arrays] : \n"<<endl;
    int arr1[] = {1,1,2,3,4,3,2,4,1,2,
                 5,6,8,7,6,3,5,5,2,
                 9,4,2,3,1,2,3,9};
    int n = sizeof(arr1)/sizeof(arr1[0]); // Sizeof() returns Bytes.
    sort(arr1,arr1+n);
    int frq1 = 1;
    for(int i=0;i<n;i++)
    {
        if(arr1[i]==arr1[i+1])
            frq1++;
        else
        {
            cout<<arr1[i]<<" -> "<<frq1<<" times\n";
            frq1=1;
        }
    }

    cout<<"----------------------------\n";

    // 2:
    cout<<"2) How many times u type an item? [arrays] : "<<endl<<endl;
    cout<<"Enter ur Size : ";
    int t;
    cin>>t;
    int arr2[100];
    int frq2[100] = { 0 };
    cout<<"Enter ur Values : "<<endl;
    for(int i=1;i<=t;i++)
    {
        cin>>arr2[i];
        frq2[arr2[i]]++;
    }
    sort(arr2,arr2+n);
    cout<<"---------\n";
    for(int i=1;i<=t;i++)
    {
        if(arr2[i]!=arr2[i+1])
            cout<<arr2[i]<<" -> "<<frq2[arr2[i]]<<" times\n";
    }

    cout<<"----------------------------\n";

    // 3: =. Here u don't have to sort.
    cout<<"3) How many times u type an item? [maps] : "<<endl<<endl;
    map<int,int>m;
    cout<<"Enter ur Size : ";
    int s;
    cin>>s;
    cout<<"Enter ur Values : "<<endl;
    for(int i=0;i<s;i++)
    {
        int mm;
        cin>>mm;
        m[mm]++; // We increment the keys.
    }
    cout<<"---------\n";
    for(auto item : m)
        cout<<item.first<<" -> "<<item.second<<" times\n";

    return 0;
}
