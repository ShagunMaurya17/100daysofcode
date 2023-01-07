// Day 4 coding Date-07.01.2023

// Ques No. 1 Find Common Characters
// Ques Blog - https://github.com/Vishal-raj-1/DSA-for-Placement-Internship/blob/main/HashMap%20%26%20HashSet/findCommonCharacters.cpp
// Ques Link - https://leetcode.com/problems/find-common-characters/
// Ques Solution - https://www.youtube.com/watch?v=KBQXKkAPLlU&ab_channel=VishalRajput

// Approach 1: (Most Optimised)
// Usind Character Array
// Time Complexity : O(N) Space Complexity : O(1)

vector<string> commonChars(vector<string> &words){
    vector<int> common(26,INT_MAX);
    vector<string> res;
    for(auto alpha : words){
        vector<int> count(26,0);
        for(auto c : alpha){
            count[c-'a']++;
        }
        for(int i=0;i<26;++i){
            common[i]=min(common[i],count[i]);
        }
    }
    for(int i=0;i<26;++i){
        for(int j=0;j<common[i];++j){
            res.push_back(string(1,i+'a'));
        }
    }
    return res;
}

// Ques No 2. Sum of All Odd Length Subarrays
// Ques Blog - https://pastebin.com/6LnQvVQL
// Ques Link - https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Ques Solution - https://www.youtube.com/watch?v=KZYTXiax7nQ&ab_channel=codeExplainerage O(N^3)
// Ques Solution2 - https://www.youtube.com/watch?v=LSFcmgq0HYY&t=1257s&ab_channel=ShashwatTiwari

// Approach 1:
// Begin with Brute Force
// Time Complexity : O(N^3) Space Complexity : O(1)

int sumOddLengthSubarrays(vector<int>& arr){
    int n =arr.size();
    int sum =0;
    for(int i =0;i<n;i+=2){
        for(int j=0;j<n;++j){
            if(j+i<n){
                for(int k= 0;k<=i;++k){
                    sum +=arr[(j+k)];
                }
            }
        }
    }
    return sum;
}

// Approach 2: (Most Optimised)
// using formula 
// Time Complexity : O(N) Space Complexity : O(1)

int sumOddLengthSubarrays(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    for(int i =0;i<n;++i){
        sum += (((i+1)*(n-i))+1)/2 * arr[i];
    }
    return sum;
}

// Ques No 3. Range Sum Query - Immutable
// Ques Blog - https://leetcode.com/problems/range-sum-query-immutable/submissions/873072748/
// Ques Link - https://leetcode.com/problems/range-sum-query-immutable/
// Ques Solution - https://www.youtube.com/watch?v=k5Im14rNUFA&ab_channel=CodewithAlisha

// Approach 1:
// Begin with Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> arr;
Numarray(vector<int>&nums){
    this->arr=nums;
}
int sumRange(int left, int right){
    return accumulate(this->arr.begin()+left,this->arr.begin +right+1,0);
}

// Approach 2: (Most Optimised)
// Prefix sum
// Time Complexity : O(less than N) Space Complexity : O(N)

vector<int> arr;
vector<int> prefix;
NumArray(vector<int>&nums){
    this -> arr=nums;
    int n = arr.size();
    prefix.resize(n);
    PrefixCalculator(arr);
}
void PrefixCalculator(vector<int> &arr){
    for(int i= 0;i<arr.size();++i){
        (i==0)? prefix[i]=arr[i]:prefix[i]=arr[i]+prefix[i-1];
    }
}
int sumRange(int left,int right){
    return left-1>=0?prefix[right]-prefix[left-1]:prefix[right];
}

// Ques No 4. Shuffle the Array
// Ques Blog - https://leetcode.com/problems/shuffle-an-array/solutions/3003517/c-concise-solution/
// Ques Link - https://leetcode.com/problems/shuffle-an-array/
// Ques Solution - https://www.youtube.com/watch?v=NhVMsP9ibuE&ab_channel=AyushiSharma

// Approach 1:
// Begin with Brute Force with inbuilt shuffle function
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> beforeShuffled;
vector<int> afterShuffled;
Solution(vector<int> &nums) {
    this->beforeShuffled = nums;
    this->afterShuffled = nums;
}

vector<int> reset(){
    return beforeShuffled;
}

vector<int> shuffle(){
    random_shuffle(afterShuffled.begin(),afterShuffled.end());
    return afterShuffled;
}

// Approach 2: (Most Optimised)
// Swapping with random
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> original;
int n;

public:
Solution(vector<int> &nums)
{
    this->original = nums;
    n = original.size();
}

vector<int> reset()
{
    return original;
}

vector<int> shuffle()
{
    vector<int> shuffled = original;
    int lastIndex = n;
    for (int i = n - 1; i >= 0; --i)
    {
        int randVar = (rand() % lastIndex);
        swap(shuffled[i], shuffled[randVar]);
        lastIndex--;
    }
    return shuffled;
}

// Ques No 5. Max Consecutive Ones (striver sheet day 7 Problem 6)
// Ques Blog - https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/
// Ques Link - https://leetcode.com/problems/max-consecutive-ones/description/
// Ques Solution - https://www.youtube.com/watch?v=Mo33MjjMlyA&ab_channel=takeUforward

// Approach 1: (Most Optimised)
// Begin with Brute Force with count and maximum var
// Time Complexity : O(N) Space Complexity : O(1)

int findMaxConsecutiveOnes(vector<int> &nums) {
    int count=0;
    int maximum =0;
    for(int i =0;i<nums.size();++i){
        if(nums[i]==1){
            count++;
        }
        else{
            count=0;
        }
        maximum=max(count,maximum);
    }
    return maximum;
}

// Ques No 6. Max Consecutive Ones (striver sheet day 7 Problem 6)
// Ques Blog - https://leetcode.com/problems/sort-array-by-parity/solutions/3004352/c-odd-even-check/
// Ques Link - https://leetcode.com/problems/sort-array-by-parity/
// Ques Solution - https://www.youtube.com/watch?v=SNHeJl2h38I&ab_channel=AyushiSharma

// Approach 1: 
// Begin with Brute Force with even odd/even
// Time Complexity : O(N) + O(N) Space Complexity : O(N)

vector<int> sortArrayByParity(vector<int> &nums){
    vector<int> res;
    for(int i =0;i<nums.size();++i){
        if(nums[i]%2 == 0){
            res.push_back(nums[i]);
        }
    }
    for(int i = 0;i<nums.size();++i){
        if(nums[i]%2==1){
            res.push_back(nums[i]);
        }
    }
    return res;
}

// Approach 2: (Most Optimised)
// Two Pointers
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> sortArrayByParity(vector<int> &nums){
    int j=0;
    for(int i =0;i<nums.size();++i){
        if(nums[i]%2 == 0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
    return nums;
}
