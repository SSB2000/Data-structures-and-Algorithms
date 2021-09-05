// Print all the power of 2 container in the number

const powerOf2 = (num) => {
    if (num < 1) return 0;
    if (num === 1) {
        console.log(1);
        return 1;
    }
    let prev = powerOf2(Math.floor(num / 2));
    let curr = prev * 2;
    console.log(curr);
    return curr;
};

powerOf2(50);
