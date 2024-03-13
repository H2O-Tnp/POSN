#include <bits/stdc++.h>
using namespace std;

bool CheckBracket(string str)
{
    size_t found_left = str.find("{");
    size_t found_right = str.find_last_of("}");
    if (found_left > str.length() && found_right > str.length())
    {
        // cannot find { }
        return true;
    }
    else if (found_left < str.length() && found_right < str.length())
    { // found { }
        str = str.substr(0, found_left) + str.substr(found_left + 1);
        size_t found_right 
        = str.find_last_of("}");
        str = str.substr(0, found_right) + str.substr(found_right + 1);
        return CheckBracket(str);
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    getline(cin, s);
    if (CheckBracket(s))
    {
        cout << "true";
    }
    else
        cout << "false";
}

/*
Hello MyDay { int x = 5+7; }
*/