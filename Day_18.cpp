// Day 18 coding Date-21.01.2023

// Ques No. 1 Word Pattern
// Ques Blog - https://leetcode.com/problems/word-pattern/solutions/1194802/100-faster-code-with-explanation/
// Ques Link - https://leetcode.com/problems/word-pattern/
// Ques Solution - https://www.youtube.com/watch?v=XO4U2KWgIgY&t=217s&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// Brute Force using Map and Set
// Time Complexity : O(N) Space Complexity : O(N)

bool wordPattern(string pattern, string s){
    vector<string> v;
    int i =0;
    string temp =  "";
    while(i<s.size()){
        if(s[i] == ' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp += s[i];
        }
        i++;
    }
    v.push_back(temp);
    if(pattern.size()!= v.size()) return false;
    unordered_map<char,string> mp;
    unordered_set<string> st;
    for(int i = 0;i< pattern.size();++i){
        if(mp.find(pattern[i])!=mp.end()){
            if(mp[pattern[i]]!=v[i]){
                return false;
            }
        }
        else{
            if(st.count(v[i])>0){
                return false;
            }
            mp[pattern[i]] = v[i];
            st.insert(v[i]);
        }
    }
    return true;

}

// Ques No. 2 Word Pattern
// Ques Blog - https://leetcode.com/problems/number-of-good-pairs/solutions/1622683/brute-and-optimal-approaches/
// Ques Link - https://leetcode.com/problems/number-of-good-pairs/
// Ques Solution - https://www.youtube.com/watch?v=qvQSvQaY9KI&ab_channel=codeExplainer

// Approach 1: 
// Brute Force 
// Time Complexity : O(N*N) Space Complexity : O(1)

int numIdenticalPairs(vector<int> &nums){
    int n = nums.size();
    int result =0;
    for(int i =0;i<n-1;++i){
        for(int j= i+1;j<n;++j){
            if(nums[i] ==  nums[j]){
                result++;
            }
        }
    }
    return result;
}

// Approach 2: (Most Optimised)
// Brute Force using Map 
// Time Complexity : O(N) Space Complexity : O(N)

int numIdenticalPairs(vector<int> &nums){
    int result = 0;
    unordered_map<int,int> mp;
    for(int i =0;i<nums.size();++i){
        result += mp[nums[i]];
        mp[nums[i]]++;
    }
    return result;
}

// Ques No 3. Flood Fill
// Ques Blog - https://takeuforward.org/graph/flood-fill-algorithm-graphs/
// Ques Link -  https://leetcode.com/problems/flood-fill/
// Ques Solution - https://www.youtube.com/watch?v=C-2_uSRli8o&ab_channel=takeUforward

// Approach 1: 
// Simple Dfs with using new graph
// Time Complexity : O(N*M) Space Complexity : O(M*N) RSS(O(M*N))

private:
void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>>&image,int newcolor,int delRow[],int delCol[],int iniColor){
    ans[row][col] = newcolor;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0 ;i<4;++i){
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && image[nrow][ncol] == iniColor && ans[nrow][ncol]!= newcolor){
            dfs(nrow,ncol,ans,image,newcolor,delRow,delCol,iniColor);
        }
    }
}

public:
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[]={-1,0,+1,0};
    int delCol[] = {0,-1,0,+1};
    dfs(sr,sc,ans,image,color,delRow,delCol,iniColor);
    return ans;
}

// Approach 2: (Most Optimised)
// Simple Dfs without using new graph
// Time Complexity : O(N*M) Space Complexity : O(1) RSS(O(M*N))

private:
void dfs1(vector<vector<int>> & image, int color,int startColor,int i ,int j){
    int m = image.size();
    int n = image[0].size();
    if(i<0 || j<0) return;
    if(i>=m || j>=n) return;
    if(image[i][j]!= startColor)return;
    image[i][j] = color;
    dfs1(image,color,startColor,i-1,j);
    dfs1(image, color, startColor, i+1, j);
    dfs1(image, color, startColor, i, j-1);
    dfs1(image, color, startColor, i, j+1);
}

public:
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int startColor = image[sr][sc];
    if(startColor != color){
        dfs1(image,color,startColor,sr,sc);
    }
    return image;
}

// Ques No 4. Island Perimeter
// Ques Blog - https://leetcode.com/problems/island-perimeter/solutions/2285887/c-beats-100-recursion-dfs-easy/
// Ques Link - https://leetcode.com/problems/island-perimeter/
// Ques Solution - https://www.youtube.com/watch?v=KEyd_d9EA0c&ab_channel=Codebix

// Approach 1: (Most Optimised)
// Simple Dfs 
// Time Complexity : O(N*M) Space Complexity : O(1) RSS(O(M*N))

int count =0;
void dfs(vector<vector<int>>&grid , int i ,int j){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0){
        count++;
        return;
    }
    if(grid[i][j] == -1)return;
    grid[i][j] = -1;
    dfs(grid,i-1,j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
}
int islandPerimeter(vector<vector<int>> &grid){
    for(int i =0;i<grid.size();++i){
        for(int j =0;j<grid[0].size();++j){
            if(grid[i][j] == 1){
                dfs(grid,i,j);
                break;
            }
        }
    }
    return count;
}

// Ques No 5. Find if Path Exists in Graph
// Ques Blog - https://leetcode.com/problems/find-if-path-exists-in-graph/solutions/3080483/c-dfs-solution/
// Ques Link - https://leetcode.com/problems/find-if-path-exists-in-graph/
// Ques Solution - https://www.youtube.com/watch?v=Eso1Lu4mtmU&t=9s&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// Simple Dfs 
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(M*N))
bool dfs(vector<vector<int>> &graph,vector<int>&visited,int current,int end){
    if(current == end){
        return true;
    }
    if(visited[current]){
        return false;
    }
    visited[current] = 1;
    for(int i =0;i<graph[current].size();++i){
        if(dfs(graph,visited,graph[current][i],end)){
            return true;
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination){
    vector<vector<int>> graph(n);
    for(int i =0;i<edges.size();++i){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n,0);
    return dfs(graph,visited,source,destination);
}

// Day 18 Completed Ontime