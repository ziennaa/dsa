import re
s = str(input())
lis = re.findall(r'\w+|[^\w\s]', s)
h = ""
for i in range(len(lis)-1):
    if lis[i].isalnum():
        h += lis[i]
        if lis[i+1].isalnum():
            h += " "
    elif lis[i] in "?!,.":
        h += lis[i] + " "
h += lis[-1]
print(h.strip())

# now do it with cpp too
