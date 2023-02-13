let arr = [1, 2, [3, 4, 5, 6], 7, 8, [9, 10], 11, 12];

const flattanArray = (index, arr, output) => {
    if (index >= arr.length) return;

    if (Array.isArray(arr[index])) {
        flattanArray(0, arr[index], output);
    } else {
        outputArr.push(arr[index]);
    }
    flattanArray(index + 1, arr, output);
}

let outputArr = [];

flattanArray(0, arr, outputArr);

console.log(outputArr);