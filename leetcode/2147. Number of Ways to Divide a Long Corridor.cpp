class Solution {
public:
    int numberOfWays(string corridor) {
        int scount = 0;
        for(char c: corridor){
            if(c=='S'){
                scount++;
            }
        }
        long long mod = 1e9+7;
        if(scount<2) return 0;
        if(scount == 2) return 1;
        if(scount % 2 != 0) return 0;
        int sc = 0;
        long long div = 1;
        int pc = 0;
        for(int i=0; i<corridor.size(); i++){
            if(corridor[i]=='S'){
                if(sc == 2){
                    div = (div*(pc+1))%mod;
                    pc = 0;
                    sc = 1;
                }else{
                    sc++;
                }
            }else{
                if(sc == 2) pc++;
            }
        }
        return div;
    }
};
