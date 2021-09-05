// largest component

// Write a function, largestComponent, that takes in the adjacency list of an undirected graph. The function should return the size of the largest connected component in the graph.

const count = (graph, src, visited) => {
    if (visited.has(parseInt(src))) return 0;
    visited.add(parseInt(src));
    let numOfNodes = 1;
    for (let neighbor of graph[src]) {
        numOfNodes += count(graph, neighbor, visited);
    }
    return numOfNodes;
};
// dfs implementation
const largestComponent = (graph, visited) => {
    let mx = 0;
    for (let ele in graph) {
        let eleNum = count(graph, ele, visited);
        mx = Math.max(mx, eleNum);
    }

    return mx;
};

console.log(
    largestComponent(
        {
            0: ["8", "1", "5"],
            1: ["0"],
            5: ["0", "8"],
            8: ["0", "5"],
            2: ["3", "4"],
            3: ["2", "4"],
            4: ["3", "2"],
        },
        new Set()
    )
); // -> 4

console.log(
    largestComponent(
        {
            1: ["2"],
            2: ["1", "8"],
            6: ["7"],
            9: ["8"],
            7: ["6", "8"],
            8: ["9", "7", "2"],
        },
        new Set()
    )
); // -> 6

console.log(largestComponent({}, new Set())); // -> 0

console.log(
    largestComponent(
        {
            0: ["4", "7"],
            1: [],
            2: [],
            3: ["6"],
            4: ["0"],
            6: ["3"],
            7: ["0"],
            8: [],
        },
        new Set()
    )
); // -> 3
