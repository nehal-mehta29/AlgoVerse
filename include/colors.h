#ifndef COLORS_H
#define COLORS_H

//========== Reset & Text Styles ==========

#define COLOR_RESET        "\033[0m"

#define STYLE_BOLD         "\033[1m"
#define STYLE_DIM          "\033[2m"
#define STYLE_UNDERLINE    "\033[4m"

//========== Main UI Colors ==========

/* Logo / Splash Screen */
#define COLOR_LOGO         "\033[38;2;216;180;248m"   // Lilac Bloom (#D8B4F8)

/* Breadcrumb Navigation */
#define COLOR_BREADCRUMB   "\033[38;2;142;138;159m"   // Muted Lavender (#8E8A9F)

/* Menu Numbers */
#define COLOR_NUMBER       "\033[38;2;244;162;97m"    // Peach Apricot (#F4A261)

/* General Text */
#define COLOR_TEXT         "\033[38;2;240;244;241m"   // Soft Cream (#F0F4F1)

/* User Input */
#define COLOR_INPUT        "\033[38;2;153;217;140m"   // Soft Matcha (#99D98C)

/* Success Messages */
#define COLOR_SUCCESS      "\033[38;2;129;178;154m"   // Sage Green (#81B29A)

/* Error Messages */
#define COLOR_ERROR        "\033[31m"                 // Standard Red

/* Prompts (Press ENTER...) */
#define COLOR_PROMPT       "\033[38;2;92;90;112m"     // Dim Slate (#5C5A70)

/* Borders / Dividers */
#define COLOR_BORDER       "\033[38;2;75;72;92m"      // Soft Border (#4B485C)

/* Reserved for future badges/highlights */
#define COLOR_ACCENT       "\033[38;2;230;184;162m"   // Dusty Rose (#E6B8A2)

//========== Visualization Colors ==========

/* Current Node Being Processed */
#define COLOR_CURRENT      "\033[38;2;255;214;102m"   // Soft Gold

/* Swapped / Relinked Node */
#define COLOR_ACTIVE       "\033[38;2;129;178;154m"   // Same as Success (Sage Green)

/* Broken Link Marker */
#define COLOR_BREAK        "\033[31m"                 // Standard Red

/* Pointer / Address Highlight */
#define COLOR_POINTER      "\033[38;2;173;216;230m"   // Soft Sky Blue

/* Final Sorted Elements */
#define COLOR_SORTED       "\033[38;2;216;180;248m"   // Lilac Bloom

#endif /* COLORS_H */