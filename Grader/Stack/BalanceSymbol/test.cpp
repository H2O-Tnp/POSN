#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    string cop = {"({[\"\'<"};
    string cen = {")}]\"\'>"};
    while (n--) {
        stack<char> bal;
        string in;
        getline(cin, in);

        int memid;
        bool ex = false;
        bool yes = true;
        for (int idin = 0; idin < in.size(); idin++) { // string travel
            for (int idch = 0; idch < cop.size(); idch++) { // symbol
                if (in[idin] == cop[idch] && !ex) { // open
                    if (in[idin] == '\'' || in[idin] == '\"') {
                        ex = true;
                    }
                    // cout<<"Open\n";
                    bal.push(cop[idch]);
                    memid = idch;
                    break;
                } else if (in[idin] == cen[idch]) { // close
                    if (in[idin] == '\'' || in[idin] == '\"') {
                        ex = false;
                    }
                    if (bal.empty() || in[idin] != cen[memid]) {
                        cout << "NO\n";
                        idin = in.size();
                        yes = false;
                        break;
                    } else {
                        bal.pop();
                        if (!bal.empty()) memid = cop.find(bal.top());
                        break;
                    }
                }
            }
        }
        if (bal.empty() && yes) {
            cout << "YES\n";
        } else if (!bal.empty() && yes) {
            cout << "NO\n";
        }
    }
    return 0;
}