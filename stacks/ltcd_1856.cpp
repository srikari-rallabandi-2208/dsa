//LeetCode - problem 1856

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefix_sum(n+1);
        prefix_sum[0] = 0;

        for(int i=1; i<=n; i++)
           prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        
        stack<pair<int,int>> stk;  //val , posi
        stk.push(pair<int,int>{-1,0});
        long ret = 0;

        for(int i=0; i<n; i++) {
            int posi = i;

            while(stk.size() > 1 && nums[stk.top().first] > nums[i])
            {
                pair<int,int> p = stk.top();
                stk.pop();

                long t = (long)(nums[p.first]) * (prefix_sum[i] - prefix_sum[p.second]);
                ret = max(ret, t);

                posi = p.second;
            }

            stk.push(pair<int,int>{i, posi});
        }

        while(stk.size() > 1) {
            pair<int,int> p = stk.top();
            stk.pop();

            long t = (long)(nums[p.first]) * (prefix_sum[n] - prefix_sum[p.second]);
            ret = max(ret, t);
        }

        return ret % 1000000007;
    }
