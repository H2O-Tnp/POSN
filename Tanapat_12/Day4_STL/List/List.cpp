#include <bits/stdc++.h>
using namespace std;

void print(list<int> lst){
    for(int i:lst) cout<<i<<' ';
    cout<<endl;
}

int main()
{
    cout<< "fill(begin, end, data)\n";
    list<float> height(10);
    fill(height.begin(), height.end(), 100);
    for (float t : height)
        cout << t << " ";
    cout << endl;

    cout<< "assign(n, data)\n";
    list<double> height2;
    height2.assign(15, 100);
    for (double t : height2)
        cout << t << " ";
    cout << endl;

    cout<< "iter\n";
    list<int> lst{12, 7, 9, 21, 13, 20, 3, 44};
    print(lst);
    // list<int>::iterator iter;
    // for (iter = lst.begin(); iter != lst.end(); iter++)
    for (auto iter = lst.begin(); iter != lst.end(); iter++)
        cout << (*iter) << " ";
    cout << endl;

    cout<< "pop_front/back()\n";
    list<int> lst2{5, 7, 9, 21, 23, 27, 33, 45};
    print(lst2);
    int val = 30;
    while (lst2.size() > 0 && lst2.front() < val)
    {
        cout << lst2.front() << " ";
        lst2.pop_front();
    }
    cout << endl;

    cout<< "remove (data)\n";
    list<int> lst3{15, 45, 9, 21, 27, 23, 21, 7};
    print(lst3);
    int val2 = 21;
    lst3.remove(val2);
    print(lst3);

    cout<< "insert\n";
    list<int> lst4{5,7,9,21,23,27,33,45};
    print(lst4);
    int val3=20;
    list<int>::iterator iter;
    for(iter=lst4.begin(); (*iter) <= val3; iter++) ; //null statement
    lst4.insert(iter,val3);
    print(lst4);

    cout<< "erase\n";
    list<int> lst5{5,7,9,21,23,27,33,45};
    print(lst5);
    int val4=21;
    for(iter=lst5.begin(); (*iter)!=val4&&iter!=lst5.end(); iter++)
    ; //null statement
    if(iter!=lst5.end())
        lst5.erase(iter);
    print(lst5);

    cout<< "unique\n";
    list<int> lst6{7,7,9,21,23,23,27,33}; //sorted
    print(lst6);
    lst6.unique();
    print(lst6);

    cout<< "reverse\n";
    list<int> lst7{9,21,13,27,21,9,45,24};
    print(lst7);
    lst7.reverse();
    print(lst7);
    
    cout<< "merge\n";
    list<int> lst8{5,7,9,21,23,27,33,45}; //sorted
    print(lst8);
    list<int> lst9{1,2,19,25,29,30,44,49}; //sorted
    print(lst9);
    lst8.merge(lst9);
    print(lst8);

    cout<< "sort\n";
    list<int> lst10{9,21,13,27,21,9,45,24};
    print(lst10);
    lst10.sort();
    print(lst10);

}