// Day 8 coding Date-11.01.2023

// Ques No. 1  Path Sum
// Ques Blog - https://leetcode.com/problems/path-sum/solutions/2660366/c-simple-and-concise-o-n-dfs-detailed-explanation/
// Ques Link - https://leetcode.com/problems/path-sum/
// Ques Solution - https://www.youtube.com/watch?v=3LKHFfuqlIg&ab_channel=Pepcoding

// Approach 1: (Most Optimised)
// Simple DFS (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(h))

bool hasPathSum(TreeNode *root, int targetSum) {
    if(root == NULL){
        return false;
    }
    targetSum -= root->val;
    if(targetSum == 0 && root->left == NULL && root->right == NULL){
        return true;
    }
    bool left = hasPathSum(root->left,targetSum);
    bool right = hasPathSum(root->right,targetSum);
    return left || right;
}

// Ques No. 2  Binary Tree Paths
// Ques Blog - https://leetcode.com/problems/path-sum/solutions/2660366/c-simple-and-concise-o-n-dfs-detailed-explanation/
// Ques Link - https://leetcode.com/problems/binary-tree-paths/
// Ques Solution - https://www.youtube.com/watch?v=gSFcPOPyq-Y&ab_channel=codeExplainer

// Approach 1: (Most Optimised)
// Simple DFS (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(h))

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string>ans;
    vector<int> path;
    solve(root,path,ans);
    return ans;
}
void solve(TreeNode *&root,vector<int>&path,vector<string>&ans){
    if(root==NULL)return;
    if(root->left == NULL && root->right ==NULL){
        path.push_back(root->val);
        ans.push_back(convert(path));
        path.pop_back();
        return;
    }
    path.push_back(root->val);
    solve(root->left,path,ans);
    solve(root->right,path,ans);
    path.pop_back();
    return;
}
string convert(vector<int>&path){
    string ans= "";
    int n = path.size();
    for(int i =0;i<n-1;++i){
        ans+=to_string(path[i]);
        ans.push_back('-');
        ans.push_back('>');
    }
    ans+=to_string(path[n-1]);
    return ans;
}

// Ques No. 3  Cousins in Binary Tree
// Ques Blog - https://gist.github.com/SuryaPratapK/c8bde7ae3b860c181be47250792db713
// Ques Link - https://leetcode.com/problems/cousins-in-binary-tree/
// Ques Solution - https://www.youtube.com/watch?v=UyxnGWMvxwc&ab_channel=TECHDOSE

// Approach 1: (Most Optimised)
// Simple DFS (Recursive)
// Time Complexity : O(2N) Space Complexity : O(1) RSS(O(h))

bool isCousins(TreeNode *root, int x, int y){
    if(root->val == x || root->val ==y)return false;
    int xparent = -1;
    int xHeight = findHeight(root,xparent,x,0);
    int yparent = -1;
    int yHeight = findHeight(root,yparent,y,0);
    if(xparent!=yparent && xHeight == yHeight){
        return true;
    }
    return false;
}
int findHeight(TreeNode *root, int &parent, int value,int height){
    if(root == NULL){
        return 0;
    }
    if(root->val == value){
        return height;
    }
    parent = root->val;
    int left = findHeight(root->left,parent,value,height+1);
    if(left){
        return left;
    }
    parent = root->val;
    int right = findHeight(root->right,parent,value,height+1);
    return right;
}

// Ques No. 4  Convert Sorted Array to Binary Search Tree
// Ques Blog - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/solutions/2404906/easy-solution-beginner-friendly-best-method/
// Ques Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Ques Solution - https://www.youtube.com/watch?v=HdR8Aeq_TkU&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// Simple function call (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(n))

TreeNode *sortedArrayToBST(vector<int> &nums){
    if(nums.size()==0)return NULL;
    return bst(nums,0,nums.size()-1);
}
TreeNode *bst(vector<int>&nums,int left,int right){
    if(left>right){
        return NULL;
    }
    int mid = left +(right-left)/2;
    TreeNode * node = new TreeNode(nums[mid]);
    node->left = bst(nums,left,mid-1);
    node->right = bst(nums,mid+1,right);
    return node;

}

// Ques No. 5 Range Sum of BST
// Ques Blog - https://github.com/Ayu-99/Data-Structures/blob/master/Leetcode%20Challenge/December/Range%20Sum%20of%20BST.cpp
// Ques Link - https://leetcode.com/problems/range-sum-of-bst/
// Ques Solution - https://www.youtube.com/watch?v=wIloFJzSOfE&ab_channel=AyushiSharma

// Approach 1: (Most Optimised)
// Simple function call (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(h))

int rangeSumBST(TreeNode *root, int low, int high){
    if(root==NULL)return 0;
    if(root->val>=low &&root->val<=high){
        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
    else if(root->val<low){
        return rangeSumBST(root->right,low,high);
    }
    else{
        return rangeSumBST(root->left,low,high);
    }
}