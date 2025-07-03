class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> freqs;
        map<char, int> freqt;
        for(char c: s){
            freqs[c]++;
        }
        for(char c: t){
            freqt[c]++;
        }
        if(freqs.size()==freqt.size()){
            return true;
        }else{
            return false;
        }
    }
};

// question says all occurences must be replaced and this doesnt count it

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> freqs;
        map<char, char> freqt;
        for(int i=0; i<s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];
            if(freqs.count(c1)){
                if(freqs[c1]!=c2) return false;
            }else{
                freqs[c1] = c2;
            }
            if(freqt.count(c2)){
                if(freqt[c2]!=c1) return false;
            }else{
                freqt[c2] = c1;
            }
        }
        return true;
    }
};

// here were creating 2 maps
/*
map is of char and char so that we can track string s to string t
and string t to string s
then we iterate over the length 
we see if the string s char occurs in map if not add it
if yes see if character of string s is equal to character of string t
if not then false 
cuz thats what all weve to see
do the same with string t
*/
