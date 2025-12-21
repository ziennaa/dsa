// Basic Sieve Code
const int N = 1e7;
bool is_prime[N+1];

void sieve() {
    for(int i = 2; i <= N; i++) is_prime[i] = 1;
    
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = 2*i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

// Optimised Sieve Code
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i<=n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=1LL*i*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

//Thus, the final complexity is O(N log log N).
