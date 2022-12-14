#ifndef NERD_BASE_DESTROYARRAY_HPP
#define NERD_BASE_DESTROYARRAY_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include <new>

#include "types.hpp"

namespace nerd {
namespace base {

	template<typename SubjectT>
	class DestroyArray {

	  public:
		typedef SubjectT Subject;

	  private:
		SubjectT* array;
		MemorySize count;

	  public:
		DestroyArray(SubjectT* array, MemorySize count = static_cast<MemorySize>(0u))
				: array(array), count(count) {}

		DestroyArray(const DestroyArray& pointer) : array(pointer.array), count(pointer.count) {}

		~DestroyArray() {
			if(!array)
				return;
			MemorySize u;
			for(u = static_cast<MemorySize>(0u); u < count; ++u)
				array[u].~SubjectT();
		}

		inline void constructElements(MemorySize targetSize) {
			while(count < targetSize) {
				new(array + count) SubjectT;
				++count;
			}
		}

		inline SubjectT* operator*() const {
			return array;
		}

		inline SubjectT* operator->() const {
			return array;
		}

		SubjectT* set(SubjectT* newArray = nullptr, MemorySize newCount = static_cast<MemorySize>(0u)) {
			SubjectT* oldArray = array;
			array = newArray;
			count = newCount;
			return oldArray;
		}

		inline MemorySize size() const {
			return count;
		}

		inline MemorySize extend(MemorySize countDelta) {
			return count += countDelta;
		}

		inline SubjectT*& pointerLocation() {
			return array;
		}

		inline SubjectT* operator=(const DestroyArray& pointer) {
			if(array) {
				MemorySize u;
				for(u = static_cast<MemorySize>(0u); u < count; ++u)
					array[u].~SubjectT();
			}
			count = pointer.count;
			return array = pointer.array;
		}

		inline SubjectT& operator[](MemorySize index) {
			return array[index];
		}

		inline const SubjectT& operator[](MemorySize index) const {
			return array[index];
		}

	};

}}

#endif /* NERD_BASE_DESTROYARRAY_HPP */
