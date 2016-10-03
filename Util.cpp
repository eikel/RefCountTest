#include "Util/References.h"
#include "Util/ReferenceCounter.h"
#include <cstdint>
#include <iostream>

struct BaseClass : public Util::ReferenceCounter<BaseClass> {
	static uint32_t numInstances;
	BaseClass(uint32_t _a, uint32_t _b) : Util::ReferenceCounter<BaseClass>(), a(_a), b(_b) {
		++numInstances;
	}
	uint32_t a;
	uint32_t b;
};
uint32_t BaseClass::numInstances = 0;

int main(int, char **) {
	Util::Reference<BaseClass> refCounter = new BaseClass(5, 10);
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		refCounter = new BaseClass(i, 19);
	}
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		Util::Reference<BaseClass> secondRefCounter = refCounter.get();
	}
	std::cout << BaseClass::numInstances << std::endl;
	return 0;
}
