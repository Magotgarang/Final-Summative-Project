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

    if (*blockchain == NULL) {
        strcpy(new_block->previous_hash, "0");
    } else {
        strcpy(new_block->previous_hash, (*blockchain)->current_hash);
    }
    
    strcpy(new_block->current_hash, hash_block(new_block));
    new_block->next = *blockchain;
    *blockchain = new_block;
}

// Function to mine a block (simulating Proof of Work)
void mine_block(Block** blockchain) {
    // Simulate mining process
}

// Function to view wallet balance
void view_balance(Wallet* wallet) {
    printf("Wallet address: %s\n", wallet->wallet_address);
    printf("Balance: %u\n", wallet->balance);
}

// Function to create a wallet
void create_wallet(Wallet* wallet) {
    // Generate a random wallet address (simplified)
    sprintf(wallet->wallet_address, "wallet-%u", rand() % 10000);
    wallet->balance = 1000; // Initial balance
}
