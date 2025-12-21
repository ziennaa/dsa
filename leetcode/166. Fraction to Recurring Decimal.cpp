// Fraction to Recurring Decimal
// LeetCode
// Number of companies: 11
class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        string ans = "";
        if(n == 0){
            ans += "0";
            return ans;
        }
        if((n<0)^(d<0)){
            ans += "-";
        }
        n = llabs(n);
        d = llabs(d);
        //if(n == 0){
        //    ans += "0";
        //    return ans;
        //}
        if(d == 1){
            ans += to_string(n);
            return ans;
        }
        int q = n/d;
        int r = n%d;
        ans += to_string(q);
        if(r == 0){
            return ans;
            //continue;
        }else{
            ans += ".";
            string dec = "";
            vector<int> pos(d, -1);
            while(r!=0 && pos[r]==-1){
                pos[r] = (int)dec.size();
                r*=10;
                int digit = r/d;
                dec.push_back(char('0'+digit));
                r %= d;
            }
            if(r == 0){
                ans += dec;
                return ans;
            }else{
                int start = pos[r];
                ans+=dec.substr(0, start);
                ans+="(";
                ans+=dec.substr(start);
                ans+=")";
            }
        }
        return ans;
    }
};
// this was causing mle cause of vector pos
// changed to unordered_map then
class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        string ans = "";
        if(n == 0){
            ans += "0";
            return ans;
        }
        if((n<0)^(d<0)){
            ans += "-";
        }
        n = llabs(n);
        d = llabs(d);
        //if(n == 0){
        //    ans += "0";
        //    return ans;
        //}
        if(d == 1){
            ans += to_string(n);
            return ans;
        }
        long long q = n/d;
        long long r = n%d;
        ans += to_string(q);
        if(r == 0){
            return ans;
            //continue;
        }else{
            ans += ".";
            string dec = "";
            //vector<int> pos(d, -1);
            unordered_map<long long, long long> pos;
            while(r!=0 && pos.count(r) == 0){
                pos[r] = (int)dec.size();
                r*=10;
                int digit = r/d;
                dec.push_back(char('0'+digit));
                r %= d;
            }
            if(r == 0){
                ans += dec;
                return ans;
            }else{
                int start = pos[r];
                ans+=dec.substr(0, start);
                ans+="(";
                ans+=dec.substr(start);
                ans+=")";
            }
        }
        return ans;
    }
};
