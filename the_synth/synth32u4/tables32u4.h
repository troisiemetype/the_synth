//*************************************************************************************
//  Arduino synth V4.1
//  Optimized audio driver, modulation engine, envelope engine.
//
//  Dzl/Illutron 2014
//
//*************************************************************************************

/*
 * Height channel sound generator for arduino.
 *
 * enhancements by Pierre-Loup Martin, 2015.
 *
 * It can generate sounds out of waveform, enveloppes and midi pitchs.
 * tables32u4.h contains table to set waveforms, enveloppes, midi pitchs, length and bpm.
 */


#ifndef tables_h
#define tables_h

// These are the tables used by the Synth to generate sounds.

// waveforms definition

PROGMEM const char sinTable[256]={
	0,3,6,9,12,16,19,22,25,28,31,34,37,40,43,46,49,51,54,57,60,63,65,68,71,73,76,78,81,83,85,88,90,92,94,96,98,100,102,104,106,107,109,111,112,113,115,116,117,118,120,121,122,122,123,124,125,125,126,126,126,127,127,127,127,127,127,127,126,126,126,125,125,124,123,122,122,121,120,118,117,116,115,113,112,111,109,107,106,104,102,100,98,96,94,92,90,88,85,83,81,78,76,73,71,68,65,63,60,57,54,51,49,46,43,40,37,34,31,28,25,22,19,16,12,9,6,3,0,-3,-6,-9,-12,-16,-19,-22,-25,-28,-31,-34,-37,-40,-43,-46,-49,-51,-54,-57,-60,-63,-65,-68,-71,-73,-76,-78,-81,-83,-85,-88,-90,-92,-94,-96,-98,-100,-102,-104,-106,-107,-109,-111,-112,-113,-115,-116,-117,-118,-120,-121,-122,-122,-123,-124,-125,-125,-126,-126,-126,-127,-127,-127,-127,-127,-127,-127,-126,-126,-126,-125,-125,-124,-123,-122,-122,-121,-120,-118,-117,-116,-115,-113,-112,-111,-109,-107,-106,-104,-102,-100,-98,-96,-94,-92,-90,-88,-85,-83,-81,-78,-76,-73,-71,-68,-65,-63,-60,-57,-54,-51,-49,-46,-43,-40,-37,-34,-31,-28,-25,-22,-19,-16,-12,-9,-6,-3
};// sinusoid wave

PROGMEM const char triTable[256]={
	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,127,125,123,121,119,117,115,113,111,109,107,105,103,101,99,97,95,93,91,89,87,85,83,81,79,77,75,73,71,69,67,65,63,61,59,57,55,53,51,49,47,45,43,41,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1,-1,-3,-5,-7,-9,-11,-13,-15,-17,-19,-21,-23,-25,-27,-29,-31,-33,-35,-37,-39,-41,-43,-45,-47,-49,-51,-53,-55,-57,-59,-61,-63,-65,-67,-69,-71,-73,-75,-77,-79,-81,-83,-85,-87,-89,-91,-93,-95,-97,-99,-101,-103,-105,-107,-109,-111,-113,-115,-117,-119,-121,-123,-125,-127,-128,-126,-124,-122,-120,-118,-116,-114,-112,-110,-108,-106,-104,-102,-100,-98,-96,-94,-92,-90,-88,-86,-84,-82,-80,-78,-76,-74,-72,-70,-68,-66,-64,-62,-60,-58,-56,-54,-52,-50,-48,-46,-44,-42,-40,-38,-36,-34,-32,-30,-28,-26,-24,-22,-20,-18,-16,-14,-12,-10,-8,-6,-4,-2
};// triangle wave

PROGMEM const char squTable[256]={
	127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127,-127
};// square wave

PROGMEM const char sawTable[256]={
	127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24,-25,-26,-27,-28,-29,-30,-31,-32,-33,-34,-35,-36,-37,-38,-39,-40,-41,-42,-43,-44,-45,-46,-47,-48,-49,-50,-51,-52,-53,-54,-55,-56,-57,-58,-59,-60,-61,-62,-63,-64,-65,-66,-67,-68,-69,-70,-71,-72,-73,-74,-75,-76,-77,-78,-79,-80,-81,-82,-83,-84,-85,-86,-87,-88,-89,-90,-91,-92,-93,-94,-95,-96,-97,-98,-99,-100,-101,-102,-103,-104,-105,-106,-107,-108,-109,-110,-111,-112,-113,-114,-115,-116,-117,-118,-119,-120,-121,-122,-123,-124,-125,-126,-127,-128
};// decrescent sawteeth wave

PROGMEM const char noiseTable[256]={
	108,5,-14,-53,85,15,75,-35,85,109,-55,97,-81,73,101,44,-126,72,73,-23,-96,3,72,-69,19,88,-41,19,-69,-2,103,-54,87,-121,-118,95,118,-104,-49,62,-47,-31,15,35,-58,86,15,97,114,14,-92,-81,118,-99,110,-52,73,-98,-77,-32,97,-77,52,5,-7,-99,-94,70,-99,-4,-30,126,-101,3,63,60,126,91,94,-98,55,109,64,-2,99,21,-34,-98,-34,-38,-95,85,-87,-105,-25,-90,-25,103,0,-6,-36,15,-1,59,-14,-89,-57,80,27,84,41,-63,87,-56,-19,-71,-73,-113,-35,-77,-97,-66,-40,103,106,88,78,-86,19,74,69,-115,-125,-83,75,117,-13,-103,34,-119,-80,8,103,60,73,56,103,7,61,54,-33,-69,-117,27,4,-93,106,51,51,-78,17,-61,-40,-113,12,-29,81,94,34,79,90,-68,-31,-51,8,50,-79,-30,86,41,-80,6,65,-80,-127,4,-9,31,17,73,125,9,-82,-62,112,25,-57,-39,127,56,123,-66,82,-96,-38,-98,-122,13,37,-86,-70,-92,-45,87,114,82,77,96,-124,-18,-92,-83,85,5,-120,107,-34,-22,98,-121,-33,-17,-49,-105,25,59,55,-106,-105,-28,-117,73,-86,-104,57,99,-35,77,63,10,-69,-19,-87,-33,95,-68
};// "random" noise


//enveloppes definition

PROGMEM const unsigned char env1[128]={
	254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0
};// sinus-like decrescent

PROGMEM const unsigned char env2[128]={
	255,242,230,218,207,197,187,178,169,161,153,145,138,131,124,118,112,107,101,96,91,87,82,78,74,71,67,64,61,58,55,52,49,47,45,42,40,38,36,34,33,31,30,28,27,25,24,23,22,21,20,19,18,17,16,15,14,14,13,12,12,11,11,10,10,9,9,8,8,7,7,7,6,6,6,5,5,5,5,4,4,4,4,4,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0
};// progressive

PROGMEM const unsigned char env3[128]={
	255,255,255,255,255,255,255,255,255,255,255,254,254,254,254,254,254,253,253,253,253,252,252,252,251,251,250,250,249,249,248,247,247,246,245,245,244,243,242,241,240,239,238,237,236,235,234,233,231,230,229,227,226,225,223,222,220,218,217,215,213,211,209,207,205,203,201,199,197,195,192,190,188,185,183,180,177,175,172,169,166,163,160,157,154,151,148,145,141,138,134,131,127,124,120,116,112,109,105,101,97,92,88,84,79,75,71,66,61,57,52,47,42,37,32,27,22,17,11,6,0,0,0,0,0,0,0,0
};// inverse (slow, then faster and faster

PROGMEM const unsigned char env4[128]={
	1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124,127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,210,165,127,80,35,0
};// sinus-like crescent (reverse sound)

PROGMEM const unsigned char env5[128]={
	6,13,19,25,31,37,44,50,56,62,68,74,80,86,92,98,103,109,115,120,126,131,136,142,147,152,157,162,167,171,176,180,185,189,193,197,201,205,208,212,215,219,222,225,228,231,233,236,238,240,242,244,246,247,249,250,251,252,253,254,254,255,255,255,255,255,254,254,253,252,251,250,249,247,246,244,242,240,238,236,233,231,228,225,222,219,215,212,208,205,201,197,193,189,185,180,176,171,167,162,157,152,147,142,136,131,126,120,115,109,103,98,92,86,80,74,68,62,56,50,44,37,31,25,19,13,6,0
};// cosinus-like (crescent then decrescent, symetrical)


// Definition of the increment values of the tables / sampling frequency. Multiplied by 256 (fixed point math)
// MIDI steps and bpm steps are given for a sampling frequence of 22050Hz (22038, exactly)

PROGMEM const unsigned int pitchTable[128] = {
	24,26,27,29,31,32,34,36,
	39,41,43,46,49,52,55,58,
	61,65,69,73,77,82,87,92,
	97,103,109,116,123,130,138,146,
	154,164,173,184,194,206,218,231,
	245,260,275,291,309,327,347,367,
	389,412,437,463,490,519,550,583,
	617,654,693,734,778,824,873,925,
	980,1038,1100,1166,1235,1308,1386,1469,
	1556,1649,1747,1850,1960,2077,2201,2331,
	2470,2617,2772,2937,3112,3297,3493,3701,
	3921,4154,4401,4663,4940,5234,5545,5875,
	6224,6594,6986,7402,7842,8308,8802,9325,
	9880,10467,11090,11749,12448,13188,13972,14803,
	15683,16616,17604,18651,19760,20935,22180,23499,
	24896,26376,27945,29606,31367,33232,35208,37302
};

// EFTWS stands for Enveloppe Frequency Tunning Word: it gives the evolving height of the sound during the  play
PROGMEM const unsigned int EFTWS[] = {
	255,252,249,246,243,240,237,234,230,227,224,221,218,215,212,209,206,203,200,197,194,191,188,185,182,179,176,174,171,168,165,162,159,156,154,151,148,145,142,140,137,134,132,129,126,124,121,118,116,113,111,108,106,103,101,98,96,93,91,89,86,84,82,80,77,75,73,71,69,67,65,63,61,59,57,55,53,51,49,47,46,44,42,41,39,37,36,34,33,31,30,28,27,26,24,23,22,20,19,18,17,16,15,14,13,12,11,10,9,8,8,7,6,6,5,4,4,3,3,2,2,2,1,1,1,1,0,0
};

// tickBPM is a table that gives the number of ISR cycle to count to have the the corresponding bpm
PROGMEM const unsigned int tickBPM[] = {
	44077,41322,38892,36731,34798,33058,31484,30053,28746,27548,26446,25429,24487,23613,22799,22039,21328,20661,20035,19446,18890,18365,17869,17399,16953,16529,16126,15742,15376,15026,14692,14373,14067,13774,13493,13223,12964,12715,12475,12244,12021,11806,11599,11399,11206,11019,10839,10664,10495,10331,10172,10018,9868,9723,9582,9445,9312,9183,9057,8935,8815,8699,8586,8476,8369,8264,8162,8063,7966,7871,7778,7688,7600,7513,7429,7346,7265,7186,7109,7034,6960,6887,6816,6747,6678,6612,6546,6482,6419,6357,6297,6237,6179,6122,6066,6011,5956,5903,5851,5800,5749,5700,5651,5603,5556,5510,5464,5419,5375,5332,5289,5247,5206,5165,5125,5086,5047,5009,4971,4934,4897,4861,4826,4791,4757,4723,4689,4656,4623,4591,4560,4528,4498,4467,4437,4408,4379,4350,4321,4293,4266,4238,4211,4185,4158,4132,4107,4081,4056,4031,4007,3983,3959,3935,3912,3889,3866,3844,3822,3800,3778,3757,3735,3714,3694,3673,3653,3633,3613,3593,3574,3555,3536,3517,3498,3480,3462,3444,3426,3408,3391,3373,3356,3339,3322,3306,3289,3273,3257,3241,3225,3210,3194,3179,3163,3148,3133,3119,3104,3090,3075,3061,3047,3033,3019,3005,2992,2978,2965,2952,2938,2925,2913,2900,2887,2875,2862,2850,2838,2825,2813,2802,2790,2778,2766,2755,2743,2732,2721,2710,2699,2688,2677,2666,2655,2645,2634,2624,2613,2603,2593,2583,2573,2563,2553,2543,2533,2524,2514,2504,2495,2486,2476,2467,2458,2449
};

#endif