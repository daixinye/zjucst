
function makeClosures(arr, fn) {
  return arr.map(function(val, index) {
    return function() {
      return fn(arr[index]);
    };
  });
}

var result = makeClosures([1, 2, 3], function(x) {
  return x * x;
});

console.log(result[1]())