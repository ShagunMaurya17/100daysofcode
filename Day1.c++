// Day 1 coding Date-04.01.2023

// Ques No 1. Two Sum problem (striver sheet day 4 Problem 1)
// Ques Blog - https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
// Ques Link -  https://leetcode.com/problems/two-sum/
// Ques Solution - https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=3&ab_channel=takeUforward

// Approach 1:
// Begin with Brute Force:
// Time Complexity : O(N^2) Space Complexity : O(1)

vector <int> twoSum(vector<int>&nums, int target){
    vector<int> result;
    for(int i=0;i<nums.size();++i){
        for(int j=i+1;j<nums.size();++j){
            if(nums[i]+nums[j]== target){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
        if (result.size() == 2)
        {
            break;           
        }
    }
    return result;
}

// Approach 2:
// Using sort and two pointer approach
// Time Complexity : O(NlogN) Space Complexity : O(N)

vector <int> twoSum(vector<int>&nums,int target)
{
    vector<int> result,sorted_nums;
    sorted_nums=nums;
    sort(sorted_nums.begin(),sorted_nums.end());
    int left_ptr = 0;
    int right_ptr = nums.size()-1;
    int firstValue,secondValue;
    while(left_ptr<right_ptr){
        if(sorted_nums[left_ptr]+sorted_nums[right_ptr] == target){
            firstValue = sorted_nums[left_ptr];
            secondValue = sorted_nums[right_ptr];
            break;
        }
        else if (sorted_nums[left_ptr]+sorted_nums[right_ptr] > target){
            right_ptr--;
        }
        else{
            left_ptr++;
        }
    }
    for(int i = 0;i<nums.size();++i){
        if(nums[i]==firstValue){
            result.push_back(i);
        }
        else if(nums[i]==secondValue){
            result.push_back(i);
        }
    }
    return result;
}

// Approach 3 (Most Optimised)
// Using Unordered map
// Time Complexity : O(N) Space Complexity O(N)

vector <int> twoSum(vector<int>&nums,int target){
    vector<int> result;
    unordered_map<int,int> Hash_map;
    for(int i=0;i<nums.size();++i){
        if(Hash_map.find(target-nums[i]) != Hash_map.end()){
            result.emplace_back(Hash_map[target-nums[i]]);
            result.emplace_back(i);
            return result;
        }
        Hash_map[nums[i]]=i;
    }
    return result;
}

// Ques No 2. Best time to buy and sell stock (striver sheet day 1 Ques 6)
// Ques Blog - https://takeuforward.org/data-structure/stock-buy-and-sell/
// Ques Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Ques Solution - https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12&ab_channel=takeUforward

// Approach 1:
// Begin with Brute Force
// Time Complexity : O(N^2) Space Complexity : O(1)

int maxProfit(vector<int>&prices){
    int max_Profit = 0;
    for(int i = 0;i<prices.size();++i){
        for(int j=i+1;j<prices.size();++j){
            if(prices[j]>prices[i]){
                max_Profit=max(prices[j]-prices[i],max_Profit);
            }
        }
    }
    return max_Profit;
}

// Approach 2: (Most Optimised)
// Most Optimised with min counter
// Time Complexity : O(N) Space Complexity : O(1)

int maxProfit(vector<int>&prices){
    int MaxProfit = 0;
    int minimumValue = INT_MAX;
    for(int i =0;i<prices.size();++i){
        minimumValue = min(minimumValue,prices[i]);
        MaxProfit = max(MaxProfit,prices[i]-minimumValue);
    }
    return MaxProfit;
}

// Ques No. 3 Majority Element [n/2] (stiver sheet day 3 Ques 3)
// Ques Blog - https://leetcode.com/problems/majority-element/solutions/1787584/c-easy-explanation-sorting-hashmap-brute/?q=brute&orderBy=most_relevant
// Ques Blog2 - https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
// Ques Link - https://leetcode.com/problems/majority-element/
// Ques Solution - https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=17&ab_channel=takeUforward

// Approach 1:
// Brute Force:
// Time Complexity : O(N^2) Space Complexity : O(1)

int majorityElement(vector<int>&nums){
    int middleNums = nums.size()/2;
    for(int i = 0;i<nums.size();++i){
        int count = 0;
        for(int j = 0;j<nums.size();++j){
            if(nums[j]==nums[i]){
                count ++;
            }
            if(count > middleNums){
                return nums[i];
            }
        }

    }
    return -1;
}

// Approach 2:
// Using Sort 
// Time Complexity : O(NlogN) Space Complexity : O(1) *note(if there will be restriction in change the array then we have to create a new array take SC will be O(N))

int majorityElement(vector<int>&nums){
    int n =nums.size();
    sort(nums.begin(),nums.end());
    for(int i = 0;i<n;++i){
        if(nums[i]==nums[(n/2)+i]){
            return nums[i];
            break;
        }
    }
    return -1;
}

// Approach 3
// Using HashMap and counting the frequeny
// Time Complexity : O(N) Space Complexity : O(N)

int majorityElement(vector<int>&nums){
    int n = nums.size();
    unordered_map <int,int> Hash_map;
    for(auto value:nums){
        Hash_map[value]++;
    }
    for(auto freq:Hash_map){
        if(freq.second > n/2){
            return freq.first;
        }
    }
    return -1;
}

// Approach 4 (Most Optimised)
// Using Moore's Voting Algo
// Time Complexity : O(N) Space Complexity : O(1)

int majorityElement(vector<int>&nums){
    int n = nums.size();
    int count = 0;
    int candidate = 0;
    for(auto freq:nums){
        if(count == 0){
            candidate = freq;
        }
        if(freq == candidate){
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

// Ques No. 4 Move Zeroes
// Ques Blog - https://leetcode.com/problems/move-zeroes/solutions/1575841/c-fast-explained/?q=C%2B%2B+explained&orderBy=most_relevant
// Ques Link - https://leetcode.com/problems/move-zeroes/
// Ques Solution - https://www.youtube.com/watch?v=mgzcjQ1x9Mw&ab_channel=Fraz

// Approach 1: (Most Optimised)
// Two Pointers
// Time Complexity : O(N) Space Complexity : O(1)
void moveZeroes(vector<int> &nums){
    int n =nums.size();
    int j = 0;
    for(int i = 0;i<n;++i){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    while(j<n){nums[j++]=0;}
}

// Ques No. 5 Squares of a Sorted array
// Ques Blog - https://leetcode.com/problems/squares-of-a-sorted-array/solutions/495394/c-simplest-one-pass-two-pointers/?orderBy=most_votes
// Ques Link - https://leetcode.com/problems/squares-of-a-sorted-array/
// Ques Solution - https://www.youtube.com/watch?v=XgRIr8CCCVk&ab_channel=CodewithAlisha

// Approach 1:
// Brute Force with sorting
// Time Complexity : O(NlogN) Space Complexity : O(1)

vector<int> sortedSquares(vector<int> &nums){
    for(int i = 0;i<nums.size();++i){
        nums[i]=nums[i]*nums[i];
    }
    sort(nums.begin(),nums.end());
    return nums;
}

// Approach 2: (Most Optimised)
// Two Pointer 
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> sortedSquares(vector<int> &nums){
    int n =nums.size();
    int left_ptr = 0;
    int right_ptr = n-1;
    vector<int>result(n);
    for(int i = n-1;i>=0;--i){
        if(abs(nums[left_ptr])>abs(nums[right_ptr])){
            result[i] = nums[left_ptr]*nums[left_ptr]; // or we can use nums[left_ptr++]
            left_ptr++;
        }
        else
        {
            result[i] = nums[right_ptr]*nums[right_ptr];
            right_ptr--;
        }
    }
    return result;
}

// Ques No. 5 Merge Sorted Array
// Ques Blog - https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
// Ques Blog2 - https://leetcode.com/problems/merge-sorted-array/solutions/600243/c-solution-o-m-n-solution-with-detailed-explanation/?orderBy=most_votes
// Ques Link - https://leetcode.com/problems/merge-sorted-array/
// Ques Solution - https://www.youtube.com/watch?v=XgRIr8CCCVk&ab_channel=CodewithAlisha

// Approach 1:
// Brute Force
// Time Complexity : O(Nlogn) + O(N) + O(M) Space Complexity : O(N)

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> result(m + n, 0);
    int k = 0;
    for (int i = 0; i < m; ++i)
    {
        result[k++] = nums1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        result[k++] = nums2[i];
    }
    sort(result.begin(), result.end());
    k = 0;
    for (int i = 0; i < m + n; ++i)
    {
        nums1[i] = result[k++];
    }
}

// Approach 2:
// Gap method
// Time Complexity : O(NlogN) Space Complexity : O(1)

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int k = 0;
    for(int i = m ;i<m+n;++i){
        nums1[i]=nums2[k++];
    }
    int gap = ceil((float)(m+n)/2);
    while(gap>0){
        int left = 0;
        int right = gap;
        while(right<m+n){
            if(nums1[left]>nums1[right]){
                swap(nums1[left],nums1[right]);
            }
            left++;
            right++;
        }
        if(gap == 1){
            gap=0;
        }
        else{
            gap = ceil((float(gap/2)));
        }
    }
}
// Approach 2:
// Three Pointer
// Time Complexity : O(N+M) Space Complexity : O(1)

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = m-1,j=n-1,k=m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--]= nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}

// Day 1 Completed +2hr Delay