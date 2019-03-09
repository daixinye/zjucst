function bubbleSort(nums) {
  const len = nums.length;

  for (var i = 0; i < len - 1; i++) {
    // 小的跟 i 交换
    for (var j = 0; j < len - 1 - i; j++) {
      if (nums[j] > nums[j + 1]) {
        [nums[j], nums[j + 1]] = [nums[j + 1], nums[j]];
      }
    }
  }

  return nums;
}

const testCases = [[], [1], [5, 4, 3, 2, 1], [1, 2, 3, 4, 5]];

testCases.forEach((testCase, index) => {
  console.log("#", index);
  console.log("input:", testCase);
  console.log("output:", bubbleSort(testCase));
});
