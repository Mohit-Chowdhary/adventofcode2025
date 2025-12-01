#include <iostream>
#include <vector>
#include <string>

using namespace std;

int next_zero(int lo) {
    int z = (lo / 100) * 100;  // base multiple of 100

    // if lo is already a multiple, move to next
    if (z == lo) {
        return lo + 100;             // skip current zero
    }

    // otherwise:
    if (lo > 0) {
        if (z < lo) z += 100;         // go upward
        return z;
    } else { // lo < 0
        if (z < lo) z += 100;         
        return z;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int dail=50;
    int total=0;

    string s;
    while(cin>>s && s!="#"){
        char a = s[0];
        int b = stoi(s.substr(1));
        if(a=='L'){
            b*=-1;
        }
        int e = dail + b;
        int start = min(e,dail);
        int end = max(e,dail);
        while(next_zero(start)<end){
            total++;
            start=next_zero(start);
        }
        dail = (e%100 + 100) %100;
        if(dail==0){
            total++;
        }
    }
    cout<<"done "<<total;
    return 0;
}