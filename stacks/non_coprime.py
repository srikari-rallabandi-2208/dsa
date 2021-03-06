'''
LeetCode - problem 2197
'''

    def replaceNonCoprimes(self, A):
        res = []
        for a in A:
            while True:
                x = math.gcd(res[-1] if res else 1, a)
                if x == 1: break # co-prime
                a *= res.pop() // x
            res.append(a)
        return res
