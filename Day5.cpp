// Day 5 coding Date-08.01.2023

// Ques No. 1 Reverse Linked List (striver sheet day 5 Problem 1)
// Ques Blog - https://takeuforward.org/data-structure/reverse-a-linked-list/
// Ques Link - https://leetcode.com/problems/reverse-linked-list/
// Ques Solution - https://www.youtube.com/watch?v=iRtLEoL-r-g&t=12s&ab_channel=takeUforward

// Approach 1: 
// Three Pointer Approach(Iterative)
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *reverseList(ListNode *head) {
    ListNode * prev_ptr = NULL;
    ListNode * current_ptr = head;
    ListNode * next_ptr ;
    while(current_ptr){
        next_ptr = current_ptr->next;
        current_ptr->next = prev_ptr;
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }
    head = prev_ptr;
    return head;
}

// Approach 2:
// Three Pointer Approach(Recursive)
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *reverseList(ListNode * &head) {
    if(head==NULL || head->next == NULL){
        return head;
    }
    ListNode * newNode = reverseList(head->next);
    head ->next->next = head;
    head->next = NULL;
    return newNode;
}

// Approach 3: (Most Optimised)
// Two Pointer Approach(Recursive)
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *reverseList(ListNode *&head) {
    ListNode * newHead = NULL;
    while(head!= NULL){
        ListNode * next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

// Ques No. 2 Remove Linked List Elements
// Ques Blog - https://leetcode.com/problems/remove-linked-list-elements/submissions/873903087/
// Ques Link - https://leetcode.com/problems/remove-linked-list-elements/
// Ques Solution - https://www.youtube.com/watch?v=JrRoR7ycM8U&ab_channel=Fraz

// Approach 1:
// Simple Brute Force (Iterative)
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *removeElements(ListNode *head, int val){
    if(head == NULL) return NULL;
    ListNode * dummy = new ListNode(-1);
    dummy -> next = head;
    ListNode * tail = dummy;
    while(tail != NULL && tail -> next != NULL){
        if(tail->next->val == val){
            ListNode * temp = tail ->next;
            tail->next = temp->next;
            delete temp;
        }
        else{
            tail =tail->next;
        }
    }
    return dummy->next;
}

// Approach 2:
// Simple Brute Force (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

ListNode *removeElements(ListNode *&head, int val){
    if(head == NULL) return NULL;
    head->next = removeElements(head->next,val);
    if(head->val == val){
        ListNode * ans = head->next;
        delete head;
        return ans;
    }
    else{
        return head;
    }
}

// Approach 3: (Most Optimise)
// Three lines (Recursive)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

ListNode *removeElements(ListNode *&head, int val)
{
    if (head == NULL)
        return NULL;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next:head;
}

// Ques No. 3 Remove Duplicates from Sorted List (striver sheet day 7 Problem 5)
// Ques Blog - https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/873976585/
// Ques Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Ques Solution - https://www.youtube.com/watch?v=_Dc1IqY2WpQ&ab_channel=Fraz

// Approach 1:
// Simple Brute Force (Recursion)
// Time Complexity : O(N) Space Complexity : O(1) RSS(O(N))

ListNode *deleteDuplicates(ListNode *&head){
    if(head == NULL || head->next == NULL) return head;
    ListNode * newHead = deleteDuplicates(head->next);
    if(head->val == newHead->val)return newHead;
    else{
        head->next=newHead;
        return head;
    }
}

// Approach 2: (Most Optimised)
// Simple Brute Force (Iterative)
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *deleteDuplicates(ListNode *&head){
    if(head == NULL || head->next == NULL)return head;
    ListNode * temp =head;
    while(temp->next!=NULL){
        if(temp->val == temp->next->val){
            ListNode * delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

// Ques No. 4 Merge Two Sorted Lists (striver sheet day 5 Problem 3)
// Ques Blog - https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
// Ques Link - https://leetcode.com/problems/merge-two-sorted-lists/
// Ques Solution - https://www.youtube.com/watch?v=Xb4slcp1U38&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=0QPpgAsd4IY&ab_channel=Fraz

// Approach 1:
// Simple Brute Force (Recursion)
// Time Complexity : O(N+M) Space Complexity : O(1) RSS(O(N+M))

ListNode * Merge(ListNode* l1,ListNode* l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    if(l1->val<l2->val){
        l1->next = Merge(l1->next,l2);
        return l1;
    }
    else{
        l2->next = Merge(l1,l2->next);
        return l2;
    }
}
ListNode * mergeTwoLists(ListNode *list1, ListNode *list2) {
    return Merge(list1,list2);
}

// Approach 2: (Most Optimised)
// Simple Brute Force (Iterative)
// Time Complexity : O(N+M) Space Complexity : O(1)

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    ListNode* ans,*tail;
    if(list1->val<list2->val){
        ans=list1;
        tail= list1;
        list1=list1->next;
    }
    else{
        ans=list2;
        tail=list2;
        list2=list2->next;
    }
    while(list1!=NULL&&list2!=NULL){
        if(list1->val<list2->val){
            tail->next=list1;
            tail=list1;
            list1=list1->next;
        }
        else{
            tail->next=list2;
            tail=list2;
            list2=list2->next;
        }
    }
    if(list1 == NULL) tail->next=list2;
    else{
        tail->next=list1;
    }
    return ans;
}

// Ques No. 5 Middle of the Linked List (striver sheet day 5 Problem 2)
// Ques Blog - https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
// Ques Link - https://leetcode.com/problems/middle-of-the-linked-list/
// Ques Solution - https://www.youtube.com/watch?v=sGdwSH8RK-o&t=1s&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=5blSG0JZNbg&ab_channel=Fraz

// Approach 1:
// Simple Brute Force 
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *middleNode(ListNode *head){
    int n=0;
    ListNode * temp=head;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    int half=n/2;
    temp=head;
    while(half--){
        temp=temp->next;
    }
    return temp;
}

// Approach 2: (Most Optimised)
// fast and slow pointer
// Time Complexity : O(N) Space Complexity : O(1)

ListNode *middleNode(ListNode *head){
    ListNode *slow=head,*fast=head;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

// Ques No. 6 Palindrome Linked List (striver sheet day 6 Problem 4)
// Ques Blog - https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
// Ques Link - https://leetcode.com/problems/palindrome-linked-list/
// Ques Solution - https://www.youtube.com/watch?v=-DtNInqFUXs&ab_channel=takeUforward
// Ques Solution2 - https://www.youtube.com/watch?v=XYY2tc_8KDM&ab_channel=Fraz

// Approach 1:
// Simple Brute Force with vector
// Time Complexity : O(N) Space Complexity : O(N)

bool isPalindrome(ListNode *head) {
    vector<int>res;
    while(head!=NULL){
        res.push_back(head->val);
        head=head->next;
    }
    int n=res.size();
    for(int i =0;i<n/2;++i){
        if(res[i]!=res[n-i-1]) return false;
    }
    return true;
}

// Approach 2: (Most Optimised)
// half reversal
// Time Complexity : O(N/2+N/2+N/2) Space Complexity : O(N)

ListNode* Reverse(ListNode* &head){
    if(head==NULL) return NULL;
    ListNode * newhead = NULL;
    while(head!=NULL){
        ListNode*next = head->next;
        head->next= newhead;
        newhead=head;
        head=next;
    }
    return newhead;
}

bool isPalindrome(ListNode *head){
    ListNode *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow= slow->next;
        fast=fast->next->next;
    }
    slow->next=Reverse(slow->next);
    ListNode*start=head,*mid = slow->next;
    while(mid!=NULL){
        if(mid->val != start->val){
            return false;
        }
        start = start->next;
        mid=mid->next;
        
    }
    slow->next=Reverse(slow->next);
    return true;
}

// Day 5 Completed Ontime