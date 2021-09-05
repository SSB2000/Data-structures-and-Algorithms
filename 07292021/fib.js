// print the fibonacci series up to n;

// Memoization method
const fib = (num, memo) => {
    if (num in memo) return memo[num];
    if (num == 1 || num == 0) {
        memo[num] = num;
        return memo[num];
    }
    memo[num] = fib(num - 1, memo) + fib(num - 2, memo);
    return memo[num];
};

const allFibs = (range) => {
    let memo = {};
    for (let i = 0; i <= range; i++) {
        fib(i, memo);
    }

    return memo;
};
// console.log(allFibs(50));

// Tabulation Method

const fibT = (num) => {
    let table = Array(num + 1).fill(0);
    table[0] = 0;
    table[1] = 1;
    for (let i = 0; i <= num; i++) {
        table[i + 1] += table[i];
        table[i + 2] += table[i];
    }
    return table[num];
};

console.log(fibT(6));
console.log(fibT(7));
console.log(fibT(8));
console.log(fibT(50));
