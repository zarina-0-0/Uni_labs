#ifndef LAB2_TEST_MYPTRS_H
#define LAB2_TEST_MYPTRS_H

#include "cassert"
#include <vector>
#include "ISorter.h"
#include "../Lab1/containers_with_myptrs/arrseq_myptrs.h"
#include "bubblesort.h"
#include "cocktailsort.h"
#include "quicksort.h"
#include "../Lab1/libs/colour.h"
#include "genseq.h"
void TEST_BUBBLESORT();
void TEST_QUICKSORT();
void TEST_SHAKERSORT();
void TEST_HEAVY_1000();
void TEST_HEAVY_5000();
void TEST_HEAVY_10000();
void TEST_HEAVY_25000();
void TEST_HEAVY_50000();
void TEST_HEAVY_75000();
void TEST_HEAVY_100000();


#endif //LAB2_TEST_MYPTRS_H