#include <cstdint>
#include <memory>

struct BaseClass {
	BaseClass(uint32_t _a, uint32_t _b) : a(_a), b(_b) {
	}
	uint32_t a;
	uint32_t b;
};

int main(int, char **) {
	std::shared_ptr<BaseClass> refCounter(new BaseClass(5, 10));
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		refCounter.reset(new BaseClass(i, 19));
	}
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		std::shared_ptr<BaseClass> secondRefCounter = refCounter;
	}
	return 0;
}
