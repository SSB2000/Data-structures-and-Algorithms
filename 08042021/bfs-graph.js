// BreadthFirstSeach

const bfsPrint = (graph, source) => {
    const queue = [source];
    while (queue.length > 0) {
        const curr = queue.shift();
        console.log(curr);
        for (let neib of graph[curr]) {
            queue.push(neib);
        }
    }
};

const graph = {
    a: ["b", "c"],
    b: ["d"],
    c: ["e"],
    d: ["f"],
    e: [],
    f: [],
};

bfsPrint(graph, "a");
