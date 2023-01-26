// Day 19 coding Date-22.01.2023

// Ques No. 1 Fibonacci Number
// Ques Blog - https://leetcode.com/problems/fibonacci-number/solutions/1159784/easy-solution-w-multiple-approaches-explained/
// Ques Link - https://leetcode.com/problems/fibonacci-number/
// Ques Solution - https://www.youtube.com/watch?v=Za2To2Qix0E&ab_channel=AyushiSharma

// Approach 1: 
// Brute Force using Recursion 
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

int fib(int n){
    if(n <=1)return n;
    return fib(n-1)+fib(n-2);
}

// Approach 1:
// Memoization using DP
// Time Complexity : O(N) Space Complexity : O(N)

int fib(int n){
    int dp[n+1];
    if(n<=1){
        return n;
    }
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=n;++i){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// Approach 3:
// DP space Optimsation
// Time Complexity : O(N) Space Complexity : O(1)

int fib(int n){
    int prev1 = 1;
    int prev2 = 0;
    for(int i = 2;i<=n;++i){
        int curi = prev1+prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    if(n<=1)return n;
    return prev1;
}

// Approach 4: (Most Optimised)
// Using Math formula
// Time Complexity : O(logN) Space Complexity : O(1)

int fib(int n){
    double phi = (sqrt(5)+1)/2;
    return round(pow(phi,n)/sqrt(5));
}

// Ques No. 2  Min Cost Climbing Stairs
// Ques Blog - https://leetcode.com/problems/min-cost-climbing-stairs/solutions/1193197/java-all-3-approach/
// Ques Blog2 - https://leetcode.com/problems/min-cost-climbing-stairs/solutions/2260986/recursion-memoization-tabulation-space-optimization/
// Ques Link - https://leetcode.com/problems/min-cost-climbing-stairs/
// Ques Solution - https://www.youtube.com/watch?v=kLCGmZGtImM&ab_channel=AyushiSharma

// Approach 1: (TLE)
// Brute Force using Recursion
// Time Complexity : O(2^N) Space Complexity : O(1) RSS(O(N))

int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    return min(helper(cost,n-1),helper(cost,n-2));
}
int helper(vector<int> & nums,int i){
    if(i<=1) return nums[i];
    int pick = helper(nums,i-1);
    int notpick = helper(nums,i-2);
    return min(pick,notpick)+nums[i];
}

// Approach 2:
// Memoization using Dp
// Time Complexity : O(N) Space Complexity : O(N) RSS(O(N))

int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n+1,-1);
    return min(helper(cost,n-1,dp),helper(cost,n-2,dp));
}
int helper(vector<int> & arr,int i ,vector<int> & dp){
    if(i<=1) dp[i] = arr[i];
    if(dp[i] != -1) return dp[i];
    int pick = helper(arr,i-1,dp);
    int notpick = helper(arr,i-2,dp);
    return dp[i] = min(pick,notpick)+arr[i];
}

// Approach 3:
// Tabulation using Dp
// Time Complexity : O(N) Space Complexity : O(N)

int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n+1);
    for(int i =2;i<=n;++i){
        int firstJump = dp[i-1]+cost[i-1];
        int secondJump = dp[i-2]+cost[i-2];
        dp[i] = min(firstJump,secondJump);
    }
    return dp[n];
}

// Approach 4: (Most Optimised)
// Space Optimization
// Time Complexity : O(N) Space Complexity : O(1)

int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    int prev =0;
    int secPrev = 0;
    for(int i =2;i<=n;++i){
        int firstJump = prev+cost[i-1];
        int secondJump = secPrev + cost[i-2];
        secPrev = prev;
        prev = min(firstJump,secondJump);
    }
    return prev;
}

// Ques No. 3  Climbing Stairs
// Ques Blog - https://leetcode.com/problems/climbing-stairs/solutions/1722907/c-all-possible-solutions/
// Ques Link - https://leetcode.com/problems/climbing-stairs/
// Ques Solution - https://www.youtube.com/watch?v=mLfjzJsN8us&ab_channel=takeUforward
// Ques Solution2 - https: // www.youtube.com/watch?v=ejjE-eaA_BU&ab_channel=CodewithAlisha

// Approach 1: (TLE)
// Brute Force using Recursion
// Time Complexity : O(2^N) Space Complexity : O(N) RSS(O(N))

int climbStairs(int n){
    if(n<=2) return n;
    return climbStairs(n-1)+climbStairs(n-2);
}

// Approach 2:
// Memoization using Dp
// Time Complexity : O(N) Space Complexity : O(N) RSS(O(N))

int climbStairs(int n){
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}
int helper(int i , vector<int>&dp){
    if(i<=2)return dp[i] = i;
    if(dp[i] != -1) return dp[i];
    return dp[i] = helper(i-1,dp)+helper(i-2,dp);
}

// Approach 3:
// Tabulation using Dp
// Time Complexity : O(N) Space Complexity : O(N)

int climbStairs(int n){
    if(n<=2)return n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i =3;i<=n;++i){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// Approach 4: (Most Optimised)
// Space Optimization
// Time Complexity : O(N) Space Complexity : O(1)

int climbStairs(int n){
    int prev = 2;
    int secPrev =1;
    if(n<=2)return n;
    for(int i =3;i<=n;++i){
        int curi = prev+ secPrev;
        secPrev = prev;
        prev = curi;
    }
    return prev;
}

// Ques No. 4 Pascal's Triangle (striver sheet day 1 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
// Ques Link - https://leetcode.com/problems/pascals-triangle/
// Ques Solution - https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=Q1lj9B33Euc&ab_channel=CodewithAlisha
// Ques Solution3 - https://www.youtube.com/watch?v=U36MSp4-XVI&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// Brute Force 
// Time Complexity : O(N*N) Space Complexity : O(1)

vector<vector<int>> generate(int numRows){
    vector<vector<int>> result;
    for(int i =0;i<numRows;++i){
        vector<int>row(i+1,1);
        for(int j =1;j<i;++j){
            row[j] = result[i-1][j]+result[i-1][j-1];
        }
        result.push_back(row);
    }
    return result;
}

// Ques No. 5 Can Place Flowers
// Ques Blog - https://leetcode.com/problems/can-place-flowers/solutions/2739217/java-1ms-100-faster-jump-3-spaces-least-iterations/
// Ques Link - https://leetcode.com/problems/can-place-flowers/
// Ques Solution - https://www.youtube.com/watch?v=57dy_jm7rWI&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// Brute Force 
// Time Complexity : O(N) Space Complexity : O(1)

bool canPlaceFlowers(vector<int> &flowerbed, int n){
    int m = flowerbed.size();
    int count =0;
    for(int i = 0;i<m && count<n;++i){
        if(flowerbed[i] == 0){
            int prev = (i == 0)?0: flowerbed[i-1];
            int next = (i == m-1)?0: flowerbed[i+1];
            if(next == 0 && prev == 0){
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count == n;
}

// Ques No. 6 Maximum Units on a Truck
// Ques Blog - https://leetcode.com/problems/maximum-units-on-a-truck/solutions/2220730/greedy-with-explanation/
// Ques Link - https://leetcode.com/problems/maximum-units-on-a-truck/
// Ques Solution - https://www.youtube.com/watch?v=3szII9tOceY&ab_channel=AyushiSharma
// Ques Solution2 - https://www.youtube.com/watch?v=SrdKYil7G28&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// Using Priority Queue
// Time Complexity : O(N) Space Complexity : O(N)

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize){
    priority_queue<pair<int,int>> pq;
    int count =0;
    for(vector<int> x:boxTypes){
        pq.push({x[1],x[0]});
    }
    int units = 0;
    while(!pq.empty() && count<truckSize){
        if(count+pq.top().second<truckSize){
            count +=pq.top().second;
            units +=pq.top().second*pq.top().first;
            pq.pop();
        }
        else{
            int quantity = truckSize - count;
            count += quantity;
            units +=pq.top().first*quantity;
            pq.pop();
        }
    }
    return units;
}

// Day 19 Completed Ontime