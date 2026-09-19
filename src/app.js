// Fortified JSON-RPC 1.0/2.0 request structure matching the Alpha-0 backend engine layout
fetch('http://127.0.0', {
    method: 'POST',
    headers: {
        // Core Node RPC filters traditionally require text/plain or application/json headers
        'Content-Type': 'text/plain;',
        'Authorization': 'Basic ' + btoa('rpcuser:rpcpassword')
    },
    body: JSON.stringify({
        jsonrpc: '1.0',
        id: 'qmask_dashboard_telemetry', // Explicit session tracker tag prevents 501 handling drifts
        method: 'getblockchaininfo',
        params: []
    })
})
.then(response => {
    if (!response.ok) {
        throw new Error("HTTP connection anomaly logged! Status payload code: " + response.status);
    }
    return response.json();
})
.then(data => {
    // Check if the data payload structure returned from your moneud core is valid
    if (data.result) {
        let currentBlockHeight = data.result.blocks;
        let activeChainNetwork = data.result.chain;
        console.log("📡 [SUCCESS] Connected to Qmask Alpha-0 Node Framework live!");
        console.log("🧱 Chain Matrix: " + activeChainNetwork + " | Verified Block Height: " << currentBlockHeight);
    } else if (data.error) {
        console.error("❌ Core Node RPC Exception Profile Caught:", data.error);
    }
})
.catch(error => {
    console.error("❌ Node Connection Error: Ensure ./src/moneud is running live on port 8328!", error);
});
