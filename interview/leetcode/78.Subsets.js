/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    var max = 1 << nums.length;
    var bitmap = 0;
    var result = []
    while (bitmap < max) {
      var set = [];
      for (var i = 0; i < nums.length; i++) {
        if ((1 << i) & bitmap) {
          set.push(nums[i]);
        }
      }
      result.push(set)
      bitmap++;
    }
    return result
  };