#ifndef NERD_BASE_INTEGERBOUNDS_HPP
#define NERD_BASE_INTEGERBOUNDS_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename IntegerT>
	class IntegerBounds {

	  private:
		template<typename IntT, bool Signed>
		struct BoundsImpl {

			static const IntT MIN = static_cast<IntT>(0);
			static const IntT MAX = ~static_cast<IntT>(0);

		};

		template<typename IntT>
		struct BoundsImpl<IntT, true> {

			static const IntT MIN = static_cast<IntT>(static_cast<IntT>(1)
					<< (static_cast<unsigned>(sizeof(IntT)) * 8u - 1u));
			static const IntT MAX = ~static_cast<IntT>(static_cast<IntT>(1)
					<< (static_cast<unsigned>(sizeof(IntT)) * 8u - 1u));

		};

	  public:
		typedef IntegerT Integer;

	  public:
		static const bool SIGNED = static_cast<IntegerT>(-1) < static_cast<IntegerT>(0);

	  private:
		typedef BoundsImpl<IntegerT, SIGNED> Bounds;

	  public:
		static const IntegerT MIN = Bounds::MIN;
		static const IntegerT MAX = Bounds::MAX;

	};

}}

#endif /* NERD_BASE_INTEGERBOUNDS_HPP */
