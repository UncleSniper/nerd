#ifndef NERD_BASE_TYPECOMBINATORS_HPP
#define NERD_BASE_TYPECOMBINATORS_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "IntegerBounds.hpp"

namespace nerd {
namespace base {

	template<typename T, typename U>
	class OfTwoIntegerTypes {

	  private:
		enum Width {
			T_IS_WIDER,
			SAME_WIDTH,
			U_IS_WIDER
		};

		template<typename, typename, Width, bool, bool>
		struct Impl;

		#define NERD_BASE_OFTWOINTEGERTYPES_IMPL(width, tSigned, uSigned, narrower, wider, lower, higher) \
			template<typename T2, typename U2> \
			struct Impl<T2, U2, width, tSigned, uSigned> { \
				typedef narrower Narrower; \
				typedef wider Wider; \
				typedef lower WithLowerLowerBound; \
				typedef higher WithHigherUpperBound; \
			};

		NERD_BASE_OFTWOINTEGERTYPES_IMPL(T_IS_WIDER, false, false, U2, T2, T2, T2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(T_IS_WIDER, false, true,  U2, T2, U2, T2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(T_IS_WIDER, true,  false, U2, T2, T2, T2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(T_IS_WIDER, true,  true,  U2, T2, T2, T2)

		NERD_BASE_OFTWOINTEGERTYPES_IMPL(SAME_WIDTH, false, false, T2, T2, T2, T2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(SAME_WIDTH, false, true,  T2, T2, U2, T2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(SAME_WIDTH, true,  false, T2, T2, T2, U2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(SAME_WIDTH, true,  true,  T2, T2, T2, T2)

		NERD_BASE_OFTWOINTEGERTYPES_IMPL(U_IS_WIDER, false, false, T2, U2, T2, U2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(U_IS_WIDER, false, true,  T2, U2, U2, U2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(U_IS_WIDER, true,  false, T2, U2, T2, U2)
		NERD_BASE_OFTWOINTEGERTYPES_IMPL(U_IS_WIDER, true,  true,  T2, U2, U2, U2)

	  private:
		static const Width WIDTH = sizeof(T) > sizeof(U) ? T_IS_WIDER
				: (sizeof(U) > sizeof(T) ? U_IS_WIDER : SAME_WIDTH);

	  private:
		typedef Impl<T, U, WIDTH, IntegerBounds<T>::SIGNED, IntegerBounds<U>::SIGNED> I;

	  public:
		typedef typename I::Narrower Narrower;
		typedef typename I::Wider Wider;
		typedef typename I::WithLowerLowerBound WithLowerLowerBound;
		typedef typename I::WithHigherUpperBound WithHigherUpperBound;

	};

}}

#endif /* NERD_BASE_TYPECOMBINATORS_HPP */
