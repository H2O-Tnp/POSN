#include <iostream>
using namespace std;
void geeks()
{
    int var = 20;
    int *ptr, *ptr2;
    int val[3] = {5, 9, 12};
    ptr = &var;
    ptr2 = val;
    cout << ("Value of ptr = ") << ptr << endl;
    cout << ("Value of var = ") << var << endl;
    cout << ("Value of *ptr = ") << *ptr << endl;
    cout << "Element of the array are : ";
    cout << ptr2[0] << " " << ptr2[1] << " " << ptr2[2];
}

int main()
{
    geeks();
}
