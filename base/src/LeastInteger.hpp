#ifndef NERD_BASE_LEASTINTEGER_HPP
#define NERD_BASE_LEASTINTEGER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include <cstdint>

namespace nerd {
namespace base {

	template<unsigned MinimumBits>
	class LeastInteger {

	  private:
		template<int Dummy, unsigned Exponent>
		struct Candidates;

		template<int Dummy>
		struct Candidates<Dummy, 0u> {
			typedef int8_t Signed;
			typedef uint8_t Unsigned;
		};

		template<int Dummy>
		struct Candidates<Dummy, 1u> {
			typedef int16_t Signed;
			typedef uint16_t Unsigned;
		};

		template<int Dummy>
		struct Candidates<Dummy, 2u> {
			typedef int32_t Signed;
			typedef uint32_t Unsigned;
		};

		template<int Dummy>
		struct Candidates<Dummy, 3u> {
			typedef int64_t Signed;
			typedef uint64_t Unsigned;
		};

		template<unsigned Exponent, bool WideEnough>
		struct LeastImpl {

			typedef Candidates<0, Exponent + 1u> NextWider;
			typedef LeastImpl<
				Exponent + 1u,
				static_cast<unsigned>(sizeof(typename NextWider::Signed)) * 8u >= MinimumBits
			> NextAttempt;

			typedef typename NextAttempt::Signed Signed;
			typedef typename NextAttempt::Unsigned Unsigned;

		};

		template<unsigned Exponent>
		struct LeastImpl<Exponent, true> {

			typedef Candidates<0, Exponent> ThisAttempt;

			typedef typename ThisAttempt::Signed Signed;
			typedef typename ThisAttempt::Unsigned Unsigned;

		};

		typedef LeastImpl<
			0u,
			static_cast<unsigned>(sizeof(typename Candidates<0, 0u>::Signed)) * 8u >= MinimumBits
		> FirstAttempt;

	  public:
		typedef typename FirstAttempt::Signed Signed;
		typedef typename FirstAttempt::Unsigned Unsigned;

	};

}}

#endif /* NERD_BASE_LEASTINTEGER_HPP */
