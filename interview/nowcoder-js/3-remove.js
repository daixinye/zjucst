var test_case = [[1,2,3,4,2], 2]

function remove(arr, item) {
    return arr.filter(function(v){
        return v !== item
    })
}

console.log(remove.apply(null, test_case))