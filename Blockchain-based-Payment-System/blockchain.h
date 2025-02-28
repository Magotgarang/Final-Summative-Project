#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Define wallet structure
typedef struct Wallet {
    char wallet_address[64];
    unsigned int balance;
} Wallet;

// Define transaction structure
typedef struct Transaction {
    char sender[64];
    char receiver[64];
    unsigned int amount;
} Transaction;

// Define block structure
typedef struct Block {
    unsigned int index;
    char previous_hash[64];
    char current_hash[64];
    Transaction transaction;
    struct Block* next;
} Block;

// Function declarations
char* hash_block(Block* block);
void add_transaction_to_blockchain(Transaction tx, Wallet* sender, Wallet* receiver);
void mine_block(Block* block);

#endif // BLOCKCHAIN_H
