### Travel Pass | Problem Code: TRAVELPS | CodeChef September Long Challenge

- Chef is going on a road trip and needs to apply for inter-district and inter-state travel e-passes. It takes A minutes to fill each inter-district e-pass application and B minutes for each inter-state e-pass application. His journey is given to you as a binary string S of length N where 0 denotes crossing from one district to another district (which needs an inter-district e-pass), and a 1 denotes crossing from one state to another (which needs an inter-state e-pass). Find the total time Chef has to spend on filling the various forms.

#### Input Format
- The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
- Each test case contains two lines of input.
- First line contains three space separated integers N,A and B.
- Second line contains the string S

### Output Format
- For each testcase, output in a single line the total time Chef has to spend on filling the various forms for his journey.

### Sample Input
3 <br/>
2 1 2 <br/>
00 <br/>
2 1 1 <br/>
01 <br/>
4 2 1 <br/>
1101 <br/>

### Sample Output
2 <br/>
2 <br/>
5 <br/>

### Explanation
- **Test case 1:** Chef needs total 2 inter-district e-passes, and he will be filling them in total 1⋅2=2 minutes.
- **Test case 2:** Chef needs total 1 inter-district e-pass and 3 inter-state e-passes, and he will be filling them in total 2⋅1+1⋅3=5 minutes.

