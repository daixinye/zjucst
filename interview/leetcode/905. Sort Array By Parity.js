/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    // 双指针
    
    let evenIdx = A.length - 1, oddIdx = 0
    
    while(true){
        // 终止条件
        if(evenIdx <= oddIdx || oddIdx >= A.length || evenIdx <= 0){
            return A
        }

        if(A[evenIdx] %2 !== 0){
            evenIdx--
            continue
        }

        if(A[oddIdx] %2 === 0){
            oddIdx++
            continue
        }

        [A[evenIdx],A[oddIdx]] = [A[oddIdx],A[evenIdx]]
        evenIdx--
        oddIdx++
    }
};

console.log(sortArrayByParity([0,1]))

console.log(sortArrayByParity([1,0]))