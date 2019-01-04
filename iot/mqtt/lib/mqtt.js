const mqtt = require("mqtt");

const config = require("../config");

const { SERVER_NAME, USERNAME, CLIENT_NAME, PASSWORD, PUB_TOPIC } = config;

const client = mqtt.connect(
  SERVER_NAME,
  {
    username: USERNAME,
    password: PASSWORD,
    clientId: CLIENT_NAME
  }
);

// client.on("connect", function() {
//   // 订阅 消息
//   client.subscribe(SUB_TOPIC, function(err) {
//     if (!err) {
//     }
//   });
//   // 推送消息
//   let count = 0;
//   setInterval(() => {
//     console.log(count);
//     client.publish(PUB_TOPIC, `{"LIGHT": ${count}}`);
//     count = (count + 1) % 10;
//   }, 1000);
// });

// // 收到消息
// client.on("message", function(topic, message) {
//   // message is Buffer
//   console.log(message.toString());
//   client.end();
// });

module.exports = {
  __client: client,
  pub: content => {
    console.log(`${Date()} mqtt: ${PUB_TOPIC} => ${content}`);
    client.publish(PUB_TOPIC, content);
  }
};
