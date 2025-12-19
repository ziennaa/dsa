// understood but need to do these topics

class Solution {
    bool cmp(const vector<int>& meetinga, const vector<int>& meetingb){
        if(meetinga[2] != meetingb[2]){
            return meetinga[2] < meetingb[2];
        }
        return meetinga[0] < meetingb[0];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // sorting meetings by time need to use a comparator here DONE
        // maintaining knowSecret[0 to n-1] bool or 0/1 thing DONE
        vector<int> knowssecret(n);
        sort(meetings.begin(), meetings.end(), 
        [this](const vector<int>& a,
                const vector<int>& b) {
                return cmp(a, b);
                }
        );
        knowssecret[0] = 1;
        knowssecret[firstPerson] = 1;
        int i = 0;
        int m = meetings.size();
        while(i<m){
            int time = meetings[i][2];
            unordered_map<int, vector<int>> adj;
            unordered_set<int> people;
            while(i<m && meetings[i][2] == time){
                int x = meetings[i][0];
                int y= meetings[i][1];
                adj[x].push_back(y);
                adj[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }
            queue<int> q;
            unordered_set<int> visited;
            for(int p: people){
                if(knowssecret[p]){
                    q.push(p);
                    visited.insert(p);
                }
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v: adj[u]){
                    if(!visited.count(v)){
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            for(int p: visited){
                knowssecret[p] = 1;
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(knowssecret[i]) ans.push_back(i);
        }
        return ans;

        // t = meetigs[i][2]
        // collecting meetings with same time range
        // adjacency list of people with same time range
        // running dfs/bfs
        // those true or 1 return

    }
};
