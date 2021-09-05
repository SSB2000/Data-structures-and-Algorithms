// bestSum
// give the best shortest possible list of elements to generate targetSum from numbers array

// Tabulation

const bestSumTable = (targetSum, numbers) => {
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;
    let table = Array(targetSum + 1).fill(null);
    table[0] = [];
    for (let i = 0; i < table.length; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                if (i + num < table.length) {
                    let newValues = [...table[i], num];
                    if (table[i + num] === null) {
                        table[i + num] = newValues;
                    } else {
                        if (newValues.length < table[i + num].length) {
                            table[i + num] = newValues;
                        }
                    }
                }
            }
        }
    }
    return table[targetSum];
};

// Memoization
const bestSumMemo = (targetSum, numbers, memo = {}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;
    let bestList = null;
    for (let num of numbers) {
        const diff = targetSum - num;
        const possibleList = bestSum(diff, numbers, memo);
        if (possibleList !== null) {
            if (bestList === null || possibleList.length < bestList.length) {
                bestList = [...possibleList, num];
            }
        }
    }

    memo[targetSum] = bestList;
    return memo[targetSum];
};

console.log(bestSumTable(7, [5, 3, 4, 7]));
console.log(bestSumTable(8, [2, 3, 5]));
console.log(bestSumTable(8, [1, 4, 5]));
console.log(bestSumTable(100, [1, 2, 5, 25]));
