function captureThreeNumbers(str) {
    var pattern = /\d{3}/g

    return pattern.test(str) ? str.match(pattern)[0] : false
}

console.log(captureThreeNumbers('9876543'))