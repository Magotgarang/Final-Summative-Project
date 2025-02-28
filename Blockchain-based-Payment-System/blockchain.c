#include "blockchain.h"
#include <openssl/sha.h>

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
void add_transaction_to_blockchain(Transaction tx, Wallet* sender, Wallet* receiver) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    
    // Assign transaction details to the new block
    new_block->transaction = tx;
    new_block->index = 0;  // You can increment this based on the blockchain structure

    // Example: Set the initial values for the previous hash (can be adjusted based on your implementation)
    strcpy(new_block->previous_hash, "0");

    // Hash this block and set the current hash
    strcpy(new_block->current_hash, hash_block(new_block));

    // Add new block to blockchain (Here we just print it for demonstration)
    printf("Transaction added to blockchain:\n");
    printf("Sender: %s, Receiver: %s, Amount: %d\n", tx.sender, tx.receiver, tx.amount);

    // Adjust sender and receiver balances based on transaction
    sender->balance -= tx.amount;
    receiver->balance += tx.amount;
}

// Example of mining a block (implementing mining logic)
void mine_block(Block* block) {
    printf("Mining block...\n");
    // Implement mining logic here (e.g., proof of work)
}
