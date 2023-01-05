// Day 2 coding Date-05.01.2023

// Ques No. 1 Remove Duplicate in an sorted array (striver sheet day 7 Problem 5)
// Ques Blog - https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/
// Ques Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Ques Solution - https://www.youtube.com/watch?v=Fm_p9lJ4Z_8&ab_channel=takeUforward

// Approach 1:
// Begin with Brute Force Using Set
// Time Complexity : O(Nlogn) + O(N) Space Complexity : O(N)

int removeDuplicates(vector<int>&nums){
    set<int> hashSet;
    for(int i = 0;i<nums.size();++i){
        hashSet.insert(nums[i]);
    }
    int valueStoredinSet = hashSet.size();
    int j = 0;
    for(auto val : hashSet){
        nums[j++] = val;
    }
    return valueStoredinSet;
}

// Approach 2: 
// Using STL inbuilt unique function
// Time Complexity : O(NlogN) Space Complexity : O(1)

int removeDuplicates(vector<int>&nums){
    return unique(nums.begin(),nums.end()) - nums.begin();
}

// Approach 3: (Most Optimised)
// Using Two Pointers 
// Time Complexity : O(N) Space Complexity : O(1)

int removeDuplicates(vector<int>&nums){
    if(nums.size()==0){
        return 0;
    }
    int i = 0;
    for(int j=0;j<nums.size();++j){
        if(nums[j]!=nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
// Ques No 2. Remove Duplicate in an sorted array II
// Ques Blog - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/1759409/c-two-methods-easy-implementation/?q=brute+force&orderBy=most_relevant
// Ques Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Ques Solution - https://www.youtube.com/watch?v=drbtmYjZQHQ&ab_channel=AyushiSharma

// Approach 1:
// Begin with Brute Force using Map
// Time Complexity : O(NLogN) Space Complexity : O(N)

int removeDuplicates2(vector<int>&nums){
    map <int,int> hashMap;
    for(auto i : nums){
        hashMap[i]++;
    }
    vector<int> result;
    for(auto it : hashMap){
        result.push_back(it.first);
        if(it.second >= 2){
            result.push_back(it.first);
        }
    }
    nums = result;
    return result.size();
}

// Approach 2: (Most Optimised)
// using Two Pointer
// Time Complexity : O(N) Space Complexity : O(1)

int removeDuplicates2(vector<int> &nums){
    int i = 0;
    for(auto it :nums){
        if(i==0 || i==1 || nums[i-2]!=it){
            nums[i]=it;
            i++;
        }
    }
    return i;
}

// Ques No 3. Find All Numbers Disappeared in an Array
// Ques Blog - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/1584009/from-brute-to-optimized-without-extra-space-c/?q=brute+force&orderBy=most_relevant
// Ques Link - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// Ques Solution - https://www.youtube.com/watch?v=Y5AkrdnUOxs&ab_channel=AshishKumar

// Approach 1:
// Begin with Brute Force using extra vector
// Time Complexity : O(N) + O(N) Space Complexity : O(N)

vector<int> findDisappearedNumbers(vector<int>&nums){
    int n = nums.size();
    vector<int> ans;
    vector<int> temp(n+1,0);
    for(int i = 0;i<n;++i){
        temp[nums[i]] = 1;
    }
    for(int i =1;i<temp.size();++i){
        if(temp[i]==0){
            ans.push_back(i);
        }
    }
    return ans;
}

// Approach 2: (Most Optimised)
// Marking the Index negative
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> findDisappearedNumbers(vector<int> &nums){
    vector<int> result;
    for(int i=0;i<nums.size();++i){
        int index = abs(nums[i]) - 1;
        if(nums[index]>0){
            nums[index]=nums[index]* -1;
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            result.push_back(i+1);
        }
    }
    return result;
}

// Ques No 4. Intersection of Two Arrays
// Ques Blog - https://leetcode.com/problems/intersection-of-two-arrays/solutions/2687174/brute-force-c-solution/
// Ques Link - https://leetcode.com/problems/intersection-of-two-arrays/
// Ques Solution - https://www.youtube.com/watch?v=dTmYy5yCSX8&ab_channel=codeExplainer

// Approach 1:
// Begin with Brute Force using Set
// Time Complexity : O(N^2 * logN(set)) Space Complexity : O(N)

vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
    vector<int>res;
    set<int>s;
    for(int i = 0;i<nums1.size();++i){
        for(int j =0;j<nums2.size();++j){
            if(nums1[i]==nums2[j]){
                s.insert(nums1[i]);
                break;
            }
        }
    }
    for(auto it :s){
        res.push_back(it);
    }
    return res;
}

// Approach 2: (Most Optimised)
// Using Sort, Set and two pointer 
// Time Complexity : O(NlogN) Space Complexity : O(N)

vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    unordered_set<int> s;
    int n=nums1.size();
    int m = nums2.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(nums1[i]>nums2[j]){
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            s.insert(nums1[i]);
            i++;
            j++;
        }
    }
    vector<int> ans;
    for(auto it:s){
        ans.push_back(it);
    }
    return ans;
}

// Ques No 5. Intersection of Two Arrays II
// Ques Blog - https://leetcode.com/problems/intersection-of-two-arrays-ii/solutions/1012318/c-brute-force-solution/?q=brute&orderBy=most_relevant
// Ques Link - https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Ques Solution - https://www.youtube.com/watch?v=dTmYy5yCSX8&ab_channel=codeExplainer

// Approach 1:
// Begin with Brute Force 
// Time Complexity : O(N^2) Space Complexity : O(1)

vector<int> intersect(vector<int> &nums1, vector<int> &nums2){
    vector<int>res;
    for(int i =0;i<nums1.size();++i){
        for(int j =0;j<nums2.size();++j){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                nums2.erase(nums2.begin()  + j);
                j=nums2.size();
            }
        }
    }
    return res;
}

// Approach 2: (Most Optimised)
// Using Sort and two pointer
// Time Complexity : O(NlogN) Space Complexity : O(N)

vector<int> intersect(vector<int> &nums1, vector<int> &nums2){
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int> res;
    int i=0,j=0;
    int m= nums1.size();
    int n = nums2.size();
    while(i<m && j<n){
        if(nums1[i]>nums2[j]){
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            res.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return res;
}

// Ques No 6. Maximum Population Year
// Ques Blog - https://www.youtube.com/watch?v=dTmYy5yCSX8&ab_channel=codeExplainer
// Ques Link - https://leetcode.com/problems/maximum-population-year/
// Ques Solution - https://www.youtube.com/watch?v=dTmYy5yCSX8&ab_channel=codeExplainer

// Approach 1: (Most Optimised)
// By Sweep Algorithms
// Time Complexity : O(N) Space Complexity : O(N)

int maximumPopulation(vector<vector<int>> &logs){
    vector<int>res(2500);
    for(auto it:logs){
        res[it[0]]++;
        res[it[1]]--;
    }
    int maxi = 0;
    int years;
    for(int i =1950;i<=2050;++i){
        res[i]+=res[i-1];
        if(res[i]>maxi){
            maxi = res[i];
            years=i;
        }
    }
    return years;

}

// Ques No 7. Find Pivot Index
// Ques Blog - https://www.youtube.com/watch?v=dTmYy5yCSX8&ab_channel=codeExplainer
// Ques Link - https://leetcode.com/problems/maximum-population-year/
// Ques Solution - https://www.youtube.com/watch?v=dTmYy5yCSX8&ab_channel=codeExplainer

// Approach 1: (Most Optimised)
// Running sum variables
// Time Complexity : O(N) Space Complexity : O(1)

int pivotIndex(vector<int>& nums){
    int sum = 0;
    for(int i = 0;i<nums.size();++i){
        sum+=nums[i];
    }
    int Rsum = sum;
    int Lsum = 0;
    for(int i =0;i<nums.size();++i){
        Rsum-=nums[i];
        if(Rsum==Lsum){
            return i;
        }
        Lsum+=nums[i];
    }
    return -1;
}

// Day 2 Completed Ontime