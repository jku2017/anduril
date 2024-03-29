// BLF Lantern config options for Anduril
/* BLF Lantern pinout
 *           ----
 *   Reset -|1  8|- VCC
 * eswitch -|2  7|- powerbank enable?
 * aux LED -|3  6|- PWM (5000K)
 *     GND -|4  5|- PWM (3000K)
 *           ----
 */

// basically the same as a Q8...  sort of
#include "hwdef-BLF_Q8.h"

// the button lights up
#define USE_INDICATOR_LED
// the button is visible while main LEDs are on
#define USE_INDICATOR_LED_WHILE_RAMPING
// enable blinking indicator LED while off
#define TICK_DURING_STANDBY
#define STANDBY_TICK_SPEED 3  // every 0.128 s
#define USE_FANCIER_BLINKING_INDICATOR
// off mode: high (2)
// lockout: blinking (3)
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 2)

// the lantern has two PWM channels, but they drive different sets of emitters
// (one channel for warm emitters, one channel for cold)
// so enable a special ramping mode which changes tint instead of brightness
#define USE_TINT_RAMPING

#ifdef RAMP_LENGTH
#undef RAMP_LENGTH
#endif

// level_calc.py 1 150 7135 1 30 800
#define RAMP_LENGTH 150
#define PWM1_LEVELS 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,11,11,12,13,13,14,15,15,16,17,18,18,19,20,21,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,43,44,45,46,48,49,50,51,53,54,56,57,58,60,61,63,64,66,67,69,70,72,74,75,77,79,80,82,84,85,87,89,91,93,95,97,98,100,102,104,106,108,111,113,115,117,119,121,124,126,128,130,133,135,137,140,142,145,147,150,152,155,157,160,163,165,168,171,173,176,179,182,185,188,190,193,196,199,202,205,209,212,215,218,221,224,228,231,234,238,241,245,248,251,255
#define MAX_1x7135 65
#define HALFSPEED_LEVEL 14
#define QUARTERSPEED_LEVEL 5

// the default of 26 looks a bit flat, so increase it
#define CANDLE_AMPLITUDE 40

// set floor and ceiling as far apart as possible
// because this lantern isn't overpowered
#define RAMP_STYLE 1  // 0 = smooth, 1 = stepped
#define RAMP_SMOOTH_FLOOR 1
#define RAMP_SMOOTH_CEIL 150
#define RAMP_DISCRETE_FLOOR 10
#define RAMP_DISCRETE_CEIL RAMP_SMOOTH_CEIL
#define RAMP_DISCRETE_STEPS 5

#define MUGGLE_FLOOR    15  // about  20 lm
#define MUGGLE_CEILING 115  // about 350 lm

// the sensor (attiny85) is nowhere near the emitters
// so thermal regulation can't work
#ifdef USE_THERMAL_REGULATION
#undef USE_THERMAL_REGULATION
#endif

// also, the set_level_gradually() thing isn't compatible with tint ramping
// (but unsetting it here doesn't actually do anything, because the thermal
//  regulation define enables it later...  so this is mostly just a note to
//  make this compatibility issue explicit)
#ifdef USE_SET_LEVEL_GRADUALLY
#undef USE_SET_LEVEL_GRADUALLY
#endif

// don't blink while ramping
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_FLOOR
#undef BLINK_AT_RAMP_FLOOR
#endif
// except the top... blink at the top
#ifndef BLINK_AT_RAMP_CEILING
#define BLINK_AT_RAMP_CEILING
#endif
