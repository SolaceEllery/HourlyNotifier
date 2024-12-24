#include <string>
#include <map>

// Disable these messages
#pragma warning (disable : VCR101)
#pragma warning (disable : VCR003)

// Create a map, used for programs outside Visual Studio/windows.h
std::map<std::string, int> VirtualKey;

// Adds or changes a map value to the "VirtualKey" map. The map will be used
static void defineVK(std::string vkName, uint8_t vkValue)
{
    VirtualKey[vkName] = vkValue;
}

// Uncomment to also include other Windows.h functions. They're already defined though, so idk why you would need to uncomment it.

// **Keyboard constants**



// Letters
#define VK_A               65
#define VK_B               66
#define VK_C               67
#define VK_D               68
#define VK_E               69
#define VK_F               70

#define VK_G               71
#define VK_H               72
#define VK_I               73
#define VK_J               74
#define VK_K               75
#define VK_L               76
#define VK_M               77
#define VK_N               78
#define VK_O               79
#define VK_P               80

#define VK_Q               81
#define VK_R               82
#define VK_S               83
#define VK_T               84
#define VK_U               85
#define VK_V               86
#define VK_W               87
#define VK_X               88
#define VK_Y               89
#define VK_Z               90



// *Numbers (Literal Words)*
#define VK_ZERO            48
#define VK_ONE             49
#define VK_TWO             50
#define VK_THREE           51
#define VK_FOUR            52
#define VK_FIVE            53
#define VK_SIX             54
#define VK_SEVEN           55
#define VK_EIGHT           56
#define VK_NINE            57



// *Numbers (Actual Numbers)*
#define VK_0               48
#define VK_1               49
#define VK_2               50
#define VK_3               51
#define VK_4               52
#define VK_5               53
#define VK_6               54
#define VK_7               55
#define VK_8               56
#define VK_9               57



// *Number Pad Keys (Literal Words)*
#define VK_NUMPAD_ZERO     96
#define VK_NUMPAD_ONE      97
#define VK_NUMPAD_TWO      98
#define VK_NUMPAD_THREE    99
#define VK_NUMPAD_FOUR     100
#define VK_NUMPAD_FIVE     101
#define VK_NUMPAD_SIX      102
#define VK_NUMPAD_SEVEN    103
#define VK_NUMPAD_EIGHT    104
#define VK_NUMPAD_NINE     105




// *Reserved Keys*
#define VK_RESERVED1       7
#define VK_RESERVED2       10
#define VK_RESERVED3       11
#define VK_RESERVED4       14
#define VK_RESERVED5       15
#define VK_RESERVED6       58
#define VK_RESERVED7       59
#define VK_RESERVED8       60
#define VK_RESERVED9       61
#define VK_RESERVED10      62

#define VK_RESERVED11      63
#define VK_RESERVED12      64
#define VK_RESERVED13      94
#define VK_RESERVED14      184
#define VK_RESERVED15      185
#define VK_RESERVED16      193
#define VK_RESERVED17      194
#define VK_RESERVED18      195
#define VK_RESERVED19      196
#define VK_RESERVED20      197

#define VK_RESERVED21      198
#define VK_RESERVED22      199
#define VK_RESERVED23      200
#define VK_RESERVED24      201
#define VK_RESERVED25      202
#define VK_RESERVED26      203
#define VK_RESERVED27      204
#define VK_RESERVED28      205
#define VK_RESERVED29      206
#define VK_RESERVED30      207

#define VK_RESERVED31      208
#define VK_RESERVED32      209
#define VK_RESERVED33      210
#define VK_RESERVED34      211
#define VK_RESERVED35      212
#define VK_RESERVED36      213
#define VK_RESERVED37      214
#define VK_RESERVED38      215
#define VK_RESERVED39      224

// *Unassigned Keys*
#define VK_UNASSIGNED      136
#define VK_UNASSIGNED2     137
#define VK_UNASSIGNED3     138
#define VK_UNASSIGNED4     139
#define VK_UNASSIGNED5     140
#define VK_UNASSIGNED6     141
#define VK_UNASSIGNED7     142
#define VK_UNASSIGNED8     143
#define VK_UNASSIGNED9     151
#define VK_UNASSIGNED10    152

#define VK_UNASSIGNED11    153
#define VK_UNASSIGNED12    154
#define VK_UNASSIGNED13    155
#define VK_UNASSIGNED14    156
#define VK_UNASSIGNED15    157
#define VK_UNASSIGNED16    158
#define VK_UNASSIGNED17    159
#define VK_UNASSIGNED18    216
#define VK_UNASSIGNED19    217
#define VK_UNASSIGNED20    218

#define VK_UNASSIGNED21    232









#define VK_OEM_RESERVED_1  146
#define VK_OEM_RESERVED_2  147
#define VK_OEM_RESERVED_3  148
#define VK_OEM_RESERVED_4  149
#define VK_OEM_RESERVED_5  150

#define VK_VOLUME_MUTE        173
#define VK_VOLUME_DOWN        174
#define VK_VOLUME_UP          175
#define VK_MEDIA_NEXT_TRACK   176
#define VK_MEDIA_PREV_TRACK   177
#define VK_MEDIA_STOP         178
#define VK_MEDIA_PLAY_PAUSE   179
#define VK_LAUNCH_MAIL        180

#define VK_LAUNCH_MEDIA_SELECT  181
#define VK_LAUNCH_APP1          182
#define VK_LAUNCH_APP2          183

#define VK_OEM_1                186 //Colon/Semicolon (It can vary by keyboard though)
#define VK_OEM_PLUS             187 //Plus/Equals
#define VK_OEM_COMMA            188 //Comma/Less Than
#define VK_OEM_MINUS            189 //Underscore/Dash (Hyphen)


#define VK_OEM_2                191 //Question Mark/Slash (It can vary by keyboard though)
#define VK_OEM_3                192 //Tilde/Acute (It can vary by keyboard though)

#define VK_OEM_4                219 //Left Brace/Left Bracket (It can vary by keyboard though)
#define VK_OEM_5                220 //Backslash/Pipe (It can vary by keyboard though)

#define VK_OEM_6                221 //Right Brace/Right Bracket (It can vary by keyboard though)
#define VK_OEM_7                222 //Quote/Apostrophe (It can vary by keyboard though)
#define VK_OEM_8                223 //This can vary by keyboard

#define VK_OEM_RESERVED_6       225
#define VK_OEM_102              226 //<> Keys (Or \| on non-US 102-key keyboard)
#define VK_OEM_RESERVED_7       227
#define VK_OEM_RESERVED_8       228
#define VK_PROCESSKEY           229
#define VK_OEM_RESERVED_9       230

#define VK_PACKET               231 //Used to pass Unicode characters as if they were keystrokes. The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods.

#define VK_OEM_RESERVED_10      233
#define VK_OEM_RESERVED_11      234
#define VK_OEM_RESERVED_12      235
#define VK_OEM_RESERVED_13      236
#define VK_OEM_RESERVED_14      237
#define VK_OEM_RESERVED_15      238
#define VK_OEM_RESERVED_16      239
#define VK_OEM_RESERVED_17      240

#define VK_OEM_RESERVED_18      241
#define VK_OEM_RESERVED_19      242
#define VK_OEM_RESERVED_20      243
#define VK_OEM_RESERVED_21      244
#define VK_OEM_RESERVED_22      245
#define VK_OEM_RESERVED_23      246
#define VK_ATTN                 247
#define VK_CRSEL                248
#define VK_EXSEL                249
#define VK_EREOF                250

#define VK_PLAY                 251
#define VK_ZOOM                 252
#define VK_NONAME               253
#define VK_PA1                  254
#define VK_OEM_CLEAR            255

#define VK_OEM_1                186 //Colon/Semicolon (It can vary by keyboard though)
#define VK_OEM_PLUS             187 //Plus/Equals
#define VK_OEM_COMMA            188 //Comma/Less Than
#define VK_OEM_MINUS            189 //Underscore/Dash (Hyphen)
#define VK_OEM_PERIOD           190 //Period/Greater Than

#define VK_OEM_2                191 //Question Mark/Slash (It can vary by keyboard though)
#define VK_OEM_3                192 //Tilde/Acute (It can vary by keyboard though)

