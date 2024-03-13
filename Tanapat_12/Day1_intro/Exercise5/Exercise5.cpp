#include <bits/stdc++.h>
using namespace std;
int main()
{
    float num1, num2, num3;
    cout << "Enter 1st number :: ";
    cin >> num1;
    cout << "Enter 2nd number :: ";
    cin >> num2;
    cout << "Enter 3rd number :: ";
    cin >> num3;
    cout << "The SUM of 3 Number [ " << num1 << " + " << num2 << " + " << num3 << " ] = " << num1 + num2 + num3 << endl;
    cout << "The AVERAGE of 3 Number [ " << num1 << "," << num2 << "," << num3 << " ] = " << (num1 + num2 + num3) / 3;
}