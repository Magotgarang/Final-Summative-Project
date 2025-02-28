#include <stdio.h>
#include <string.h>
#include "blockchain.h"

int main() {
    // Create sender wallet
    Wallet sender = {"wallet-9383", 1000};  // Example wallet
    printf("Created sender wallet:\nWallet address: %s\nBalance: %d\n", sender.wallet_address, sender.balance);

    // Create receiver wallet
    Wallet receiver = {"wallet-886", 1000};  // Example wallet
    printf("Created receiver wallet:\nWallet address: %s\nBalance: %d\n", receiver.wallet_address, receiver.balance);

    // Initialize the transaction struct properly
    Transaction tx;
    strcpy(tx.sender, sender.wallet_address); // Sender wallet address
    strcpy(tx.receiver, receiver.wallet_address); // Receiver wallet address
    tx.amount = 200;  // Transaction amount

    // Print transaction details for debugging
    printf("\nTransaction Details:\nSender: %s\nReceiver: %s\nAmount: %d\n", tx.sender, tx.receiver, tx.amount);

    // Add transaction to blockchain and update wallet balances
    add_transaction_to_blockchain(tx, &sender, &receiver);

    // Show wallet balances after transaction
    printf("\nViewing updated wallet balances after transaction:\n");
    printf("Wallet address: %s\nBalance: %d\n", sender.wallet_address, sender.balance);
    printf("Wallet address: %s\nBalance: %d\n", receiver.wallet_address, receiver.balance);

    return 0;
}
