// Write a function, undirectedPath, that takes in an array of edges for an undirected graph and two nodes (nodeA, nodeB). The function should return a boolean indicating whether or not there exists a path between nodeA and nodeB.

const undirectedPath = (edges, src, dst) => {
    const graph = makeGraph(edges);
    return hasPath(graph, src, dst, new Set());
};

// dfs Recursive
const hasPath = (graph, src, dst, visited) => {
    if (src === dst) return true;
    if (visited.has(src)) return false;
    visited.add(src);
    for (let neibhor of graph[src]) {
        if (hasPath(graph, neibhor, dst, visited) === true) return true;
    }
    return false;
};

const makeGraph = (edges) => {
    const graph = {};
    for (let edge of edges) {
        const [a, b] = edge;
        if (!(a in graph)) graph[a] = [];
        if (!(b in graph)) graph[b] = [];
        graph[a].push(b);
        graph[b].push(a);
    }
    return graph;
};

let edges = [
    ["i", "j"],
    ["k", "i"],
    ["m", "k"],
    ["k", "l"],
    ["o", "n"],
];
console.log(undirectedPath(edges, "j", "m")); // -> true

edges = [
    ["i", "j"],
    ["k", "i"],
    ["m", "k"],
    ["k", "l"],
    ["o", "n"],
];
console.log(undirectedPath(edges, "i", "o")); // -> false

edges = [
    ["b", "a"],
    ["c", "a"],
    ["b", "c"],
    ["q", "r"],
    ["q", "s"],
    ["q", "u"],
    ["q", "t"],
];
console.log(undirectedPath(edges, "a", "b")); // -> true

edges = [
    ["b", "a"],
    ["c", "a"],
    ["b", "c"],
    ["q", "r"],
    ["q", "s"],
    ["q", "u"],
    ["q", "t"],
];
console.log(undirectedPath(edges, "a", "c")); //  -> true

edges = [
    ["b", "a"],
    ["c", "a"],
    ["b", "c"],
    ["q", "r"],
    ["q", "s"],
    ["q", "u"],
    ["q", "t"],
];
console.log(undirectedPath(edges, "r", "t")); // -> true

edges = [
    ["b", "a"],
    ["c", "a"],
    ["b", "c"],
    ["q", "r"],
    ["q", "s"],
    ["q", "u"],
    ["q", "t"],
];
console.log(undirectedPath(edges, "r", "b")); // -> false
