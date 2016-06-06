#define TEST_ASSERT(x) do { if(!(x)) throw std::invalid_argument("SB了！");  } while(0)

#define TEST_CASE(NAME)												\
	extern void TESTCASE_##NAME();									\
	namespace unittest_executors									\
	{																\
		class TESTCASE_RUNNER_##NAME								\
		{															\
		public:														\
			TESTCASE_RUNNER_##NAME()								\
			{														\
				TESTCASE_##NAME();									\
			}														\
		}TESTCASE_RUNNER_##NAME##_INSTANCE;							\
	}																\
	void TESTCASE_##NAME()