#include <bits/stdc++.h>
using namespace std;

void print(stack<int> lst){
    for(int i:lst) cout<<i<<' ';
    cout<<endl;
}

int main()
{
    cout<< "fill(begin, end, data)\n";
    stack<float> height(10);
    fill(height.begin(), height.end(), 100);
    for (float t : height)
        cout << t << " ";
    cout << endl;

    cout<< "assign(n, data)\n";
    stack<double> height2;
    height2.assign(15, 100);
    for (double t : height2)
        cout << t << " ";
    cout << endl;

    cout<< "iter\n";
    stack<int> lst{12, 7, 9, 21, 13, 20, 3, 44};
    print(lst);
    // stack<int>::iterator iter;
    // for (iter = lst.begin(); iter != lst.end(); iter++)
    for (auto iter = lst.begin(); iter != lst.end(); iter++)
        cout << (*iter) << " ";
    cout << endl;

    cout<< "pop_front/back()\n";
    stack<int> lst2{5, 7, 9, 21, 23, 27, 33, 45};
    print(lst2);
    int val = 30;
    while (lst2.size() > 0 && lst2.front() < val)
    {
        cout << lst2.front() << " ";
        lst2.pop_front();
    }
    cout << endl;

    cout<< "remove (data)\n";
    stack<int> lst3{15, 45, 9, 21, 27, 23, 21, 7};
    print(lst3);
    int val2 = 21;
    lst3.remove(val2);
    print(lst3);

    cout<< "insert\n";
    stack<int> lst4{5,7,9,21,23,27,33,45};
    print(lst4);
    int val3=20;
    stack<int>::iterator iter;
    for(iter=lst4.begin(); (*iter) <= val3; iter++) ; //null statement
    lst4.insert(iter,val3);
    print(lst4);

    cout<< "erase\n";
    stack<int> lst5{5,7,9,21,23,27,33,45};
    print(lst5);
    int val4=21;
    for(iter=lst5.begin(); (*iter)!=val4&&iter!=lst5.end(); iter++)
    ; //null statement
    if(iter!=lst5.end())
        lst5.erase(iter);
    print(lst5);

    cout<< "unique\n";
    stack<int> lst6{7,7,9,21,23,23,27,33}; //sorted
    print(lst6);
    lst6.unique();
    print(lst6);

    cout<< "reverse\n";
    stack<int> lst7{9,21,13,27,21,9,45,24};
    print(lst7);
    lst7.reverse();
    print(lst7);
    
    cout<< "merge\n";
    stack<int> lst8{5,7,9,21,23,27,33,45}; //sorted
    print(lst8);
    stack<int> lst9{1,2,19,25,29,30,44,49}; //sorted
    print(lst9);
    lst8.merge(lst9);
    print(lst8);

    cout<< "sort\n";
    stack<int> lst10{9,21,13,27,21,9,45,24};
    print(lst10);
    lst10.sort();
    print(lst10);


    stack<int> lst11{9,21,13,27,21,9,45,24};
    auto it = lst11.begin();
    advance(it,3);
    cout<<*it;
}