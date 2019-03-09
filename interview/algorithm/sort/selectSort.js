function selectSort(nums) {
  const len = nums.length;

  for (var i = 1; i < len; i++) {
    var j = i
    while(j > 0){
        if(nums[j] < nums[j-1]){
            [nums[j],nums[j-1]] = [nums[j-1],nums[j]]
        }
        j--
    }
  }

  return nums;
}

const testCases = [[1, 3, 5, 4, 2], [], [1]];

testCases.forEach((testCase, index) => {
  console.log("#", index);
  console.log("input:", testCase);
  console.log("output:", selectSort(testCase));
});
