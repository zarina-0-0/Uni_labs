#ifndef LAB2_UI_H
#define LAB2_UI_H
#include "test_myptrs.h"

const string HELLO = "Let's generate sequences and sort them!\n",
FUNCSY = "\nHere are the options you can choose: \n",
DATA_TYPE = "Choose type of data in sequences: \n",
WR = "Please check input and try again",
SIZE = "Enter the size of sequence: ",
SEE = " See the sorted sequence",
COMPLEX = " Complex numbers\n",
TEST = " See some tests \n",
INT = " Integer numbers",
BUBBLE = " Bubble sort",
SHAKER = " Shaker sort",
REAL = " Real numbers",
QUICK = " Quick sort",
BYE = "Goodbye! \n",
EXIT = " EXIT",
CHAR = " Char";

template<typename T> void actions_from_menu(Sequence<T>*, int, T);
template<typename T>T check_input_type(T* res, int down, int up);
template<typename T>T check_input_size(T* res);
template<typename T>T check_input_func(T* res);
template<typename T>T check_input_index(T* res, int the_seq_size);

void mini_main();
int funcs();
int size();
int data();
void menu();
int data_type_act(int type, int size);

enum class DATATYPE{
    EXIT = 1,
    INT,
    REAL,
    COMPLEX,
    CHAR,
    TESTS
};

enum class FUNCS{
    EXIT = 1,
    QUICKSORT,
    SHAKERSORT,
    BUBBLESORT,
    SEE
};

#endif //LAB2_UI_H
