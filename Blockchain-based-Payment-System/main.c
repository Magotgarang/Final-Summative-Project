#include "blockchain.h"

int main() {
    Block* blockchain = NULL;
    Wallet wallet;
    create_wallet(&wallet);
    
    printf("Created wallet:\n");
    view_balance(&wallet);

    // Add transaction example
    Transaction tx = {"wallet-1234", "wallet-5678", 100};
    add_transaction(&blockchain, tx);

    // Mining the block
    mine_block(&blockchain);

    printf("Viewing updated wallet balance:\n");
    view_balance(&wallet);
    
    return 0;
}
