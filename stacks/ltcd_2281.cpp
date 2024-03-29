//LeetCode - problem 2281

    int totalStrength(vector<int>& strength) {
        int MOD = 1'000'000'007, n = strength.size(); 
        vector<long> pw(1), ps(1); 
        for (long i = 0; i < n; ++i) {
            pw.push_back((pw.back() + (i+1)*strength[i]) % MOD); 
            ps.push_back((ps.back() + strength[i]) % MOD); 
        }
        
        vector<long> sw(1), ss(1); 
        for (long i = n-1; i >= 0; --i) {
            sw.push_back((sw.back() + (n-i)*strength[i]) % MOD); 
            ss.push_back((ss.back() + strength[i]) % MOD); 
        }
        
        reverse(sw.begin(), sw.end()); 
        reverse(ss.begin(), ss.end()); 
        
        long ans = 0; 
        stack<int> stk; 
        strength.push_back(0); 
        for (int i = 0; i < strength.size(); ++i) {
            while (stk.size() && strength[stk.top()] >= strength[i]) {
                int mid = stk.top(); stk.pop(); 
                int lo = -1; 
                if (stk.size()) lo = stk.top(); 
                long left = (long) strength[mid] * (pw[mid+1] - pw[lo+1] - (ps[mid+1] - ps[lo+1]) * (lo+1) % MOD) % MOD * (i-mid) % MOD; 
                long right = (long) strength[mid] * (sw[mid+1] - sw[i] - (ss[mid+1] - ss[i]) * (n-i) % MOD) % MOD * (mid - lo) % MOD; 
                ans = (ans + left + right) % MOD; 
            }
            stk.push(i); 
        }
        return ans; 
    }
