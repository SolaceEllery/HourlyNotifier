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
#include <winuser.h>

#include "Globals.h"
#include "VK_ExtraKeyboardVariables.h"

std::string ProgramName = "Time Notifier";
std::string VersionNumber = "v1.0.0";

bool HourPassed = false;
int HourPreviousValue = 0;
int HourPassFrameCounter = 1;
int HourPassTimeDelay = 180;

bool WindowInBackground = false;
int WindowInBackground_KeyPressDelay = 200;
int WindowInBackground_KeyPressDelay_Timer = WindowInBackground_KeyPressDelay;

bool ProgramStarted = false;

int main(int argc, char* argv[])
{
    const WCHAR* ProgramTitle = L"Hourly Notifier";
    SetConsoleTitle(ProgramTitle);

    if (argc > 1)
    {
        // Terminal command support
        for (int i = 1; i < argc; ++i)
        {
            // Background mode
            if ((argv[i] == "-b") || (argv[i] == "--background"))
            {
                ShowWindow(GetConsoleWindow(), SW_HIDE);
                WindowInBackground = true;
            }
            // Sound changing
            if ((argv[i] == "-s") || (argv[i] == "--sound") || (argv[i] == "--sfx") || (argv[i] == "--soundeffect"))
            {
                // WIP
            }
        }
    }

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
            WindowInBackground_KeyPressDelay_Timer -= 1;
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
        if (Program_IsKeyDown(keyState_CTRL) && Program_IsKeyDown(keyState_ALT) && Program_IsKeyDown(keyState_SHIFT) && Program_IsKeyDown(keyState_N) && Program_IsKeyDown(keyState_M))
        {
            // Background mode
            if (WindowInBackground_KeyPressDelay_Timer == 0)
            {
                // Put the program in the background or not when these keys are pressed simuntaneously
                if (WindowInBackground)
                {
                    ShowWindow(GetConsoleWindow(), SW_SHOW);
                    WindowInBackground_KeyPressDelay_Timer = WindowInBackground_KeyPressDelay;
                    WindowInBackground = false;
                }
                else
                {
                    ShowWindow(GetConsoleWindow(), SW_HIDE);
                    WindowInBackground_KeyPressDelay_Timer = WindowInBackground_KeyPressDelay;
                    WindowInBackground = true;
                }
            }
        }
        if (Program_IsKeyDown(keyState_ESC) && (GetFocus() == FindWindowA(NULL, "Hourly Notifier")))
        {
            // Close the program
            return 0;
        }
    }
}
