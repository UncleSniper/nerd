// This file shamelessly ripped off from RedEngine RedStrain

#define _ISOC99_SOURCE
#include <math.h>

#include "mathwrap.hpp"

namespace nerd {
namespace base {

	#define clamp(cname) case FP_ ## cname: return FPC_ ## cname;
	#define classify \
		switch(fpclassify(value)) { \
			clamp(NAN) \
			clamp(INFINITE) \
			clamp(ZERO) \
			clamp(SUBNORMAL) \
			default: return FPC_NORMAL; \
		}

	NERD_BASE_API FloatingPointClass floatClassify(float value) {
		classify
	}

	NERD_BASE_API FloatingPointClass doubleClassify(double value) {
		classify
	}

}}
