#ifndef NERD_BASE_POINTER_HPP
#define NERD_BASE_POINTER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename SubjectT>
	class Pointer {

	  public:
		typedef SubjectT Subject;

	  protected:
		SubjectT* object;

	  public:
		Pointer(SubjectT* object) : object(object) {}

		Pointer(const Pointer& pointer) : object(pointer.object) {}

		inline SubjectT* operator*() const {
			return object;
		}

		inline SubjectT* operator->() const {
			return object;
		}

		SubjectT* set(SubjectT* newObject = NULL) {
			SubjectT* oldObject = object;
			object = newObject;
			return oldObject;
		}

		inline SubjectT* operator=(SubjectT* newObject) {
			return object = newObject;
		}

		inline SubjectT*& pointerLocation() {
			return object;
		}

	};

}}

#endif /* NERD_BASE_POINTER_HPP */
