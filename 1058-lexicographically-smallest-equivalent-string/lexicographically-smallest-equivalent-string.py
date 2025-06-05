class Solution:
    def smallestEquivalentString(self, s1, s2, baseStr):
        parent = list(range(26))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            px = find(x)
            py = find(y)
            if px == py:
                return
            if px < py:
                parent[py] = px
            else:
                parent[px] = py

        for a, b in zip(s1, s2):
            union(ord(a) - ord('a'), ord(b) - ord('a'))

        result = ''
        for c in baseStr:
            result += chr(find(ord(c) - ord('a')) + ord('a'))
        return result
