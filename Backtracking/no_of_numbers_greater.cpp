#Question Description
/*
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
Input Format :
Integer n
Output Format :
Count of greater numbers
Sample Input :
122
Sample Output :
2
*/

#Algorithm
/*
So here we are given just the number. We will need to calculate permutions based on frequencies. Hence we need factorials and frequencies.
1. Number of digits in num=n.
2. Store the digits in array format (here we'll use deque because it helps to access digits in same format as given num.
3. We'll create a frequency vector "freq" which will store frequency of each digit.
4. We'll create another vector fact which will store factorials till n.
5. Now we'll call a helper function "solve" which will calculate the number of greater numbers.
6. First we pass the entire num (we'll pass the deque) and then we'll check all the digits which are greater than the 1st digit (at index 0) because this will
help us directly calculate number of numbers greater than original number using math as when these greater digits are appearing at index 0, then number which
will be formed will obviously be greater than original number.
7. Next we need to calculate count when the index 0 digit is unchanged (for eg if we have 1223, then when "1" is fixed, we can have 1322, 1232 etc as greaternumbers).
8. So we'll recursively call the function and we'll remove the index 0 digit and pass the rest.
*/
#Solution
#include <bits/stdc++.h>
using namespace std;

long solve(deque<int> &number, vector<int> &freq, vector<int> &fact, int n){
    if(n==0 || n==1){
        return 0;
    }
    long ans=0;
    long den=1;
    for(int i=0;i<10;i++){
        den*=fact[freq[i]];
    }
    for(int i=number[0]+1;i<10;i++){
        ans+=(fact[n-1]*freq[i])/den;
    }
    freq[number[0]]--;
    number.pop_front();
    ans+=solve(number,  freq, fact, n-1);
    
    return ans;
}

long numberOfNumbersWithDuplicates(long num){
    int n=0;
    long temp=num;
    while(temp!=0){
        n++;
        temp/=10;
    }
	vector<int> freq(10,0);
    vector<int> fact(n+1);
    deque<int> number;
    fact[0]=1;
    int i=0;
    while(num!=0){
        int temp=num%10;
        number.push_front(temp);
        freq[temp]++;
        fact[i+1]=(i+1)*fact[i];
        i++;
        num/=10;
    }
    long ans=solve(number, freq, fact, number.size());
    
    return ans;
}
