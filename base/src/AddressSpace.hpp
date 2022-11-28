#ifndef NERD_BASE_ADDRESSSPACE_HPP
#define NERD_BASE_ADDRESSSPACE_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "IntegerBounds.hpp"

namespace nerd {
namespace base {

	template<typename SpaceT, typename AddressT>
	class AddressSpace {

	  public:
		enum AddressSpaceWidth {
			ASW_ADDRESS_IS_WIDER,
			ASW_SPACE_IS_WIDER,
			ASW_ADDRESS_AND_SPACE_ARE_SAME_WIDTH
		};

		enum AddressSpaceSignedness {
			ASS_ADDRESS_AND_SPACE_ARE_UNSIGNED,
			ASS_ADDRESS_IS_UNSIGNED_BUT_SPACE_IS_SIGNED,
			ASS_ADDRESS_IS_SIGNED_BUT_SPACE_IS_UNSIGNED,
			ASS_ADDRESS_AND_SPACE_ARE_SIGNED
		};

	  private:
		template<
			typename ImplSpaceT,
			typename ImplAddressT,
			AddressSpaceWidth WidthRelationship,
			AddressSpaceSignedness SignednessRelationship
		>
		struct AddressSpaceImpl {

			static inline bool exceededBy(ImplAddressT address) {
				return ImplSpaceT::addressSpaceExcessCaseNotCovered(address);
			}

		};

	#define NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(widthRel, signednessRel, param) \
		template< \
			typename ImplSpaceT, \
			typename ImplAddressT \
		> \
		struct AddressSpaceImpl<ImplSpaceT, ImplAddressT, widthRel, signednessRel> { \
			static inline bool exceededBy(param) { \
				return
	#define NERD_BASE_ADDRESSSPACE_IMPL_END \
				; \
			} \
		};

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_IS_WIDER,
			ASS_ADDRESS_AND_SPACE_ARE_UNSIGNED,
			ImplAddressT address
		)
			// address might exceed space width, but only upwards, as both are unsigned
			address > static_cast<AddressT>(IntegerBounds<SpaceT>::MAX)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_IS_WIDER,
			ASS_ADDRESS_IS_UNSIGNED_BUT_SPACE_IS_SIGNED,
			ImplAddressT address
		)
			// address might exceed space width or overrun into negative space
			// by exceeding space mantissa (which is exceeding width, too)
			address > static_cast<AddressT>(IntegerBounds<SpaceT>::MAX)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_IS_WIDER,
			ASS_ADDRESS_IS_SIGNED_BUT_SPACE_IS_UNSIGNED,
			ImplAddressT address
		)
			// address might be negative or exceed space width
			address < static_cast<AddressT>(0)
			// even with the additional mantissa bit, the bound will fit into
			// an AddressT, as address is as least 8 bits wider than space
			|| address > static_cast<AddressT>(IntegerBounds<SpaceT>::MAX)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_IS_WIDER,
			ASS_ADDRESS_AND_SPACE_ARE_SIGNED,
			ImplAddressT address
		)
			// address might exceed space width in either direction
			address < static_cast<AddressT>(IntegerBounds<SpaceT>::MIN)
			|| address > static_cast<AddressT>(IntegerBounds<SpaceT>::MAX)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_SPACE_IS_WIDER,
			ASS_ADDRESS_AND_SPACE_ARE_UNSIGNED,
			ImplAddressT
		)
			false
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_SPACE_IS_WIDER,
			ASS_ADDRESS_IS_UNSIGNED_BUT_SPACE_IS_SIGNED,
			ImplAddressT
		)
			// even with the additional mantissa bit, address cannot
			// overrun space, as address is at least 8 bits wider that space;
			// being unsigned, address cannot underrun space, either
			false
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_SPACE_IS_WIDER,
			ASS_ADDRESS_IS_SIGNED_BUT_SPACE_IS_UNSIGNED,
			ImplAddressT address
		)
			address < static_cast<AddressT>(0)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_SPACE_IS_WIDER,
			ASS_ADDRESS_AND_SPACE_ARE_SIGNED,
			ImplAddressT
		)
			false
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_AND_SPACE_ARE_SAME_WIDTH,
			ASS_ADDRESS_AND_SPACE_ARE_UNSIGNED,
			ImplAddressT
		)
			false
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_AND_SPACE_ARE_SAME_WIDTH,
			ASS_ADDRESS_IS_UNSIGNED_BUT_SPACE_IS_SIGNED,
			ImplAddressT address
		)
			// address might overrun space into the sign bit;
			// with the additional mantissa bit, the upper space bound
			// will fit into an AddressT
			address > static_cast<AddressT>(IntegerBounds<SpaceT>::MAX)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_AND_SPACE_ARE_SAME_WIDTH,
			ASS_ADDRESS_IS_SIGNED_BUT_SPACE_IS_UNSIGNED,
			ImplAddressT address
		)
			// address cannot overrun space, as space has one mantissa bit more,
			// but address might be negative
			address < static_cast<AddressT>(0)
		NERD_BASE_ADDRESSSPACE_IMPL_END

		NERD_BASE_ADDRESSSPACE_IMPL_BEGIN(
			ASW_ADDRESS_AND_SPACE_ARE_SAME_WIDTH,
			ASS_ADDRESS_AND_SPACE_ARE_SIGNED,
			ImplAddressT
		)
			false
		NERD_BASE_ADDRESSSPACE_IMPL_END

	  private:
		typedef IntegerBounds<SpaceT> SpaceBounds;
		typedef IntegerBounds<AddressT> AddressBounds;

	  public:
		typedef SpaceT Space;
		typedef AddressT Address;

	  public:
		static const AddressSpaceWidth WIDTH_RELATIONSHIP =
				sizeof(SpaceT) < sizeof(AddressT) ? ASW_ADDRESS_IS_WIDER
				: (sizeof(SpaceT) > sizeof(AddressT) ? ASW_SPACE_IS_WIDER
				: ASW_ADDRESS_AND_SPACE_ARE_SAME_WIDTH);
		static const AddressSpaceSignedness SIGNEDNESS_RELATIONSHIP =
				static_cast<AddressSpaceSignedness>(AddressBounds::SIGNED * 2 + SpaceBounds::SIGNED);
		static const bool CANNOT_EXCEED =
				(sizeof(SpaceT) > sizeof(AddressT) && SpaceBounds::SIGNED >= AddressBounds::SIGNED)
				|| (sizeof(SpaceT) == sizeof(AddressT) && SpaceBounds::SIGNED == AddressBounds::SIGNED);

	  public:
		static inline bool exceededBy(AddressT address) {
			return AddressSpaceImpl<SpaceT, AddressT, WIDTH_RELATIONSHIP, SIGNEDNESS_RELATIONSHIP>
					::exceededBy(address);
		}

	};

}}

#endif /* NERD_BASE_ADDRESSSPACE_HPP */
