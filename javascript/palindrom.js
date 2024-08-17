const fibbonacchiNumber = (x) => {
    let arr = [0, 1];

    for (let index = 2; index <= x; index++) {
        arr.push(arr[index - 1] + arr[index - 2]);
    }
    console.log(arr);
}

const isPalindrom = (x) => {
    if (x < 0) return false;

    return x === +x.toString().split().reverse().join("");
}


const isAnagram = (x) => {
    
}

