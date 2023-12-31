#ifndef INC_UI_H
#define INC_UI_H

#include "../tests/tests.h"

#define HELLO  "Let's create sequences and do different stuff with them!\n"
#define DATA_STRUCT "Choose type of sequence to work with: \n"
#define FUNCSY "\nHere are the options you can choose: \n"
#define DATA_TYPE "Choose type of data in sequences: \n"
#define CONCAT_ " Concat the this suquence with itself"
#define GETFIRST_ " Get first element of the sequence"
#define GETLAST_ " Get last element of the sequence"
#define SUBSEQ_ " Get subsequence of the sequence"
#define THE_SEQ "You've created the sequence: \n"
#define GETLENGTH_ " Get length of the sequence"
#define WR "Please check input and try again"
#define GET_ " Get element of the sequence"
#define SIZE "Enter the size of sequence: "
#define COMPLEX_ " Complex numbers\n"
#define PREP_ " Prepend the element"
#define CLEAR_ " Clear the sequence"
#define APP_ " Append the element"
#define SEE_ " See the sequence\n"
#define AT_ " Insert at the place"
#define TEST " See some tests \n"
#define INT_ " Integer numbers"
#define E "Enter the elemet: "
#define SET_ " Set the elemet"
#define REAL_ " Real numbers"
#define I "Enter the index: "
#define BYE "Goodbye! \n"
#define EXIT_ " EXIT"
#define CHAR_ " Char"

int data_type_act(int type, int size);
template<typename T> void actions_from_menu(Sequence<T>*, int, T);
template<typename T>T check_input_type(T* res, int down, int up);
template<typename T>T check_input_size(T* res);
template<typename T>T check_input_func(T* res);
template<typename T>T check_input_index(T* res, int the_seq_size);
template<typename T>T check_input_elem(T* res);
int mini_main();
int funcs();
int size();
int data();
void menu();

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
    GETLENGTH,
    GETFIRST,
    GETLAST,
    GET,
    GETSUBSEQ,
    APPEND,
    PREPEND,
    INSERTAT,
    SET,
    CONCAT,
    CLEAR,
    SEE
};

#endif