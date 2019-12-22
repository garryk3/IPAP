// найти максимум чисел
// сложность 5
const findMaxFromLimitedArgs = (a, b, c) => {
    let max = a;

    if (b > max) max = b;
    if (c > max) max = c;

    return max;
};
// сложность 1 + 2 * i
const findMaximumNumber = (...numbers) => {
    let max = 0;

    numbers.forEach(number => {
        if(number > max) max = number;
    })

    return max;
}

const testArgs1 = [10, 50, 25];
const testArgs2 = [1, 2, 3, 4, 100, 54, 6];
const testArgs3 = [1, -200, 0, 2, 3, 4, 200, 54, 6];

const max1 = findMaxFromLimitedArgs(...testArgs1);
const max2 = findMaximumNumber(...testArgs2);
const max3 = findMaximumNumber(...testArgs3);

if(max1 !== Math.max(...testArgs1) || max2 !== Math.max(...testArgs2) || max3 !== Math.max(...testArgs3)) {
    throw new Error('!!!');
} else {
    console.log('success', max1, max2, max3);
}