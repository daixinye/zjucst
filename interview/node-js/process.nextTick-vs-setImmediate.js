setImmediate(() => {
  console.log("Immediate 第一次 执行");
});

setImmediate(() => {
  console.log("Immediate 第二次 执行");
});

process.nextTick(() => {
  console.log("nextTick 第一次执行");
});

console.log("开始");
