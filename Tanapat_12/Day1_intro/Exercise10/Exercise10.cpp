#include <iostream>
using namespace std;
int main()
{
    cout << "Enter Marks of Student\n\n";
    int x, sum = 0;
    cout << "Thai:";
    cin >> x;
    sum += x;
    cout << endl
         << endl;
    cout << "English:";
    cin >> x;
    sum += x;
    cout << endl
         << endl;
    cout << "Math:";
    cin >> x;
    sum += x;
    cout << endl
         << endl;
    cout << "History:";
    cin >> x;
    sum += x;
    cout << endl
         << endl;
    cout << "Science:";
    cin >> x;
    sum += x;
    cout << endl
         << endl;

    float avg = (sum * 1.0) / 5;
    cout << "Average Marks = \n"
         << avg;
    cout << "Percebtage = " << avg << " %";
}