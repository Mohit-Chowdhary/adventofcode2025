#include <bits/stdc++.h>
using namespace std;

#define ll long long

int max(int a, int b, int c){
    return ( (a>b)?  ((a>c)? a : c) : ((b>c)? b : c) );
}

int main(){
    string s;
    ll finalsum=0;
    int m=0;
    while(cin>>s && s!="#"){
        m++;
        char prev = s[0];
        ll maxelem=0;
        for(int i=1; i<s.size();i++){
            maxelem = max( 0, 10 * (ll)(prev-'0') + (ll)(s[i]-'0'), maxelem  );
            if(s[i]>prev) prev=s[i];
        }
        //cout<<"level "<<m<<" max is "<<maxelem<<endl;
        finalsum+=maxelem;
    }
    cout<<"sum is "<<finalsum<<endl;
}