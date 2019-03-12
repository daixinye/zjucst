function add(b,c){
    return this.a + b + c
}

const bind = add.bind({a:1},2)
console.log(bind(5))