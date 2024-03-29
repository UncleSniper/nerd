#ifndef NERD_BASE_TYPES_HPP
#define NERD_BASE_TYPES_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "IntegerTypeByTraits.hpp"

namespace nerd {
namespace base {

	typedef IntegerPointer MemorySize;
	typedef PointerOffset MemoryOffset;
	typedef uint64_t FileSize;
	typedef int64_t FileOffset;

}}

#endif /* NERD_BASE_TYPES_HPP */
