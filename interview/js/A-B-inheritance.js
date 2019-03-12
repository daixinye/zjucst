function A() {
  this.a = "a";
}
A.prototype.sayA = function() {
  console.log(this.a);
};

function B() {
  this.b = "b";
}
B.prototype = new A();
B.prototype.constructor = B;
B.prototype.sayB = function() {
  console.log(this.b);
};

let b = new B();
console.log(b);
console.log(b.a);
b.sayA();
console.log(b.constructor);
