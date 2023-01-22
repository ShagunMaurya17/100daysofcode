// Day 16 coding Date-19.01.2023

// Ques No. 1 Binary Search
// Ques Blog - https://leetcode.com/problems/binary-search/solutions/2677095/c-solution-recursive-approach/
// Ques Link - https://leetcode.com/problems/binary-search/
// Ques Solution - https://www.youtube.com/watch?v=eM0ZVMdrU0M&ab_channel=AyushiSharma

// Approach 1: 
// Recursive Approach
// Time Complexity : O(LogN) Space Complexity : O(1) RSS(O(LogN))

int search(vector<int> &nums, int target){
    int result = binarySearch(nums, 0 ,nums.size()-1,target);
    return result == -1?-1:result;
}
int binarySearch(vector<int>& vec,int left,int right,int key){
    if(left<=right){
        int mid = (left + right)/2;
        if(key == vec[mid]){
            return mid;
        }
        else if(key<vec[mid]){
            return binarySearch(vec,left,mid-1,key);
        }
        else {
            return binarySearch(vec,mid+1,right,key);
        }
    }
    return -1;
}

// Approach 2: (Most Optimised)
// Iterative Approach
// Time Complexity : O(LogN) Space Complexity : O(1)

int search(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target<nums[mid]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}

// Ques No. 2 Search Insert Position
// Ques Blog - https://leetcode.com/problems/search-insert-position/solutions/3069175/beats-100-of-other-codes-runtime-0ms-c/
// Ques Link - https://leetcode.com/problems/search-insert-position/
// Ques Solution - https://www.youtube.com/watch?v=0A40XJH_VvE&ab_channel=TECHDOSE

// Approach 1: (Most Optimised)
// Iterative Approach (binary search) low
// Time Complexity : O(LogN) Space Complexity : O(1)

int searchInsert(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target< nums[mid]){
            high = mid-1;
        }
        else {
            low = mid +1;
        }
    }
    return low;
}

// Ques No. 3 First Bad Version
// Ques Blog - https://leetcode.com/problems/first-bad-version/solutions/2720842/java-brute-and-optimal-solutions/?q=brut&orderBy=most_relevant
// Ques Link - https://leetcode.com/problems/first-bad-version/
// Ques Solution - https://www.youtube.com/watch?v=fMqvirQf-88&ab_channel=CodewithAlisha

// Approach 1:
// Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

int firstBadVersion(int n) {
    for(int i =1;i<=n;++i){
        if (isBadVersion(i))
        return i;
    }
    return 0;
}

// Approach 2: (Most Optimised)
// Iterative Approach (binary search)
// Time Complexity : O(LogN) Space Complexity : O(1)

int firstBadVersion(int n){
    int low = 1;
    int high = n;
    while(low<high){
        int mid = low + (high - low)/2;
        if(!isBadVersion(mid)){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return high;
}

// Ques No. 4 Valid Perfect Square
// Ques Blog - https://leetcode.com/problems/valid-perfect-square/solutions/3069764/simple-c-solution-using-binary-search/
// Ques Link - https://leetcode.com/problems/valid-perfect-square/
// Ques Solution - https://www.youtube.com/watch?v=tSy8lDLPduU&ab_channel=TECHDOSE

// Approach 1:
// Brute Force
// Time Complexity : O(RootN) Space Complexity : O(1)

bool isPerfectSquare(int num){
    if(num == 1){
        return true;
    }
    for(long long i =0;i<=(num/2);i++){
        long long sq = (i*i);
        if(sq == num){
            return true;
        }
    }
    return false;
}

// Approach 2: (Most Optimised)
// Iterative Approach (binary search)
// Time Complexity : O(LogN) Space Complexity : O(1)

bool isPerfectSquare(int num){
    long long low =1;
    long long high = 1000000;
    long long sq;
    long long mid;
    while(low<=high){
        mid = low +(high-low)/2;
        sq = mid*mid;
        if(sq == num){
            return true;
        }
        else if(sq>num){
            high = mid -1;
        }
        else 
        {
            low = mid +1;
        }
    }
    return false;
}

// Ques No. 5 Kth Missing Positive Number
// Ques Blog - https://leetcode.com/problems/kth-missing-positive-number/solutions/780764/c-o-n-and-o-logn-solutions-with-explanation/
// Ques Link - https://leetcode.com/problems/kth-missing-positive-number/
// Ques Solution - https://www.youtube.com/watch?v=tcjjJBJw1rM&ab_channel=CodingDecoded

// Approach 1:
// Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

int findKthPositive(vector<int> &arr, int k){
    for(int i =0;i<arr.size();++i){
        if(arr[i]<=k)k++;
        else break;
    }
    return k;
}

// Approach 2: (Most Optimised)
// Iterative Approach (binary search)
// Time Complexity : O(LogN) Space Complexity : O(1)

int findKthPositive(vector<int> &arr, int k){
    
}