/*
Brute Force means:
Try all possible solutions (even if it’s slow),
until you find the correct answer
It's the most basic, direct, and usually slowest method to solve a problem.
When to Use Brute Force?Use brute force when:
You’re stuck and want to just get any working solution
Input size is small (like n <= 10)
You're trying to understand the problem first
Then you optimize later.
  */
// eg
// TXT="AABAACAADAABAABA"
// PATTERN = "AABA"
// pattern is found at 0, 9 and 12th index
// so your outer loop runs from n-m : n is txt length and m is pattern length so its runnin till 12th
// inner loop runs from m so till 4

#include <bits/stdc++.h>
using namespace std;
void patternsearch(string text, string pat){
  int n = text.length();
  int m = pat.length();
  for(int i=0; i<n-m; i++){
    int j;
    for(j=0; j<m; j++){
      if(text[i+j]!=pat[j]){
        break;
      }
      if(j==m){
        cout<<"pattern found at index"<<i<<endl;
      }
    }
  }
}
int main(){
  string text="";
  string pat="";
  patternsearch(string text, string pat);
  return 0;
  }
