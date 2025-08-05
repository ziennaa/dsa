class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;
        for(auto fruit : fruits){
            int unset = 1;
            for(int i=0; i<n; i++){
                if(fruit <= baskets[i]){
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            unplaced += unset;
        }
        return unplaced;
    }
};

/*
int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    int unplaced = 0; // count of unplaced fruits

    for(auto fruit : fruits){   // iterate over each fruit type
        int unset = 1;          // assume this fruit is unplaced (1 = unplaced, 0 = placed)
        for(int i=0; i<n; i++){ // check each basket from left to right
            if(fruit <= baskets[i]){  // if basket has enough capacity
                baskets[i] = 0;       // mark basket as used (capacity 0 means taken)
                unset = 0;            // fruit successfully placed
                break;                // stop searching for this fruit
            }
        }
        unplaced += unset; // if unset=1, fruit was unplaced → increase counter
    }
    return unplaced;
}*/
