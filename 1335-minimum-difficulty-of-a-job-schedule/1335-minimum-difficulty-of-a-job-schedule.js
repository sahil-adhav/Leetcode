/**
 * @param {number[]} jobDifficulty
 * @param {number} d
 * @return {number}
 */


const minDifficulty = (A, D) => {
    let n = A.length, inf = Infinity, maxd;
    
    if (n < D) return -1;
    
    let dp = new Array(n + 1).fill(Infinity);
    dp[n] = 0;
    
    for (let d = 1; d <= D; d++) {
        for (let i = 0; i <= n - d; i++) {
            maxd = 0, dp[i] = inf;

            for (let j = i; j <= n - d; j++) {
                maxd =  Math.max(maxd, A[j]);
                dp[i] = Math.min(dp[i], maxd + dp[j + 1]);
            }
        }
    }
    
    return dp[0];
}