#include "Globals.h"

#include <string>
#include <iostream>

#include <windows.h>





// |---------------|
// [-- VARIABLES --]
// |---------------|

std::string noteOctave0Blacklist[] = {
    "A",
    "A#",
    "B",
};

std::string noteList[] = {
    "A",
    "A#",
    "B",
    "C",
    "C#",
    "D",
    "D#",
    "E",
    "F",
    "F#",
    "G",
    "G#",
};







// |---------------|
// [-- FUNCTIONS --]
// |---------------|

// Simple function to write to the terminal with std::string types
void WriteTerminalMessage(std::string msg)
{
    std::cout << msg.c_str();
}

// Simplified function to play Windows beeps in a musical fashion
bool StartBeep(std::string note, int octave, int secondsLength)
{
    // Create variables for total note values and octave counts
    int noteTotalSeparation = 50;
    int octaveCount = (noteTotalSeparation * 12);

    // And create one for 1 second to millisecond conversion
    int millisecondsTotalSeconds = 1000;

    // Start a for loop
    for (int i = 1; i <= 12; i++)
    {
        // Check if octave 0 is not on B and below, and return if so
        if (octave == 0 && note == noteOctave0Blacklist[i])
        {
            return false;
        }

        // Make sure we know we have a valid note and key
        if (note == noteList[i] && octave >= 0)
        {
            return Beep((noteTotalSeparation * (i - 1)) * octave, millisecondsTotalSeconds * secondsLength);
        }
    }

    return false;
}

bool Program_IsKeyDown(SHORT vKey)
{
    if (((1 << 15) & (vKey)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
