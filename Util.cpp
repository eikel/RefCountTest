/*
 * Copyright (C) 2016 Benjamin Eikel <benjamin@eikel.org>
 *
 * This file is subject to the terms of the Mozilla Public License, v. 2.0.
 * You should have received a copy of the MPL along with this library; see the
 * file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "Util/References.h"
#include "Util/ReferenceCounter.h"
#include <cstdint>
#include <iostream>
#include <vector>

struct BaseClass : public Util::ReferenceCounter<BaseClass> {
	static uint32_t numInstances;
	BaseClass(uint32_t _a, uint32_t _b) : Util::ReferenceCounter<BaseClass>(), a(_a), b(_b) {
		++numInstances;
	}
	~BaseClass() {
		--numInstances;
	}
	uint32_t a;
	uint32_t b;
};
uint32_t BaseClass::numInstances = 0;

int main(int, char **) {
	std::vector<Util::Reference<BaseClass>> refs;
	refs.reserve(1000);
	for(uint_fast32_t r = 0; r < 1000; ++r) {
		refs.emplace_back(new BaseClass(5, 10));
		for(uint_fast32_t i = 0; i < 100000; ++i) {
			refs.back() = new BaseClass(i, 19);
		}
		for(uint_fast32_t i = 0; i < 100000; ++i) {
			Util::Reference<BaseClass> secondRefCounter = refs.back().get();
		}
	}
	std::cout << BaseClass::numInstances << std::endl;
	return 0;
}
