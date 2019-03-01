function isUSD(str) {
    var pattern = /^\$(\d{1,3}(,\d{3})*(\.\d{2})*)$/g
    return pattern.test(str)
}

console.log(isUSD('$20,933,209.93'))