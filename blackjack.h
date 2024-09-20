#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <stdbool.h>
#include <stddef.h>

#define MAX_DECK_SIZE 52

typedef enum {
    HEARTS = 0,
    DIAMONDS,
    CLUBS,
    SPADES,
} Suite;

typedef enum {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
} Rank;

typedef struct {
    Suite suite;
    Rank rank;
} Card;

typedef struct {
    size_t size;
    Card cards[MAX_DECK_SIZE];
} Deck;

void reshuffle_deck(Deck *deck);

// Theoretical biggest hand: 4 aces, 4 twos, 3 threes -> Total: 11.
#define MAX_HAND_SIZE 11

typedef struct {
    int value;
    bool is_soft;
    bool first_ace_seen;

    size_t size;
    Card cards[MAX_HAND_SIZE];
} Hand;

typedef int Chips;

typedef struct {
    Chips chips;
    Hand hand;
} Player;

// Draws a card from the deck to the player's hand
// and updates the hand's value.
void draw_card(Player *player, Deck *deck);

#endif // BLACKJACK_H_
