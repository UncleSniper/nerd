#ifndef NERD_BASE_INTEGERBITS_HPP
#define NERD_BASE_INTEGERBITS_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "StandardIntegerMapping.hpp"

namespace nerd {
namespace base {

	template<typename IntegerT>
	class IntegerBits {

	  public:
		typedef IntegerT Integer;

	  private:
		template<int, typename>
		struct BitsImpl;

#define NERD_BASE_INTEGERBITS_IMPL(subject, sig, unsig) \
		template<int Dummy> \
		struct BitsImpl<Dummy, subject> { \
			typedef sig AsSigned; \
			typedef unsig AsUnsigned; \
		};

		NERD_BASE_INTEGERBITS_IMPL(int8_t, int8_t, uint8_t)
		NERD_BASE_INTEGERBITS_IMPL(uint8_t, int8_t, uint8_t)
		NERD_BASE_INTEGERBITS_IMPL(int16_t, int16_t, uint16_t)
		NERD_BASE_INTEGERBITS_IMPL(uint16_t, int16_t, uint16_t)
		NERD_BASE_INTEGERBITS_IMPL(int32_t, int32_t, uint32_t)
		NERD_BASE_INTEGERBITS_IMPL(uint32_t, int32_t, uint32_t)
		NERD_BASE_INTEGERBITS_IMPL(int64_t, int64_t, uint64_t)
		NERD_BASE_INTEGERBITS_IMPL(uint64_t, int64_t, uint64_t)

		template<typename IntT, bool Signed>
		struct NegativityImpl {

			static inline bool isNegative(IntT) {
				return false;
			}

		};

		template<typename IntT>
		struct NegativityImpl<IntT, true> {

			static inline bool isNegative(IntT value) {
				return value < static_cast<IntT>(0);
			}

		};

		template<typename IntT, bool Signed>
		struct WithSignednessImpl {

			typedef typename BitsImpl<0, typename StandardIntegerMapping<IntT>::StandardType>::AsUnsigned As;

		};

		template<typename IntT>
		struct WithSignednessImpl<IntT, true> {

			typedef typename BitsImpl<0, typename StandardIntegerMapping<IntT>::StandardType>::AsSigned As;

		};

		typedef BitsImpl<0, typename StandardIntegerMapping<IntegerT>::StandardType> Bits;
		static const bool SIGNED = static_cast<IntegerT>(-1) < static_cast<IntegerT>(0);
		typedef NegativityImpl<IntegerT, SIGNED> Negativity;

	  public:
		typedef typename Bits::AsSigned AsSigned;
		typedef typename Bits::AsUnsigned AsUnsigned;

		template<bool Signed>
		struct WithSignedness {

			typedef typename WithSignednessImpl<IntegerT, Signed>::As As;

		};

		template<typename TargetT>
		struct WithSameSignednessAs {

			static const bool SIGNED = static_cast<TargetT>(-1) < static_cast<TargetT>(0);

			typedef typename WithSignednessImpl<IntegerT, SIGNED>::As As;

		};

	  public:
		static const unsigned WIDTH = static_cast<unsigned>(sizeof(IntegerT)) * 8u;

	  public:
		static inline IntegerT shiftLeft(IntegerT value, unsigned count) {
			if(count >= WIDTH)
				return static_cast<IntegerT>(0);
			return static_cast<IntegerT>(value << count);
		}

		static IntegerT shiftRightSigned(IntegerT value, unsigned count) {
			if(count >= WIDTH) {
				if(Negativity::isNegative(value))
					return static_cast<IntegerT>(~static_cast<IntegerT>(0));
				else
					return static_cast<IntegerT>(0);
			}
			IntegerT u = static_cast<IntegerT>(static_cast<AsUnsigned>(static_cast<AsUnsigned>(value) >> count));
			if(Negativity::isNegative(value)) {
				AsUnsigned one = static_cast<AsUnsigned>(static_cast<AsUnsigned>(1u) << count);
				IntegerT ones = static_cast<AsUnsigned>(one - static_cast<AsUnsigned>(1u));
				u = static_cast<IntegerT>(u | static_cast<IntegerT>(ones << (WIDTH - count)));
			}
			return u;
		}

		static inline IntegerT shiftRightUnsigned(IntegerT value, unsigned count) {
			if(count >= WIDTH)
				return static_cast<IntegerT>(0);
			return static_cast<IntegerT>(static_cast<AsUnsigned>(static_cast<AsUnsigned>(value) >> count));
		}

		static IntegerT getBits(IntegerT value, unsigned count, unsigned exponent) {
			AsUnsigned one = static_cast<AsUnsigned>(static_cast<AsUnsigned>(1u) << count);
			IntegerT ones = static_cast<AsUnsigned>(one - static_cast<AsUnsigned>(1u));
			return static_cast<IntegerT>(shiftRightUnsigned(value, exponent * count) & ones);
		}

		template<typename TargetT>
		static TargetT getBitsAs(IntegerT value, unsigned count, unsigned exponent) {
			AsUnsigned u = static_cast<AsUnsigned>(getBits(value, count, exponent));
			return static_cast<TargetT>(static_cast<typename BitsImpl<0, TargetT>::AsUnsigned>(u));
		}

		static inline bool isNegative(IntegerT value) {
			return Negativity::isNegative(value);
		}

	};

}}

#endif /* NERD_BASE_INTEGERBITS_HPP */
