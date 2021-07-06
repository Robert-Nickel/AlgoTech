## Finding Median
source: https://brilliant.org/wiki/median-finding-algorithm/

1. divide list into sublists with length of 5
2. sort each sublist and determine median O(n)
3. use median of median algorithm to recursively compute all medians
4. use median as approximate for whole list (pivot - element)
5. partition A so that elements smaller pivot are left, and elements higher are right
6. k = rank of x
7. a) i = k -> return x
   b) i < k -> recurse(k-1, i)
   c) i > k -> recurse(k+1, i-k)