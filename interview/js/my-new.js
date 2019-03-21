function Constructor(){
    this.name = 'dxy'
}

function createInstance(constructor){
    // 1. 创建一个新对象
    var obj = {}
    // 2. 链接原型
    obj.__proto__ = constructor.prototype
    // 3. 添加属性
    constructor.call(obj)
    // 4. 返回对象
    return obj
}

console.log(createInstance(Constructor) instanceof Constructor)