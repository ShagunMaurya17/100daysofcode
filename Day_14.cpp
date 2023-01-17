// Day 14 coding Date-17.01.2023

// Ques No. 1 Count Odd Numbers in an Interval Range
// Ques Blog - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/879951361/
// Ques Link - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Ques Solution - https://www.youtube.com/watch?v=TkT-6WsmqY0&ab_channel=FisherCoder

// Approach 1:
// Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

int countOdds(int low, int high){
    int count =0;
    for(int i = low;i<=high;i++){
        if(i%2!=0){
            count++;
        }
    }
    return count;
}

// Approach 2: (Most Optimised)
// Simple formula
// Time Complexity : O(1) Space Complexity : O(1)

int countOdds(int low, int high){
    if((low %2 ==0) && (high %2 == 0)){
        return (high-low)/2;
    }
    return (high - low)/2 +1;
}

// Ques No. 2 Rectangle Overlap
// Ques Blog - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/879951361/
// Ques Link - https://leetcode.com/problems/rectangle-overlap/
// Ques Solution - https://www.youtube.com/watch?v=4sFFxnKX8Mc&ab_channel=HelperFunc

// Approach 1: (Most Optimised)
// Brute Force using Simple Geometry
// Time Complexity : O(1) Space Complexity : O(1)

bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
    if(rec1[0]>=rec2[2] || rec2[0]>= rec1[2] || rec1[1]>=rec2[3] || rec2[1]>=rec1[3]){
        return false;
    }
    return true;
}

// Ques No. 3 Add Digits
// Ques Blog - https://leetcode.com/problems/add-digits/solutions/1754049/easy-o-1-explanation-with-example/
// Ques Link - https://leetcode.com/problems/add-digits/
// Ques Solution - https://www.youtube.com/watch?v=doTBRB6_IFs&ab_channel=AyushiSharma

// Approach 1: 
// Brute Force 
// Time Complexity : O(N) Space Complexity : O(1)

int addDigits(int num){
    int sum =0;
    while(num>9){
        while(num){
            sum+=num%10;
            num/=10;
        }
        num = sum;
        sum =0;
    }
    return num;
}

// Approach 2: (Most Optimised)
// Using 9 property 
// Time Complexity : O(1) Space Complexity : O(1)

int addDigits(int num){
    if(num == 0) return 0;
    return num%9 == 0 ?9:num%9;
}

// Ques No. 4 Maximum Product of Three Numbers
// Ques Blog - https://leetcode.com/problems/maximum-product-of-three-numbers/solutions/3048102/easy-c-solution-sorting/
// Ques Link - https://leetcode.com/problems/maximum-product-of-three-numbers/
// Ques Solution - https://www.youtube.com/watch?v=9A4Bebss1WQ&ab_channel=codeExplainer

// Approach 1: (Most Optimised)
// staring and last number multiplying
// Time Complexity : O(Nlogn) Space Complexity : O(1)

int maximumProduct(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int st = nums[0] *nums[1]*nums[n-1];
    int en = nums[n-1]*nums[n-2]*nums[n-3];
    return max(st,en);
}

// Ques No. 5 Excel Sheet Column Number
// Ques Blog - https://leetcode.com/problems/excel-sheet-column-number/solutions/1790101/c-4-lines-easy-to-understand-0ms-100/
// Ques Link - https://leetcode.com/problems/excel-sheet-column-number/
// Ques Solution - https://www.youtube.com/watch?v=_NqvWkRN3Dc&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// simple multiply by 26
// Time Complexity : O(N) Space Complexity : O(1)

int titleToNumber(string columnTitle){
    int result =0;
    for(auto c : columnTitle){
        int d = c-'A'+1;
        result = result*26 +d;
    }
    return result;
}