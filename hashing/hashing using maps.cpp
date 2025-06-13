// we've 2 sets of maps
// ordered and unordered maps
// maps are better than arrays cuz arrays requires tons of space and we've designate them before taking in any
// action however in maps we can directly use maps and they're or spaces or value is stored at time itself

/*THERE ARE 3 HASHING METHODS 
  1. DIVISION METHOD
  2. FOLDING METHOD
  3. MID SQUARE METHOD*/
  
// ordered maps
// in all cases time complexity is O(logn) i.e basically the number of elements
// o(logn) for best worst and avg
// if i print this it will be ordered therefore ordered map
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    } 
    map <int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[a[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
}
// this was ordered
// however in unordered time complexity is 0(1) in best and average and most of the cases
// however sometime tc becomes o(N) and that is the worst case it happens basically at the time of collision 
/*
ive an unordered map of 
 1 4 5 10 13 12 14 16 18 28
  and maybe say that whatever it can store values up to 10 only
  soo we made this thing
a%m=h1
  b%m=h2
  so say
1%10= 1
  so if we see
1 stores 1
  4 stores 4, 14
  5 stores 5
  0 stores 10
  3 stores 13
  2 stores 12
  6 stores 16
  8 stores 18,28

  SO we see 4 is storing 2 
8 is storing 2 
how is this even posibble???
  THIS IS COLLISON 
  (IN ORDER TO TAKE OUT NUMBERS LIKE 18,28 AND 4,14 we make a chain ig and make linked list something like that not sure yet)
what is collison??? every value went to same hash
and this is what we call WORST CASE O(N)*/

/// SYNTAX OF UNORDERED MAP
unordered_map<int, int> mpp;
key can be anything singular like not arrays vectors stuff but like other data primitive ig
