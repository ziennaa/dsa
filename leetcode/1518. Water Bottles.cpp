class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        while(numBottles>=numExchange){
            numBottles = numBottles - numExchange + 1;
            count++;
            
        }
        return count;
    }
};

// earlier did numBottles>1
// but you can only exchange when youve enough numExchange
// so its numBottles>=numExchange
