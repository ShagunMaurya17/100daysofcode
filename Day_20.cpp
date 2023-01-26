// Day 20 coding Date-23.01.2023

// Ques No. 1 3Sum (striver sheet day 7 Problem 3)
// Ques Blog - https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
// Ques Blog2 - https://leetcode.com/problems/3sum/solutions/2186306/c-brute-force-better-optimal/
// Ques Link - https://leetcode.com/problems/3sum/
// Ques Solution - https://www.youtube.com/watch?v=onLoX6Nhvmg&ab_channel=takeUforward

// Approach 1: (TLE)
// Brute Force using set and sort
// Time Complexity : O(N*N*N*LogN) Space Complexity : O(N)

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> st;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i =0;i<n;++i){
        for(int j = i+1;j<n;++j){
            for(int k =j+1;k<n;++k){
                if(nums[i]+nums[j]+nums[k] == 0){
                    st.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
    }
    for(auto it : st){
        ans.push_back(it);
    }
    return ans;
}

// Approach 2: 
// using HashMap
// Time Complexity : O(N*N*LogN) Space Complexity : O(N+N)

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    set<vector<int>> st;
    unordered_map<int,int> mp;
    int n = nums.size();
    for(auto it :nums){
        mp[it]++;
    }
    for(int i = 0;i<n;++i){
        mp[nums[i]]--;
        for(int j = i+1;j<n;++j){
            mp[nums[j]]--;
            if(mp[-(nums[i]+nums[j])]){
                vector<int> temp = {nums[i],nums[j],-(nums[i]+nums[j])};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            mp[nums[j]]++;
        }
        mp[nums[i]]++;
    }
    for(auto it :st){
        ans.push_back(it);
    }
    return ans;
}

// Approach 3: (Most Optimised)
// using Two Pointers & sorting
// Time Complexity : O(N*N) Space Complexity : O(1)

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i =0;i<n;++i){
        if(i == 0 || (i<n &&nums[i] != nums[i-1])){
            int low = i+1,high = n-1,sum = 0-nums[i];
            while(low<high){
                if(nums[low]+nums[high] == sum){
                    vector<int> temp = {nums[i],nums[low],nums[high]};
                    ans.push_back(temp);
                    while(low<high && nums[low] == nums[low+1]) low++;
                    while(low<high && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]<sum) low++;
                else high--;
            }
        }
    }
    return ans;
}

// Ques No. 2 3Sum Closest
// Ques Blog - https://leetcode.com/problems/3sum-closest/solutions/1675008/c-solution-with-explanations-brute-force-to-optimal-solution-explained/
// Ques Blog2 - https://leetcode.com/problems/3sum-closest/solutions/1853887/brute-force-to-optimal-solution-in-cpp/
// Ques Link - https://leetcode.com/problems/3sum-closest/
// Ques Solution - https://www.youtube.com/watch?v=anuarmFjTGU&ab_channel=CodewithAlisha

// Approach 1:
// Brute Force
// Time Complexity : O(N*N*N) Space Complexity : O(1)

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int diff = INT_MAX;
    int ans =0;
    for(int i =0;i<n-2;++i){
        for(int j =i+1;j<n-1;++j){
            for(int k =j+1;k<n;++k){
                int tSum = nums[i]+nums[j]+nums[k];
                if(tSum == target) return target;
                if(abs(target-tSum)<=diff){
                    diff= abs(tSum- target);
                    ans = tSum;
                }
            }
        }
    }
    return ans;
}

// Approach 2: (Most Optimised)
// using Two Pointers & sorting
// Time Complexity : O(N*N) Space Complexity : O(1)

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int diff = INT_MAX;
    int ans = 0;
    sort(nums.begin(),nums.end());
    for(int i =0;i<n;++i){
        int first = nums[i];
        int start = i+1;
        int end = n-1;
        while(start<end){
            int value = first + nums[start]+ nums[end];
            if(value == target)return target;
            else if(abs(value-target)<diff){
                diff = abs(value-target);
                ans = value;
            }
            if(value>target) end--;
            else start++;
        }
    }
    return ans;
}

// Ques No. 3 Non-decreasing Array
// Ques Blog - https://leetcode.com/problems/non-decreasing-array/solutions/2193488/c-solution-2-approaches-brute-lis-concept-optimal/
// Ques Link - https://leetcode.com/problems/non-decreasing-array/
// Ques Solution - https://www.youtube.com/watch?v=iL7oSNc3OXA&ab_channel=AlgorithmsMadeEasy

// Approach 1:
// Brute Force (greedy)
// Time Complexity : O(N) Space Complexity : O(1)

bool checkPossibility(vector<int>& nums){
    int n = nums.size();
    bool flag = 0;
    for(int i =1;i<n;++i){
        if(nums[i]<nums[i-1]){
            if( flag == 1){
                return false;
            }
            if(i<2 || nums[i-2]<=nums[i]){
                nums[i-1] = nums[i];
            }
            else{
                nums[i] = nums[i-1];
            }
            flag =1;
        }
    }
    return true;
}


// Approach 2: (Most optimised)
// Using Position and keep track of prev element
// Time Complexity : O(N) Space Complexity : O(1)

bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    int pos =-1;
    for(int i =0;i<n-1;++i){
        if(nums[i]>nums[i+1]){
            if(pos != -1){
                return false;
            }
            pos =i;
        }
    }
    bool ans = (pos == -1 || pos == 0 || pos == n-2 || nums[pos-1]<=nums[pos+1] || nums[pos]<=nums[pos+2]);
    return ans;
}

// Ques No. 4 Product of Array Except Self
// Ques Blog - https://leetcode.com/problems/product-of-array-except-self/solutions/3089230/c-commented-with-full-explanation-solution-brute-force-optimized/
// Ques Link - https://leetcode.com/problems/product-of-array-except-self/
// Ques Solution - https://www.youtube.com/watch?v=gREVHiZjXeQ&ab_channel=TECHDOSE
// Ques Solution2 - https://www.youtube.com/watch?v=0TIUlVdvVJo&ab_channel=EngineeringDigest

// Approach 1:
// Brute Force But using Division
// Time Complexity : O(3N) Space Complexity : O(1)

vector<int> productExceptSelf(vector<int> &nums){
    int product =1;
    int zeroCount = count(nums.begin(),nums.end(),0);
    if(zeroCount>1)return vector<int> (nums.size());
    for(auto it : nums){
        if(it){
            product = product * it;
        }
    }
    for(auto &it : nums){
        if(zeroCount){
            if(it == 0) it = product;
            else it = 0;
        }
        else it = product/it;
    }
    return nums;
}

// Approach 2:
// Using left prefix and right suffix 
// Time Complexity : O(3N) Space Complexity : O(2N)

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n),left(n),right(n);
    left[0] = nums[0];
    for(int i =1;i<n;++i){
        left[i] = nums[i]*left[i-1];
    }
    right[n-1] = nums[n-1];
    for(int i =n-2;i>=0;--i){
        right[i] = nums[i]*right[i+1];
    }
    ans[0] = right[1];
    ans[n-1]=left[n-2];
    for(int i =1;i<n-1;++i){
        ans[i] = left[i-1]*right[i+1];
    }
    return ans;
}

// Approach 3: (Most optimised)
// Using result array and backward prefix product
// Time Complexity : O(2N) Space Complexity : O(1)

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> res(n);
    int Bprod = 1;
    int Aprod = 1;
    for(int i =0;i<n;++i){
        res[i] = Bprod;
        Bprod *=nums[i];
    }
    for(int i = n-1;i>=0;--i){
        res[i]*= Aprod;
        Aprod*=nums[i];
    }
    return res;
}

// Day 20 Completed Delay of +2 day