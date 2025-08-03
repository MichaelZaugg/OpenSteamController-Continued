
# Keycodes

This document goes over the values of each keycode. These are used for storing configurations within the EEPROM.
Keyboard keycodes are ordered as if you're reading each individual key from left to right, top to bottom.

## IMPORTANT

This is currently not in use. These keycodes will be used later in development, *after* the base controller firmware has been fully completed, and development moves on to custom firmware.

## Keyboard

| Key    | Hex  |
| ------ | ---- |
| ESC    | 0x00 |
| F1     | 0x01 |
| F2     | 0x02 |
| F3     | 0x03 |
| F4     | 0x04 |
| F5     | 0x05 |
| F6     | 0x06 |
| F7     | 0x07 |
| F8     | 0x08 |
| F9     | 0x09 |
| F10    | 0x0A |
| F11    | 0x0B |
| F12    | 0x0C |
| PRNSCR | 0x0D |
| SCRLCK | 0x0E |
| PSBRK  | 0x0F |
| `      | 0x10 |
| 1      | 0x11 |
| 2      | 0x12 |
| 3      | 0x13 |
| 4      | 0x14 |
| 5      | 0x15 |
| 6      | 0x16 |
| 7      | 0x17 |
| 8      | 0x18 |
| 9      | 0x19 |
| 0      | 0x1A |
| -      | 0x1B |
| =      | 0x1C |
| BCKSPC | 0x1D |
| INS    | 0x1E |
| HOME   | 0x1F |
| PG UP  | 0x20 |
| NUMLK  | 0x21 |
| NUM/  | 0x22 |
| NUM*   | 0x23 |
| NUM-   | 0x24 |
| TAB    | 0x25 |
| Q      | 0x26 |
| W      | 0x27 |
| E      | 0x28 |
| R      | 0x29 |
| T      | 0x2A |
| Y      | 0x2B |
| U      | 0x2C |
| I      | 0x2D |
| O      | 0x2E |
| P      | 0x2F |
| [      | 0x30 |
| ]      | 0x31 |
| \\     | 0x32 |
| DEL    | 0x33 |
| END    | 0x34 |
| PG DN  | 0x35 |
| NUM7   | 0x36 |
| NUM8   | 0x37 |
| NUM9   | 0x38 |
| NUM+   | 0x39 |
| CAPS   | 0x3A |
| A      | 0x3B |
| S      | 0x3C |
| D      | 0x3D |
| F      | 0x3E |
| G      | 0x3F |
| H      | 0x40 |
| J      | 0x41 |
| K      | 0x42 |
| L      | 0x43 |
| ;      | 0x44 |
| '      | 0x44 |
| ENTER  | 0x45 |
| NUM4   | 0x46 |
| NUM5   | 0x47 |
| NUM6   | 0x48 |
| LSHIFT | 0x49 |
| Z      | 0x4A |
| X      | 0x4B |
| C      | 0x4C |
| V      | 0x4D |
| B      | 0x4E |
| N      | 0x4F |
| M      | 0x50 |
| ,      | 0x51 |
| .      | 0x52 |
| /      | 0x53 |
| RSHIFT | 0x54 |
| ARRUP  | 0x55 |
| NUM1   | 0x56 |
| NUM2   | 0x57 |
| NUM3   | 0x58 |
| NUMENT | 0x59 |
| LCRTL  | 0x5A |
| LSUPER | 0x5B |
| LALT   | 0x5C |
| SPACE  | 0x5D |
| RALT   | 0x5E |
| RSUPER | 0x5F |
| RAPP   | 0x60 |
| RCTRL  | 0x61 |
| LARR   | 0x62 |
| DARR   | 0x63 |
| RARR   | 0x64 |
| NUM0   | 0x65 |
| NUMDOT | 0x66 |

## Mouse

| Key         | Hex  |
| ----------- | ---- |
| LMB         | 0x67 |
| MMB         | 0x68 |
| RMB         | 0x69 |
| Scroll Up   | 0x6A |
| Scroll Down | 0x6B |
| Mouse 4     | 0x6C |
| Mouse 5     | 0x6D |

## Gamepad

| Key               | Hex  |
| ----------------- | ---- |
| LB                | 0x6E |
| LT                | 0x6F |
| RB                | 0x70 |
| RT                | 0x71 |
| Left Stick Up     | 0x72 |
| Left Stick Down   | 0x73 |
| Left Stick Left   | 0x74 |
| Left Stick Right  | 0x75 |
| Left Stick Click  | 0x76 |
| Right Stick Up    | 0x77 |
| Right Stick Down  | 0x78 |
| Right Stick Left  | 0x79 |
| Right Stick Right | 0x7A |
| Right Stick Click | 0x7B |
| D-Pad Up          | 0x7C |
| D-Pad Down        | 0x7D |
| D-Pad Left        | 0x7E |
| D-Pad Right       | 0x7F |
| A                 | 0x80 |
| B                 | 0x81 |
| X                 | 0x82 |
| Y                 | 0x83 |
| Select            | 0x84 |
| Start             | 0x85 |

## System

| Key                           | Hex  |
| ----------------------------- | ---- |
| Take Screenshot               | 0x86 |
| Toggle Manual Recording       | 0x87 |
| Add Timeline Marker           | 0x88 |
| Create Clip                   | 0x89 |
| Show Keyboard                 | 0x8A |
| Toggle Magnifier              | 0x8B |
| Force Game Shutdown           | 0x8C |
| Changer Player Slot           | 0x8D |
| Turn Off Controller           | 0x8E |
| Touchscreen Native Support    | 0x8F |
| Touchscreen Left Click        | 0x90 |
| Touchscreen Right Click       | 0x91 |
| Touchscreen Scrollwheel Click | 0x91 |
| Touchscreen Cursor Movement   | 0x92 |
| Touchscreen Off               | 0x93 |
| Volume Up Key                 | 0x94 |
| Volume Down Key               | 0x95 |
| Minimize Big Picture          | 0x96 |
| Open Big Picture              | 0x97 |
| Quit Big Picture              | 0x98 |
| Suspend System                | 0x99 |
| Power Off System              | 0x9A |
| Restart System                | 0x9B |
