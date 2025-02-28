#include "blockchain.h"

// Function to hash a block's data
char* hash_block(Block* block) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);

    SHA256_Update(&sha256_ctx, block->transaction.sender, strlen(block->transaction.sender));
    SHA256_Update(&sha256_ctx, block->transaction.receiver, strlen(block->transaction.receiver));
    SHA256_Update(&sha256_ctx, &block->transaction.amount, sizeof(block->transaction.amount));

    SHA256_Final(hash, &sha256_ctx);

    static char hash_output[SHA256_DIGEST_LENGTH*2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_output + (i * 2), "%02x", hash[i]);
    }
    return hash_output;
}

// Function to add transaction to blockchain
void add_transaction(Block** blockchain, Transaction tx) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    new_block->transaction = tx;
    new_block->index = *blockchain == NULL ? 0 : (*blockchain)->index + 1;
    strcpy(new_block->previous_hash, (*blockchain) ? (*blockchain)->current_hash : "0");

    // Hash the current block
    char* current_hash = hash_block(new_block);
    strcpy(new_block->current_hash, current_hash);

    new_block->next = *blockchain;
    *blockchain = new_block;
}

// Function to mine a block (simulate the mining process)
void mine_block() {
    printf("Mining block...\n");
    // Here you can simulate the mining process, such as adding some delay or simulating proof-of-work
}

// Function to create a wallet (this can generate random wallet addresses)
Wallet create_wallet() {
    Wallet wallet;
    snprintf(wallet.wallet_address, sizeof(wallet.wallet_address), "wallet-%d", rand() % 10000);
    wallet.balance = 1000; // Starting balance
    return wallet;
}

// Function to add transaction to the blockchain
void add_transaction_to_blockchain(Transaction tx) {
    static Block* blockchain = NULL;
    add_transaction(&blockchain, tx);
}
