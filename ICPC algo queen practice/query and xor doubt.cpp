/*You have initially an array A of N elements. You have to perform Q queries on this array. The queries are of the following type:

L R X: For each i such that L <= i <= R, change the value of A[i] to A[i] = A[i] & X, i.e., A[L] = A[L] & X, A[L+1] = A[L+1] & X, ... A[R] = A[R] & X. And print the bitwise XOR of the entire array, i.e. A[1]⊕A[2]⊕A[3]...⊕A[N].
Print the result of each query.

Here ⊕ means Bitwise XOR operation and & means Bitwise AND operation.

Constraints
1 <= N <= 10^5
1 <= Q <= 10^5
0 <= X < 2^20
1 <= L <= R <= N
0 <= A[i] < 2^20
Subtasks
Subtask #1 (25 points): N <= 1000 and Q <= 1000.
Subtask #2 (75 points): original constraints.

Input Format
First line contains a single integer N.
Second line contains N space seperated integers - array A.
Third line contains a single integer Q.
Each of the next Q lines contains 3 space separated integers, which represents a query L R X.
Output Format
Print the result of each query on a new line.
Sample 0
Input
6
2 7 5 4 1 0
2
3 5 3
2 6 0
Output
5
2
Explanation
Initally, the array is 2 7 5 4 1 0 After the first query,

A[3] = 5&3 = 1
A[4] = 4&3 = 0
A[5] = 1&3 = 1
Hence, the array becomes 2 7 1 0 1 0

The answer to the first query is thus 2⊕7⊕1⊕0⊕1⊕0 = 5

After the second query,

A[2] = 7&0 = 0
A[3] = 1&0 = 0
A[4] = 0&0 = 0
A[5] = 1&0 = 0
A[6] = 0&0 = 0
Hence, the array becomes 2 0 0 0 0 0

The answer to the second query is thus 2⊕0⊕0⊕0⊕0⊕0 = 2*/ // doubt 
