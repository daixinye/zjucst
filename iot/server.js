const http = require('http')

const httpServer = http.createServer((req, res) => {
    res.writeHead(200, 'OK')
    res.end('hello world')
})

httpServer.listen(8080)

httpServer.on('connection',socket => {
    socket.on('data', data => {
        console.log(data.toString())
    })

    socket.on('connect', () => {
        console.log('connect')
    })

    socket.on('drain', () => {
        console.log('drain')
    })
    
    socket.on('end', ()=> {
        console.log('end')
    })

    socket.on('close', () => {
        console.log('close')
    })
})

