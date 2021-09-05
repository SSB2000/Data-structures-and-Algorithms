// Write a method to replace all spaces in a string with '%20'. You may assume that the  string
// has sufficient space at the end  to  hold the additional characters,  and that you are given the "true" length  of  the  string.
// CTCI 1.3

// Not compelete
const countSpaces = (str) => {
    let count;
    for (let ch of str) if (ch === " ") count++;

    return count;
};

const URLify = (str) => {
    const spacesNum = countSpaces(str);
    const tLen = str.length;
    const newLen = tLen + spacesNum * 2;
    let index = newLen;
    for (let i = tLen; i >= 0; i--) {
        if (str[i] === " ") {
            str[index - 1] = "0";
            str[index - 2] = "2";
            str[index - 3] = "%";
            console.log("str :>> ", str);
            index -= 3;
        } else {
            str[index] = str[i];
            index--;
        }
    }
    console.log(str[23]);
    return str;
};

let str = URLify("My name is Shubham");

console.log(str);
