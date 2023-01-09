// Day 6 coding Date-09.01.2023

// Ques No. 1 Intersection of Two Linked Lists (striver sheet day 6 Problem 1)
// Ques Blog - https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
// Ques Link - https://leetcode.com/problems/intersection-of-two-linked-lists/
// Ques Solution - https://www.youtube.com/watch?v=u4FWXfgS8jw&ab_channel=takeUforward
// Ques Solution - https://www.youtube.com/watch?v=DGEqY5rLyVc&ab_channel=Fraz

// Approach 1:
// Simple Brute Force (Iterative)
// Time Complexity : O(M*N) Space Complexity : O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *b=headB;
    while(b!=NULL){
        ListNode*temp=headA;
        while(temp!=NULL){
            if(temp == b)return b;
            temp=temp->next;
        }
        b=b->next;
    }
    return NULL;
}

// Approach 2:
// Using set (Iterative)
// Time Complexity : O(M+N) Space Complexity : O(N)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode * a =headA,*b =headB;
    unordered_set<ListNode *>st;
    while(a!=NULL){
        st.insert(a);
        a=a->next;
    }
    while(b!=NULL){
        if(st.find(b)!=st.end())return b;
        b=b->next;
    }
    return NULL;
}

// Approach 3: (Most Optimised)
// Lenght Difference Clean Code (Iterative)
// Time Complexity : O(M+N) Space Complexity : O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode*first=headA,*second=headB;
    while(first!=second){
        if(first== NULL){
            first=headB;
        }
        else{
            first=first->next;
        }
        if(second == NULL){
            second=headA;
        }
        else{
            second=second->next;
        }
    }
    return first;
}

// Ques No. 2 Intersection of Two Linked Lists (striver sheet day 6 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
// Ques Link - https://leetcode.com/problems/linked-list-cycle/
// Ques Solution - https://www.youtube.com/watch?v=354J83hX7RI&ab_channel=takeUforward
// Ques Solution - https://www.youtube.com/watch?v=nbQUEN3IRFk&ab_channel=Fraz

// Approach 1:
// Simple Brute Force using set (Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

bool hasCycle(ListNode *head){
    unordered_set<ListNode *> st;
    while(head!=NULL){
        if(st.find(head)!=st.end()){
            return true;
        }
        st.insert(head);
        head=head->next;
    }
    return false;
}

// Approach 2: (Most Optimised)
// fast and slow pointer (Iterative)
// Time Complexity : O(N) Space Complexity : O(1)

bool hasCycle(ListNode *head){
    if(head==NULL || head->next==NULL){
        return false;
    }
    ListNode *slow=head,*fast=head;
    while(fast->next!=NULL &&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

// Ques No. 3 Valid Parentheses (striver sheet day 13 Problem 5)
// Ques Blog - https://takeuforward.org/data-structure/check-for-balanced-parentheses/
// Ques Link - https://leetcode.com/problems/valid-parentheses/
// Ques Solution - https://www.youtube.com/watch?v=wkDfsKijrZ8&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=YTcnHHpexXc&ab_channel=HelloWorld

// Approach 1: (Most Optimised)
// Simple Brute Force using Stack (Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

bool isValid(string s){
    stack<char>st;
    for(auto c:s){
        if(st.empty()){
            st.push(c);
        }
        else if((st.top()=='(' && c==')')||(st.top()=='{' && c=='}')|| (st.top()=='[' && c==']')){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    if(st.size()==0){
        return true;
    }
    return false;
}

// Ques No. 4 Implement Queue using Stacks (striver sheet day 13 Problem 4)
// Ques Blog - https://takeuforward.org/data-structure/implement-queue-using-stack/
// Ques Link - https://leetcode.com/problems/implement-queue-using-stacks/
// Ques Solution - https://www.youtube.com/watch?v=3Et9MrMc02A&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=d0l8-7Bv-i0&ab_channel=HelloWorld

// Approach 1: (Most Optimised)
// Simple Brute Force using Stack (Iterative)
// Time Complexity : O(1) Space Complexity : O(2N)

stack<int> input,output;
MyQueue()
{

}
void push(int x){
    input.push(x);
}
int pop(){
    int val = peek();
    output.pop();
    return val;
}
int peek(){
    if(output.empty()){
        while(input.empty()== false){
            output.push(input.top());
            input.pop();
        }
    }
    return output.top();
}
bool empty(){
    return input.empty()&& output.empty();
}

// Ques No. 5 Backspace String Compare 
// Ques Blog - https://leetcode.com/problems/backspace-string-compare/solutions/2000502/c-solution-with-multiple-approach-detailed-explained-with-time-complexity/
// Ques Link - https://leetcode.com/problems/backspace-string-compare/
// Ques Solution - https://www.youtube.com/watch?v=HFaTWyEHMPo&ab_channel=AyushiSharma

// Approach 1: 
// Simple Brute Force using Stack (Iterative)
// Time Complexity : O(N) Space Complexity : O(2N)

bool backspaceCompare(string s, string t){
    stack<char> s1,t1;
    string str1,str2;
    for(int i =0;i<s.size();++i){
        if(s[i]=='#' && !s1.empty()){
            s1.pop();
        }
        else if(s[i]!='#'){
            s1.push(s[i]);
        }
    }
    for(int i =0;i<t.size();++i){
        if(t[i]=='#' && !t1.empty()){
            t1.pop();
        }
        else if(t[i]!='#'){
            t1.push(t[i]);
        }
    }
    while(!s1.empty()){
        str1.push_back(s1.top());
        s1.pop();
    }
    while(!t1.empty()){
        str2.push_back(t1.top());
        t1.pop();
    }
    return str1==str2;
}

// Approach 2: (Most Optimised)
// using Two pointer (Iterative)
// Time Complexity : O(N) Space Complexity : O(1)

bool backspaceCompare(string s, string t) {
    int x=0,y=0;
    for(int i =0;i<s.size();++i){
        if(s[i]=='#'){
            x--;
            x=max(0,x);
        }
        else{
            s[x]=s[i];
            x++;
        }
    }
    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i] == '#')
        {
            y--;
            y = max(0, y);
        }
        else
        {
            t[y] = t[i];
            y++;
        }
    }
    if(x!=y)return false;
    else{
        for(int i = 0;i<x;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
    }
    return true;
}

// Ques No. 6 Next Greater Element I
// Ques Blog - https://leetcode.com/problems/next-greater-element-i/solutions/3018822/0ms-easy-solution-unsing-simple-vector/
// Ques Link - https://leetcode.com/problems/next-greater-element-i/
// Ques Solution - https://www.youtube.com/watch?v=CzBVZPDo1HI&ab_channel=HelloWorld

// Approach 1: (Most Optimised)
// Using Stack && unorderedMap (Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> umap;
    stack<int>st;
    int n=nums2.size();
    for(int i =n-1;i>=0;--i){
        int ele = nums2[i];
        while(!st.empty()&&st.top()<=ele){
            st.pop();  
        }
        int res= (st.empty())? -1:st.top();
        umap.insert({ele,res});
        st.push(ele);
    }
    vector<int>ans;
    for(auto s:nums1){
        ans.push_back(umap[s]);
    }
    return ans;
}

// Ques No. 7 Next Greater Element II (striver sheet day 13 Problem 6)
// Ques Blog - https://takeuforward.org/data-structure/next-greater-element-using-stack/
// Ques Link - https://leetcode.com/problems/next-greater-element-ii/description/
// Ques Solution - https://www.youtube.com/watch?v=Du881K7Jtk8&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=G4yAJ5l29L8&t=467s&ab_channel=HelloWorld

// Approach 1: (Most Optimised)
// Using Stack and Modulo (Iterative)
// Time Complexity : O(N) Space Complexity : O(N)

vector<int> nextGreaterElements(vector<int> &nums) {
    int n=nums.size();
    vector<int>nge(n,-1);
    stack<int>st;
    for(int i = 2*n-1;i>=0;--i){
        while(!st.empty() && st.top()<=nums[i%n]){
            st.pop();
        }
        if(i<n){
            if(!st.empty()){
                nge[i]=st.top();
            }
        }
        st.push(nums[i%n]);
    }
    return nge;
}

// Day 6 Completed Ontime