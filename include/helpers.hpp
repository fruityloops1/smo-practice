#include <string>
#include <cstring>
#include "sead/math/seadVector.h"
#include "sead/math/seadQuat.h"
#include "types.h"



bool isPartOf(char* w1, char* w2);

int indexOf(char *w1, char c1);

sead::Vector3f QuatToEuler(sead::Quatf *quat);

#define RAD(deg) (deg * (M_PI / 180)) // converts Degrees to Radians
#define DEG(rad) (rad * (180 / M_PI)) // converts Radians to Degrees