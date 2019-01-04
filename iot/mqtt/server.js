const express = require("express");
const app = express();
const url = require("url");
const mqttClient = require("./lib/mqtt");

const utils = {
  parseQuery: function(query) {
    let obj = {};
    query.split("&").forEach(kv => {
      if (kv !== undefined) {
        kv = kv.split("=");
        obj[kv[0]] = kv[1];
      }
    });
    return obj;
  }
};

app.get("*", (req, res) => {
  let queryString = url.parse(req.url).query;
  let queryObj = utils.parseQuery(queryString);
  console.log(queryObj);
  let content = JSON.stringify({
    LIGHT: Number(queryObj.light),
    TEMP: Number(queryObj.temp),
    HUMI: Number(queryObj.humi)
  });
  mqttClient.pub(content);

  res.send("Hello World!");
});

app.listen(80, () => console.log("Example app listening on port 80!"));
