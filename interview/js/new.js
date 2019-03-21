function Constructor(){
    this.num = 1
    // return {num:2}
}

var foo = new Constructor()
var bar = Constructor()

console.log(foo,bar)