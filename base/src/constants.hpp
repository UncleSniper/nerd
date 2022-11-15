#ifndef BASE_CONSTANTS_HPP
#define BASE_CONSTANTS_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "api.hpp"

namespace nerd {
namespace base {

	enum NERD_BASE_API OperatingSystem {
		OS_LINUX,
		OS_WINDOWS,
		OS_UNKNOWN
	};

	enum NERD_BASE_API CompilerFlavor {
		COMP_GCC,
		COMP_MSVC,
		COMP_UNKNOWN
	};

	enum NERD_BASE_API Architecture {
		ARCH_I686,
		ARCH_X86_64,
		ARCH_UNKNOWN
	};

}}

#endif /* BASE_CONSTANTS_HPP */
