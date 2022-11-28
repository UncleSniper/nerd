#ifndef NERD_BASE_MATHWRAP_HPP
#define NERD_BASE_MATHWRAP_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "api.hpp"

namespace nerd {
namespace base {

	enum NERD_BASE_API FloatingPointClass {
		FPC_NAN,
		FPC_INFINITE,
		FPC_ZERO,
		FPC_SUBNORMAL,
		FPC_NORMAL
	};

	NERD_BASE_API FloatingPointClass floatClassify(float);
	NERD_BASE_API FloatingPointClass doubleClassify(double);

	template<typename Float>
	class FloatingPointClassify;

	template<>
	class FloatingPointClassify<float> {

	  public:
		static inline FloatingPointClass classify(float value) {
			return floatClassify(value);
		}

	};

	template<>
	class FloatingPointClassify<double> {

	  public:
		static inline FloatingPointClass classify(double value) {
			return doubleClassify(value);
		}

	};

}}

#endif /* NERD_BASE_MATHWRAP_HPP */
