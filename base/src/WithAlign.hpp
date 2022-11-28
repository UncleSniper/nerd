#ifndef NERD_BASE_WITHALIGN_HPP
#define NERD_BASE_WITHALIGN_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include <cstddef>

namespace nerd {
namespace base {

	template<std::size_t Alignment>
	class WithAlign {

	  private:
		template<typename PrimitiveT, std::size_t PrimitiveAlignment, typename NextT>
		struct Link {

			typedef PrimitiveT Primitive;
			typedef NextT Next;

			static const std::size_t ALIGNMENT = PrimitiveAlignment;

		};

		struct EndLink {};

		typedef int (*Function)(int);
		typedef int (EndLink::*Method)(int);

#define NERD_BASE_WITHALIGN_CASE(primitive, name, prev) \
		typedef Link<primitive, alignof(primitive), prev ## Link> name ## Link;

		NERD_BASE_WITHALIGN_CASE(Method, Method, End)
		NERD_BASE_WITHALIGN_CASE(Function, Function, Method)
		NERD_BASE_WITHALIGN_CASE(void*, Pointer, Function)
		NERD_BASE_WITHALIGN_CASE(long double, LongDouble, Pointer)
		NERD_BASE_WITHALIGN_CASE(double, Double, LongDouble)
		NERD_BASE_WITHALIGN_CASE(float, Float, Double)
		NERD_BASE_WITHALIGN_CASE(long long, LongLong, Float)
		NERD_BASE_WITHALIGN_CASE(long, Long, LongLong)
		NERD_BASE_WITHALIGN_CASE(int, Int, Long)
		NERD_BASE_WITHALIGN_CASE(short, Short, Int)
		NERD_BASE_WITHALIGN_CASE(char, Char, Short)
		typedef CharLink LastLink;

		template<int Dummy, typename LinkT>
		struct Lookup {

			template<int Dummy2, bool>
			struct Found {

				typedef typename Lookup<Dummy2, typename LinkT::Next>::Primitive Primitive;

			};

			template<int Dummy2>
			struct Found<Dummy2, true> {

				typedef typename LinkT::Primitive Primitive;

			};

			typedef typename Found<Dummy, LinkT::ALIGNMENT == Alignment>::Primitive Primitive;

		};

		template<int Dummy>
		struct Lookup<Dummy, EndLink> {

			typedef char Primitive;

		};

	  public:
		typedef typename Lookup<0, LastLink>::Primitive Primitive;

	};

}}

#endif /* NERD_BASE_WITHALIGN_HPP */
