// 791. Custom Sort String
// Medium

// 1663

// 262

// Add to List

// Share
// You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.

 

// Example 1:

// Input: order = "cba", s = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
// Example 2:

// Input: order = "cbafg", s = "abcd"
// Output: "cbad"
 

// Constraints:

// 1 <= order.length <= 26
// 1 <= s.length <= 200
// order and s consist of lowercase English letters.
// All the characters of order are unique.
// Accepted
// 146,133
// Submissions
// 215,008


class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mymap;
        string ans = "";
        
        for(auto x:s){
            mymap[x]++;
        }
        
        for(auto x:order){
            if(mymap.find(x) != mymap.end()){
                auto temp = mymap.find(x);
                int count = temp->second;
                string s(count,x);
                ans += s;
                mymap.erase(x);
            }
        }
        
        for(auto x : mymap){
            string s(x.second,x.first);
            ans += s;
        }
        
        return ans;
    }
};


















