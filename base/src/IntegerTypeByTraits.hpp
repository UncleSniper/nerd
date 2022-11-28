#ifndef NERD_BASE_INTEGERTYPEBYTRAITS_HPP
#define NERD_BASE_INTEGERTYPEBYTRAITS_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include <cstddef>
#include <cstdint>

namespace nerd {
namespace base {

	template<std::size_t Size, bool Signed>
	class IntegerTypeByTraits {

	  private:
		template<int, std::size_t, bool>
		struct Mapping;

#define NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(type, sign) \
	template<int Dummy> \
	struct Mapping<Dummy, sizeof(type), sign> { \
		typedef type StandardType; \
	};

		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(int8_t, true)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(uint8_t, false)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(int16_t, true)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(uint16_t, false)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(int32_t, true)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(uint32_t, false)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(int64_t, true)
		NERD_BASE_DEFINE_STANDARD_INTEGER_MAPPING(uint64_t, false)

	  public:
		typedef typename Mapping<0, Size, Signed>::StandardType StandardType;

	};

	typedef IntegerTypeByTraits<sizeof(void*), false>::StandardType IntegerPointer;

	typedef IntegerTypeByTraits<sizeof(float), false>::StandardType FloatBits;
	typedef IntegerTypeByTraits<sizeof(double), false>::StandardType DoubleBits;

}}

#endif /* NERD_BASE_INTEGERTYPEBYTRAITS_HPP */
