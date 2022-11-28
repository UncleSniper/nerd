#ifndef NERD_BASE_MAX_HPP
#define NERD_BASE_MAX_HPP

namespace nerd {
namespace base {

	template<typename IntegerT>
	constexpr IntegerT maxint(IntegerT a, IntegerT b) {
		return a > b ? a : b;
	}

	template<typename IntegerT>
	constexpr IntegerT minint(IntegerT a, IntegerT b) {
		return a < b ? a : b;
	}

}}

#endif /* NERD_BASE_MAX_HPP */
