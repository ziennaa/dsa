class Solution {
    bool valid_code(string g){
        if(g == ""){
            return false;
        }else{
            for(char it : g){
                if(!(isalnum(it) || it == '_')){
                    return false;
                }
            }
        }
        return true;
    }
    bool valid_businessLine(string m){
        if(m != "electronics" && m!="grocery" && m!="pharmacy" && m!="restaurant"){
            return false;
        }
        return true;
    }
    bool validity(string k, string l, bool activity){
        if(valid_code(k) && valid_businessLine(l) && activity){
            return true;
        }
        return false;
    }
    unordered_map<string, int> rank = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
    bool cmp(const pair<string, string>& a, const pair<string, string>& b){
        if(rank[a.first] != rank[b.first]){
            return rank[a.first] < rank[b.first];
        }
        return a.second<b.second;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> ans;
        //vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        //unordered_map<string, int> rank = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
        //for(int i=0; i<order.size(); i++){
        //    rank[order[i][0]] = i;
        //}
        for(int i=0; i<n; i++){
            if (!(validity(code[i], businessLine[i], isActive[i]))){
                continue;
            }else{
                auto p = lower_bound(ans.begin(), ans.end(), make_pair(businessLine[i], code[i]),
                // lowerbound figures out 1st position where coupon should go
                // ans always sorted 
                [this](const pair<string,string>& a,
                const pair<string,string>& b) {
                return cmp(a, b);
                }
                );
                ans.insert(p, {businessLine[i], code[i]});
            }
        }
        vector<string> res;
        for (auto &x : ans) {
            res.push_back(x.second);
        }
        return res;
    }
};
