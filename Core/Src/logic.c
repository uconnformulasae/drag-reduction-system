// logic.c
// B. Deutsch (2/3/26)

#define MAX_ABS_STEERING_ANGLE 0	// source: it came to me in a dream
#define MAX_ABS_LAT_G 0.35			// according to sample Michigan corner data
#define MAX_ABS_LONG_G 0
#define MODE 0

// Returns absolute value of float argument f
float absFloat(float f) {
	return f >= 0 ? f : -1 * f;
}

// Returns whether DRS should be enabled given the input info
bool shouldActivateDRS(double steeringAngle, double latG, double longG) {
	return (
			absFloat(latG) < MAX_ABS_LAT_G &&
			absFloat(steeringAngle) < MAX_ABS_STEERING_ANGLE
			);
}
