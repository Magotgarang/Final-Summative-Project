# Task 2: Blockchain-based Payment System

## Task Overview
The task involves creating a blockchain-based payment system. Users can create wallets, send payments, and ensure the integrity of their transactions through blockchain principles. Each transaction is recorded in the blockchain, and each block contains a hash that connects it to the previous block to prevent tampering.

### Objective:
- **Create wallets**: Users can generate a wallet with a unique address and an initial balance.
- **Send Payments**: Users can send payments to another wallet, and each transaction is recorded in the blockchain.
- **Verify Transaction Integrity**: The blockchain structure ensures that transactions are secure and cannot be altered.

### Key Features:
- **Blockchain Integrity**: Ensures that transactions are tamper-proof by using cryptographic hashes for each block.
- **Wallet Creation**: Allows users to create wallets with a unique address and balance.
- **Transaction History**: Every transaction is stored in the blockchain, maintaining an immutable record.

### How to Compile and Run
To compile the application, use the following command:

```bash
gcc -o payment_system main.c blockchain.c -lssl -lcrypto
