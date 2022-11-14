#ifndef NERD_BASE_DELETEARRAY_HPP
#define NERD_BASE_DELETEARRAY_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Pointer.hpp"

namespace nerd {
namespace base {

	template<typename SubjectT>
	class DeleteArray : public Pointer<SubjectT> {

	  public:
		DeleteArray(SubjectT* array = NULL) : Pointer<SubjectT>(array) {}

		DeleteArray(const DeleteArray& pointer) : Pointer<SubjectT>(pointer) {}

		~DeleteArray() {
			if(this->object)
				delete[] this->object;
		}

		using Pointer<SubjectT>::operator=;

		inline SubjectT* operator=(const DeleteArray& pointer) {
			if(this->object)
				delete[] this->object;
			return this->object = pointer.object;
		}

		inline SubjectT& operator[](unsigned index) {
			return this->object[index];
		}

		inline const SubjectT& operator[](unsigned index) const {
			return this->object[index];
		}

	};

}}

#endif /* NERD_BASE_DELETEARRAY_HPP */
