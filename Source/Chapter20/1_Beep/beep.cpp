#include "windows.h"
using namespace System;
using namespace System::Runtime::InteropServices;
public ref struct Beep
{
    enum struct BeepTypes : unsigned int
    {
        Beep = (unsigned int) -1,
               Asterix = MB_ICONASTERISK,
        Exclamation = MB_ICONEXCLAMATION,
        Hand = MB_ICONHAND,
        Question = MB_ICONQUESTION,
        OK = MB_OK,
    };
    static void MessageBeep(enum class BeepTypes beep)
    {
        ::MessageBeep((unsigned int)beep);
    }
};
void main()
{
    Beep::MessageBeep(Beep::BeepTypes::Exclamation);
}
