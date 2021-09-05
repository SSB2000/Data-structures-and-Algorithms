// shortest path
// Write a function, shortestPath, that takes in an array of edges for an undirected graph and two nodes (nodeA, nodeB). The function should return the length of the shortest path between A and B. Consider the length as the number of edges in the path, not the number of nodes. If there is no path between A and B, then return -1.

//BFS implementation

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

const calculatePath = (graph, src, dst, queue, visited) => {
    if (src === dst) return 0;
    queue.push([src, 0]);
    while (queue.length > 0) {
        const curr = queue.shift();
        visited.add(curr[0]);
        for (let neighbor of graph[curr[0]]) {
            // console.log(queue);
            if (!visited.has(neighbor)) {
                queue.push([neighbor, curr[1] + 1]);
                if (neighbor === dst) {
                    return curr[1] + 1;
                }
            }
        }
    }
    return "No path!";
};

shortestPath = (edges, src, dst) => {
    const graph = makeGraph(edges);
    let queue = [];
    let visited = new Set();
    return calculatePath(graph, src, dst, queue, visited);
};

// test_01
console.log(
    shortestPath(
        (edges = [
            ["w", "x"],
            ["x", "y"],
            ["z", "y"],
            ["z", "v"],
            ["w", "v"],
        ]),
        "w",
        "z"
    )
); // -> 2

// test_02:
console.log(
    shortestPath(
        (edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"],
        ]),
        "a",
        "e"
    )
); // -> 3

// test_03:
console.log(
    shortestPath(
        (edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"],
        ]),
        "e",
        "c"
    )
); // -> 2

// test_04:
console.log(
    shortestPath(
        (edges = [
            ["a", "c"],
            ["a", "b"],
            ["c", "b"],
            ["c", "d"],
            ["b", "d"],
            ["e", "d"],
            ["g", "f"],
        ]),
        "b",
        "g"
    )
); // -> -1

// test_05:
console.log(
    shortestPath(
        (edges = [
            ["c", "n"],
            ["c", "e"],
            ["c", "s"],
            ["c", "w"],
            ["w", "e"],
        ]),
        "w",
        "e"
    )
); // -> 1

// test_06:
console.log(
    shortestPath(
        (edges = [
            ["c", "n"],
            ["c", "e"],
            ["c", "s"],
            ["c", "w"],
            ["w", "e"],
        ]),
        "n",
        "e"
    )
); // -> 2

// test_07:
console.log(
    shortestPath(
        (edges = [
            ["m", "n"],
            ["n", "o"],
            ["o", "p"],
            ["p", "q"],
            ["t", "o"],
            ["r", "q"],
            ["r", "s"],
        ]),
        "m",
        "s"
    )
); // -> 6
