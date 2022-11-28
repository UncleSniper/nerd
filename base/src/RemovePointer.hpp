#ifndef NERD_BASE_REMOVEPOINTER_HPP
#define NERD_BASE_REMOVEPOINTER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename T>
	class RemovePointer {

	  public:
		typedef T Component;
		typedef T Leaf;

	  public:
		static const unsigned POINTER_LEVELS = 0u;

	};

	template<typename T>
	class RemovePointer<T*> {

	  public:
		typedef T Component;
		typedef typename RemovePointer<T>::Leaf Leaf;

	  public:
		static const unsigned POINTER_LEVELS = RemovePointer<T>::POINTER_LEVELS + 1u;

	};

	template<typename T>
	class RemovePointer<T *const> {

	  public:
		typedef T Component;
		typedef typename RemovePointer<T>::Leaf Leaf;

	  public:
		static const unsigned POINTER_LEVELS = RemovePointer<T>::POINTER_LEVELS + 1u;

	};

}}

#endif /* NERD_BASE_REMOVEPOINTER_HPP */
