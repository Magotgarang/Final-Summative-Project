#include "blockchain.h"

// Function to hash a block's data
char* hash_block(Block* block) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);

    // Concatenate block data for hashing
    SHA256_Update(&sha256_ctx, block->job_listing.title, strlen(block->job_listing.title));
    SHA256_Update(&sha256_ctx, block->job_listing.company, strlen(block->job_listing.company));
    SHA256_Update(&sha256_ctx, block->job_listing.location, strlen(block->job_listing.location));
    SHA256_Update(&sha256_ctx, block->job_listing.description, strlen(block->job_listing.description));

    SHA256_Final(hash, &sha256_ctx);

    static char hash_output[SHA256_DIGEST_LENGTH*2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_output + (i * 2), "%02x", hash[i]);
    }
    return hash_output;
}

// Function to add job listing to blockchain
void add_job_listing(Block** blockchain, Job job) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    strcpy(new_block->job_listing.title, job.title);
    strcpy(new_block->job_listing.company, job.company);
    strcpy(new_block->job_listing.location, job.location);
    strcpy(new_block->job_listing.description, job.description);
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

// Function to search for a job by keyword
void search_job_by_keyword(Block* blockchain, const char* keyword) {
    Block* current = blockchain;
    while (current != NULL) {
        if (strstr(current->job_listing.title, keyword) != NULL ||
            strstr(current->job_listing.description, keyword) != NULL) {
            print_block(current);
        }
        current = current->next;
    }
}

// Function to verify the integrity of the blockchain
void verify_integrity(Block* blockchain) {
    Block* current = blockchain;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->current_hash, current->next->previous_hash) != 0) {
            printf("Integrity breach detected between block %d and block %d\n", current->index, current->next->index);
            return;
        }
        current = current->next;
    }
    printf("Blockchain integrity verified successfully!\n");
}

// Function to print block details
void print_block(Block* block) {
    printf("Job Title: %s\n", block->job_listing.title);
    printf("Company: %s\n", block->job_listing.company);
    printf("Location: %s\n", block->job_listing.location);
    printf("Description: %s\n", block->job_listing.description);
    printf("Block Hash: %s\n\n", block->current_hash);
}
