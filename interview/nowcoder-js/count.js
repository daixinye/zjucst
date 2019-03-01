const testCases = [
   {
       input: [
           [1],
           4
        ],
       output: 0
   },
   {
       input: [
           [1,2,3,4,2],
           2
       ],
       output: 2
   },
   {
       input: [
        [1, 2, 4, 4, 3, 4, 3], 4
       ],
       output: 3
   }
]

function count(arr, item) {
    var ct = 0

    arr.forEach(function(value){
        if(value === item){
            ct++
        }
    })
    return ct
}

testCases.forEach(function(testCase){
    console.log(count.apply(null, testCase.input) === testCase.output ? "pass" : "fail" )
})