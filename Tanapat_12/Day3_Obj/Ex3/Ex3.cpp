#include <bits/stdc++.h>
using namespace std;
class Fraction
{
private:
    int num = 0;
    int denom = 1;
public:
    Fraction(int n,int d);
    Fraction(){};
    void setFraction(int n,int d);
    void getFraction(int &n,int &d);
    int getNum();
    int getDenom();
    Fraction add(Fraction other);
    Fraction sub(Fraction other);
    Fraction mul(Fraction other);
    Fraction div(Fraction other);
    bool isEqualTo(Fraction other);
    void print();
    string str();

    Fraction lowest_fraction(Fraction frac);
};
Fraction::Fraction(int n,int d)
{
    num = n;
    denom = d;
};
void Fraction::setFraction(int n,int d){
    num = n;
    denom = d;
}
void Fraction::getFraction(int &n,int &d){
    n = num;
    d = denom;
}
int Fraction::getNum(){
    return num;
}
int Fraction::getDenom(){
    return denom;
}
Fraction Fraction::add(Fraction other){
    Fraction res;
    res.num = (num*other.denom) + (other.num*denom);
    res.denom = denom*other.denom;
    int resgcd = __gcd(res.num,res.denom);

    return lowest_fraction(res);
}
Fraction Fraction::sub(Fraction other){
    Fraction res;
    res.num = (num*other.getDenom()) - (other.getNum()*denom);
    res.denom = denom*other.getDenom();
    
    return lowest_fraction(res);
}
Fraction Fraction::mul(Fraction other){
    Fraction res;
    res.num = num*other.num;
    res.denom = denom*other.denom;

    return lowest_fraction(res);
}
Fraction Fraction::div(Fraction other){
    Fraction res;
    res.num = num*other.denom;
    res.denom = denom*other.num;

    return lowest_fraction(res);
}
bool Fraction::isEqualTo(Fraction other){
    if(num == other.num && denom == other.denom){
        return true;
    }else{
        return false;
    }
}
void Fraction::print(){
    cout<<getNum()<<'/'<<getDenom();
}
string Fraction::str(){
    return to_string(getNum()) + '/' + to_string(getDenom());
}

Fraction Fraction::lowest_fraction(Fraction frac){
    int resgcd = __gcd(frac.getNum(),frac.getDenom());
    frac.num /= resgcd;
    frac.denom /= resgcd;
    return frac;
}

int main() {
    Fraction f1(2,3),f2(4,7),f3,f4;
    int x,y;
    f2.getFraction(x,y);
    f3.setFraction(x,y);
    f4=f3.mul(f1);
    f1.print(); cout<<" x ";
    f3.print(); cout<<" = ";
    f4.print(); cout<<endl;
    Fraction *f5=new Fraction(1,2);
    cout<<f4.str()+" / "+f5->str();
    cout<<" = "+f4.div(*f5).str()+"\n";
    if(f2.isEqualTo(f3))
    cout<<"Equal.\n";
    else
    cout<<"Not equal.\n";
}