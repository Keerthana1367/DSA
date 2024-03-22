#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 3

int generateRandomVote() {
    return rand() % NUM_CANDIDATES;
}

void calculateVotes(int votes[], int num_votes[]) {
    int i;
    for ( i = 0; i < NUM_CANDIDATES; i++) {
        num_votes[i] = 0;
    }

    for ( i = 0; i < NUM_CANDIDATES; i++) {
        num_votes[votes[i]]++;
    }
}


void declareResults(int num_votes[]) {
    printf("Voting Results:\n");
    int i;
    for ( i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d received %d votes.\n", i+1, num_votes[i]);
    }

    int max_votes = num_votes[0];
    int winner_index = 0;

    for ( i = 1; i < NUM_CANDIDATES; i++) {
        if (num_votes[i] > max_votes) {
            max_votes = num_votes[i];
            winner_index = i;
        }
    }

    printf("Candidate %d wins with %d votes!\n", winner_index+1, max_votes);
}

int main() {
    int votes[NUM_CANDIDATES];
    int num_votes[NUM_CANDIDATES] = {0};

    srand(time(NULL));
    printf("Online Voting System\n");
    int i;
    for ( i = 0; i < NUM_CANDIDATES; i++) {
        votes[i] = generateRandomVote();
        printf("User %d voted for Candidate %d.\n", i+1, votes[i]+1);
    }

    calculateVotes(votes, num_votes);
    declareResults(num_votes);

    return 0;
}
