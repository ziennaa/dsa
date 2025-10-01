#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    int max = ((n-m+1)*(n-m))/2;
    int q = n/m;
    int r = n%m;
    int min = (r*((q+1)*(q)/2)) + ((m-r)*((q)*(q-1)/2));
    cout<<min<<" "<<max<<"\n";
}

/*
explanation: 
Imagine a team with some number of people.

Every possible pair inside that team becomes friends.

So if a team has 2 people → those 2 become friends (1 pair).

If a team has 3 people → all pairs of those 3 become friends (3 pairs: (A,B), (A,C), (B,C)).

If a team has 4 people → 6 pairs ((A,B), (A,C), (A,D), (B,C), (B,D), (C,D)).

In general, if a team has k people, the number of friend-pairs in that team = k choose 2 = k(k-1)/2*.

Now, when the competition is over:

Each team generates friend pairs inside itself.

No friendships happen between different teams.

So the total number of friendships = sum of friend-pairs from each team.
We have:

n = total participants.

m = number of teams.

Every team must have at least 1 participant.

So, before we do anything:

Put 1 person in each team. That way, all m teams exist.

After doing that, we have used up m people.

Now, how many participants are left?

Leftover = n − m.

We can put all these leftovers into one team (to make one team as large as possible).

That one big team already had 1 person (from the "at least 1 in each team"),

plus the n − m leftover participants.

So the big team’s size = 1 + (n − m) = n − m + 1.

Suppose:

Divide n people into m teams.

Each team will have either ⌊n/m⌋ or ⌈n/m⌉ members.

Let:

q = n // m (integer division).

r = n % m (remainder).

So:

r teams will have size q+1.

m−r teams will have size q.

Then:
Minimum pairs = r * ( (q+1)q/2 ) + (m−r) * ( q(q-1)/2 )

If a team has k people → friendships = k*(k-1)/2.

Big teams = lots of pairs.

Small teams = few pairs.

So to make the minimum total friendships, we want the teams to be as equal as possible in size (so no team gets too big).

🔹 Splitting n people into m teams

When we split n people into m teams:

Some teams will have size ⌊n/m⌋ (call this q).

Some teams will have size ⌈n/m⌉ = q+1.

Specifically:

r = n % m teams get q+1 members.

The other m-r teams get q members.

This is just the standard way division works:

Example: 7 people into 3 teams → q=2, remainder r=1.

So we get teams of sizes: (3, 2, 2).
*/
