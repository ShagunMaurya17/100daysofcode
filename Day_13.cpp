// Day 13 coding Date-16.01.2023

// Ques No. 1  Roman to Integer
// Ques Blog - https://leetcode.com/problems/roman-to-integer/solutions/2588499/simple-c-solution-using-if-else-statement-in-o-n/
// Ques Link - https://leetcode.com/problems/roman-to-integer/
// Ques Solution - https://www.youtube.com/watch?v=Ydho2JPTI3Y&ab_channel=TECHDOSE

// Approach 1:
// Simple implentation Using map and sliding window element
// Time Complexity : O(N) Space Complexity : O(N)

int romanToInt(string s){
    unordered_map<char,int> mp{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int value =0;
    for(int i =0;i<s.size();++i){
        if(mp[s[i]]<mp[s[i+1]]){
            value -= mp[s[i]];
        }
        else{
            value +=mp[s[i]];
        }
    }
    return value;
}

// Approach 2: (Most optimised)
// Simple if else statement
// Time Complexity : O(N) Space Complexity : O(1)

int romanToInt(string s){
    int value = 0;
    for(int i =0;i<s.size();++i){
        if(s[i] == 'I'){
            if(s[i+1] == 'X' || s[i+1] == 'V') value -= 1;
            else value +=1;
        }
        else if(s[i] == 'V') value +=5;
        else if (s[i] == 'X'){
            if(s[i+1] == 'L' || s[i+1] == 'C') value -=10;
            else value +=10;
        }
        else if(s[i] == 'L') value +=50;
        else if(s[i] == 'C'){
            if(s[i+1] == 'M' || s[i+1] == 'D') value -=100;
            else value +=100;
        }
        else if (s[i] == 'D') value +=500;
        else if(s[i] == 'M') value +=1000;
    }
    return value;
}

// Ques No. 2 Palindrome Number
// Ques Blog - https://leetcode.com/problems/palindrome-number/solutions/3056590/c-reverse-half-the-number/
// Ques Link - https://leetcode.com/problems/palindrome-number/
// Ques Solution - https://www.youtube.com/watch?v=uNSdy7-JKtI&ab_channel=codeExplainer

// Approach 1:
// Using to_string function and reverse function
// Time Complexity : O(N) Space Complexity : O(1)

bool isPalindrome(int x){
    string reversenum = to_string(x);
    reverse(reversenum.begin(),reversenum.end());
    return to_string(x) == reversenum;
}

// Approach 2:
// Using to_string function and two pointer
// Time Complexity : O(N) Space Complexity : O(1)

bool isPalindrome(int x){
    string ans = to_string(x);
    int left =0;
    int right = ans.size()-1;
    while(left <right){
        if(ans[left++] != ans[right--]){
            return false;
        }
    }
    return true;
}

// Approach 3: (Most Optimised)
// Using digit and reverse it
// Time Complexity : O(Logbase 10 N) Space Complexity : O(1)

bool isPalindrome(int x){
    long long ans = x;
    long long reversenum =0;
    if(x<0) return false;
    while(x){
        long long lastdig = x%10;
        reversenum *=10;
        reversenum +=lastdig;
        x/=10;
    }
    return reversenum == ans;
}

// Ques No. 3 Happy Number
// Ques Blog - https://leetcode.com/problems/happy-number/solutions/2819767/best-c-code-0ms-beats-100-solution/
// Ques Link - https://leetcode.com/problems/happy-number/
// Ques Solution - https://www.youtube.com/watch?v=Egw03gI-Tf0&ab_channel=TECHDOSE

// Approach 1: (Most Optimised)
// Using unordered_set
// Time Complexity : O(N) Space Complexity : O(N)

bool isHappy(int n){
    unordered_map<int> st;
    int value;
    int index;
    while(1){
        value =0;
        while(n){
            index = n%10;
            value += index*index;
            n /=10;
        }
        if(value == 1) return true;
        else if(st.find(value)!=st.end()){
            return false;
        }
        st.insert(value);
        n=value;
    }
    return false;
}

// Ques No. 4 Power of Two
// Ques Blog - https://leetcode.com/problems/power-of-two/solutions/1638704/c-easy-to-solve-all-interview-approaches-with-detailed-explanations/
// Ques Link - https://leetcode.com/problems/power-of-two/
// Ques Solution - https://www.youtube.com/watch?v=4cqHahxFTYw&ab_channel=TECHDOSE

// Approach 1: 
// Using Recursion
// Time Complexity : O(logN) Space Complexity : O(1) RSS(O(logN))

bool isPowerOfTwo(int n){
    if(n ==0) return false;
    return ((n == 1) || (n%2 == 0 && isPowerOfTwo(n/2)));
}

// Approach 2:
// while Loop interating version
// Time Complexity : O(logN) Space Complexity : O(1)

bool isPowerOfTwo(int n){
    if(n == 0) return false;
    while(n%2 == 0){
        n/=2;
    }
    return n==1;
}

// Approach 3:
// bits Manipulation
// Time Complexity : O(logN) Space Complexity : O(1)

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    return ((n & (n-1))) == 0;
}

// Approach 4: (Most Optimised)
// Using ciel and floor
// Time Complexity : O(1) Space Complexity : O(1)

bool isPowerOfTwo(int n){
    if(n<=0) return false;
    return ((ceil(log2(n))) == floor(log2(n)) );
}

// Approach 5: (Most Optimised)
// Using Stl __builtin_popcount function
// Time Complexity : O(1) Space Complexity : O(1)

bool isPowerOfTwo(int n){
    if(n<= 0) return false;
    int bit = __builtin_popcount(n);
    return bit == 1;
}

// Ques No. 5 Sqrt(x)
// Ques Blog - https://leetcode.com/problems/sqrtx/solutions/3057341/c-binary-search-method-100-beats/
// Ques Link - https://leetcode.com/problems/sqrtx/
// Ques Solution - https://www.youtube.com/watch?v=eC0b6lUj84w&ab_channel=Fraz

// Approach 1:
// Using while loop
// Time Complexity : O(ROOT N) Space Complexity : O(1)

int mySqrt(int x){
    long long ans= 0;
    while(ans * ans <= x){
        ++ans;
    }
    return ans-1;
}

// Approach 2: (Most Optimised)
// Using Binary Search
// Time Complexity : O(logN) Space Complexity : O(1)

int mySqrt(int x){
    int start =0;
    int end =x;
    int ans=0;
    while(start<=end){
        long long mid = start +(end- start)/2;
        long long square = mid*mid;
        if(square == x){
            return mid;
        }
        else if(square<x){
            ans = mid;
            start =mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

// Ques No. 6 Plus One
// Ques Blog - https://leetcode.com/problems/plus-one/solutions/3056619/c-properly-explained-with-comments/
// Ques Link - https://leetcode.com/problems/plus-one/
// Ques Solution -https://www.youtube.com/watch?v=Tcxob-LyBTo&ab_channel=Fraz

// Approach 1:
// Using while loop
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> plusOne(vector<int> &digits){
    for(int i = digits.size()-1;i>=0;--i){
        if(digits[i]<9){
            digits[i]+=1;
            return digits;
        }
        else{
            digits[i] =0;
        }
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}

// Day13 Completed Ontime