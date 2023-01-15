// Day 12 coding Date-15.01.2023

// Ques No. 1  Defanging an IP Address
// Ques Link - https://leetcode.com/problems/defanging-an-ip-address/

// Approach 1:
// Simple Brute Force
// Time Complexity : O(N) Space Complexity : O(1)

string defangIPaddr(string address) {
    string ans = "";
    for(int i = 0;i<address.size();++i){
        if(address[i] == '.'){
            ans += "[.]";
        }
        else{
            ans += address[i];
        }
    }
    return ans;

}

// Ques No. 2  Reverse Only Letters
// Ques Blog - https://leetcode.com/problems/reverse-only-letters/solutions/3035159/easy-solution-c-0ms-happy-coding/
// Ques Link - https://leetcode.com/problems/reverse-only-letters/description/
// Ques Solution - https://www.youtube.com/watch?v=N3LdO9RL0tQ&ab_channel=ShashwatTiwari

// Approach 1:
// Simple Brute Force two pointer
// Time Complexity : O(N) Space Complexity : O(1)

string reverseOnlyLetters(string s){
    int i =0;
    int j =s.size()-1;
    while(i<j){
        if(!((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))){
            ++i;
            continue;
        }
        if (!((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z'))){
            --j;
            continue;
        }
        swap(s[i++],s[j--]);
    }
    return s;
}

// Ques No. 3 Reverse Vowels of a String
// Ques Blog - https://leetcode.com/problems/reverse-vowels-of-a-string/solutions/3043969/easy-solution-using-two-pointer-in-c/
// Ques Link - https://leetcode.com/problems/reverse-vowels-of-a-string/
// Ques Solution - https://www.youtube.com/watch?v=f8cIGIPMtOc&ab_channel=codeExplainer

// Approach 1:
// Simple Brute Force two pointer
// Time Complexity : O(N) Space Complexity : O(1)

string reverseVowels(string s){
    int left =0;
    int right = s.size()-1;
    while(left<right){
        if(isVowel(s[left]) && isVowel(s[right])){
            swap(s[left++],s[right--]);
        }
        else if(!isVowel(s[left])){
            left++;
        }
        else{
            right--;
        }
    }
    return s;
}
bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || 
    c == 'O' || c == 'I' || c == 'U' ;
}

// Ques No. 4 Length of Last Word
// Ques Blog - https://leetcode.com/problems/length-of-last-word/solutions/3048547/c-easy-approach/
// Ques Link - https://leetcode.com/problems/length-of-last-word/
// Ques Solution - https://www.youtube.com/watch?v=lGMHQQV4Tig&ab_channel=FarjeeGuruji

// Approach 1:
// Simple Brute Force and count
// Time Complexity : O(N) Space Complexity : O(1)

int lengthOfLastWord(string s) {
    int count =0;
    bool flag = false;
    for(int i = s.size()-1;i>=0;--i){
        if(s[i] == ' ' && flag == true){
            break;
        }
        else if( s[i]!= ' '){
            flag = true;
            ++count;
        }
    }
    return count;
}

// Ques No. 5 Add Strings
// Ques Blog - https://leetcode.com/problems/add-strings/solutions/3043815/simple-c-solution-using-for-loop/
// Ques Link - https://leetcode.com/problems/add-strings/
// Ques Solution - https://www.youtube.com/watch?v=xlPIH9216Ak&ab_channel=CodewithAlisha

// Approach 1:
// Simple Brute Force 
// Time Complexity : O(N) Space Complexity : O(1)

string addStrings(string num1, string num2){
    int n1 = num1.size()-1;
    int n2 = num2.size()-1;
    int carry = 0;
    string ans;
    while(n1>=0 || n2>=0){
        if(n1<0){
            ans.push_back(((num2[n2]-48 + carry)%10)+48);
            carry = ((num2[n2]-48 + carry)/10);
            n2--;
        }
        else if(n2<0){
            ans.push_back(((num1[n1] - 48 + carry) % 10) + 48);
            carry = ((num1[n1] - 48 + carry) / 10);
            n1--;
        }
        else
        {
            ans.push_back(((num1[n1]-48 + num2[n2]-48 +carry)%10)+48);
            carry = ((num1[n1]-48 + num2[n2]-48 + carry)/10);
            n1--;
            n2--;
        }
    }
    if(carry){
        ans.push_back(carry+48);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// Ques No. 6 Fizz Buzz
// Ques Blog - https://leetcode.com/problems/fizz-buzz/submissions/878512204/
// Ques Link - https://leetcode.com/problems/fizz-buzz/
// Ques Solution - https://www.youtube.com/watch?v=Uq6MEiECDqk&ab_channel=codeExplainer

// Approach 1:
// Simple Brute Force 
// Time Complexity : O(N) Space Complexity : O(1)

vector<string> fizzBuzz(int n){
    vector<string> ans;
    for(int i =1;i<=n;++i){
        if( (i%3 == 0) && (i%5 == 0)){
            ans.push_back("FizzBuzz");
        }
        else if( i%5 == 0){
            ans.push_back("Buzz");
        }
        else if(i%3 ==0){
            ans.push_back("Fizz");
        }
        else{
            ans.push_back(to_string(i));
        }
    }
    return ans;
}