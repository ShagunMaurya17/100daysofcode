// Day 15 coding Date-18.01.2023

// Ques No. 1 Add Binary
// Ques Blog - https://leetcode.com/problems/add-binary/submissions/880653170/
// Ques Link - https://leetcode.com/problems/add-binary/
// Ques Solution - https://www.youtube.com/watch?v=jCEmOqL8W80&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// simple approach with carry
// Time Complexity : O(N) Space Complexity : O(1)

string addBinary(string a, string b){
    int alen = a.length();
    int blen = b.length();
    int i  = 0,carry= 0;
    string ans = "";
    while(i<alen || i<blen || carry !=0){
        int lastdigit_A = 0;
        if(i<alen && a[alen-i-1] == '1'){
            lastdigit_A =1;
        }
        int lastdigit_B =0;
        if(i<blen && b[blen - i -1] == '1'){
            lastdigit_B =1;
        }
        ans = to_string((lastdigit_A + lastdigit_B + carry)%2) + ans;
        carry = (lastdigit_A + lastdigit_B + carry)/2;
        i+=1;

    }
    return ans;
}

// Ques No. 2 Counting Bits
// Ques Blog - https://leetcode.com/problems/counting-bits/submissions/880666925/
// Ques Link - https://leetcode.com/problems/counting-bits/
// Ques Solution - https://www.youtube.com/watch?v=rbzEecDRhAE&ab_channel=CodewithAlisha

// Approach 1: 
// simple Brute force
// Time Complexity : O(NLOGN) Space Complexity : O(1)

vector<int> countBits(int n) {
    vector<int> ans(n+1,0);
    for(int i = 0;i<=n;++i){
        int num = i;
        int count = 0;
        while(num){
            count += num%2;
            num/=2;
        }
        ans[i] = count;
    }
    return ans;
}

// Approach 2: (Most Optimised)
// Pattern in even number left shift
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> countBits(int n){
    vector<int> ans(n+1,0);
    for(int i =0;i<=n;++i){
        if(i%2 ==0){
            ans[i] = ans[i/2];
        }
        else{
            ans[i] = ans[i/2]+1;
        }
    }
    return ans;
}

// Ques No. 3  Number of 1 Bits
// Ques Blog - https://leetcode.com/problems/number-of-1-bits/solutions/3065607/c-bit-manipulation-approach/?orderBy=newest_to_oldest
// Ques Link - https://leetcode.com/problems/number-of-1-bits/
// Ques Solution - https://www.youtube.com/watch?v=EKmUgWZXPMs&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// simple n &n-1 approach
// Time Complexity : O(N) Space Complexity : O(1)

int hammingWeight(uint32_t n){
    int count = 0;
    while(n){
        n = n&(n-1);
        count++;
    }
    return count;
}

// Ques No. 4  Single Number
// Ques Blog - https://leetcode.com/problems/single-number/solutions/1771720/c-easy-solutions-sorting-xor-maps-or-frequency-array/
// Ques Link - https://leetcode.com/problems/single-number/
// Ques Solution - https://www.youtube.com/watch?v=-qcn310RvGw&ab_channel=AyushiSharma

// Approach 1:
// simple Brute Force and sort
// Time Complexity : O(NlogN) Space Complexity : O(1)

int singleNumber(vector<int> &nums){
    sort(nums.begin(),nums.end());
    for(int i =1;i<nums.size();i+=2){
        if(nums[i]!=nums[i-1]){
            return nums[i-1];
        }
    }
    return nums[nums.size()-1];
}

// Approach 2:
// Using hashmap
// Time Complexity : O(N) Space Complexity : O(N)

int singleNumber(vector<int> &nums){
    unordered_map<int,int> hashMap;
    for(auto value : nums){
        hashMap[value]++;
    }
    for(auto it : hashMap){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

// Approach 3: (Most Optimised)
// Using BitWise Xor
// Time Complexity : O(N) Space Complexity : O(1)

int singleNumber(vector<int> &nums){
    int ans =0;
    for(auto val : nums){
        ans^=val;
    }
    return ans;
}

// Ques No. 5 Missing Number
// Ques Blog - https://leetcode.com/problems/missing-number/solutions/3069719/c-very-simple-solution-using-stl/
// Ques Link - https://leetcode.com/problems/missing-number/
// Ques Solution - https://www.youtube.com/watch?v=W4pHluYsLYM&ab_channel=CodewithAlisha

// Approach 1:
// simple Brute Force and sort
// Time Complexity : O(NlogN) Space Complexity : O(1)

int missingNumber(vector<int> &nums){
    int ans = 0;
    sort(nums.begin(),nums.end());
    for(int i =0;i<nums.size();++i){
        if(nums[i]!=i+1){
            ans = i+1;
        }
    }
    return ans;
}

// Approach 2:
// Using total sum - array sum
// Time Complexity : O(N) Space Complexity : O(1)

int missingNumber(vector<int> &nums){
    int n =nums.size();
    return n*(n+1)/2 - accumulate(nums.begin(),nums.end(),0);
}

// Approach 3: (Most Optimised)
// Using BitWise Xor
// Time Complexity : O(N) Space Complexity : O(1)

int missingNumber(vector<int> &nums){
    int n = nums.size();
    int ans = 0;
    for(int i =0;i<n;++i){
        ans^=(nums[i]^i);
    }
    ans^=(n);
    return ans;
}

// Ques No. 6 Reverse Bits
// Ques Blog - https://leetcode.com/problems/reverse-bits/solutions/3060388/step-by-step-explanation-because-others-didn-t/
// Ques Link - https://leetcode.com/problems/reverse-bits/
// Ques Solution - https://www.youtube.com/watch?v=LJiMk8lPJNc&ab_channel=Codebix

// Approach 1: (Most Optimised)
// Using bits and shift
// Time Complexity : O(32) Space Complexity : O(1)

uint32_t reverseBits(uint32_t n){
    int res =0;
    for(int i =0;i<32;++i){
        int lsb = n&1;
        int reverse = lsb <<(31-i);
        res = res | reverse;
        n = n>>1;
    }
    return res;
}

// Ques No. 7 Hamming Distance
// Ques Blog - https://leetcode.com/problems/hamming-distance/solutions/3058034/c-simplest-solution-xor-operation/
// Ques Link - https://leetcode.com/problems/hamming-distance/
// Ques Solution - https://www.youtube.com/watch?v=N9xFjDGwFOY&ab_channel=Codebix

// Approach 1: (Most Optimised)
// Using Xor
// Time Complexity : O(LogN) Space Complexity : O(1)

int hammingDistance(int x, int y){
    int count = 0;
    int n = x^y;
    while(n){
        if(n%2 == 1){
            count++;
        }
        n/=2;
    }
    return count;
}