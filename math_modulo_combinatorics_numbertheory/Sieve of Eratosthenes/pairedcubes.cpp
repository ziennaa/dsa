#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> factorise(int x){
    vector<pair<int, int>> ans;
    for(int i=2; i*i<=x; i++){
        if(x % i == 0){
            int count = 0;
            while(x % i == 0){
                count++;
                x /= i;
            }
            ans.push_back({i, count});
        }
    }
    if(x>1) ans.push_back({x, 1});
    return ans;
}
vector<pair <int, int>> signature(int x){
    auto f = factorise(x);
    vector<pair <int, int>> s;
    for(auto [p, count] : f){
        count %= 3;
        if(count) s.push_back({p, count});
    }
    return s;
}
vector<pair<int, int>> complement(vector<pair<int, int>>& s){
    vector<pair<int, int>> c;
    for(auto [p, count]: s){
        c.push_back({p, (3-count)%3});
    }
    return c;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    map<vector<pair <int, int>>, int>  freq;
    int ans = 0;
    for(int i=0; i<n; i++){
        auto s = signature(a[i]);
        auto c = complement(s);
        ans += freq[c];
        freq[s]++;
    }
    cout<<ans<<"\n";    
}

// HARD
// OA
// Tc: O(root x) in factorise 
// per n for factorise would be O(root x)
// sign and complement O(1)
// map : o(nlogn)
// total: O(nrootn​+nlogn)
// q
/*
Paired Cubes
Solved

Time Limit : 
2 sec
Memory Limit : 
256000 MB
Description
You are given 
n
n positive integers 
A
1
,
A
2
,
…
,
A
n
A 
1
​
 ,A 
2
​
 ,…,A 
n
​
 . Your task is to find the number of pairs 
(
i
,
j
)
(i,j) such that 
A
i
×
A
j
A 
i
​
 ×A 
j
​
  is a cube number.

Input Format
The first line of input contains 
n
n - the size of the array.
The second line of input contains 
n
n space-separated integers 
A
1
,
A
2
,
…
,
A
n
A 
1
​
 ,A 
2
​
 ,…,A 
n
​
 .

Output Format
Print the answer on a new line.

Constraints
1
≤
n
≤
1
0
5
1≤n≤10 
5
 
1
≤
A
i
≤
1
0
6
1≤A 
i
​
 ≤10 
6
 

Sample Input 1
5
1 2 4 8 27
Sample Output 1
4
Note
The pairs are 
(
1
,
8
)
(1,8), 
(
2
,
4
)
(2,4), 
(
1
,
27
)
(1,27), 
(
8
,
27
)
(8,27).*/
