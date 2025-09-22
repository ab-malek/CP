#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;
using u128 = unsigned __int128;

// Convert signed __int128 to string
string to_string128(i128 x) {
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    string s;
    do {
        int digit = x % 10;
        s.push_back('0' + digit);
        x /= 10;
    } while (x > 0);
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

// Convert unsigned __int128 to string
string to_string128(u128 x) {
    string s;
    do {
        int digit = x % 10;
        s.push_back('0' + digit);
        x /= 10;
    } while (x > 0);
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    i128 a = (i128)1e18;   // 1,000,000,000,000,000,000
    i128 b = (i128)1e18;
    i128 c = a * b;        // 1e36

    cout << "a = " << to_string128(a) << "\n";
    cout << "b = " << to_string128(b) << "\n";
    cout << "a * b = " << to_string128(c) << "\n";

    u128 d = (u128)1 << 100;  // 2^100
    cout << "2^100 = " << to_string128(d) << "\n";
}
