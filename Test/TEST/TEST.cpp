#include <iostream>
#include <string>

using namespace std;

int mult(int a, int b)
{
    int result;

    if (b == 1) return (a);
    else
    {
        result = mult(a, (b - 1))     + a;
        return result;
    }
}

int main()
{
    /* string test
    string words;
    words = "Tasty";
    string s1 = "hot", s2 = "dog";
    string food = s1 + s2; // food = "hotdog"
    words += food; // words now = "Tasty hotdog"
    cout<<words;
    */
    int num = 8;
    string ch;
    ch = 'G';
    //    for(int i=0;i<2;i++){
    //     cout<<i<<' '<<ch[i]<<endl;
    //    }
    cout << '\0';
    cout<<mult(5,4);
}