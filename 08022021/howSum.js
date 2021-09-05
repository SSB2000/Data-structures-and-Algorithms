// howSum
// Return 1 array of possible element which add up to targetsum
// DP FFC 5hr

// Tabulation
// T.C = O(M^2*N) M = targetSum.length & N = numbers.length
// S.C = O(M^2)

const howSumTable = (targetSum, numbers) => {
    let table = Array(targetSum + 1).fill(null);
    table[0] = [];
    for (let i = 0; i < table.length; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                if (i + num < table.length) {
                    table[i + num] = [...table[i], num];
                }
            }
        }
    }
    return table[targetSum];
};

// Memoization
const howSumMemo = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (const num of numbers) {
        const diff = targetSum - num;
        const resultArray = howSum(diff, numbers, memo);
        if (resultArray !== null) {
            memo[targetSum] = [...resultArray, num];
            return memo[targetSum];
        }
    }
    memo[targetSum] = null;
    return memo[targetSum];
};

console.log(howSumTable(7, [2, 3]));
console.log(howSumTable(7, [5, 3, 4, 7]));
console.log(howSumTable(7, [2, 4]));
console.log(howSumTable(8, [2, 3, 5]));
console.log(howSumTable(300, [14, 7]));
