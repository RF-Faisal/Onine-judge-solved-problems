//https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description

class Solution {
    const int MOD = 1e9 + 7;
    
    // Matrix multiplication
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int rows = A.size();
        int cols = B[0].size();
        int common = B.size();
        vector<vector<long long>> result(rows, vector<long long>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < common; k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
                }
            }
        }
        
        return result;
    }
    
    // Matrix power using binary exponentiation
    vector<vector<long long>> matrixPow(vector<vector<long long>> base, long long power) {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        
        // Initialize result as identity matrix
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        
        while (power > 0) {
            if (power & 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            power >>= 1;
        }
        
        return result;
    }
    
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Create transformation matrix
        vector<vector<long long>> transform(26, vector<long long>(26, 0));
        
        for(int j=0; j<26; ++j){
            int i = j;
            while(nums[j]--){
                ++i;
                i %= 26;
                transform[i][j] = 1;
            }
        }
        
        // Compute transform^t
        vector<vector<long long>> transformPower = matrixPow(transform, t);
        
        // Count initial frequency of each letter
        vector<long long> letterCount(26, 0);
        for (char c : s) {
            letterCount[c - 'a']++;
        }
        
        // Compute final state vector
        vector<long long> finalState(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                finalState[i] = (finalState[i] + transformPower[i][j] * letterCount[j] % MOD) % MOD;
            }
        }
        
        // Sum up all letters for final length
        long long totalLength = 0;
        for (int i = 0; i < 26; i++) {
            totalLength = (totalLength + finalState[i]) % MOD;
        }
        
        return (int)totalLength;
    }
};