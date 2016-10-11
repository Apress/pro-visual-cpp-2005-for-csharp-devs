using namespace System;
ref struct Painting
{
    String ^artist;
    String ^name;
    int date;
    Painting(String ^artist, String ^name, int date)
    {
        this->artist = artist;
        this->name = name;
        this->date = date;
    }
    virtual String ^ToString() override
    {
        return String::Format("{0} ({1})", name, date);
    }
};
ref struct R
{
    static void Main()
    {
        array<array<Painting^>^> ^Painters =
        {
            {
                gcnew Painting("Leonardo da Vinci", "Mona Lisa", 1505)
            },
            {
                gcnew Painting("Marc Chagall", "I and the Village", 1911),
                gcnew Painting("Marc Chagall", "La Mariee", 1927)
            }
        };
        for each (array<Painting^>^ painter in Painters)
        {
            Console::WriteLine("Paintings by {0}", painter[0]->artist);
            for each (Painting ^painting in painter)
            {
                Console::WriteLine(" {0}",painting);
            }
        }
    }
};
void main() {R::Main();}
