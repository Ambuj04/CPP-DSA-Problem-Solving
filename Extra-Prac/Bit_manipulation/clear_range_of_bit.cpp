#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 42, left = 2, right = 5; // 1-based
    // create sequence of required one's then right shift into correct position then do negation for 0 . Then & which clear the range of bits

    int mask = ~(((1 << (right - left + 1)) - 1) << (left - 1));
    int result = num & mask;

    cout << result; // 32
}