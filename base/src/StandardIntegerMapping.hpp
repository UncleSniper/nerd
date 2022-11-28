#ifndef NERD_BASE_STANDARDINTEGERMAPPING_HPP
#define NERD_BASE_STANDARDINTEGERMAPPING_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "IntegerTypeByTraits.hpp"

namespace nerd {
namespace base {

	template<typename IntegerT>
	class StandardIntegerMapping {

	  private:
		static const bool SIGNED = static_cast<IntegerT>(-1) < static_cast<IntegerT>(0);

	  public:
		typedef typename IntegerTypeByTraits<sizeof(IntegerT), SIGNED>::StandardType StandardType;

	};

}}

#endif /* NERD_BASE_STANDARDINTEGERMAPPING_HPP */
