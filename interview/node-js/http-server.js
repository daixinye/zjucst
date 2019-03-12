const http = require("http")

const httpServer = http.createServer((req,res)=>{
    res.writeHead(200)
    res.end(JSON.stringify( gvfreq.rawHeaders))
})

httpServer.listen(8888)