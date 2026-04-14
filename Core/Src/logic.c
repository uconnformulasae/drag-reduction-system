// logic.c
// B. Deutsch (2/3/26)

#include <stdbool.h>

/*
 * CRITICAL PARAMETERS
 */
#define MAX_ABS_STEERING_ANGLE 30		// source: jake-ish
#define MAX_ABS_LAT_G 0.35				// according to sample Michigan corner data
#define MAX_BRAKE_INPUT_PERCENTAGE 0.2	// source: it came to me in a dream
#define MIN_COOLDOWN_SECONDS 1			// TODO: make this faster later once we have better data
#define MODE 0
//#define MAX_ABS_LONG_G 0

/*
 * ASST FUNCTIONS
 */
// Returns absolute value of float argument f
float absFloat(float f) {
	return f >= 0 ? f : -1 * f;
}

/*
 * MAIN LOGIC
 */
// Returns whether DRS should be enabled given the input info
bool shouldActivateDRS(float steeringAngle, float latG, float brakeInputPercentage, float* cooldown) {
	return (
			absFloat(latG) < MAX_ABS_LAT_G &&
			absFloat(steeringAngle) < MAX_ABS_STEERING_ANGLE &&
			brakeInputPercentage < MAX_BRAKE_INPUT_PERCENTAGE &&
			(*cooldown) >= MIN_COOLDOWN_SECONDS
	);
}
