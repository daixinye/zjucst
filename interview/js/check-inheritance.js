function Super(){
    this.a = 1
    this.b = 2
}

const instance = Object.create(new Super())

console.log(instance.constructor == Super)
console.log(Super.prototype.isPrototypeOf(instance))
console.log(instance instanceof Super)