#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct Wallet {
    char wallet_address[64];
    unsigned int balance;
} Wallet;

typedef struct Transaction {
    char sender[64];
    char receiver[64];
    unsigned int amount;
} Transaction;

typedef struct Block {
    unsigned int index;
    char previous_hash[64];
    char current_hash[64];
    Transaction transaction;
    struct Block* next;
} Block;

// Function prototypes
Wallet create_wallet();
void add_transaction_to_blockchain(Transaction tx);
void mine_block();

#endif
