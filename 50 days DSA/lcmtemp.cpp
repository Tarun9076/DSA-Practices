#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    ll a, b;
    cin >> a >> b;

    ll gcd = std::gcd(a, b);

    ll lcm = (a / gcd) * b;

    cout << "GCD: " << gcd << '\n';
    cout << "LCM: " << lcm << '\n';

    return 0;
}