#ifndef INC_UI_H
#define INC_UI_H

#include "../tests/tests.h"

const string HELLO =  "Let's create sequences and do different stuff with them!\n",
DATA_STRUCT = "Choose type of sequence to work with: \n",
funcsy = "\nHere are the options you can choose: \n",
DATA_TYPE = "Choose type of data in sequences: \n",
CONCAT = " Concat the this suquence with itself",
GETFIRST = " Get first element of the sequence",
GETLAST = " Get last element of the sequence",
SUBSEQ = " Get subsequence of the sequence",
THE_SEQ = "You've created the sequence: \n",
GETLENGTH = " Get length of the sequence",
WR = "Please check input and try again",
GET = " Get element of the sequence",
SIZE = "Enter the size of sequence: ",
COMPLEX = " Complex numbers\n",
PREP = " Prepend the element",
CLEAR = " Clear the sequence",
APP = " Append the element",
SEE = " See the sequence\n",
AT = " Insert at the place",
TEST = " See some tests \n",
INT  = " Integer numbers",
ENTER = "Enter the elemet: ",
SET = " Set the elemet",
REAL = " Real numbers",
INDEX = "Enter the index: ",
BYE = "Goodbye! \n",
EXIT = " EXIT",
CHAR = " Char";

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