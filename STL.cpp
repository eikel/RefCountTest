#include <cstdint>
#include <iostream>
#include <memory>

struct BaseClass {
	static uint32_t numInstances;
	BaseClass(uint32_t _a, uint32_t _b) : a(_a), b(_b) {
		++numInstances;
	}
	uint32_t a;
	uint32_t b;
};
uint32_t BaseClass::numInstances = 0;

int main(int, char **) {
	std::shared_ptr<BaseClass> refCounter(new BaseClass(5, 10));
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		refCounter.reset(new BaseClass(i, 19));
	}
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		std::shared_ptr<BaseClass> secondRefCounter = refCounter;
	}
	std::cout << BaseClass::numInstances << std::endl;
	return 0;
}
