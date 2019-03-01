const testCases = [
  {
    input: [[1, 2, 4, 4, 3, 3, 1, 5, 3]],
    output: [1, 3, 4]
  }
];

testCases.forEach(function(testCase) {
  console.log(duplicates.apply(null, testCase.input));
});

function duplicates(arr) {
  var map = {};
  arr.forEach(function(val) {
    map[val] = "" + val in map ? ++map[val] : 1;
  });
  var result = [];
  for (var key in map) {
    if (map[key] > 1) {
      result.push(key);
    }
  }
  return result;
}
