#ifndef LAB2_UI_H
#define LAB2_UI_H
#include "test_myptrs.h"

#define HELLO  "Let's generate sequences and sort them!\n"
#define FUNCSY "\nHere are the options you can choose: \n"
#define DATA_TYPE "Choose type of data in sequences: \n"
#define WR "Please check input and try again"
#define SIZE "Enter the size of sequence: "
#define SEE_ " See the sorted sequence"
#define COMPLEX_ " Complex numbers\n"
#define TEST " See some tests \n"
#define INT_ " Integer numbers"
#define BUBBLE " Bubble sort"
#define SHAKER " Shaker sort"
#define E "Enter the elemet: "
#define REAL_ " Real numbers"
#define I "Enter the index: "
#define QUICK " Quick sort"
#define BYE "Goodbye! \n"
#define EXIT_ " EXIT"
#define CHAR_ " Char"

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

extern int* input;
extern int* the_size;
extern int* input_func;
extern int the_seq_size;

enum class SEQTYPE{
    EXIT = 1,
    ARRAY
};

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
