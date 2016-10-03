#
# Copyright (C) 2016 Benjamin Eikel <benjamin@eikel.org>
#
# This file is subject to the terms of the Mozilla Public License, v. 2.0.
# You should have received a copy of the MPL along with this library; see the 
# file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
#
cmake_minimum_required(VERSION 3.1.0)
project(RefCountTest VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(STLTest
	STL.cpp
)
add_executable(UtilTest
	Util.cpp
)

find_program (TIME time)

include(CTest)
add_test(NAME STLTestTime COMMAND ${TIME} $<TARGET_FILE:STLTest>)
add_test(NAME UtilTestTime COMMAND ${TIME} $<TARGET_FILE:UtilTest>)
