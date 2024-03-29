// Mateminco/Astrolux MF01-Mini options for Anduril
#include "hwdef-Mateminco_MF01-Mini.h"

// the button lights up
#define USE_INDICATOR_LED
//#define INDICATOR_LED_SKIP_LOW  // low mode doesn't work on this driver
// the button is visible while main LEDs are on
//#define USE_INDICATOR_LED_WHILE_RAMPING
// enable blinking indicator LED while off
#define TICK_DURING_STANDBY
#define STANDBY_TICK_SPEED 3  // every 0.128 s
#define USE_FANCIER_BLINKING_INDICATOR
// off mode: low (1)
// lockout: blinking (3)
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 1)


// doesn't quite fit
#ifdef USE_MUGGLE_MODE
#undef USE_MUGGLE_MODE
#endif


// don't blink during ramp, it's irrelevant and annoying on this light
#define BLINK_AT_RAMP_CEILING
#undef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_FLOOR

// measured brightness with Sofirn 5500mAh cell at 3.97V:
// moon: 0.3 lm
// channel 1: 113 lm
// channel 2: 718 lm
// channel 3: 3500 lm
// ../../../bin/level_calc.py ninth 3 150 7135 1 2.5 115.65 7135 11 5 708.65 FET 1 10 3500
// (plus some manual tweaks for a smoother ramp)
#define RAMP_LENGTH 150
#define PWM1_LEVELS 1,1,2,2,3,3,4,5,5,6,7,8,9,9,10,14,15,16,17,18,19,20,21,22,24,26,28,30,32,34,37,39,42,45,48,51,54,58,62,65,69,74,78,83,88,93,98,104,110,116,123,130,137,145,153,161,170,179,188,198,208,219,231,243,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,13,16,18,20,23,25,28,31,34,37,40,43,47,50,54,58,62,66,70,75,80,85,90,95,100,106,112,118,125,131,138,145,153,161,169,177,185,194,204,213,223,233,244,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM3_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,6,10,13,17,21,24,28,33,37,41,46,50,55,60,66,71,76,82,88,94,101,107,114,121,128,135,143,151,159,167,176,185,194,203,213,223,233,244,255
#define MAX_1x7135 65  // ~113 lm
#define MAX_Nx7135 110
#define HALFSPEED_LEVEL 16
#define QUARTERSPEED_LEVEL 8

#define RAMP_SMOOTH_FLOOR 1   // ~0.3 lm
#define RAMP_SMOOTH_CEIL 130  // ~??? lm
// 14/135/6 = 14, 38, 62, 86, [110], 135
// 20/110/7 = 20, 35, 50, [65], 80, 95, [110]
// 15/130/7 = 15, 34, 53, 72, 91, [110], 130  <--
#define RAMP_DISCRETE_FLOOR 15 // ~?? lm
#define RAMP_DISCRETE_CEIL 130 // ~??? lm
#define RAMP_DISCRETE_STEPS 7  // ??, ??, ... lm


#define USE_TENCLICK_THERMAL_CONFIG  // by request
#define THERM_FASTER_LEVEL 130  // throttle back faster when high
//#define THERM_HARD_TURBO_DROP  // this light is massively overpowered
#define THERMAL_WARNING_SECONDS 1  // FIXME: increase by 2 after merging newer code
//#define THERMAL_UPDATE_SPEED 1
//#define THERM_PREDICTION_STRENGTH 4

