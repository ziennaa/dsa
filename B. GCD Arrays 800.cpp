#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r,k;
        cin>>l>>r>>k;
        if(l==r){
            if(l==1){
                cout<<"NO\n";
                continue;
            }else{
                cout<<"YES\n";
                continue;
            }
        }
        int total = r-l+1;
        int oddcount = total/2;
        if(l%2==1 && r%2==1){
            oddcount++;
        }
        if(oddcount<=k){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

/*
2 numbers
  remove both
insert their prodcut
goal : gcd>1
  so to get this every number in the array must be having a common factor 
now odd numbers gcd mostly 1
  so an idea that if we can remove all odd and its count would be less than equla to k i.e the no of operations then yes otherwise no
also if l==r only 1 number
if that 1 number is 1 then no
otherwise that number itself
pseodocode

input t
while(T--)
  input l,r,k;
  if l==r:
      if l==1:
          print no
          continue
      else 
          print yes
          continue
  int total = l-r+1
  int odd = total/2
  if(l odd and r odd)
    odd++;
  if(odd<=k)
    print yes
else 
    print no
*/
