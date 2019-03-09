function insertionSort(nums) {
  const len = nums.length

  for(var i = 0; i < len - 1; i++){
    for(var j = i + 1; j < len; j++){
        if(nums[i] > nums[j]){
            [nums[i], nums[j]] = [nums[j],nums[i]]
        }
    }
  }
  return nums
}

const testCases = [[], [1], [5, 4, 3, 2, 1]];

testCases.forEach((testCase, index) => {
  console.log("#", index);
  console.log("input:", testCase);
  console.log("output:", insertionSort(testCase));
});
