/*
 * Copyright (C) 2016 Benjamin Eikel <benjamin@eikel.org>
 *
 * This file is subject to the terms of the Mozilla Public License, v. 2.0.
 * You should have received a copy of the MPL along with this library; see the
 * file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

struct BaseClass {
	static uint32_t numInstances;
	BaseClass(uint32_t _a, uint32_t _b) : a(_a), b(_b) {
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
	std::vector<std::shared_ptr<BaseClass>> refs;
	refs.reserve(1000);
	for(uint_fast32_t r = 0; r < 1000; ++r) {
		refs.emplace_back(std::make_shared<BaseClass>(5, 10));
		for(uint_fast32_t i = 0; i < 1000; ++i) {
			refs.back().reset(new BaseClass(i, 19));
		}
		for(uint_fast32_t i = 0; i < 1000; ++i) {
			std::shared_ptr<BaseClass> secondRefCounter = refs.back();
		}
	}
	std::cout << BaseClass::numInstances << std::endl;
	return 0;
}
