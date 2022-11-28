#ifndef NERD_BASE_CLASSIFYTYPE_HPP
#define NERD_BASE_CLASSIFYTYPE_HPP

// This file shamelessly ripped off from RedEngine RedStrain

namespace nerd {
namespace base {

	enum {
		TCLS_INTEGER         = 001,
		TCLS_FLOAT           = 002,
		TCLS_NUMERIC         = 003,
		TCLS_POINTER         = 004,
		TCLS_FUNCTION        = 010,
		TCLS_MEMBER_FUNCTION = 020,
		TCLS_FUNCTOID        = 030,
		TCLS_OTHER           = 000
	};

	template<typename T>
	class ClassifyType {

	  private:
		template<int, typename>
		struct Classifier {
			static const int CLASS = TCLS_OTHER;
		};

#define NERD_BASE_TYPE_CLASSIFIER_BODY(clazz) \
	{ \
		static const int CLASS = clazz; \
	};
#define NERD_BASE_DEFINE_TYPE_CLASSIFIER(type, clazz) \
	template<int Dummy> \
	struct Classifier<Dummy, type> \
	NERD_BASE_TYPE_CLASSIFIER_BODY(clazz)

		// ==== BEGIN PRIMITIVES ====
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(signed char, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(unsigned char, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(short, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(unsigned short, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(int, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(unsigned, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(long, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(unsigned long, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(long long, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(unsigned long long, TCLS_INTEGER)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(float, TCLS_FLOAT)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(double, TCLS_FLOAT)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(long double, TCLS_FLOAT)
		NERD_BASE_DEFINE_TYPE_CLASSIFIER(wchar_t, TCLS_INTEGER)
		// ==== END PRIMITIVES ====

		// ==== BEGIN FUNCTIONS ====
		template<
			int Dummy,
			typename ReturnT
		>
		struct Classifier<Dummy, ReturnT (*)()>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T,
			typename Arg13T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T,
			Arg13T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T,
			typename Arg13T,
			typename Arg14T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T,
			Arg13T,
			Arg14T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)

		template<
			int Dummy,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T,
			typename Arg13T,
			typename Arg14T,
			typename Arg15T
		>
		struct Classifier<Dummy, ReturnT (*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T,
			Arg13T,
			Arg14T,
			Arg15T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_FUNCTION)
		// ==== END FUNCTIONS ====

		// ==== BEGIN MEMBER FUNCTIONS ====
		template<
			int Dummy,
			typename BaseT,
			typename ReturnT
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)()>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T,
			typename Arg13T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T,
			Arg13T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T,
			typename Arg13T,
			typename Arg14T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T,
			Arg13T,
			Arg14T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)

		template<
			int Dummy,
			typename BaseT,
			typename ReturnT,
			typename Arg0T,
			typename Arg1T,
			typename Arg2T,
			typename Arg3T,
			typename Arg4T,
			typename Arg5T,
			typename Arg6T,
			typename Arg7T,
			typename Arg8T,
			typename Arg9T,
			typename Arg10T,
			typename Arg11T,
			typename Arg12T,
			typename Arg13T,
			typename Arg14T,
			typename Arg15T
		>
		struct Classifier<Dummy, ReturnT (BaseT::*)(
			Arg0T,
			Arg1T,
			Arg2T,
			Arg3T,
			Arg4T,
			Arg5T,
			Arg6T,
			Arg7T,
			Arg8T,
			Arg9T,
			Arg10T,
			Arg11T,
			Arg12T,
			Arg13T,
			Arg14T,
			Arg15T
		)>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_MEMBER_FUNCTION)
		// ==== END MEMBER FUNCTIONS ====

		template<int Dummy, typename U>
		struct Classifier<Dummy, U*>
		NERD_BASE_TYPE_CLASSIFIER_BODY(TCLS_POINTER)

	  public:
		static const int CLASS = Classifier<0, T>::CLASS;

	};

}}

#endif /* NERD_BASE_CLASSIFYTYPE_HPP */
