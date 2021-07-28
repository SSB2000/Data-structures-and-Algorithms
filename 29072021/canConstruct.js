// Is it possible to construct targetString from the list of word in the wordBank
// FFC 5hr DP.

function canConstruct(targetString, wordBank, memo = {}) {
    if (targetString in memo) return memo[targetString];
    if (targetString === "") return true;
    for (let word of wordBank) {
        if (targetString.indexOf(word) === 0) {
            const suffixToCheck = targetString.slice(word.length);
            if (canConstruct(suffixToCheck, wordBank, memo) === true) {
                memo[targetString] = true;
                return true;
            }
        }
    }

    memo[targetString] = false;
    return memo[targetString];
}

console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); //ture
console.log(
    canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])
); //false
console.log(
    canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])
); // true
console.log(
    canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
        "e",
        "ee",
        "eee",
        "eeee",
        "eeeeee",
        "eeeeeeee",
    ])
);
