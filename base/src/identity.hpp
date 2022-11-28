#ifndef NERD_BASE_IDENTITY_HPP
#define NERD_BASE_IDENTITY_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename T>
	T identity(T object) {
		return object;
	}

}}

#endif /* NERD_BASE_IDENTITY_HPP */
