#include <bits/stdc++.h>
using namespace std;
struct Country
{
    string countryName;
    string countryCode;
    map<int,long long int> yearPopulation;

    string toString(const Country& country){
        string ans = "";
        ans += country.countryName;
        ans += " (";
        ans += country.countryCode;
        ans += "): ";
        for(auto i : yearPopulation){
            //cout << i.first << ' ' << i.second << endl;
            ans += to_string(i.second);
            ans += "[";
            ans += to_string(i.first);
            ans += "], ";
        }
        return ans;
    }

};
int main(){
    Country a;
    a.countryCode = "usa";
    a.countryName = "america";
    map<int, long long int> m;
    m[2000] = 50;
    m[2001] = 60;
    m[2002] = 70;
    a.yearPopulation = m;
    cout << a.toString(a) << endl;
    return 0;
}