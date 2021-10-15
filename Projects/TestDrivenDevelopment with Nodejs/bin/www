
const app = require('../app');
const http = require('http');

const port = normalizePort('3000');
app.set('port', port);

const server = http.createServer(app);
server.listen(port);
server.on('error', onError);
server.on('listening', onListening);

function normalizePort(val) {
    let port = parseInt(val, 10);

    if (isNaN(port)) {
        return val;
    }

    if (port >= 0) {
        return port;
    }

    return false;
}

function onError(error) {
    if (error.syscall !== 'listen') {
        throw error;
    }

    let bind = typeof port === 'string' ? 'Pipe' + port : 'Port' + port;

    switch (error.code) {
        case 'EACCESS':
            console.error(bind + 'requires elevated privileges');
            process.exit(1);
            break;
        case "EADDRINUSE":
            console.error(bind + " is already in use");
            process.exit(1);
            break;
        default:
            throw error;
    }
}

function onListening() {
    let addr = server.address();
    let bind = typeof addr === 'string' ? 'pipe' + addr : 'port' + addr.port;
    console.log(`test server listening on port ${port}`);
}