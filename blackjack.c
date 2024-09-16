#include "blackjack.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

size_t card_value(Card card) {
    switch (card.rank) {
    case ACE:
        return 1;
    case TWO:
        return 2;
    case THREE:
        return 3;
    case FOUR:
        return 4;
    case FIVE:
        return 5;
    case SIX:
        return 6;
    case SEVEN:
        return 7;
    case EIGHT:
        return 8;
    case NINE:
        return 9;
    case TEN:
    case JACK:
    case QUEEN:
    case KING:
        return 10;
    }
    assert(0 && "Unreachable");
    return 0;
}

static inline Suite random_suite(void) {
    return HEARTS + (rand() % 4);
}

static inline Rank random_rank(void) {
    return ACE + (rand() % 13);
}

static bool card_exists(Deck *d, Card c) {
    for (size_t i = 0; i < d->size; i++) {
        Card it = d->cards[i];
        if (it.suite == c.suite && it.rank == c.rank) return true;
    }
    return false;
}

void deck_reshuffle(Deck *deck) {
    while (deck->size < MAX_DECK_SIZE) {
        Card c = {
            .suite = random_suite(),
            .rank = random_rank(),
        };
        if (!card_exists(deck, c)) {
            deck->cards[deck->size++] = c;
        }
    }
}

Card deck_draw(Deck *deck) {
    return deck->cards[--deck->size];
}
