#ifndef BLACKJACK_H_
#define BLACKJACK_H_

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

size_t card_value(Card card);

typedef struct {
    size_t size;
    Card cards[MAX_DECK_SIZE];
} Deck;

void deck_reshuffle(Deck *deck);
Card deck_draw(Deck *deck);

#endif // BLACKJACK_H_
