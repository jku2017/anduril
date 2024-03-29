// Emisar FET+13+1 config options for Anduril
#include "hwdef-Emisar_D18.h"

// front-facing aux LEDs
#define USE_INDICATOR_LED
//#define USE_INDICATOR_LED_WHILE_RAMPING
// enable blinking indicator LED while off
#define TICK_DURING_STANDBY
#define STANDBY_TICK_SPEED 3  // every 0.128 s
#define USE_FANCIER_BLINKING_INDICATOR
// off mode: low (1)
// lockout: blinking (3)
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 1)

// Emisar wanted a shortcut to this
#define USE_TENCLICK_THERMAL_CONFIG


// save space, and remove a mode which doesn't make much sense on this light
#ifdef USE_MUGGLE_MODE
#undef USE_MUGGLE_MODE
#endif


// level_calc.py seventh 3 150 7135 1 1.4 117.99 7135 6 1 1706.86 FET 3 10 13000
// (designed to make 1x hit at level 50, and Nx hit at level 100)
#define RAMP_LENGTH 150
#define PWM1_LEVELS 1,1,2,2,3,4,4,5,6,7,8,9,10,11,15,16,18,20,22,24,26,28,30,33,36,39,43,47,51,56,61,66,72,78,85,92,99,107,116,125,135,145,156,168,180,194,208,222,238,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,10,11,13,14,16,18,19,21,23,26,28,30,33,35,38,41,44,47,51,54,58,62,66,70,75,79,84,90,95,101,106,112,119,126,133,140,147,155,164,172,181,190,200,210,221,232,243,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM3_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,9,11,13,15,18,20,23,25,28,31,34,37,40,44,47,51,54,58,62,66,70,75,79,84,89,94,99,104,110,115,121,127,134,140,147,154,161,168,176,183,191,200,208,217,226,235,245,255
#define MAX_1x7135 50
#define MAX_Nx7135 100
#define HALFSPEED_LEVEL 15
#define QUARTERSPEED_LEVEL 6

// start at ~2000 lm after battery change, not ~150 lm (at Emisar's request)
#define DEFAULT_LEVEL MAX_Nx7135

// higher floor than default, and stop at highest regulated level
#define RAMP_DISCRETE_FLOOR 25
#define RAMP_DISCRETE_CEIL MAX_Nx7135
#define RAMP_DISCRETE_STEPS 7

// only blink at max regulated level and ceiling
#define BLINK_AT_RAMP_MIDDLE
#define BLINK_AT_RAMP_MIDDLE_1 MAX_Nx7135
#define BLINK_AT_RAMP_CEILING

// stop panicking at about ~40% power or ~5000 lm
#define THERM_FASTER_LEVEL 125
// optional, makes initial turbo step-down faster so first peak isn't as hot
//#define THERM_HARD_TURBO_DROP
