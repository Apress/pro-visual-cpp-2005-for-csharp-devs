using namespace System;
namespace CPP
{
    public ref class Deck
    {
        array<unsigned int>^Cards;
        Random^ randomGenerator;
        enum class Suit
        {
            Clubs = 0, Diamonds, Hearts, Spades
        };
        enum class Card
        {
            Ace=0, Deuce, Trey, Four, Five, Six, Seven,
            Eight, Nine, Ten, Jack, Queen, King
        };
        Deck()
        {
            randomGenerator = gcnew Random();
            Cards = gcnew array<unsigned int>(52);
            for (unsigned int u = 0; u < 52; ++u)
            {
                Cards[u] = u;
            }
        }
        void Swap(unsigned int %u,unsigned int %v)
        {
            unsigned int tmp;
            tmp = u;
            u = v;
            v = tmp;
        }
        void Shuffle()
        {
            for (unsigned int u = 52; u > 0; --u)
            {
                Swap(Cards[u - 1],Cards[RandomCard(u)]);
            }
        }
        unsigned int RandomCard(unsigned int Max)
        {
            return(unsigned int)((double)Max * randomGenerator->NextDouble());
        }
        String^ CardToString(unsigned int u)
        {
            Suit s = (Suit)(Cards[u] / 13);
            Card c = (Card)(Cards[u] % 13);
            return c.ToString() + " of " + s.ToString();
        }
        public:
        static void Main()
        {
            Deck^ deck = gcnew Deck();
            deck->Shuffle();
            for (unsigned int u = 0; u < 5; ++u)
            {
                Console::WriteLine(deck->CardToString(u));
            }
            Console::ReadLine();
        }
    };
}
void main()
{
    CPP::Deck::Main();
}
