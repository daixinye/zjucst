function argsAsArray(fn, arr) {
  console.log(fn.apply(null, arr));
}

argsAsArray(
  function(greeting, name, punctuation) {
    return greeting + ", " + name + (punctuation || "!");
  },
  ["Hello", "Ellie", "!"]
);
