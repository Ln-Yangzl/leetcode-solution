int climbStairs(int n) {
    int next = 1, nnext = 0, start = 1;
    for (int i = 0; i < n - 1; i++) {
        next = nnext + start;
        nnext = start;
        start = next;
    }
    return next + nnext;
}