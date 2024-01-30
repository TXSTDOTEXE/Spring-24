 /* 
    The provided code gives a class for a Card, Deck, and Hand. The only thing you
    need to do is implement the game logic in main. Feel free to modify this code,
    if you have any questions feel free to use the internet or ask for help. 
    It's recommended to have completed Foundations II or to have knowledge in
    classes to do this mini-project.
    Template by James.
*/
    
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Card structure
class Card {
    public:

        /* If you don't know what enums are check out 
        https://www.programiz.com/cpp-programming/enumeration
        TL;DR they are just ints with special names.
        */
    
        enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
        enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

        Suit suit;
        Rank rank;
        // Constructor
        Card(Suit s, Rank r) : suit(s), rank(r) {}
        // Get value of the card
        int getValue() const {
            // 2-10 are counted as face value.
            if (rank >= TWO && rank <= TEN)
                return rank;
            // J, Q, K are all counted as a value of 10 in blackjack
            else if (rank >= JACK && rank <= KING)
                return 10;
            // Aces can be either 1 or 11, implemented in getHandValue(), for now its value is 11.
            else
                return 11;
        }
};

// Deck class
class Deck {
    private:
        // If you don't know what vectors are, they are essentially just fancy arrays that
        // don't need to have an exact size. (Like ArrayList if you've used Java)
        // Read more here: https://www.geeksforgeeks.org/vector-in-cpp-stl/#
        vector<Card> cards;

    public:
        // Constructor - Create every card in a 52 card deck.
        Deck() {
            for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
                for (int r = Card::ACE; r <= Card::KING; ++r) {
                    cards.push_back(Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
                }
            }
            shuffle();
        }

        // Shuffle the deck - We use the random_shuffle function from importing algorithm.
        // Read more about it here:
        // https://cplusplus.com/reference/algorithm/random_shuffle/

        void shuffle() {
            srand(time(0)); // Random seed
            random_shuffle(cards.begin(), cards.end());
        }

        // Deal a card - pops a Card from the end of the vector and returns it.
        Card dealCard() {
            Card c = cards.back();
            cards.pop_back();
            return c;
        }
};

// Hand class
class Hand {
    private:
        vector<Card> hand;
    public:
        // Add a card to player's hand
        void addCard(const Card& card) {
            hand.push_back(card);
        }

        // Clear player's hand
        void clearHand() {
            hand.clear();
        }

        // Get player's hand value
        int getHandValue() const {
            int value = 0;
            int numAces = 0;

            // Calculate the value of the hand, not including aces.
            for (Card card : hand) {
                value += card.getValue();
                if (card.getValue() == 11)
                    numAces++;
            }
            // Aces can be 11 or 1, this will make sure it will be 1 if it's beneficial.
            while (value > 21 && numAces > 0) {
                value -= 10;
                numAces--;
            }

            return value;
        }

        // Display player's hand
        void showHand() const {
            for (Card card : hand) {
                cout << "[" << card.rank << " of " << card.suit << "] ";
            }
            cout << endl;
        }
    };

    // Main function
int main() {
    // Class implementations are provided above
    Deck deck;
    Hand player, dealer;
    
    // Initial deal
    // These give examples of how to add cards to hands.
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
   
    // Display hands
    cout << "Player's Hand:\n";
    player.showHand();
    cout << "Dealer's Hand:\n";
    dealer.showHand();

    // *** INSERT GAME LOGIC HERE ***
    
    return 0;
}
