#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Range {
    ll start, end;
};

// Convert __int128 to string for printing
string toString128(__int128 x) {
    if (x == 0) return "0";
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }

    string s;
    while (x > 0) {
        s.push_back(char('0' + (int)(x % 10)));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    vector<Range> arr;
    string token;

    // -------- INPUT PARSING --------
    while (getline(cin, token, ',')) {
        // trim
        while (!token.empty() && isspace((unsigned char)token.back())) token.pop_back();
        while (!token.empty() && isspace((unsigned char)token.front())) token.erase(token.begin());
        if (token == "#" || token.empty()) continue;

        int dash = token.find('-');
        if (dash == string::npos) continue;

        ll a = stoll(token.substr(0, dash));
        ll b = stoll(token.substr(dash + 1));
        arr.push_back({a, b});
    }
    if (arr.empty()) return 0;

    // -------- MERGE INTERVALS (CORRECT & CLEAN) --------
    sort(arr.begin(), arr.end(), [](const Range &a, const Range &b){
        return a.start < b.start;
    });

    vector<Range> merged;
    merged.push_back(arr[0]);

    for (int i = 1; i < (int)arr.size(); i++) {
        if (arr[i].start <= merged.back().end) {
            merged.back().end = max(merged.back().end, arr[i].end);
        } else {
            merged.push_back(arr[i]);
        }
    }

    // Store all unique invalid IDs
    unordered_set<ll> invalid;

    // -------- GENERAL REPEATED-PATTERN GENERATOR --------
    auto genRepeated = [&](ll L, ll R) {

        int minD = to_string(L).size();
        int maxD = to_string(R).size();

        for (int n = minD; n <= maxD; n++) {

            // find divisors of n smaller than n
            vector<int> divs;
            for (int d = 1; d < n; d++) {
                if (n % d == 0) divs.push_back(d);
            }
            if (divs.empty()) continue;

            for (int d : divs) {
                int k = n / d; // repeat count

                // Generate block ranges
                ll lower, upper;
                if (d == 1) {
                    lower = 0;
                    upper = 10;
                } else {
                    lower = 1;
                    for (int i = 1; i < d; i++) lower *= 10; // 10^(d-1)
                    upper = lower * 10;                      // 10^d
                }

                for (ll block = lower; block < upper; block++) {
                    string s = to_string(block);
                    string full;
                    full.reserve(n);
                    for (int i = 0; i < k; i++) full += s;

                    if ((int)full.size() != n) continue; // safety

                    ll num = stoll(full);
                    if (num > R) break;
                    if (num >= L) invalid.insert(num);
                }
            }
        }
    };

    // Run generator on merged intervals
    for (auto &rng : merged) {
        genRepeated(rng.start, rng.end);
    }

    // -------- SUM ALL UNIQUE VALUES --------
    __int128 sum = 0;
    for (ll v : invalid) sum += (__int128)v;

    cout << "summies " << toString128(sum) << "\n";
}
