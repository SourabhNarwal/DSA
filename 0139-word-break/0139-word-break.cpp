class Solution {
public:
    bool canSegment(int start, const string& s, const vector<string>& wordDict, unordered_map<int, bool>& memo) {
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }

        if (start == s.size()) {
            return true;
        }

        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (find(wordDict.begin(), wordDict.end(), substring) != wordDict.end()) {
                if (canSegment(end, s, wordDict, memo)) {
                    memo[start] = true;
                    return true;
                }
            }
        }

        memo[start] = false;
        return false;
    }

    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_map<int, bool> memo;
        return canSegment(0, s, wordDict, memo);
    }
};