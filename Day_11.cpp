// Day 11 coding Date-14.01.2023

// Ques No. 1  Is Subsequence
// Ques Blog - https://leetcode.com/problems/is-subsequence/solutions/1811180/c-easy-3-approaches-brute-force-recursive-memoization/
// Ques Link - https://leetcode.com/problems/is-subsequence/
// Ques Solution - https://www.youtube.com/watch?v=GKdDshno8-A&ab_channel=CodewithAlisha

// Approach 1: 
// By using Recursion
// Time Complexity : O(N+M) Space Complexity : O(1) RSS(O(M+N))

bool isSubsequence(string s, string t){
    if(isSubs(s,t,s.size(),t.size())){
        return true;
    }
    return false;
}
bool isSubs(string &s,string &t, int m ,int n){
    if(m==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(s[m-1]==t[n-1]){
        return isSubs(s,t,m-1,n-1);
    }
    return isSubs(s,t,m,n-1);
}

// Approach 2:
// By using Memoization/DP
// Time Complexity : O(N+M) Space Complexity : O(M+N) 

bool isSubsequence(string s, string t){
    int m = s.size();
    int n = t.size();
    if(m>n){
        return false;
    }
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    if(isSub(s,t,m,n,dp) == m){
        return true;
    }
    return false;
}
int isSub(string &s ,string &t,int i,int j ,vector<vector<int>>&dp){
    if(i == 0 || j== 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i-1]==t[j-1]){
        return 1+ isSub(s,t,i-1,j-1,dp);
    }
    else{
        return isSub(s,t,i,j-1,dp);
    }
}

// Approach 3: (Most Optimised)
// Simple Two Pointer
// Time Complexity : O(N+M) Space Complexity : O(1)

bool isSubsequence(string s, string t){
    if(s == "")return true;
    int j=0;
    for(int i =0;i<t.size();++i){
        if(s[j] == t[i])j++;
        if(j == s.size())return true;
    }
    return false;
}

// Ques No. 2  Reverse String
// Ques Blog - https://leetcode.com/problems/reverse-string/submissions/877829788/
// Ques Link - https://leetcode.com/problems/reverse-string/
// Ques Solution - https://www.youtube.com/watch?v=LMeYeTXrGak&ab_channel=TECHDOSE

// Approach 1: (Most Optimised)
// Simple left and right swap
// Time Complexity : O(N) Space Complexity : O(1)

void reverseString(vector<char> &s){
    int start = 0;
    int end =s.size()-1;
    while(start<end){
        swap(s[start],s[end]);
        ++start;
        --end;
    }
}

// Ques No. 3  Reverse String II
// Ques Blog - https://leetcode.com/problems/reverse-string-ii/solutions/2627754/c-world-s-fastest-solution-with-approach/
// Ques Link - https://leetcode.com/problems/reverse-string-ii/
// Ques Solution - https://www.youtube.com/watch?v=nfRO3ym-Mz8&ab_channel=codeExplainer

// Approach 1: (Most Optimised)
// simple Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

string reverseStr(string s, int k){
    int n = s.size();
    for(int i =0;i<n;i+=2*k){
        reverse(s.begin()+i,s.begin()+i+min(k,n-i));
    }
    return s;
}

// Ques No. 4  Reverse Words in a String III
// Ques Blog - https://leetcode.com/problems/reverse-string/submissions/877829788/
// Ques Link - https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Ques Solution - https://www.youtube.com/watch?v=AqCXwq4BTlY&ab_channel=KnowledgeCenter

// Approach 1: (Most Optimised)
// Two Pointer Approach
// Time Complexity : O(N) Space Complexity : O(1)

string reverseWords(string s) {
    int left=0,right =0;
    while(left<s.size()){
        while(right<s.size() && s[right]!=' '){
            right++;
        }
        reverse(s.begin()+ left,s.begin()+right);
        left = right +1;
        right = left;
    }
    return s;
}

// Ques No. 5  Isomorphic Strings
// Ques Blog - https://github.com/Ayu-99/Data-Structures/blob/master/Leetcode%20July%20Challenge/C%2B%2B/Isomorphic%20Strings.cpp
// Ques Link - https://leetcode.com/problems/isomorphic-strings/
// Ques Solution - https://www.youtube.com/watch?v=VEuPGTIqXeQ&ab_channel=AyushiSharma

// Approach 1: 
// Unordered Map 
// Time Complexity : O(N) Space Complexity : O(1)

bool isIsomorphic(string s, string t){
    unordered_map<char,char> mp1,mp2;
    for(int i  =0;i<s.size();++i){
        if(mp1[s[i]]&& mp1[s[i]]!=t[i]) return false;
        if(mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    return true;
}

// Approach 2: (Most Optimised)
// charater array
// Time Complexity : O(N) Space Complexity : O(1)

bool isIsomorphic(string s, string t){
    int n = s.size();
    char seen[128] = {};
    for(int i =0;i<n;++i){
        char c = s[i];
        if(!seen[c]){
            for(char s :seen) if(s == t[i]) return false;
            seen[c] = t[i];
        }
        else if(seen[c]!= t[i])return false;
    }
    return true;

}

// Ques No. 6  Remove All Adjacent Duplicates In String
// Ques Blog - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/solutions/3039587/using-string-only-0ms-code-c/
// Ques Link - https://leetcode.com/problems/isomorphic-strings/
// Ques Solution - https://www.youtube.com/watch?v=EMKDoj5Sshk&ab_channel=HelloWorld

// Approach 1: 
// Stack Approach
// Time Complexity : O(N) Space Complexity : O(N)

string removeDuplicates(string s){
    string ans = "";
    stack<char> st;
    for(auto c:s){
        if(st.empty()){
            st.push(c);
        }
        else if(st.top() == c){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    while(!st.empty()){
        ans +=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// Approach 2: 
// Using stl string function
// Time Complexity : O(N) Space Complexity : O(1)

string removeDuplicates(string s){
    string ans = "";
    for(int i =0;i<s.size();++i){
        if(ans == ""){
            ans.push_back(s[i]);
        }
        else if(ans.back()==s[i]){
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}

// Day11 Completed Ontime