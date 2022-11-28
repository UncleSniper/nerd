#ifndef NERD_BASE_APPENDER_HPP
#define NERD_BASE_APPENDER_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	template<typename ElementT>
	class Appender {

	  public:
		typedef ElementT Element;

	  public:
		Appender() {}
		Appender(const Appender&) {}
		virtual ~Appender() {}

		Appender& operator+=(const ElementT& element) {
			append(element);
			return *this;
		}

		virtual void append(const ElementT& element) = 0;

		virtual void doneAppending() {}

	};

}}

#endif /* NERD_BASE_APPENDER_HPP */
