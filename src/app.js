const http = require('http');
const fs = require('fs');

const RPC_PORT = 8329; 
const P2P_PORT = 8327;

// Live network memory structures
let transactionMempool = [];

console.log("🎮 =========================================================");
console.log("🎮 QMASK TRANSACTION MEMPOOL PROXY BRIDGE SYSTEM            ");
console.log("🎮 =========================================================");

const server = http.createServer((req, res) => {
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'POST, GET, OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type');

    if (req.method === 'OPTIONS') {
        res.writeHead(200); res.end(); return;
    }

    if (req.method === 'POST') {
        let body = '';
        req.on('data', chunk => { body += chunk.toString(); });
        req.on('end', () => {
            const parsedData = JSON.parse(body);
            
            // Route incoming combat move transaction requests into the network mempool!
            if (parsedData.method === "broadcast_combat_move") {
                const moveTx = {
                    txid: "qtx_" + Math.random().toString(36).substring(2, 15),
                    move: parsedData.params.move,
                    timestamp: Date.now()
                };
                transactionMempool.push(moveTx);
                console.log(`📥 [MEMPOOL INBOUND] Queued unconfirmed transaction: [${moveTx.txid}] Move: ${moveTx.move}`);
                
                res.writeHead(200, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify({ jsonrpc: "2.0", id: 1, result: { status: "QUEUED_IN_MEMPOOL", txid: moveTx.txid } }));
                return;
            }

            // Sync node status and sweep any pending mempool items inside the regular polling cycle
            let sweptMove = "NONE";
            if (transactionMempool.length > 0) {
                const activeTx = transactionMempool.shift(); // Process first transaction in array line
                sweptMove = activeTx.move;
                console.log(`🧱 [BLOCK CONSOLIDATION] Swept transaction [${activeTx.txid}] inside live block header structure.`);
            }

            res.writeHead(200, { 'Content-Type': 'application/json' });
            res.end(JSON.stringify({
                jsonrpc: "2.0",
                id: 1,
                result: {
                    status: "CONNECTED_TO_MAINNET_DAEMON",
                    p2p_port: P2P_PORT,
                    rpc_port: RPC_PORT,
                    active_node: "Yoshiki_Qmask_Base_Anchor",
                    confirmed_mempool_action: sweptMove
                }
            }));
        });
    } 
    else if (req.method === 'GET') {
        const filePath = '/mnt/c/Users/user/Desktop/Qmask-Core/src/index.html';
        fs.readFile(filePath, (err, content) => {
            if (err) {
                res.writeHead(500); res.end("Internal error.");
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' }); res.end(content);
            }
        });
    }
});

server.listen(RPC_PORT, '0.0.0.0', () => {
    console.log(`🟢 [WSL2 BRIDGE ACTIVE] Game dashboard exposed globally on port ${RPC_PORT}!`);
});
