// Day 3 coding Date-06.01.2023

// Ques No. 1 Running Sum of 1D Array
// Ques Blog - https://leetcode.com/problems/running-sum-of-1d-array/solutions/1136761/running-sum-of-1d-array/?orderBy=most_votes
// Ques Link - https://leetcode.com/problems/running-sum-of-1d-array/
// Ques Solution - https://www.youtube.com/watch?v=fFJaIDUKDoA&ab_channel=KnowledgeCenter

// Approach 1:
// Begin with Brute Force Using two loops
// Time Complexity : O(N*N) Space Complexity : O(N)

vector<int> runningSum(vector<int>&nums){
    int n= nums.size();
    vector<int> res;
    for(int i =0;i<n;++i){
        int sum =0;
        for(int j=0;j<=i;++j){
            sum+=nums[j];
        }
        res.push_back(sum);
    }
    return res;
}

// Approach 2: (Most Optimised)
// Creating current running sum
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> runningSum(vector<int> &nums){
    int n=nums.size();
    for(int i=1;i<n;++i){
        nums[i]+=nums[i-1];
    }
    return nums;
}

// Ques No 2. Remove Element
// Ques Blog - https://leetcode.com/problems/remove-element/solutions/2043915/two-approaches/
// Ques Link - https://leetcode.com/problems/remove-element/
// Ques Solution - https://www.youtube.com/watch?v=QrCds_6NiSk&ab_channel=Technosage

// Approach 1:
// Begin with Brute Force 
// Time Complexity : O(N) Space Complexity : O(N)

int removeElement(vector<int> &nums, int val){
    vector<int> res;
    for(int i =0;i<nums.size();++i){
        if(nums[i]!=val){
            res.push_back(nums[i]);
        }
    }
    for(int i =0;i<res.size();++i){
        nums[i]= res[i];
    }
    return res.size();
}

// Approach 2: (Most Optimised)
// Two Pointer
// Time Complexity : O(N) Space Complexity : O(1)

int removeElement(vector<int> &nums,int val){
    int count=0;
    for(int i =0;i<nums.size();++i){
        if(nums[i]!=val){
            nums[count]=nums[i];
            count++;
        }
    }
    return count;
}

// Ques No 3. Find Winner on a TicTacToe Game
// Ques Blog - https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/solutions/1474694/c-solution-with-explaination/
// Ques Link - https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// Ques Solution - https://www.youtube.com/watch?v=ijI-wzdS79U&t=236s&ab_channel=AnimatedAnand

// Approach 1: (Most Optimised)
// Logical Approach how to win a game Brute Force
// Time Complexity : O(N) Space Complexity : O()

string tictactoe(vector<vector<int>>& moves){
    vector<vector<char>>grid(3,vector<char>(3));
    char val = 'x';
    for(auto it : moves){
        grid[it[0]][it[1]]=val;
        if(val=='x')val='o';
        else val= 'x';
    }
    for(int i =0;i<3;++i){
        if(grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x') return "A";
        if(grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o') return "B";
        if(grid[0][i] == 'x' && grid[1][i] == 'x' && grid[2][i] == 'x') return "A";
        if(grid[0][i] == 'o' && grid[1][i] == 'o' && grid[2][i] == 'o') return "B";
    }
    if(grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x') return "A";
    if(grid[0][2] == 'x' && grid[1][1] == 'x' && grid[2][0] == 'x') return "A";
    if(grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o') return "B";
    if(grid[0][2] == 'o' && grid[1][1] == 'o' && grid[2][0] == 'o') return "B";

    if(moves.size()<9)return "Pending";
    return "Draw";
}

// Ques No 4. Building Array from Permutation
// Ques Blog - https://leetcode.com/problems/build-array-from-permutation/solutions/1820424/brute-force-to-optimized/
// Ques Link - https://leetcode.com/problems/build-array-from-permutation/
// Ques Solution - https://www.youtube.com/watch?v=S9UoX_VNnXo&ab_channel=NikhilSaini

// Approach 1:
// Begin with Brute Force 
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> buildArray(vector<int> &nums){
    vector<int> res(nums.size(),0);
    for(int i =0;i<nums.size();++i){
        res[i]= nums[nums[i]];
    }
    return res;
}

// Approach 2: (Most Optimised)
// simple modulo Property
// Time Complexity : O(N) Space Complexity : O(1)

vector<int> buildArray(vector<int> &nums){
    int n = nums.size();
    for(int i =0;i<n;++i){
        nums[i]=nums[i]+(nums[nums[i]]%n)*n;
    }
    for(int i =0 ;i<n;++i){
        nums[i]=nums[i]/n;
    }
    return nums;
}

// Ques No 5. Third Maximum Number
// Ques Blog - https://leetcode.com/problems/third-maximum-number/solutions/2403488/brute-force-approach-using-vector/
// Ques Link - https://leetcode.com/problems/third-maximum-number/
// Ques Solution - https://www.youtube.com/watch?v=YYoosudLzJ8&ab_channel=EngineeringBrains

// Approach 1:
// Begin with Brute Force & Decreasing order sort
// Time Complexity : O(NlogN) Space Complexity : O(N)

int thirdMax(vector<int>&nums){
    sort(nums.begin(),nums.end(),greater<int>());
    vector<int> res;
    res.push_back(nums[0]);
    for(int i = 1;i<nums.size();++i){
        if(nums[i]!=nums[i-1]){
            res.push_back(nums[i]);
        }
    }
    if(res.size<=2)
    {return res[0];}
    return res[2];
}

// Approach 2: (Most Optimised)
// 3 Variable one two three
// Time Complexity : O(N) Space Complexity : O(1)

int thirdMax(vector<int> &nums){
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    if(n==2){
        return max(nums[0],nums[1]);
    }
    long one=LONG_MIN,two=LONG_MIN,three=LONG_MIN;
    for(auto i : nums){
        if(i==one || i == two || i == three){
            continue;
        }
        if(i>one){
            three=two;
            two=one;
            one = i;
        }
        else if(i>two){
            three=two;
            two=i;
        }
        else if(i>three){
            three=i;
        }
    }
    if(three==LONG_MIN){
        return (int)one;
    }
    return (int)three;
}

// Ques No 6. Valid Mountain Array
// Ques Blog - https://leetcode.com/problems/valid-mountain-array/solutions/451553/c-simple-solution-with-explanations-for-newbies-3/
// Ques Link - https://leetcode.com/problems/valid-mountain-array/
// Ques Solution - https://www.youtube.com/watch?v=Of4DAJHeslE&ab_channel=AyushiSharma

// Approach 1:
// Begin with Brute Force with single pointer
// Time Complexity : O(N) + O(N) Space Complexity : O(1)

bool validMountainArray(vector<int> &arr){
    int n = arr.size();
    if(n<3){
        return false;
    }
    int count=1;
    while(count<n){
        if(arr[count-1]<arr[count]){
            count++;
        }
        else
            break;
    }
    if(count == n || count == 1) return false;
    while(count<n){
        if(arr[count-1]>arr[count]){
            count++;
        }
        else
            break;
    }
    if(count == n) return true;
    else
        return false;
}

// Approach 2: (Most Optimised)
// One  increase pointer 
// Time Complexity : O(N) Space Complexity : O(1)

bool validMountainArray(vector<int> &arr){
    int n =arr.size();
    if(n<3) return false;
    bool inc = true;
    for(int i =1;i<n;i++){
        if(arr[i]<arr[i-1]){
            if(i == 1){
                return false;
            }
            inc= false;
        }
        if(inc == true){
            if(arr[i]<=arr[i-1]){
                return false;
            }
        }
        else{
            if(arr[i]>=arr[i-1]){
                return false;
            }
        }
    }
    if(inc == 1)return false;
    else 
        return true;
}

// Day 3 Completed Ontime