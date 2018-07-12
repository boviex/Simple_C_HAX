#ifndef ICON_DISPLAY_H
#define ICON_DISPLAY_H

#include "gbafe.h"

#define MAX_SIMULTANEOUS_ICONS 0x20

// Not replaced
unsigned GetIconGfxTileIndex(unsigned slot) __attribute__((long_call));

// Core functions
unsigned GetIconTileIndex(unsigned icon);
void LoadIconObjectGraphics(unsigned icon, unsigned tile);
void ResetIconGraphics(void);
void ClearIconGfx(unsigned icon);

// User function
const void* GetIconGfx(unsigned icon);

#endif // ICON_DISPLAY_H