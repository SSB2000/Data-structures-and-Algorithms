const allConstruct = (target, wordBank) => {
    if (target === "") return [[]];

    let result = [];
    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            let suffix = target.slice(word.length);
            let suffixWays = allConstruct(suffix, wordBank);
            let targetWays = suffixWays.map((way) => [word, ...way]);
            result.push(...targetWays);
        }
    }
    return result;
};

console.log(allConstruct("purple", ["purple", "p", "ur", "le", "purpl"]));
console.log(
    allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd", "ef", "c"])
);
console.log(
    allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])
);
console.log(
    allConstruct("aaaaaaaaaaaaaaaaaaaz", ["a", "aa", "aaa", "aaaa", "aaaaaaa"])
);
