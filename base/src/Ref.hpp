#ifndef NERD_BASE_REF_HPP
#define NERD_BASE_REF_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Unref.hpp"

namespace nerd {
namespace base {

	template<typename SubjectT>
	class Ref : public Unref<SubjectT> {

	  public:
		Ref(SubjectT* object = nullptr, bool notify = false) : Unref<SubjectT>(object) {
			if(notify && object)
				object->ref();
		}

		Ref(const Unref<SubjectT>& pointer) : Unref<SubjectT>(pointer) {
			if(*pointer)
				pointer->ref();
		}

		using Unref<SubjectT>::operator=;

		inline SubjectT* operator=(const Unref<SubjectT>& pointer) {
			if(pointer.object)
				pointer.object->ref();
			if(this->object)
				this->object->unref();
			return this->object = pointer.object;
		}

		void move(SubjectT* newObject = nullptr) {
			if(newObject == this->object)
				return;
			if(newObject)
				newObject->ref();
			if(this->object)
				this->object->unref();
			this->object = newObject;
		}

	};

}}

#endif /* NERD_BASE_REF_HPP */
