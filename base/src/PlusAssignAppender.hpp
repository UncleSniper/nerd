#ifndef NERD_BASE_PLUSASSIGNAPPENDER_HPP
#define NERD_BASE_PLUSASSIGNAPPENDER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include "Appender.hpp"

namespace nerd {
namespace base {

	template<typename CollectionT, typename ElementT>
	class PlusAssignAppender : public Appender<ElementT> {

	  public:
		typedef CollectionT Collection;

	  private:
		CollectionT& collection;

	  public:
		PlusAssignAppender(CollectionT& collection) : collection(collection) {}
		PlusAssignAppender(const PlusAssignAppender& appender)
				: Appender<ElementT>(appender), collection(appender.collection) {}

		inline CollectionT& getCollection() {
			return collection;
		}

		inline const CollectionT& getCollection() const {
			return collection;
		}

		virtual void append(const ElementT& element) {
			collection += element;
		}

	};
	
}}

#endif /* NERD_BASE_PLUSASSIGNAPPENDER_HPP */
