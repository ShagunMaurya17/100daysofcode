// Day 23 coding Date-26.01.2023

// Ques No. 1 Subarray Sum Equals K
// Ques Blog - https://leetcode.com/problems/subarray-sum-equals-k/solutions/1759909/c-full-explained-every-step-w-dry-run-o-n-2-o-n-two-approaches/
// Ques Link - https://leetcode.com/problems/subarray-sum-equals-k/
// Ques Solution - https://www.youtube.com/watch?v=r1cwGocurtA&t=640s&ab_channel=CodewithAlisha

// Approach 1: (TLE)
// Brute Force 
// Time Complexity : O(N*N) Space Complexity : O(1)

int subarraySum(vector<int> &nums, int k){
    int n = nums.size();
    int count =0;
    int sum =0;
    for(int i =0;i<n;++i){
        sum = nums[i];
        if(sum == k){
            count++;
        }
        for(int j =i+1;j<n;++j){
            sum +=nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

// Approach 2: (Most Optimised)
// Using Unordered map
// Time Complexity : O(N) Space Complexity : O(N)

int subarraySum(vector<int> &nums, int k){
    int n = nums.size();
    int sum=0;
    int count =0;
    unordered_map<int,int> mp;
    for(int i =0;i<n;++i){
        sum +=nums[i];
        if(sum == k){
            count++;
        }
        if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}

// Ques No. 2 Shortest Unsorted Continuous Subarray
// Ques Blog - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solutions/1164710/all-5-approach-with-comments/
// Ques Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Ques Solution - https://www.youtube.com/watch?v=ho9x_C2akHg&ab_channel=AyushiSharma
// Ques Solution2 - https://www.youtube.com/watch?v=hZmwvBIJXPg&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// Using Two Pointers
// Time Complexity : O(N) Space Complexity : O(1)

int findUnsortedSubarray(vector<int>& nums){
    int n = nums.size();
    int low =0,high=n-1;
    while(low+1<n && nums[low]<=nums[low+1]) low++;
    while(high-1>=0 && nums[high-1]<=nums[high]) high--;
    if(low == n-1) return 0;
    int maxi= INT_MIN,mini=INT_MAX;
    for(int i = low;i<=high;++i){
        maxi =max(maxi,nums[i]);
        mini = min(mini,nums[i]);
    }
    while(low-1>=0 && nums[low-1]>mini)low--;
    while(high+1<=n-1 && nums[high+1]<maxi) high++;
    return high-low+1;
}

// Ques No. 3 Maximum Points You Can Obtain from Cards
// Ques Blog - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/solutions/1202816/c-solutions-two-approaches/
// Ques Link - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Ques Solution - https://www.youtube.com/watch?v=GIO9YRFmMXA&ab_channel=CodewithAlisha
// Ques Solution2 - https://www.youtube.com/watch?v=1DkVU2i3sOA&ab_channel=Fraz

// Approach 1: 
// Using Sliding Window Two pointers with Prefix sum
// Time Complexity : O(N) Space Complexity : O(N)

int maxScore(vector<int>& cardPoints, int k){
    int n = cardPoints.size();
    vector<int> prefix(n,0);
    int sum =0;
    for(int i =0;i<n;++i){
        sum+=cardPoints[i];
        prefix[i] = sum;
    }
    if(n == k) return sum;
    int ans =0;
    int curr =0;
    for(int i =0;i<=k;++i){
        int j = i+n-k-1;
        if(i == 0) curr = prefix[j];
        else{
            curr = prefix[j] - prefix[i-1];
        }
        ans = max(ans,sum-curr);
    }
    return ans;
}

// Approach 2: (Most Optimised)
// Using Simple Observation
// Time Complexity : O(N) Space Complexity : O(1)

int maxScore(vector<int>& cardPoints, int k){
    int res = 0;
    for(int i =0;i<k;++i){
        res+=cardPoints[i];
    }
    int curr= res;
    for(int i = k-1;i>=0;--i){
        curr-=cardPoints[i];
        curr += cardPoints[cardPoints.size() - k+i];
        res = max(curr,res);
    }
    return res;
}

// Ques No. 4 Max Consecutive Ones III
// Ques Blog - https://leetcode.com/problems/max-consecutive-ones-iii/solutions/1305102/max-consecutive-i-ii-iii-similar-approach-multiple-approaches-c/
// Ques Link - https://leetcode.com/problems/max-consecutive-ones-iii/
// Ques Solution - https://www.youtube.com/watch?v=Gl-8HLvV8bc&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// Using Sliding Window Two pointers
// Time Complexity : O(N) Space Complexity : O(1)

int longestOnes(vector<int> &nums, int k){
    int i =0,j=0,n=nums.size(),countZeroes =0, ans = INT_MIN;
    while(j<n){
        if(nums[j] == 0){
            countZeroes++;
        }
        while(countZeroes>k){
            if(nums[i] == 0){
                countZeroes--;
            }
            ++i;
        }
        ans= max(ans,j-i+1);
        ++j;
    }
    return ans;
}

// Day 23 Completed Ontime