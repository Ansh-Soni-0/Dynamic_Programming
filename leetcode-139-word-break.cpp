//recusrion+memoization
class Solution {
public:
    bool solve(string& s , int idx , int n , unordered_set<string>& st , vector<int>& dp){
        if(idx == n) return true;

        if(st.find(s.substr(idx , n-idx)) != st.end()) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int i=1 ; i<=n ; i++){
            string temp = s.substr(idx , i);
            if(st.find(temp) != st.end()){
                bool remainingString = solve(s , idx + i , n , st , dp);
                if(remainingString){
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(wordDict.begin() , wordDict.end());
        vector<int> dp(n , -1);
        return solve(s , 0 , n , st , dp);
    }
};


//simple recusrion
class Solution {
public:
    bool solve(string& s , int idx , int n , unordered_set<string>& st){
        if(idx == n) return true;

        if(st.find(s.substr(idx , n-idx)) != st.end()) return true;

        for(int i=1 ; i<=n ; i++){
            string temp = s.substr(idx , i);
            if(st.find(temp) != st.end()){
                bool remainingString = solve(s , idx + i , n , st);
                if(remainingString){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin() , wordDict.end());
        return solve(s , 0 , s.length() , st);
    }
};