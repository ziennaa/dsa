from collections import Counter
def sub(s, t):
    i =0
    for c in t:
        if i <len(s) and s[i]==c:
            i +=1
    return i==len(s)
def solve(s, t, p):
    if not sub(s, t):
        return "NO"
    countt =Counter(t)               
    countsp =Counter(s)+Counter(p)  
    for char in countt:
        if countt[char] > countsp.get(char, 0):
            return "NO" 
    return "YES"
q=int(input())
for _ in range(q):
    s =input().strip()
    t =input().strip()
    p =input().strip()
    print(solve(s, t, p))
