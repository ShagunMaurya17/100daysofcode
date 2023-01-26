// Day 21 coding Date-24.01.2023

// Ques No. 1 Merge Intervals (striver sheet day 2 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
// Ques Link - https://leetcode.com/problems/merge-intervals/
// Ques Solution - https://www.youtube.com/watch?v=2JzRBPFYbKE&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=g1zOrfmNzvk&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// Brute Force using Sort
// Time Complexity : O(NLogN) Space Complexity : O(1)

vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    if(intervals.size() == 0){
        return ans;
    }
    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
    for(auto it : intervals){
        if(it[0]<=temp[1]){
            temp[1] = max(it[1],temp[1]);
        }
        else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}

// Ques No. 2 Insert Interval
// Ques Blog - https://leetcode.com/problems/insert-interval/solutions/1879461/c-all-possible-solutions/
// Ques Blog2 - https://leetcode.com/problems/insert-interval/solutions/3057466/c-begineer-friendly-easy-understanding-union-find-video-solution/
// Ques Link - https://leetcode.com/problems/insert-interval/
// Ques Solution - https://www.youtube.com/watch?v=NWM4e4yda0w&ab_channel=NareshGupta

// Approach 1: 
// Brute Force using Sort
// Time Complexity : O(NLogN) Space Complexity : O(1)

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval){
    intervals.push_back(newInterval);
    return merge(intervals);
}
vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    if(intervals.size() == 0){
        return ans;
    }
    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
    for(auto it : intervals){
        if(it[0]<=temp[1]){
            temp[1] = max(it[1],temp[1]);
        }
        else{
            ans.push_back(temp);
            temp =it;
        }
    }
    ans.push_back(temp);
    return ans;
}

// Approach 2:  (Most Optimised)
// simply check element and merge it
// Time Complexity : O(N) Space Complexity : O(1)

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval){
    vector<vector<int>> ans;
    for(auto it : intervals){
        if(it[1]<newInterval[0]){
            ans.push_back(it);
        }
        else if(newInterval[1]<it[0]){
            ans.push_back(newInterval);
            newInterval = it;
        }
        else{
            newInterval[0] = min(newInterval[0],it[0]);
            newInterval[1] = max(newInterval[1],it[1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}

// Ques No. 3 Non-overlapping Intervals
// Ques Blog - https://leetcode.com/problems/non-overlapping-intervals/solutions/696715/very-simple-c-solutions-all-four-solutions-compared/
// Ques Blog2 - https://leetcode.com/problems/non-overlapping-intervals/solutions/2580897/java-solution-three-approaches/
// Ques Link - https://leetcode.com/problems/non-overlapping-intervals/
// Ques Solution - https://www.youtube.com/watch?v=evA9Z5p16bI&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// Brute Force using Sort
// Time Complexity : O(NLogN) Space Complexity : O(1)

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    int previous = 0;
    int ans=0;
    for(int current =1;current<n;++current){
        if(intervals[current][0]<intervals[previous][1]){
            ans++;
            if(intervals[current][1]<intervals[previous][1]){
                previous = current;
            }
        }
        else{
            previous = current;
        }
    }
    return ans;
}

// Ques No. 4 Interval List Intersections
// Ques Blog - https://leetcode.com/problems/interval-list-intersections/solutions/647342/c-two-pointer-approach/
// Ques Link - https://leetcode.com/problems/interval-list-intersections/
// Ques Solution - https://www.youtube.com/watch?v=Qh8ZjL1RpLI&ab_channel=TECHDOSE

// Approach 1: (Most Optimised)
// Brute Force using Sort and Two Pointer Approach
// Time Complexity : O(NLogN) Space Complexity : O(1)

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList){
    int n = firstList.size();
    int m = secondList.size();
    int i=0,j=0;
    vector<vector<int>> ans;
    vector<int> temp(2);
    while(i<n && j<m){
        if(secondList[j][0]<=firstList[i][1] && firstList[i][0]<=secondList[j][1]){
            temp[0] = max(firstList[i][0],secondList[j][0]);
            temp[1] = min(firstList[i][1], secondList[j][1]);
            ans.push_back(temp);
        }
        if(firstList[i][1]>secondList[j][1]){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}

// Day 21 Completed +1 day Delay
