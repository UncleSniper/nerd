#ifndef NERD_BASE_BARETYPE_HPP
#define NERD_BASE_BARETYPE_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename T>
	class BareType {

	  public:
		typedef T Bare;
		typedef const T Const;
		typedef T& Ref;
		typedef const T& ConstRef;

	  public:
		static const bool WAS_CONST = false;
		static const bool WAS_REF = false;

	};

	template<typename T>
	class BareType<const T> {

	  public:
		typedef T Bare;
		typedef const T Const;
		typedef T& Ref;
		typedef const T& ConstRef;

	  public:
		static const bool WAS_CONST = true;
		static const bool WAS_REF = false;

	};

	template<typename T>
	class BareType<T&> {

	  public:
		typedef T Bare;
		typedef const T Const;
		typedef T& Ref;
		typedef const T& ConstRef;

	  public:
		static const bool WAS_CONST = false;
		static const bool WAS_REF = true;

	};

	template<typename T>
	class BareType<const T&> {

	  public:
		typedef T Bare;
		typedef const T Const;
		typedef T& Ref;
		typedef const T& ConstRef;

	  public:
		static const bool WAS_CONST = true;
		static const bool WAS_REF = true;

	};

}}

#endif /* NERD_BASE_BARETYPE_HPP */
