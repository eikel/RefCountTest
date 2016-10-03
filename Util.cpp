#include "../PADrend/src/Util/References.h"
#include "../PADrend/src/Util/ReferenceCounter.h"
#include <cstdint>

struct BaseClass : public Util::ReferenceCounter<BaseClass> {
	BaseClass(uint32_t _a, uint32_t _b) : Util::ReferenceCounter<BaseClass>(), a(_a), b(_b) {
	}
	uint32_t a;
	uint32_t b;
};

int main(int, char **) {
	Util::Reference<BaseClass> refCounter = new BaseClass(5, 10);
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		refCounter = new BaseClass(i, 19);
	}
	for(uint_fast32_t i = 0; i < 100000000; ++i) {
		Util::Reference<BaseClass> secondRefCounter = refCounter.get();
	}
	return 0;
}
