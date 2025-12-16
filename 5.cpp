#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool bsearch(vector<pair<ll,ll>>& range, ll low, ll high, ll key){
    if(low>high) return false;

    ll mid = low + (high-low)/2;

    if(range[mid].first<= key && range[mid].second>=key){
        return true;
    }
    else if(range[mid].first>key){
        return bsearch(range,low,mid-1,key);
    }
    else{
        return bsearch(range,mid+1,high,key);
    }
}

int main(){
    string s;
    vector<pair<ll,ll>> ranges;

    while (cin >> s && s!="$") {
        size_t pos = s.find("-");
        string left  = s.substr(0, pos);
        string right = s.substr(pos + 1);

        ranges.push_back({stoll(left), stoll(right)}); 
    }

    sort(ranges.begin(), ranges.end());

    vector<pair<ll,ll>> compressed_ranges;

    compressed_ranges.push_back(ranges[0]);
    ll j = 0;

    for(int i=1;i<ranges.size();i++){
        if(compressed_ranges[j].second >= ranges[i].first){
            compressed_ranges[j].second = max(compressed_ranges[j].second, ranges[i].second);
        }
        else{
            compressed_ranges.push_back(ranges[i]);
            j++;
        }
    }

    ll num;
    ll total = 0;
    while(cin>>num && num!=-1){
        if(bsearch(compressed_ranges,0,compressed_ranges.size()-1,num)==true){
            total++;
        }
    }

    cout<<"ans is "<<total;

}
