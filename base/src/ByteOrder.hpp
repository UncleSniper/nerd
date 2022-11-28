#ifndef NERD_BASE_BYTEORDER_HPP
#define NERD_BASE_BYTEORDER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "api.hpp"

namespace nerd {
namespace base {

	enum NERD_BASE_API ByteOrder {
		BO_BIG_ENDIAN,
		BO_LITTLE_ENDIAN,
		BO_AUTODETECT_ENDIANNESS
	};

}}


#endif /* NERD_BASE_BYTEORDER_HPP */
