#include <iostream>
using namespace std;
// Naned constants
const double CESTINETERS_PER_INCH = 2.54;
const int INCHES_PER_FOOT = 12;

int main()
{
     int feet, inches;
     int totalInches;
     double centimeter;
     // Statecents: Step 1 - Step 7
     cout << "Enter two integers, one for feet and "
          << "one for inches: ";
     cin >> feet >> inches;
     cout << endl;
     cout << "The numbers you entered are " << feet
          << " for feet and " << inches
          << " for inches. " << endl;
     totalInches = INCHES_PER_FOOT * feet + inches;
     cout << "The total number of inches = "
          << totalInches << endl;
     centimeter = CESTINETERS_PER_INCH * totalInches;
     cout << "The number of centimeters = "
          << centimeter << endl;
     return 0;
}