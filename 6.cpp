#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    string s;
    vector<vector<ll>> digits;
    vector<ll> result;

    ll sum=0;

    vector<string> input;
    while(getline(cin,s) && s!="$"){
        input.push_back(s);
    }
    for(int i=0;i<input.size()-1;i++){
        vector<ll> row;

        stringstream ss(input[i]);
        ll x;
        while(ss>>x){
            row.push_back(x);
        }
        digits.push_back(row);
    }
    int j=0;

    for(char c:input[input.size()-1]){
        if(c == '+'){
            for(int i=0;i<digits.size();i++){
                sum+=digits[i][j];
            }
            j++;
        }
        if(c == '*'){
            ll mul = 1;
            for(int i=0;i<digits.size();i++){
                mul*=digits[i][j];
            }
            sum+=mul;
            j++;
        }
    }

    cout<<"total ans is "<<sum;
}