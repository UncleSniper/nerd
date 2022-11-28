#ifndef NERD_BASE_INTEXP_HPP
#define NERD_BASE_INTEXP_HPP

namespace nerd {
namespace base {

	template<typename IntegerT>
	constexpr IntegerT integerPow(IntegerT base, IntegerT exponent) {
		IntegerT power = static_cast<IntegerT>(1);
		if(exponent < static_cast<IntegerT>(0))
			return static_cast<IntegerT>(0);
		while(exponent) {
			power *= base;
			--exponent;
		}
		return power;
	}

}}

#endif /* NERD_BASE_INTEXP_HPP */
