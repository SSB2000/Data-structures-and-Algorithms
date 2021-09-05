// Is is possible to generate targetSum from a set of number and you are allowed to use any number any number of times.

// Tabulation
// T.C = O(m * n) // Where m = targetSum.length & n = numbers.length
// S.C = O(m)
const canSumTable = (targetSum, numbers) => {
    let table = Array(targetSum + 1).fill(false);
    table[0] = true;
    for (let i = 0; i < table.length; i++) {
        for (let num of numbers) {
            if (table[i] === true) {
                if (i + num < table.length) table[i + num] = true;
            }
        }
    }

    return table[targetSum];
};

// Memoization
//
const canSumMemo = (target, numbers, memo = {}) => {
    if (target in memo) return memo[target];
    if (target === 0) return true;
    if (target < 0) return false;

    for (let num of numbers) {
        let diff = target - num;
        if (canSum(diff, numbers, memo)) {
            memo[diff] = true;
            return true;
        }
    }
    memo[target] = false;
    return false;
};

console.log(canSumTable(7, [2, 3]));
console.log(canSumTable(7, [5, 4, 7]));
console.log(canSumTable(7, [2, 4]));
console.log(canSumTable(7, [2, 3, 5]));
console.log(canSumTable(300, [7, 14]));
