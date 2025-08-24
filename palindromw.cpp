/*to check if a string is a palindrome or not

case1: string == reverse of string
if true then yes palindrome else no

case2: check if the given string can be made into a palindrome
count freq of each element
all frequency must be even except 1 thqat should be one

a b b a n=2 i.e even
a b c b a = 3
case 2: works for case1 too*/

  case1
  bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

case2:
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

bool canFormPalindrome(string s) {
    int freq[256] = {0};  // assuming ASCII chars
    for (char c : s) freq[c]++;

    int oddCount = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) oddCount++;
    }

    // If oddCount <= 1, palindrome formation possible
    return oddCount <= 1;
}

int main() {
    string s;
    cin >> s;

    if (isPalindrome(s)) {
        cout << "Yes, already a Palindrome\n";
    } else if (canFormPalindrome(s)) {
        cout << "No, but can be rearranged into a Palindrome\n";
    } else {
        cout << "No, cannot be a Palindrome\n";
    }

    return 0;
}
