### Travel Pass | Problem Code: MAXARXOR | CodeChef Starters 07

-Value of an array A of length L is defined as the sum of (Ai⊕i) for all 0≤i<L, where ⊕ denotes bitwise xor operation. Note that array indices start from zero.

You are given an integer N and an array A consisting of 2N integers where Ai=i for all 0≤i<2N.

### Example
-For N=1, you have an array A of length 21=2 and A=[0,1].
-For N=2, you have an array A of length 22=4 and A=[0,1,2,3].
-You can do at most K operations on this array. In one operation, you can choose two indices i and j (0≤i,j<2N) and swap Ai and Aj (i.e. Ai becomes Aj and vice versa).

**What is the maximum value of array A you can obtain after at most K operations?**

#### Input Format
- First line will contain T, number of testcases. Then the testcases follow.
- Each testcase contains a single line of input, two integers N,K

### Output Format
- For each testcase, output in a single line the maximum value of array after doing at most K operations.


### Constraints
1. 1≤T≤10^5
2. 1≤N≤30
3. 0≤K≤109

### Sample Input
3 <br/>
2 0 <br/>
2 1 <br/>
10 100 <br/>


### Sample Output
0 <br/>
6 <br/>
204600 <br/>


### Explanation
- **Test case 1:** , for N=2, you have the array A=[0,1,2,3]. No swap operation is allowed hence value of array A=(0⊕0)+(1⊕1)+(2⊕2)+(3⊕3)=0+0+0+0=0.

- **Test case 2:**initially the array A=[0,1,2,3]. If you swap A1 and A2, A becomes [0,2,1,3]. Now value of array A=(0⊕0)+(2⊕1)+(1⊕2)+(3⊕3)=0+3+3+0=6. There is no possible way such that value of array A becomes greater than 6 using one swap operation.

