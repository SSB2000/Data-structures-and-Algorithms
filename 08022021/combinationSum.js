// 39. Combination Sum

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

function multiDimensionalUnique(arr) {
    var uniques = [];
    var itemsFound = {};
    for (var i = 0, l = arr.length; i < l; i++) {
        var stringified = JSON.stringify(arr[i]);
        if (itemsFound[stringified]) {
            continue;
        }
        uniques.push(arr[i]);
        itemsFound[stringified] = true;
    }
    return uniques;
}

function searchForArray(haystack, needle) {
    var i, j, current;
    for (i = 0; i < haystack.length; ++i) {
        if (needle.length === haystack[i].length) {
            current = haystack[i];
            for (j = 0; j < needle.length && needle[j] === current[j]; ++j);
            if (j === needle.length) return i;
        }
    }
    return -1;
}

var combinationSumTemp = (targetSum, numbers) => {
    if (targetSum === 0) return [[]];
    let resultWays = [];
    for (let num of numbers) {
        if (num <= targetSum) {
            let reducedTargetSum = targetSum - num;
            let waysreducedTargetSum = combinationSumTemp(
                reducedTargetSum,
                numbers
            );
            let waysTargetSum = waysreducedTargetSum.map((way) => [
                num,
                ...way,
            ]);
            waysTargetSum = waysTargetSum.map((way) => way.sort());
            resultWays.push(...waysTargetSum);
        }
    }
    resultWays = multiDimensionalUnique(resultWays);
    return resultWays;
};

//     if (targetSum in memo) return memo[targetSum];
//     if (targetSum === 0) return [];
//     if (targetSum < 0) return null;
//     let resultList = [];

//     for (let num of numbers) {
//         const diff = targetSum - num;
//         let resultArray = combinationSumTemp(diff, numbers, 0, memo);
//         if (resultArray !== null) {
//             if (flag === 0) {
//                 memo[targetSum] = [...resultArray, num];
//                 return memo[targetSum];
//                 // return [...resultArray, num];
//             }
//             resultArray = [...resultArray, num];
//             resultArray.sort();
//             if (searchForArray(resultList, resultArray) === -1) {
//                 // console.log(resultList);
//                 resultList.push(resultArray);
//             }
//         }
//     }

//     if (flag === 0) return null;
//     return resultList;
// };

var combinationSum = function (candidates, target) {
    return combinationSumTemp(target, candidates);
};
