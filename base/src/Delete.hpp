#ifndef NERD_BASE_DELETE_HPP
#define NERD_BASE_DELETE_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Pointer.hpp"

namespace nerd {
namespace base {

	template<typename SubjectT>
	class Delete : public Pointer<SubjectT> {

	  public:
		Delete(SubjectT* object = nullptr) : Pointer<SubjectT>(object) {}

		Delete(const Delete& pointer) : Pointer<SubjectT>(pointer) {}

		~Delete() {
			if(this->object)
				delete this->object;
		}

		using Pointer<SubjectT>::operator=;

		inline SubjectT* operator=(const Delete& pointer) {
			if(this->object)
				delete this->object;
			return this->object = pointer.object;
		}

	};

}}

#endif /* NERD_BASE_DELETE_HPP */
