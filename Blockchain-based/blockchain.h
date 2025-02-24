#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_JOB_DESC 1024
#define MAX_JOB_TITLE 256
#define MAX_COMPANY_NAME 256
#define MAX_JOB_LOCATION 256

typedef struct Job {
    char title[MAX_JOB_TITLE];
    char company[MAX_COMPANY_NAME];
    char location[MAX_JOB_LOCATION];
    char description[MAX_JOB_DESC];
} Job;

typedef struct Block {
    int index;
    char previous_hash[SHA256_DIGEST_LENGTH*2 + 1];
    char current_hash[SHA256_DIGEST_LENGTH*2 + 1];
    Job job_listing;
    struct Block* next;
} Block;

void add_job_listing(Block** blockchain, Job job);
void search_job_by_keyword(Block* blockchain, const char* keyword);
void verify_integrity(Block* blockchain);
void print_block(Block* block);
char* hash_block(Block* block);

#endif
