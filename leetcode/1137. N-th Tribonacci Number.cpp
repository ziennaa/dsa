int trifib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    else{
        return trifib(n-2)+trifib(n-1)+trifib(n-3);
    }

}
class Solution {
public:
    int tribonacci(int n) {
        return trifib(n);
    }
};

/// tle here!!!!!!

class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        int fib = 0;
        if(n==0) return a;
        if(n==1) return b;
        if(n==2) return c;
        for(int i=3; i<=n; i++){
            fib = a+b+c;
            a = c;
            c = b;
            b = fib;
        }
        return b;
    }
};
