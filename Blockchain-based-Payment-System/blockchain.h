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

void add_transaction(Block** blockchain, Transaction tx);
void mine_block(Block** blockchain);
void view_balance(Wallet* wallet);
void create_wallet(Wallet* wallet);
char* hash_block(Block* block);

#endif
