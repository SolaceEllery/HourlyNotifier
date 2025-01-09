#pragma once

#include <string>

#include <windows.h>

extern std::string noteOctave0Blacklist[];
extern std::string noteList[];

extern void WriteTerminalMessage(std::string msg);
extern bool StartBeep(std::string note, int octave, int secondsLength);
extern bool Program_IsKeyDown(SHORT vKey);
