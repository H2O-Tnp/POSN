#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> sym = {"a","b","c","d","e","f"};
    while (true){
        stack<string> res;
        string in;
        int s,d;
        int b = 0;
        long long deci = 0;
        cin>>in>>s>>d;
        if(s ==0 && d==0 && in[0] == '0'){
            cout<<"BYE\n";
            return 0;
        }
        if(s < 2 || s > 16 || d < 2 || d > 16){
            cout<<"ERROR\n";
            continue;
        }
        bool re = false;
        while(!in.empty()){
            // cout<<in[in.size()-1]<<endl;
            bool Big = in[in.size()-1] >= 'A' && in[in.size()-1] <= 'F';
            bool Small = in[in.size()-1] >= 'a' && in[in.size()-1] <= 'f';

            if(Big){
                deci += (int(in[in.size()-1])-55) * pow(s,b);
                if(b==0){
                    if(int(in[in.size()-1])-55 > s){
                        cout<<"ERROR\n";
                        re = true;
                    }
                }
            }
            else if(Small){
                deci += (int(in[in.size()-1])-87) * pow(s,b);
                if(b==0){
                    if(int(in[in.size()-1])-87 > s){
                        cout<<"ERROR\n";
                        re = true;
                    }
                }
                // cout<<int(in[in.size()-1])-55<<endl;
            }
            else if(in[in.size()-1] >= '0' && in[in.size()-1] <= '9'){
                deci += (int(in[in.size()-1])-'0') *pow(s,b);
                if(b==0){
                    if(int(in[in.size()-1])-'0' > s){
                        cout<<"ERROR\n";
                        re = true;
                    }
                }
                // cout<<in[in.size()-1]<<endl;
            }
            
            else{
                cout<<"ERROR\n";
                re = true;
            }
            in.pop_back();
            b++;
        }

        if(re) continue;

        do{
            int md = deci%d;
            if(md > 9){
                res.push(sym[md-10]);
            }else{
                res.push(to_string(md));
            }
            deci/=d;
        }while(deci!=0);
        while(!res.empty()){
            cout<<res.top();
            res.pop();
        }
        cout<<'\n';
    }
}