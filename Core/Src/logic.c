// logic.c
// B. Deutsch (2/3/26)

#define MAX_ABS_STEERING_ANGLE 30		// source: jake-ish
#define MAX_ABS_LAT_G 0.35				// according to sample Michigan corner data
#define MAX_BRAKE_INPUT_PERCENTAGE 0.2	// source: it came to me in a dream
#define MIN_COOLDOWN_SECONDS 1			// TODO: make this faster later once we have better data
#define MODE 0
//#define MAX_ABS_LONG_G 0

// Returns absolute value of float argument f
float absFloat(float* p) {
	return (*p) >= 0 ? (*p) : -1 * (*p);
}

// Returns whether DRS should be enabled given the input info
bool shouldActivateDRS(float* steeringAnglePtr, float* latGPtr, float* brakeInputPercentagePtr, float* cooldownPtr) {
	return (
			absFloat(latGPtr) < MAX_ABS_LAT_G &&
			absFloat(steeringAnglePtr) < MAX_ABS_STEERING_ANGLE &&
			(*brakeInputPercentagePtr) < MAX_BRAKE_INPUT_PERCENTAGE &&
			(*cooldownPtr) >= MIN_COOLDOWN_SECONDS
	);
}
