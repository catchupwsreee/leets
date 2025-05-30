class Solution(object):
    def maxTargetNodes(self, edges1, edges2, k):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        def build_adj(n, edges):
            adj = [[] for _ in range(n)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)
            return adj

        def all_reaches(adj, threshold):
            n = len(adj)
            reaches = [0]*n
            if threshold < 0:
                return reaches

            for i in range(n):
                dist = [-1]*n
                dist[i] = 0
                q = deque([i])
                cnt = 0
                while q:
                    u = q.popleft()
                    if dist[u] > threshold:
                        continue
                    cnt += 1
                    for w in adj[u]:
                        if dist[w] == -1:
                            dist[w] = dist[u] + 1
                            q.append(w)
                reaches[i] = cnt
            return reaches

        n = len(edges1) + 1
        m = len(edges2) + 1
        adj1 = build_adj(n, edges1)
        adj2 = build_adj(m, edges2)

        reach1 = all_reaches(adj1, k)
        reach2 = all_reaches(adj2, k-1)

        best2 = max(reach2) if reach2 else 0
        return [r1 + best2 for r1 in reach1]