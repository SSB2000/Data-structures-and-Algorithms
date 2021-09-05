// minimum island
// Write a function, minimumIsland, that takes in a grid containing Ws and Ls. W represents water and L represents land. The function should return the size of the smallest island. An island is a vertically or horizontally connected region of land.
// You may assume that the grid contains at least one island.

const countIsland = (grid, x, y, visited) => {
    const inBoundX = 0 <= x && x < grid.length;
    const inBoundY = 0 <= y && y < grid[0].length;
    if (!inBoundX || !inBoundY) return 0;
    if (grid[x][y] !== "L") return 0;
    if (visited.has(x + "," + y)) return 0;
    visited.add(x + "," + y);
    let count = 1;
    count += countIsland(grid, x - 1, y, visited);
    count += countIsland(grid, x, y - 1, visited);
    count += countIsland(grid, x + 1, y, visited);
    count += countIsland(grid, x, y + 1, visited);
    return count;
};

const minimumIsland = (grid) => {
    let mn = Infinity;
    let visited = new Set();
    for (let i = 0; i < grid.length; ++i) {
        for (let j = 0; j < grid[0].length; ++j) {
            if (grid[i][j] === "L") {
                let countI = countIsland(grid, i, j, visited);
                if (countI > 0) {
                    mn = Math.min(mn, countI);
                }
            }
        }
    }
    return mn;
};

console.log(
    minimumIsland(
        (grid = [
            ["L", "L", "L"],
            ["L", "L", "L"],
            ["L", "L", "L"],
        ])
    )
); // -> 9

console.log(
    minimumIsland(
        (grid = [
            ["W", "W"],
            ["L", "L"],
            ["W", "W"],
            ["W", "L"],
        ])
    )
); // -> 1

console.log(
    minimumIsland(
        (grid = [
            ["W", "L", "W", "W", "W"],
            ["W", "L", "W", "W", "W"],
            ["W", "W", "W", "L", "W"],
            ["W", "W", "L", "L", "W"],
            ["L", "W", "W", "L", "L"],
            ["L", "L", "W", "W", "W"],
        ])
    )
); // -> 2

console.log(
    minimumIsland(
        (grid = [
            ["L", "W", "W", "L", "W"],
            ["L", "W", "W", "L", "L"],
            ["W", "L", "W", "L", "W"],
            ["W", "W", "W", "W", "W"],
            ["W", "W", "L", "L", "L"],
        ])
    )
); // -> 1
