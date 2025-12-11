class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int k = buildings.size();
        if(k<5) return 0;
        vector<int> minx(n+1, n+1);
        vector<int> miny(n+1, n+1);
        vector<int> maxx(n+1, 0);
        vector<int> maxy(n+1, 0);
        for(auto it: buildings){
            int x = it[0];
            int y = it[1];
            minx[y] = min(minx[y], x);
            miny[x] = min(miny[x], y);
            maxx[y] = max(maxx[y], x);
            maxy[x] = max(maxy[x], y);
        }
        int total = 0;
        for(auto it: buildings){
            int x=it[0];
            int y=it[1];
            if(minx[y]<x && x<maxx[y] && miny[x]<y && y<maxy[x]){
                total++;
            }
        }
        return total;
    }
};
