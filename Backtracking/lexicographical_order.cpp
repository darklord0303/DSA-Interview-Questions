#Question Description
/*
Given a number n, print numbers from 1 to n in dictionary(lexicographical) order.
Sample Input
20
Sample Output
1
10
11
12
13
14
15
16
17
18
19
2
20
3
4
5
6
7
8
9
*/

#Algorithm
/*
We are given number n till which we need to print. So we'll start with 1.
1. We'll call solve() function to print the values and initially we'll pass 1 to it to start.
2. Base Case: if passed value k>n, return.
3. We'll print current number and call solve for k*10 (because if we have given initially 1, and lets say n=200, then 1->10->100 will come before 2.)
4. Once we come at a point where k%10==0 meaning we have explored all numbers starting with same digit. Hence we'll return there as well.
*/
#Solution

#include <iostream>
using namespace std;
void solve(int n, int k){
    if(k>n){
        return;
    }
    for(int i=0;i<10;i++){
        if(k<=n){
            cout<<k<<endl;
            solve(n, k*10);
            k++;
            if(k%10==0)return;
        }
    }
}

void lexicographicalOrder(int num){
	solve(num, 1);
}
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}
