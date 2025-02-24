#include "blockchain.h"

int main() {
    Block* blockchain = NULL;
    
    Job job1 = {"Software Engineer", "TechCorp", "NYC", "Developing cutting-edge software."};
    Job job2 = {"Data Scientist", "DataSolutions", "San Francisco", "Analyzing big data."};
    
    add_job_listing(&blockchain, job1);
    add_job_listing(&blockchain, job2);
    
    printf("Searching for 'Software':\n");
    search_job_by_keyword(blockchain, "Software");
    
    printf("Verifying blockchain integrity:\n");
    verify_integrity(blockchain);
    
    return 0;
}
