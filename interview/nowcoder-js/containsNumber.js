function containsNumber(str) {
    return str.search(/[0-9]+/g) > -1
}

console.log(containsNumber('abc'))