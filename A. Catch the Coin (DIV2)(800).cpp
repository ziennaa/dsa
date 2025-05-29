#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n<1 || n>500) return 0;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        if(x>50 || y>50 || x<-50) cout<<"NO\n";
        if(y<-1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}

/*
EXPLANATION:
🍬 Example: Coin starts at y = –2
You’re at y = 0.
It’s already below you.

Let’s try:

Second 1:
You take 1 step → maybe now you're at y = –1.

Coin falls down → now it's at y = –3.
Oops! Too far! ❌

Second 2:
You take 1 more step → maybe y = –2.

Coin falls again → now y = –4.
Still too far! ❌

The coin keeps falling, and you can’t catch up. It started too low.

🟢 But if the coin starts at y = –1 or higher…
Then it hasn’t fallen too far yet.

Example: Coin starts at y = 2
You take steps up, and it falls down.

You: 1 step up → y = 1

Coin: falls to y = 1 → 🎉 you meet it and catch it!

Okay, let’s drop all the formulas and look at it as a simple “vertical gap” game, round by round. We’ll ignore 
𝑥
x for now—just focus on how far above or below the coin is.

🎈 Vertical-gap chase
You start at height 
0
0.

Coin starts at height 
𝑦
y.

Each second:

You move up or down by 1 (your choice).

Then the coin falls by 1 (always down).

Define the gap 
𝑔
g as

𝑔
=
(
coin’s height
)
−
(
your height
)
.
g=(coin’s height)−(your height).
If 
𝑔
>
0
g>0, the coin is above you.

If 
𝑔
<
0
g<0, the coin is below you.

You catch the coin exactly when 
𝑔
=
0
g=0 right after your move (before the fall).

What happens to 
𝑔
g each round?
You move one step toward the coin.

If the coin is above (
𝑔
>
0
g>0), you go up → you reduce 
𝑔
g by 1.

If the coin is below (
𝑔
<
0
g<0), you go down → you increase 
𝑔
g by 1 (because negative gap gets less negative).

Coin falls one step (always down).

That increases 
𝑔
g by 1 (makes “coin minus you” one larger).

Net change in the gap 
𝑔
g
Case A: coin above you (
𝑔
>
0
g>0)

You step up → 
𝑔
g goes down by 1.

Coin falls → 
𝑔
g goes down by 1 again.

Net: 
𝑔
g decreases by 2 per second.

So if 
𝑦
y is 
+
10
+10, after 1s gap=8, after 2s gap=6, … in 5s gap=0 → you catch it.

Case B: coin exactly 1 below you (
𝑔
=
−
1
g=−1)

You step down → 
−
1
+
1
=
0
−1+1=0. You’ve already caught it before the coin falls!

(We don’t even need the fall.)

Case C: coin 2 or more below you (
𝑔
≤
−
2
g≤−2)

You step down → gap goes up by 1 (e.g. from –2 to –1).

Coin falls → gap goes down by 1 (back to –2).

Net: gap stays stuck at –2 (or whatever it started), round after round. You never close it to 0, so you never meet.

The “magic” cutoff at 
𝑦
=
−
1
y=−1
If the coin starts above you (
𝑦
>
0
y>0), it’s Case A → gap shrinks by 2 each second → eventually hits 0 → catch.

If it starts exactly one below (
𝑦
=
−
1
y=−1), it’s Case B → you step down once and immediately gap=0 → catch.

If it starts two or more below (
𝑦
≤
−
2
y≤−2), it’s Case C → gap never changes overall → no catch.

That is why every coin with 
𝑦
≥
−
1
y≥−1 (i.e. starting at or above one step below you) is catchable, and every coin with 
𝑦
<
−
1
y<−1 is not. 🎉






You said:
and what if its +9


ChatGPT said:

Thought for 9 seconds
Let’s run the same “gap” story when the coin starts 9 steps above you (i.e. 
𝑦
=
+
9
y=+9, gap 
𝑔
=
9
g=9):

🎈 Gap updates each second
Start: gap 
𝑔
=
9
g=9.

Each second:

You move toward the coin (up): 
𝑔
g goes down by 1.

Coin falls: 
𝑔
g goes down by 1 again.

So net per full second:

𝑔
  
⟶
  
𝑔
−
2.
g⟶g−2.
📉 Gap timeline
Second	Before your move	After your move	Catch check?	After coin falls
0	9	(you move → 8)	no (8≠0)	→ 7
1	7	(move → 6)	no (6≠0)	→ 5
2	5	(move → 4)	no (4≠0)	→ 3
3	3	(move → 2)	no (2≠0)	→ 1
4	1	(move → 0)	✓ yes!	(would fall to –1, but you’ve caught it)

On the 5th move (second “4” if you start counting from 0), right after you step up, the gap becomes 0, meaning you land exactly where the coin is before it falls.

You catch it at that moment, and the game ends.

🧸 Bottom line
Any positive gap (coin above you) shrinks by 2 each round → eventually hits 0 → you catch it.

Starting at +9, gap sequence goes: 9→7→5→3→1→(you move)→0 → catch on the 5th step.

So yep—if the coin starts 9 units above, you absolutely will catch it (in 5 seconds).





You said:
i meant to say im at 0 and coin at +9


ChatGPT said:

Thought for 5 seconds
Got it—let’s do the “gap chase” again for coin at +9 (you at 0). We track the gap 
𝑔
=
(coin height)
−
(your height)
g=(coin height)−(your height).

Initial state
You at 0, coin at 9 → gap 
𝑔
=
9
g=9.

Each second:

You step toward the coin (up): gap – 1.

Coin falls one step: gap – 1 again.

You check for catch right after your step, before the fall.

Step-by-step
Second	Start 
𝑔
g	After your move 
(
𝑔
−
1
)
(g−1)	Catch?	After coin falls 
(
𝑔
−
2
)
(g−2)
1	9	8	No (8≠0)	7
2	7	6	No (6≠0)	5
3	5	4	No (4≠0)	3
4	3	2	No (2≠0)	1
5	1	0	Yes! (0=0)	— (we caught it)

At second 5, right after your 5th step up, the gap hits 0 → you’re exactly where the coin is before it would fall again. You catch it.

Intuition
A positive gap shrinks by 2 every full second (–1 when you move, –1 when it falls).

Starting at 
+
9
+9, it takes 
⌈
9
/
2
⌉
=
5
⌈9/2⌉=5 moves to bring that gap down to 0 during your move.

As soon as that happens, you and the coin coincide, and you grab it.

No formulas—just “gap shrinks by 2 per round, catch when gap = 0 right after your move.”



*/

