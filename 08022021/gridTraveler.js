// Say you have a 2D grid and goal is to travel through top left to bottom right corner and the constraints are that you can only move either right or bottom.
// How many ways can you you achieve the goal in m * n grid.

const gridTraveler = (m, n) => {
    let grid = Array(m + 1)
        .fill()
        .map(() => Array(n + 1).fill(0));
    // Seed the table with a initial value
    grid[1][1] = 1;
    for (let i = 0; i < m + 1; i++) {
        for (let j = 0; j < n + 1; j++) {
            if (j + 1 < n + 1) grid[i][j + 1] += grid[i][j];
            if (i + 1 < m + 1) grid[i + 1][j] += grid[i][j];
        }
    }
    return grid[m][n];
};

console.log(gridTraveler(1, 1));
console.log(gridTraveler(2, 3));
console.log(gridTraveler(3, 2));
console.log(gridTraveler(3, 3));
console.log(gridTraveler(18, 18));
