#ifndef NERD_BASE_INTLOG_HPP
#define NERD_BASE_INTLOG_HPP

namespace nerd {
namespace base {

	template<typename IntegerT>
	constexpr IntegerT integerLog(IntegerT base, IntegerT power) {
		IntegerT exponent = static_cast<IntegerT>(0);
		while(power) {
			power /= base;
			++exponent;
		}
		return exponent;
	}

}}

#endif /* NERD_BASE_INTLOG_HPP */
