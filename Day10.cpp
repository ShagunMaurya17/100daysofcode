// Day 10 coding Date-13.01.2023

// Ques No. 1  Valid Palindrome
// Ques Blog - https://leetcode.com/problems/valid-palindrome/solutions/3043316/just-one-loop/
// Ques Link - https://leetcode.com/problems/valid-palindrome/
// Ques Solution - https://www.youtube.com/watch?v=XdMau9kwUvU&ab_channel=TECHDOSE

// Approach 1: (Most Optimised)
// using stl function
// Time Complexity : O(3N) Space Complexity : O(1)

bool isPalindrome(string &s) {
    int n =s.size();
    string t;
    for(int i =0;i<n;++i){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            t +=s[i];
        }
    }
    int p = t.size();
    for(int i =0;i<p;++i){
        t[i]=tolower(t[i]);
    }
    for(int i =0;i<p/2;++i){
        if(t[i]!=t[p-1-i]){
            return false;
        }
    }
    return true;
}

// Ques No. 2  Valid Palindrome II
// Ques Blog - https://github.com/Ayu-99/Data-Structures/blob/master/Leetcode%20Challenge/April/C%2B%2B/Valid%20Palindrome%20II.cpp
// Ques Link - https://leetcode.com/problems/valid-palindrome-ii/
// Ques Solution - https://www.youtube.com/watch?v=hTXgBhUYsQk&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// check the element
// Time Complexity : O(N) Space Complexity : O(1)

bool isPalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s){
    int r = s.size()-1;
    int l = 0;
    while(l<r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            return isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1);
        }
    }
    return true;
}

// Ques No. 3  Longest Palindrome
// Ques Blog - https://leetcode.com/problems/longest-palindrome/solutions/2698316/c-solution-using-hashmap/
// Ques Link - https://leetcode.com/problems/longest-palindrome/
// Ques Solution - https://www.youtube.com/watch?v=tEbOmwxmuls&ab_channel=Codebix

// Approach 1: 
// Using the unordered map and frequency
// Time Complexity : O(N) Space Complexity : O(1)

int longestPalindrome(string s) {
    unordered_map<char,int> mp;
    for(auto x:s){
        mp[x]++;
    }
    int count =0;
    int carry = 0;
    for(auto c:mp){
        if(c.second%2==1){
            carry=1;
            count += (c.second - 1);
        }
        else
        count +=c.second;
    }
    return count + carry;
}

// Approach 2: (Most Optimised)
// Using two array and count
// Time Complexity : O(N) Space Complexity : O(1)

int longestPalindrome(string s) {
    int upperCase[27]={0};
    int lowerCase[27] =  {0};
    for(int i =0;i<s.size();++i){
        char c = s[i];
        if(c-97>=0){
            lowerCase[c-97]++;
        }
        else {
            upperCase[c-65]++;
        }
    }
    int count =0;
    bool firstOdd = false;
    for(int i =0;i<26;++i){
        if(lowerCase[i]%2==0){
            count += lowerCase[i];
        }
        else{
            if(firstOdd== false){
                count +=lowerCase[i];
                firstOdd = true;
            }
            else{
                count += lowerCase[i]-1;
            }
        }
    }
    for(int i =0;i<26;++i){
        if(upperCase[i]%2==0){
            count += upperCase[i];
        }
        else{
            if(firstOdd == false){
                count+=upperCase[i];
                firstOdd = true;
            }
            else{
                count+=upperCase[i]-1;
            }
        }
    }
    return count;
}

// Ques No. 4 Longest Common Prefix
// Ques Blog - https://leetcode.com/problems/longest-common-prefix/solutions/3042034/fast-and-easy-c-solution-beats-100-time/
// Ques Link - https://leetcode.com/problems/longest-common-prefix/
// Ques Solution - https://www.youtube.com/watch?v=8LDbrlZ7834&ab_channel=codeExplainer

// Approach 1:  (Most Optimised)
// Simple Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

string findPrefix(string ans,string check){
    if(ans.size()>check.size()) swap(ans,check);
    string newans =  "";
    for(int i =0;i<ans.size();++i){
        if(ans[i] == check[i])
        newans += (char)ans[i];
        else
        break;
    }

    return newans;
}
string longestCommonPrefix(vector<string> &strs){
    string ans = strs[0];
    for(int i =1;i<strs.size();++i){
        ans= findPrefix(ans,strs[i]);
    }
    return ans;
}

// Ques No. 5 Valid Anagram
// Ques Blog - https://leetcode.com/problems/valid-anagram/solutions/3040185/c-2-approach-tc-o-n-sc-o-1-best-approach/
// Ques Link - https://leetcode.com/problems/valid-anagram/
// Ques Solution - https://www.youtube.com/watch?v=8LDbrlZ7834&ab_channel=codeExplainer

// Approach 1: 
// Simple Brute Force using Sort
// Time Complexity : O(NlogN) Space Complexity : O(1)

bool isAnagram(string s, string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

// Approach 2: (Most Optimised)
// two pointer approach
// Time Complexity : O(N) Space Complexity : O(1)

bool isAnagram(string s, string t){
    if(s.size()!=t.size()){
        return false;
    }
    int arr[26]={0};
    for(int i =0;i<s.size();++i){
        char c = s[i];
        char d = t[i];
        ++arr[c-'a'];
        --arr[d-'a'];
    }
    for(int i =0;i<26;i++){
        if(arr[i]>0){
            return false;
        }
    }
    return true;
}

// Ques No. 6 First Unique Character in a String
// Ques Blog - https://leetcode.com/problems/first-unique-character-in-a-string/solutions/3042179/c-easy-to-understand/
// Ques Link - https://leetcode.com/problems/first-unique-character-in-a-string/
// Ques Solution - https://www.youtube.com/watch?v=sOfJHJH0M7M&ab_channel=codeExplainer

int firstUniqChar(string s){
    int n = s.size();
    vector<int>ans(26);
    for(auto c:s){
        ans[c-'a']++;
    }
    for(int i =0;i<n;++i){
        if(ans[s[i]-'a']==1)
        return i;
    }
    return -1;
}