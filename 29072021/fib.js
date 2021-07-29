// print the fibonacci series up to n;


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
    let  memo = {};
    for (let i = 0; i <= range; i++) {
        fib(i, memo);
    }

    return memo;
};
console.log(allFibs(50));
