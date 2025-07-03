/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int c = guess(mid);
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
                k = mid;
                break;
            }
        }
        return k;
    }
};

/*
simple binary search sol

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        int mid = low + (high-low)/2;
        int c = guess(mid);
        while(low<high){
            mid = low + (high-low)/2;
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
                k = c;
            }
        }
        return k;  
    }
};

getting tle here
but getting tle here too

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        while(low<high){
            int mid = low + (high-low)/2;
            int c = guess(mid);
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
               return mid;
            }
        }
    }
};

getting tle here too
class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        int mid = low + (high-low)/2;
        int c = guess(mid);
        while(low<high){
            mid = low + (high-low)/2;
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
                k = c;
            }
        }
        return k;  
    }
};

getting tle here
but getting tle here too

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        while(low<high){
            int mid = low + (high-low)/2;
            int c = guess(mid);
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
               return mid;
            }
        }
    }
};



failing at this testcase
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        while(low<high){
            int mid = low + (high-low)/2;
            int c = guess(mid);
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
                k = mid;
                break;
            }
        }
        return k;
    }
};


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
/*

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        while(low<high){
            int mid = low + (high-low)/2;
            int c = guess(mid);
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
                k = mid;
                break;
            }
        }
        return k;
    }
};

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
/*
class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        int k=0;
        while(low<high){
            int mid = low + (high-low)/2;
            int c = guess(mid);
            if(c == -1){
                high = mid-1;
            }else if(c == 1){
                low = mid+1;
            }else{
                k = mid;
                break;
            }
        }
        return k;
    }
};

fails here
n =
1
pick =
1
Output
0
Expected
1


 first few times it failed cuz you were returning c which return 0,1,-1 so obviously wrong
second time cuz low<=high */
