#ifndef NERD_BASE_TYPEUTILS_HPP
#define NERD_BASE_TYPEUTILS_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename A, typename B>
	class IsSameType {

	  private:
		template<typename, typename>
		struct Same {
			static const bool SAME = false;
		};

		template<typename T>
		struct Same<T, T> {
			static const bool SAME = true;
		};

	  public:
		static const bool SAME = Same<A, B>::SAME;

	};

	template<typename A, typename B>
	constexpr bool isSameType() {
		return IsSameType<A, B>::SAME;
	}

	template<typename ObjectT, typename ConstraintT>
	class IsA {

	  private:
		static double acceptObject(ConstraintT&);
		static char acceptObject(...);

	  public:
		static const bool IS = sizeof(acceptObject(*reinterpret_cast<ObjectT*>(0))) == sizeof(double);

	};

	template<typename ObjectT, typename ConstraintT>
	constexpr bool isA() {
		return IsA<ObjectT, ConstraintT>::IS;
	}

}}

#endif /* NERD_BASE_TYPEUTILS_HPP */
