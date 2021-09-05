const dfsPrintI = (graph, source) => {
    const stack = [source];
    while (stack.length > 0) {
        const curr = stack.pop();
        console.log(curr);
        for (let neib of graph[curr]) {
            stack.push(neib);
        }
    }
};

const dfsPrintR = (graph, source) => {
    console.log(source);
    for (let neib of graph[source]) {
        dfsPrintR(graph, neib);
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

// dfsPrintI(graph, "a");
dfsPrintR(graph, "a");
