#include <stdio.h>
#include <string.h>
#include "blockchain.h"

int main() {
    // Create sender wallet
    Wallet sender = create_wallet();
    printf("Created sender wallet:\nWallet address: %s\nBalance: %d\n", sender.wallet_address, sender.balance);

    // Create receiver wallet
    Wallet receiver = create_wallet();
    printf("Created receiver wallet:\nWallet address: %s\nBalance: %d\n", receiver.wallet_address, receiver.balance);

    // Initialize the transaction struct properly
    Transaction tx;
    strcpy(tx.sender, sender.wallet_address);  // Use the sender's wallet address
    strcpy(tx.receiver, receiver.wallet_address); // Use the receiver's wallet address
    tx.amount = 200;  // Set the transaction amount

    // Print transaction details for debugging
    printf("\nTransaction Details:\nSender: %s\nReceiver: %s\nAmount: %d\n", tx.sender, tx.receiver, tx.amount);

    // Add transaction to blockchain
    add_transaction_to_blockchain(tx);

    // Simulate mining the block
    mine_block();

    // View updated wallet balances after transaction
    printf("\nViewing updated wallet balances after transaction:\n");
    printf("Wallet address: %s\nBalance: %d\n", sender.wallet_address, sender.balance);
    printf("Wallet address: %s\nBalance: %d\n", receiver.wallet_address, receiver.balance);

    return 0;
}
