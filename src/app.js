const http = require('http');
const fs = require('fs');

const RPC_PORT = 8329; 
const P2P_PORT = 8327;

console.log("🎮 =========================================================");
console.log("🎮 QMASK BINDING TO ALL INTERFACES (PUNCHING THROUGH WSL2)  ");
console.log("🎮 =========================================================");

const server = http.createServer((req, res) => {
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'POST, GET, OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type');

    if (req.method === 'OPTIONS') {
        res.writeHead(200);
        res.end();
        return;
    }

    if (req.method === 'POST') {
        let body = '';
        req.on('data', chunk => { body += chunk.toString(); });
        req.on('end', () => {
            res.writeHead(200, { 'Content-Type': 'application/json' });
            res.end(JSON.stringify({
                jsonrpc: "2.0",
                id: 1,
                result: {
                    status: "CONNECTED_TO_MAINNET_DAEMON",
                    p2p_port: P2P_PORT,
                    rpc_port: RPC_PORT,
                    active_node: "Yoshiki_Qmask_Base_Anchor"
                }
            }));
        });
    } 
    else if (req.method === 'GET') {
        const filePath = '/mnt/c/Users/user/Desktop/Qmask-Core/src/index.html';
        fs.readFile(filePath, (err, content) => {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end("Internal System Error: Missing index.html tracks.");
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.end(content);
            }
        });
    }
});

// 🛠️ CRITICAL FIX: Explicitly bind to '0.0.0.0' to open the server to your Windows host machine
server.listen(RPC_PORT, '0.0.0.0', () => {
    console.log(`🟢 [WSL2 BRIDGE ACTIVE] Game dashboard exposed globally on port ${RPC_PORT}!`);
    console.log(`💡 Gateway Target: Open Brave and navigate to http://localhost:${RPC_PORT}\n`);
});
