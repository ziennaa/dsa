class Solution {
    int extractnum(string g){
        int num = 0;
        for(char c: g){
            if(c>='0' && c '9'){
                num *= 10 + (c-'0');
            }
        }
        return num;
    }
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineTill(numberOfUsers, 0);
        for(int i=0; i<numberOfUsers; i++){
            if(events[i][0] == "MESSAGE"){
                if(events[i][2] == "ALL"){
                    mentions[i]++;
                }else if(events[i][2] == "HERE"){
                    if(offlineTill[events[i][2]] > events[i][2]){
                        mentions[i]++;
                    }
                }else{
                    numbe = extractnum(events[i][2]);
                    mentions[numbe]++;
                }
            }else if(events[i][0] == "OFFLINE"){
                offlineTill[events[i][2]] = events[i][1];
            }
        }
        return mentions;
    }
};


class Solution {
    int extractnum(string g){
        int num = 0;
        for(char c: g){
            if(c>='0' && c<= '9'){
                num = num *10 + (c-'0');
            }
        }
        return num;
    }
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineTill(numberOfUsers, 0);
        for(int i=0; i<events.size(); i++){
            string type = events[i][0];
            int times = stoi(events[i][1]);
            string op = events[i][2];
            if(type == "OFFLINE"){
                int id = stoi(op);
                offlineTill[id]=times+60;
            }else if(type == "MESSAGE"){
                if(op == "ALL"){
                    for(int j=0; j<numberOfUsers; j++){
                        mentions[j]++;
                    }
                }else if(op == "HERE"){
                    for(int j=0; j<numberOfUsers; j++){
                        if(times>=offlineTill[j]){
                            mentions[j]++;
                        }
                    }
                }else{
                    stringstream ss(op);
                    string t;
                    while(ss>>t){
                        int id = extractnum(t);
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};

above code failing at tc
Wrong Answer
52 / 673 testcases passed
submitted at Dec 13, 2025 02:41

Editorial
Input
numberOfUsers =
3
events =
[["MESSAGE","2","HERE"],["OFFLINE","2","1"],["OFFLINE","1","0"],["MESSAGE","61","HERE"]]

Use Testcase
Output
[2,1,2]
Expected
[1,0,2]


this works
class Solution {
    int extractnum(string g){
        int num = 0;
        for(char c: g){
            if(c>='0' && c<= '9'){
                num = num *10 + (c-'0');
            }
        }
        return num;
    }
    struct m{
        int to;
        int kind; // offline 0 message 1 offline first on ties
        string op; // for offline user id as string and for message mentions string
    };
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<m> mstruc;
        mstruc.reserve(events.size());
        for(auto &e : events){
            m x;
            x.to = stoi(e[1]);
            x.kind = (e[0] == "OFFLINE") ? 0: 1;
            x.op = e[2];
            mstruc.push_back(move(x));
        }
        sort(mstruc.begin(), mstruc.end(), [](const m&a, const m&b){
            if(a.to != b.to) return a.to < b.to;
            return a.kind < b.kind;
        });
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineTill(numberOfUsers, 0);
        for(auto &e: mstruc){
            //string type = events[i][0];
            int times = e.to;
            string op = e.op;
            if(e.kind == 0){
                int id = stoi(op);
                offlineTill[id]=times+60;
            }else{
                if(op == "ALL"){
                    for(int j=0; j<numberOfUsers; j++){
                        mentions[j]++;
                    }
                }else if(op == "HERE"){
                    for(int j=0; j<numberOfUsers; j++){
                        if(times>=offlineTill[j]){
                            mentions[j]++;
                        }
                    }
                }else{
                    stringstream ss(op);
                    string t;
                    while(ss>>t){
                        int id = extractnum(t);
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};


/*

explanation
 sort(mstruc.begin(), mstruc.end(), [](const m&a, const m&b){
            if(a.to != b.to) return a.to < b.to;
            return a.kind < b.kind;
        });

without this we're getting WA
    sorting is important here
sorting happens by
1. earlier timestamps first
2. same timestamp -> offline first so kind=0 and then message 
" status change is processed before handling any message at the same timestamp"
    so for case this
    
    numberOfUsers = 3
events =
[
 ["MESSAGE","2","HERE"],
 ["OFFLINE","2","1"],
 ["OFFLINE","1","0"],
 ["MESSAGE","61","HERE"]
]

    

process by time, and for same time: OFFLINE first.

So reorder by time:
t=1: OFFLINE user0 → offlineUntil[0] = 1+60 = 61
t=2: OFFLINE user1 → offlineUntil[1] = 2+60 = 62
t=2: MESSAGE "HERE"
t=61: MESSAGE "HERE"

Now simulate:
Initially: all online (offlineUntil = [0,0,0])
After t=1 OFFLINE 0: offlineUntil = [61,0,0]
At t=2 OFFLINE 1: offlineUntil = [61,62,0]
At t=2 HERE: online iff t >= offlineUntil[u]

user0: 2 >= 61  offline
user1: 2 >= 62 offline
user2: 2 >= 0 online
So only user2 gets +1 → mentions = [0,0,1]

At t=61 HERE:
user0: 61 >= 61 online again (back exactly at 61)
user1: 61 >= 62 still offline

user2:  online
So user0 and user2 get +1 → mentions = [1,0,2]
That matches Expected = [1,0,2].

    my prev code failed cuz

 process in input order:
t=2 MESSAGE HERE happens first → you count all 3 as online → mentions becomes [1,1,1]
then t=2 OFFLINE 1
then t=1 OFFLINE 0 (too late, you already processed messages at later times!)
t=61 HERE adds to user0 and user2 → final [2,1,2]


    */
