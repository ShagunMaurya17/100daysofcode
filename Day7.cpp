// Day 7 coding Date-10.01.2023

// Ques No. 1 Binary Tree Preorder Traversal (striver sheet day 17 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/preorder-traversal-of-binary-tree/
// Ques Link - https://leetcode.com/problems/binary-tree-preorder-traversal/
// Ques Solution - https://www.youtube.com/watch?v=Bfqd8BsPVuw&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=RlUu72JrOCQ&ab_channel=takeUforward

// Approach 1:
// Simple PreOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> result;
    helper(root, result);
    return result;
}
void helper(TreeNode * root,vector<int> & result){
    if(root == NULL){
        return ;
    }
    result.push_back(root->val);
    helper(root->left,result);
    helper(root->right,result);
}

// Approach 2: (Most Optimised)
// Simple PreOrder Traversal with stack(Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int>result;
    stack<TreeNode *> st;
    if(root == NULL){
        return result;
    }
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        result.push_back(root->val);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }
    return result;
}

// Ques No. 2 Binary Tree Inorder Traversal (striver sheet day 17 Problem 1)
// Ques Blog - https://takeuforward.org/data-structure/inorder-traversal-of-binary-tree/
// Ques Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Ques Solution - https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=Z_NEgBgbRVI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=8&ab_channel=takeUforward

// Approach 1:
// Simple InOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>result;
    helper(root,result);
    return result;
}
void helper(TreeNode * root,vector<int>&result){
    if(root == NULL) return;
    helper(root->left,result);
    result.push_back(root->val);
    helper(root->right,result);
}

// Approach 2: (Most Optimised)
// Simple InOrder Traversal with stack(Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> inorderTraversal(TreeNode* root){
    vector<int>result;
    TreeNode *node = root;
    stack<TreeNode *> st;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()== true)break;
            node=st.top();
            st.pop();
            result.push_back(node->val);
            node=node->right;
        }
    }
    return result;
}

// Ques No. 3 Binary Tree Postorder Traversal (striver sheet day 17 Problem 3)
// Ques Blog - https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/
// Ques Link - https://leetcode.com/problems/binary-tree-postorder-traversal/
// Ques Solution - https://www.youtube.com/watch?v=2YBhNLodD8Q&feature=youtu.be&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=COQOU6klsBg&ab_channel=takeUforward
// Ques Solution3 - https://www.youtube.com/watch?v=NzIGLLwZBS8&ab_channel=takeUforward

// Approach 1:
// Simple PostOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

vector<int> postorderTraversal(TreeNode* root){
    vector<int>result;
    helper(root,result);
    return result;
}
void helper(TreeNode * root,vector<int>&result){
    if(root==NULL)return;
    helper(root->left,result);
    helper(root->right,result);
    result.push_back(root->val);
}

// Approach 2: 
// Simple PostOrder Traversal with 2 stack(Iterative)
// Time Complexity : O(N) Space Complexity : O(N+N)

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int>result;
    if(root == NULL)return result;
    stack<TreeNode*> input,output;
    input.push(root);
    while(!input.empty()){
        root  = input.top();
        input.pop();
        output.push(root);
        if(root->left!=NULL){
            input.push(root->left);
        }
        if(root->right!=NULL){
            input.push(root->right);
        }
    }
    while(!output.empty()){
        result.push_back(output.top()->val);
        output.pop();
    }
    return result;
}

// Approach 3: (Most Optimised)
// Simple PostOrder Traversal with a stack(Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> postorderTraversal(TreeNode *root){
    vector<int> result;
    if(root==NULL)return result;
    stack<TreeNode *>st;
    while(root!=NULL || !st.empty()){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        }
        else{
            TreeNode * temp = st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                result.push_back(temp->val);
            while(!st.empty()&& temp ==st.top()->right){
                temp=st.top();
                st.pop();
                result.push_back(temp->val);
            }
        }
        else
        {
            root = temp;
            }
        }
    }
    return result;
}

// Ques No. 4 Maximum Depth of Binary Tree (striver sheet day 18 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/
// Ques Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Ques Solution - https://www.youtube.com/watch?v=eD3tmO66aBA&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=u9gLZIlomn4&ab_channel=HelloWorld

// Approach 1: (Most optimised)
// Simple InOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(height))

int maxDepth(TreeNode* root) {
    if(root == NULL)return 0;
    int leftHeight  = maxDepth(root->left);
    int rightHeight= maxDepth(root->right);
    return 1+max(leftHeight,rightHeight);
}

// Ques No. 5 Invert Binary Tree (striver sheet day 18 Problem 2)
// Ques Blog - https://leetcode.com/problems/invert-binary-tree/solutions/3027143/simple-and-easy-3-solutions-dfs-bfs-stack-and-queue-both/
// Ques Link - https://leetcode.com/problems/invert-binary-tree/
// Ques Solution - https://www.youtube.com/watch?v=VtX0wMGYpEU&ab_channel=CodewithAlisha

// Approach 1: (Most optimised)
// Simple swapping left right (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(height))

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    invertTree(root->left);
    invertTree(root->right);
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

// Ques No. 6 Symmetric Tree (striver sheet day 18 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/check-for-symmetrical-binary-tree/
// Ques Link - https://leetcode.com/problems/symmetric-tree/
// Ques Solution - https://www.youtube.com/watch?v=nKggNAiEpBE&ab_channel=takeUforward

// Approach 1: (Most optimised)
// Simple 2 InOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(height))

bool isSymmetric(TreeNode* root){
    return root==NULL || helper(root->left,root->right);
}
bool helper(TreeNode *left,TreeNode *right){
    if(left==NULL || right==NULL){
        return left == right;
    }
    if(left->val !=right->val)return false;
    return helper(left->left,right->right)&&helper(left->right,right->left);
}

// Ques No. 7 Same tree (striver sheet day 18 Problem 6)
// Ques Blog - https://takeuforward.org/data-structure/check-if-two-trees-are-identical/
// Ques Link - https://leetcode.com/problems/same-tree/
// Ques Solution - https://www.youtube.com/watch?v=BhuvF_-PWS0&ab_channel=takeUforward

// Approach 1: 
// Simple PreOrder Traversal (Recursive)
// Time Complexity : O(N) Space Complexity : O(N)

bool isSameTree(TreeNode *p, TreeNode *q){
    if(p == NULL || q == NULL){
        return p==q;
    }
    return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(q->right,q->right);
}

// Day 7 Completed Ontime