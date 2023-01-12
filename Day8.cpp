// Day 8 coding Date-11.01.2023

// Ques No. 1  Minimum Time to Collect All Apples in a Tree
// Ques Blog - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Minimum%20Time%20to%20Collect%20All%20Apples%20in%20a%20Tree.cpp
// Ques Link - https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
// Ques Solution - https://www.youtube.com/watch?v=qSBvKlUq0xo&ab_channel=codestorywithMIK

// Approach 1: (Most Optimised)
// Simple DFS (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

int dfs(unordered_map<int,vector<int>> &adj,int curr,int parent,vector<bool> &hasApple){
    int time = 0;
    for(auto &child : adj[curr]){
        if(child == parent) continue;
        int my_child = dfs(adj,child,curr,hasApple);
        if(my_child>0 || hasApple[child]){
            time+=my_child + 2;
        }
    }
    return time;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple){
    unordered_map<int,vector<int>> adj;
    for(auto &vec : edges){
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return dfs(adj,0, -1, hasApple);
}

// Ques No. 2 Subtree of Another Tree 
// Ques Blog - https://leetcode.com/problems/subtree-of-another-tree/solutions/3025410/easy-intuitive-approach-c-recursive-solution/
// Ques Link - https://leetcode.com/problems/subtree-of-another-tree/
// Ques Solution - https://www.youtube.com/watch?v=lrJaof9s4o0&ab_channel=HelloWorld

// Approach 1: (Most Optimised)
// Simple inOrder Traversal (Recursive)
// Time Complexity : O(M+N) Space Complexity : O(1) RSS(O(M+N))

bool ans=false;
bool match(TreeNode* root, TreeNode* subRoot){
    if(root!=NULL && subRoot !=NULL){
        bool a = match(root->left,subRoot->left);
        bool b = match(root->right,subRoot->right);
        if((root->val == subRoot->val)&& a && b ){
            return true;
        }
        else{
            return false;
        }
    }
    else if (root == NULL && subRoot == NULL){
        return true;
    }
    else {
        return false;
    }
}
void inorder(TreeNode* root, TreeNode* subRoot){
    if(root!=NULL){
        inorder(root->left,subRoot);
        bool x=match(root,subRoot);
        if(x){
            ans=x;
        }
        inorder(root->right,subRoot);
    }
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    inorder(root,subRoot);
    return ans;
}

// Ques No. 3 Diameter of Binary Tree (striver sheet day 18 Problem 3)
// Ques Blog - https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
// Ques Link - https://leetcode.com/problems/diameter-of-binary-tree/
// Ques Solution - https://www.youtube.com/watch?v=Rezetez59Nk&ab_channel=takeUforward

// Approach 1:  (Most Optimised)
// Simple PreOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = 0;
    height(root, maxi);
    return maxi;
}
int height(TreeNode *node, int &maxi)
{
    if (node == NULL)
    {
        return 0;
    }
    int lh = height(node->left, maxi);
    int rh = height(node->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}

// Ques No. 4 Balanced Binary Tree (striver sheet day 18 Problem 4)
// Ques Blog - https://takeuforward.org/data-structure/check-if-the-binary-tree-is-balanced-binary-tree/
// Ques Link - https://leetcode.com/problems/balanced-binary-tree/
// Ques Solution - https://www.youtube.com/watch?v=Yt50Jfbd8Po&ab_channel=takeUforward

// Approach 1:
// Simple max height left and right (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

bool isBalanced(TreeNode* root) {
    return maxHeight(root) != -1;
}
int maxHeight(TreeNode * root){
    if(root == NULL) return 0;
    int leftHeight = maxHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = maxHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight-rightHeight)>1)return -1;
    return max(leftHeight,rightHeight)+1;
}

// Ques No. 5 Merge Two Binary Trees
// Ques Blog - https://leetcode.com/problems/merge-two-binary-trees/solutions/3030602/c-easy-and-fast-tc-o-n-recursion/?orderBy=newest_to_oldest
// Ques Link - https://leetcode.com/problems/merge-two-binary-trees/
// Ques Solution - https://www.youtube.com/watch?v=Go1VKX1Uae4&ab_channel=CodewithAlisha

// Approach 1: (Most Optimised)
// Simple brute force (Recursive)
// Time Complexity : O(N+M) Space Complexity : O(1) RSS(O(N+M))

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2){
    if(!root1) return root2;
    if(!root2) return root1;
    
    root1->val +=root2->val;
    root1->left = mergeTrees(root1->left,root2->left);
    root1->right = mergeTrees(root1->right,root2->right);
    return root1;
}

// Day 8 Completed Ontime