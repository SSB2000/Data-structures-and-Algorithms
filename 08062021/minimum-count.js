// island count
// Write a function, islandCount, that takes in a grid containing Ws and Ls. "W" represents water and "L" represents land. The function should return the number of islands on the grid. An island is a vertically or horizontally connected region of land.

const explore = (grid, x, y, visited) => {
    if (visited.has(x + "," + y)) return false;
    visited.add(x + "," + y);
    let stack = [];
    if (x - 1 >= 0 && grid[x - 1][y] === "L") {
        explore(grid, x - 1, y, visited);
    }
    if (y - 1 >= 0 && grid[x][y - 1] === "L") {
        explore(grid, x, y - 1, visited);
    }
    if (x + 1 < grid.length && grid[x + 1][y] === "L") {
        explore(grid, x + 1, y, visited);
    }
    if (y + 1 < grid[0].length && grid[x][y + 1] === "L") {
        explore(grid, x, y + 1, visited);
    }
    return true;
};

const islandCount = (grid) => {
    let count = 0;
    let queue = [];
    let visited = new Set();
    for (let i = 0; i < grid.length; ++i) {
        for (let j = 0; j < grid[0].length; ++j) {
            if (grid[i][j] === "L") {
                if (explore(grid, i, j, visited)) {
                    count++;
                }
            }
        }
    }
    return count;
};

console.log(
    islandCount(
        (grid = [
            ["W", "L", "W", "W", "W"],
            ["W", "L", "W", "W", "W"],
            ["W", "W", "W", "L", "W"],
            ["W", "W", "L", "L", "W"],
            ["L", "W", "W", "L", "L"],
            ["L", "L", "W", "W", "W"],
        ])
    )
); // -> 3

console.log(
    islandCount(
        (grid = [
            ["L", "L", "L"],
            ["L", "L", "L"],
            ["L", "L", "L"],
        ])
    )
); // -> 1
console.log(
    islandCount(
        (grid = [
            ["W", "W"],
            ["W", "W"],
            ["W", "W"],
        ])
    )
); // -> 0
