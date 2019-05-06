# Interviewbit time complexity questions

- loopcmpl
    ```
    int a = 0, b = 0;    
    for (i = 0; i < N; i++) {
        a = a + rand();  
    }
    for (j = 0; j < M; j++) {
        b = b + rand();
    }
    ```
- nestedcmpl
    ```
     int a = 0, b = 0;    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a = a + j;
        }
    }
    for (k = 0; k < N; k++) {
        b = b + k;
    } 
    ```
- nestedcmpl2
    ```
    int a = 0;
    for (i = 0; i < N; i++) {
        for (j = N; j > i; j--) {
            a = a + i + j;
        }
    }
    ```
- nestedcmpl3
    ```
    int count = 0;
    for (int i = N; i > 0; i /= 2) {
        for (int j = 0; j < i; j++) {
            count += 1;
        }
    }
    ```
- loopcmpl2
    ```
    int i, j, k = 0;
    for (i  = n/2; i <= n; i++) {
        for (j = 2; j <= n; j = j * 2) {
            k = k + n/2;
        }
    }
    ```
- gcdcmpl - % reduces by logn approx
    ```
    int gcd(int n, int m) {
        if (n%m ==0) return m;
        if (n < m) swap(n, m);
        while (m > 0) {
            n = n%m;
            swap(n, m);
        }
        return n;
    }
    ```
- choose3 : fastest loop ?
    ```
      A) for(i = 0; i < n; i++)
     
      B) for(i = 0; i < n; i += 2)
     
      C) for(i = 1; i < n; i *= 2)
     
      D) for(i = n; i > -1; i /= 2)
    ```
- whilecmpl
    ```
      int a = 0, i = N;
        while (i > 0) {
            a += i;
            i /= 2;
        }
    ```
- reccmpl1 : worst case time
    ```
    /* 
     - V is sorted 
     - V.size() = N
     - The function is initially called as searchNumOccurrence(V, k, 0, N-1)
     */
    int searchNumOccurrence(vector<int> &V, int k, int start, int end) {
        if (start > end) return 0;
        int mid = (start + end) / 2;
        if (V[mid] < k) return searchNumOccurrence(V, k, mid + 1, end);
        if (V[mid] > k) return searchNumOccurrence(V, k, start, mid - 1);
        return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);
    }
    ```
- reccmpl2 - worst case complexity
    ```
    int findMinPath(vector<vector<int> > &V, int r, int c) {
      int R = V.size();
      int C = V[0].size();
      if (r >= R || c >= C) return 100000000; // Infinity
      if (r == R - 1 && c == C - 1) return 0;
      return V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
    }
    ```
- reccmpl3 - worst case complexity
    ```
    int memo[101][101];
    int findMinPath(vector<vector<int> >& V, int r, int c) {
      int R = V.size();
      int C = V[0].size();
      if (r >= R || c >= C) return 100000000; // Infinity
      if (r == R - 1 && c == C - 1) return 0;
      if (memo[r][c] != -1) return memo[r][c];
      memo[r][c] =  V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
      return memo[r][c];
    }

    Callsite : 
    memset(memo, -1, sizeof(memo));
    findMinPath(V, 0, 0);
    ```
- amortized1
    ```
     int j = 0;
        for(int i = 0; i < n; ++i) {
            while(j < n && arr[i] < arr[j]) {
                j++;
            }
        }
    ```
