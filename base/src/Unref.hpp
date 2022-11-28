#ifndef NERD_BASE_UNREF_HPP
#define NERD_BASE_UNREF_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Pointer.hpp"

namespace nerd {
namespace base {

	template<typename SubjectT>
	class Unref : public Pointer<SubjectT> {

	  public:
		Unref(SubjectT* object = nullptr) : Pointer<SubjectT>(object) {}

		Unref(const Unref& pointer) : Pointer<SubjectT>(pointer) {}

		~Unref() {
			if(this->object)
				this->object->unref();
		}

		using Pointer<SubjectT>::operator=;

		inline SubjectT* operator=(const Unref& pointer) {
			if(this->object)
				this->object->unref();
			return this->object = pointer.object;
		}

	};

}}

#endif /* NERD_BASE_UNREF_HPP */
