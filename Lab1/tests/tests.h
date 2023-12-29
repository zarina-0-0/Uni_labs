#ifndef TEST_PTR_NO_CONTAINERS_h
#define TEST_PTR_NO_CONTAINERS_h

#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <ostream>
#include <chrono>

#include "../containers_with_myptrs/arrseq_myptrs.h"
#include "../libs/colour.h"
#include "../ptrs/shared.h"
#include "../ptrs/unique.h"

using namespace std;
extern int PASS;
extern int FAIL;
void CONSTRUCTORS_TESTS_SHRD();
void OPERATOR_TESTS_SHRD();
void FUNCS_TESTS_SHRD();
void FUNCS_TESTS_UNQ();
void CONSTRUCTORS_TESTS_UNQ();
void ARRAY_SEQUENCE_TEST();
void TEST_DERIVED();
void HEAVY_FUNCS_TESTS_SHRD();
void CONSTRUCTORS_TESTS_UNQ();
void HEAVY_FUNCS_TESTS_UNQ();
void OPERATOR_TESTS_UNQ();


#endif