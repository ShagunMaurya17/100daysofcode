// Day 24 coding Date-27.01.2023

// Ques No. 1 Permutation in String
// Ques Blog - https://leetcode.com/problems/permutation-in-string/solutions/1761911/c-multiple-approaches-detailed-explaination/
// Ques Blog2 - https://leetcode.com/problems/permutation-in-string/solutions/1762171/c-sliding-window-approach-same-as-anagrams-with-explanation/
// Ques Blog3 - https://leetcode.com/problems/permutation-in-string/solutions/1762432/c-build-logic-step-by-step-full-explanation-w-commented-code-sliding-window/
// Ques Link - https://leetcode.com/problems/permutation-in-string/
// Ques Solution - https://www.youtube.com/watch?v=XFh_AoEdOTw&ab_channel=TECHDOSE

// Approach 1: 
// Brute Force Using SubStr()
// Time Complexity : O(N*N) Space Complexity : O(1)

bool checkInclusion(string s1, string s2){
    int m = s1.size(),n = s2.size();
    if(m>n)return false;
    sort(s1.begin(),s1.end());
    string temp;
    for(int i =0;i<n-m+1;++i){
        temp = s2.substr(i,m);
        sort(temp.begin(),temp.end());
        if(temp == s1){
            return true;
        }
    }
    return false;
}

// Approach 2: (Most Optimised)
// char array frequency and sliding window
// Time Complexity : O(N*N) Space Complexity : O(1)

bool checkInclusion(string s1, string s2){
    int m = s1.size(),n = s2.size();
    if(m>n) return false;
    int count =0;
    vector<int> freq1(26,0),freq2(26,0);
    for(auto c :s1){
        freq1[c-'a']++;
    }
    for(int i =0;i<n;++i){
        if(count<m){
            freq2[s2[i] - 'a']++;
            count++;
        }
        if(count == m){
            if(freq1 == freq2){
                return true;
            }
            freq2[s2[i-count+1] - 'a']--;
            count--;
        }
    }
    return false;
}

// Ques No. 2 Wiggle Sort II
// Ques Blog - https://leetcode.com/problems/wiggle-sort-ii/solutions/77677/o-n-o-1-after-median-virtual-indexing/
// Ques Blog2 - https://leetcode.com/problems/wiggle-sort-ii/solutions/2960308/c-fill-lo-then-hi-sort-or-dutchflagsort/
// Ques Link - https://leetcode.com/problems/wiggle-sort-ii/
// Ques Solution - https://www.youtube.com/watch?v=mwsjU6CHOb4&ab_channel=Pepcoding

// Approach 1:
// Using sort
// Time Complexity : O(NLogN) Space Complexity : O(1)

void wiggleSort(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end(),greater<int> ());
    int j =0;
    vector<int> v(n);
    for(int i =1;i<n;i+=2){
        v[i] = nums[j++];
    }
    for(int i =0;i<n;i+=2){
        v[i] = nums[j++];
    }
    nums =v;
}

// Approach 2:
// Using sort and Two Pointer a little bit Optimised
// Time Complexity : O(NLogN) Space Complexity : O(1)

void wiggleSort(vector<int> &nums){
    int n = nums.size();
    int i =1,j=n-1;
    vector<int> temp(n);
    sort(nums.begin(),nums.end());
    while(i<n){
        temp[i] = nums[j];
        i+=2;
        j--;
    }
    i=0;
    while(i<n){
        temp[i] = nums[j];
        i+=2;
        j--;
    }
    int p =0;
    for(auto it : temp){
        nums[p++] = it;
    }
}

// Approach 3: (Most Optimised)
// Using Modified Dutch Flag algo
// Time Complexity : O(N) Space Complexity : O(1)

void wiggleSort(vector<int> &nums){
    int n = nums.size();
    auto midptr = nums.begin()+n/2;
    nth_element(nums.begin(),midptr,nums.end());
    int mid = *midptr;
    int i =1,j=n%2 ==0?n-2:n-1,p = 0;
    while(p<n){
        if(nums[p]>mid && (p>i || p%2 ==0)){
            swap(nums[p],nums[i]);
            i+=2;
        }
        else if(nums[p]<mid && (p<j || p%2 ==1)){
            swap(nums[p],nums[j]);
            j-=2;
        }
        else p++;
    }
}

// Ques No. 3 Max Chunks To Make Sorted
// Ques Blog - https://leetcode.com/problems/max-chunks-to-make-sorted/solutions/1083242/detailed-explaination-c-without-extra-space/
// Ques Blog2 - https://leetcode.com/problems/max-chunks-to-make-sorted/solutions/301639/c-3-methods/
// Ques Link - https://leetcode.com/problems/max-chunks-to-make-sorted/
// Ques Solution - https://www.youtube.com/watch?v=XZueXHOhO5E&ab_channel=Pepcoding

// Approach 1: (Most Optimised)
// Using chaining technique
// Time Complexity : O(N) Space Complexity : O(1)

int maxChunksToSorted(vector<int>& arr) {
    int count =0;
    int maxi =0;
    for(int i =0;i<arr.size();++i){
        maxi = max(maxi,arr[i]);
        if(maxi == i){
            count++;
        }
    }
    return count;
}

// Ques No. 4 H-Index II
// Ques Blog - https://leetcode.com/problems/h-index-ii/solutions/3026671/c-easy-solution-binary-search/?orderBy=newest_to_oldest
// Ques Blog2 - https://leetcode.com/problems/h-index-ii/solutions/693730/o-n-and-log-n-approaches-explained/
// Ques Link - https://leetcode.com/problems/h-index-ii/
// Ques Solution - https://www.youtube.com/watch?v=CjKJDloMnwE&ab_channel=TECHDOSE

// Approach 1:
// Using Linear search
// Time Complexity : O(N) Space Complexity : O(1)

int hIndex(vector<int>& citations){
    int n = citations.size();
    int maxi =0;
    for(int i =0;i<n;++i){
        maxi = max(maxi,min(citations[i],n-i));
    }
    return maxi;
}

// Approach 2: (Most Optimised)
// Using Binary Search
// Time Complexity : O(logN) Space Complexity : O(1)

int hIndex(vector<int>& citations) {
    int n = citations.size();
    int low = 0,high =n-1;
    while(low<=high){
        int mid = low + high-low/2;
        if(citations[mid] == (n-mid)){
            return citations[mid];
        }
        else if(citations[mid]>(n-mid)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return n-low;
}

// Ques No. 5 H-Index
// Ques Blog - https://leetcode.com/problems/h-index/solutions/2815495/bucket-sort-solution-with-time-complexity-o-n/?orderBy=newest_to_oldest&languageTags=cpp
// Ques Link - https://leetcode.com/problems/h-index/
// Ques Solution - https://www.youtube.com/watch?v=wjOjCfkv1mg&ab_channel=TECHDOSE

// Approach 1:
// Using sort and binary search
// Time Complexity : O(NLogN) Space Complexity : O(1)

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + high - low / 2;
        if (citations[mid] == (n - mid))
        {
            return citations[mid];
        }
        else if (citations[mid] > (n - mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n - low;
}

// Approach 2: (Most Optimised)
// Using Bucket Sort and vector array
// Time Complexity : O(N) Space Complexity : O(N)

int hIndex(vector<int> &citations){
    int n = citations.size();
    vector<int> freq(n+1,0);
    for(auto &c : citations){
        freq[min(c,n)]++;
    }
    int ans = 0;
    for(int i =n ;i>=1;--i){
        ans += freq[i];
        if(ans>=i){
            return i;
        }
    }
    return ans;
}