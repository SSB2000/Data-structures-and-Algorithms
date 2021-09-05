// Recursive dfs
/*
const hasPath = (graph, src, des) => {
    if (des === src) return true;
    for (let neib of graph[src]) {
        if (hasPath(graph, neib, des) === true) return true;
    }
    return false;
};
*/

// Iterative dfs
/*
const hasPath = (graph, src, des) => {
    let stack = [src];
    while (stack.length > 0) {
        const curr = stack.pop();
        if (curr === des) return true;
        for (let neib of graph[curr]) {
            stack.push(neib);
        }
    }
    return false;
};
*/

// Iterative bfs
const hasPath = (graph, src, des) => {
    let queue = [src];
    while (queue.length > 0) {
        const curr = queue.shift();
        if (curr === des) return true;
        for (let neib of graph[curr]) {
            queue.push(neib);
        }
    }
    return false;
};

let graph = {
    f: ["g", "i"],
    g: ["h"],
    h: [],
    i: ["g", "k"],
    j: ["i"],
    k: [],
};
console.log(hasPath(graph, "f", "k")); // true

graph = {
    f: ["g", "i"],
    g: ["h"],
    h: [],
    i: ["g", "k"],
    j: ["i"],
    k: [],
};
console.log(hasPath(graph, "f", "j")); // false

graph = {
    v: ["x", "w"],
    w: [],
    x: [],
    y: ["z"],
    z: [],
};
console.log(hasPath(graph, "v", "w")); // true

graph = {
    v: ["x", "w"],
    w: [],
    x: [],
    y: ["z"],
    z: [],
};
console.log(hasPath(graph, "v", "z")); // false
