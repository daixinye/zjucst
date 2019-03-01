function sum(arr){
    return arr.reduce(function(prev,curr){
        return curr + prev
    })
}

console.log(sum([1,2,3,4]))