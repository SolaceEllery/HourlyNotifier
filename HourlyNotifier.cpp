/*
    HourlyNotifier: Beneficial sound effect notifier for every hour that passes
    By Solace D. Ellery
*/

// Seriously...? localtime_s doesn't retrieve the info correctly to determine time, so I need to do this
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#include <chrono>
#include <ctime>

#include <string>

#include <windows.h>
#include "VK_ExtraKeyboardVariables.h"

std::string ProgramName = "Time Notifier";
std::string VersionNumber = "v1.0.0";

bool HourPassed = false;
int HourPreviousValue = 0;
int HourPassFrameCounter = 1;
int HourPassTimeDelay = 180;

bool WindowInBackground = false;
int WindowInBackground_KeyPressDelay = 60;
int WindowInBackground_KeyPressDelay_Timer = WindowInBackground_KeyPressDelay;

bool ProgramStarted = false;

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

int main()
{
    // Create & print the title message to the console
    WriteTerminalMessage(ProgramName + " (" + VersionNumber + ")\n----------------\n\n");

    // Write the help messages before starting the loop
    WriteTerminalMessage("This program will now play a sound for every time a\nnew hour has passed.");
    WriteTerminalMessage("\n\n");
    WriteTerminalMessage("To place this program in the background (And unhide anytime),\npress CTRL + ALT + SHIFT + N + M.");
    WriteTerminalMessage("\n\n");
    WriteTerminalMessage("To exit this program, press ESC while the window is focused.");
    WriteTerminalMessage("\n");

    StartBeep("C", 4, 3);

    // Start the official loop!
    while (1) // This loops until the program exits
    {
        // Get the delay timer down to 0 if higher than so
        if (WindowInBackground_KeyPressDelay_Timer > 0)
        {
            WindowInBackground_KeyPressDelay_Timer = WindowInBackground_KeyPressDelay_Timer - 1;
        }

        // Get the time since the Epoch
        std::time_t EpochClock = std::time(nullptr);

        // Get the current time
        std::tm* TimeClock = std::localtime(&EpochClock);

        // Now get the hours, minutes, and seconds of the real time clock
        int TimeHour = TimeClock->tm_hour;
        int TimeMinute = TimeClock->tm_min;
        int TimeSecond = TimeClock->tm_sec;

        if (!ProgramStarted)
        {
            HourPreviousValue = TimeHour;
            WindowInBackground_KeyPressDelay_Timer = 0;
            ProgramStarted = true;
        }

        // Check if the hour has a difference vs. the real time hour. If there is, assume the next hour has passed.
        if (TimeSecond == 0 && TimeMinute == 0 && TimeClock->tm_hour != HourPreviousValue)
        {
            // Set "HourPassed" to true
            HourPassed = true;
        }
        if (HourPassed)
        {
            // Subtract the frame counter
            HourPassFrameCounter--;

            // If less than or equal to 0, reset the frame counter and set "HourPassed" to false
            if (HourPassFrameCounter <= 0)
            {
                StartBeep("C", 5, 5);
                HourPassFrameCounter = 1;
                HourPassed = false;
            }
        }

        // Fetch key states for CTRL, ALT, SHIFT, ESC, N, and M
        SHORT keyState_CTRL = GetAsyncKeyState(VK_CONTROL);
        SHORT keyState_ALT = GetAsyncKeyState(VK_MENU);
        SHORT keyState_SHIFT = GetAsyncKeyState(VK_SHIFT);
        SHORT keyState_ESC = GetAsyncKeyState(VK_ESCAPE);
        SHORT keyState_N = GetAsyncKeyState(VK_N);
        SHORT keyState_M = GetAsyncKeyState(VK_M);

        // Test high bit - if set, key was down when GetAsyncKeyState was called
        if ((1 << 15) & (keyState_CTRL && keyState_ALT && keyState_SHIFT && keyState_N && keyState_M))
        {
            if (WindowInBackground_KeyPressDelay_Timer == 0)
            {
                // Put the program in the background or not when these keys are pressed simuntaneously
                if (WindowInBackground)
                {
                    ShowWindow(GetConsoleWindow(), SW_SHOW);
                    WindowInBackground = false;
                }
                else
                {
                    ShowWindow(GetConsoleWindow(), SW_HIDE);
                    WindowInBackground = true;
                }
            }
        }
        if ((1 << 15) & (keyState_ESC))
        {
            // Close the program ONLY if the window is on focus (Will code this in and commit sometime later, just close the program yourself until it's added)
        }
    }
}
