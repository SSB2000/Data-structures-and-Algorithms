const explore = (graph, src, visited) => {
    if (visited.has(parseInt(src))) return false;
    visited.add(parseInt(src));
    for (let neighbor of graph[src]) {
        explore(graph, neighbor, visited);
    }
    return true;
};
// dfs implementation
const connectedComponentsCount = (graph, visited) => {
    let count = 0;
    for (let ele in graph) {
        if (explore(graph, ele, visited)) count++;
    }

    return count;
};

console.log(
    connectedComponentsCount(
        {
            0: [8, 1, 5],
            1: [0],
            5: [0, 8],
            8: [0, 5],
            2: [3, 4],
            3: [2, 4],
            4: [3, 2],
        },
        new Set()
    )
); // -> 2

console.log(
    connectedComponentsCount(
        {
            1: [2],
            2: [1, 8],
            6: [7],
            9: [8],
            7: [6, 8],
            8: [9, 7, 2],
        },
        new Set()
    )
); // -> 1

console.log(connectedComponentsCount({}, new Set())); // -> 0

console.log(
    connectedComponentsCount(
        {
            0: [4, 7],
            1: [],
            2: [],
            3: [6],
            4: [0],
            6: [3],
            7: [0],
            8: [],
        },
        new Set()
    )
); // -> 5
