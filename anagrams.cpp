/*Q. Given 2 strings check if they're "Anagram" 
  Amagram : 2 strings are anagrams we can rearrange 1 string to make it same as other
s1 = " a b c d a b a"
s2 = " c b d a a a b"

  sol: 
create freq array of both of size 2*10^-6
  count and store freq of alphabets in both string in an array
compare freq array of both string if same -> anagram
TC: O(N)*/

#include <bits/stdc++.h>
using namespace std;
#define DELTA 1000000
int freq1[2000100]; // freq array for s1
int freq2[2000100]; // freq array for s2
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if(s1.size()!=s2.size()){
        cout<<"Not Anagram\n";
        return 0;
    }
    for(char c: s1){
        freq1[c + DELTA]++;
    }
    for(char c: s2){
        freq2[c + DELTA]++;
    }
    bool isAnagram = true;
    for(int i=0; i<2000100; i++){
        if(freq1[i]!=freq2[i]){
            isAnagram = false;
            break;
        }
    }
    if(isAnagram){
        cout<<"Anagram\n";
    }else{
        cout<<"not anagram\n";
    }
}
