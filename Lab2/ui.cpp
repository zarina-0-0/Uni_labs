#include "ui.h"
#include "../Lab1/ptrs/unique.h"
#include "quicksort.h"
#include "bubblesort.h"
#include "cocktailsort.h"
#include "genseq.h"

using namespace std;
using namespace chrono;
typedef high_resolution_clock C;

void mini_main(){
    int type = 0;
    int* my_size = unq_ptr<int>(new int(0)).get();

    if((type = data()) == 1){
        cout << BYE;
        return;
    };
    *my_size = size();
    data_type_act(type, *my_size);
    return;
}

template<typename T>
T check_input_type(T* res, int down, int up){
    (cin >> *res);
    while(cin.fail() || (*res > up) || (*res <= down)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << WR << DEF << endl;
        cout << ">>";
        cin >> *res;
    }
    return *res;
}

template<typename T>
T check_input_size(T* res){
    (cin >> *res);
    while(cin.fail() || (*res < 0) || (*res > 10000)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << WR << DEF << endl;
        cout << ">>";
        cin >> *res;
    }
    return *res;
}

template<typename T>
T check_input_func(T* res){
    (cin >> *res);
    while(cin.fail() || (*res > 13) || (*res <= 0)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << WR << DEF << endl;
        cout << ">>";
        cin >> *res;
    }
    return *res;
}

template<typename T>
T check_input_index(T* res, int the_seq_size){
    (cin >> *res);
    while(cin.fail() || (*res >= the_seq_size) || (*res < 0)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << WR << DEF << endl;
        cout << ">>";
        cin >> *res;
    }
    return *res;
}

int data() {
    int flag = 0;
    cout << endl << BLUE << HELLO << DEF;
    cout << (DATA_TYPE) << endl;
    cout << BLUE_BG << RED << " 1 " << DEF << DEF_BG << BLUE << EXIT_ << DEF << endl;
    cout << BLUE_BG << RED << " 2 " << DEF << DEF_BG << BLUE << INT_ << DEF << endl;
    cout << BLUE_BG << RED << " 3 " << DEF << DEF_BG << BLUE << REAL_ << DEF << endl;
    cout << BLUE_BG << RED << " 4 " << DEF << DEF_BG << BLUE << COMPLEX_ << DEF;
    cout << BLUE_BG << RED << " 5 " << DEF << DEF_BG << BLUE << CHAR_ << DEF << endl;
    cout << BLUE_BG << RED << " 6 " << DEF << DEF_BG << BLUE << TEST << DEF << endl;
    cout << ">> ";
    return check_input_type<int>(input, 0, 6);
}

int size(){
    cout << SIZE << endl;
    cout << ">> ";
    return check_input_size<int>(the_size);
}

void menu(){
    cout << (FUNCSY) << endl;
    cout << BLUE_BG << RED << " 1 " << DEF << DEF_BG<< BLUE << EXIT_ << DEF << endl;
    cout << BLUE_BG << RED << " 2 " << DEF << DEF_BG<< BLUE << QUICK << DEF << endl;
    cout << BLUE_BG << RED << " 3 " << DEF << DEF_BG<< BLUE << SHAKER << DEF << endl;
    cout << BLUE_BG << RED << " 4 " << DEF << DEF_BG<< BLUE << BUBBLE << DEF << endl;
    cout << BLUE_BG << RED << " 5 " << DEF << DEF_BG<< BLUE << SEE_ << DEF << endl;
}

int funcs(){
    cout << "\n>> ";
    return check_input_func(input_func);
}

template<typename T>
void actions_from_menu(Sequence<T>* seq, int act, T elem) {
    switch (act) {
        case static_cast<int>(FUNCS::EXIT): {
            cout << BYE;
            break;
        }
        case static_cast<int>(FUNCS::QUICKSORT): {
            QuickSort<T> sort;
            auto begin = high_resolution_clock::now();
            sort.ISort(seq, &my_comparator, 0, (seq->GetLength()-1));
            auto end = high_resolution_clock::now();
            auto elapsed = duration_cast<milliseconds>(end - begin);
            cout << BLUE << "Time of sorting by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;
            break;
        }
        case static_cast<int>(FUNCS::SHAKERSORT): {
            CocktailSort<T> sort;
            auto begin = high_resolution_clock::now();
            sort.ISort(seq, &my_comparator, 0, (seq->GetLength()-1));
            auto end = high_resolution_clock::now();
            auto elapsed = duration_cast<milliseconds>(end - begin);
            cout << BLUE << "Time of sorting by shakersort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;
            break;
        }
        case static_cast<int>(FUNCS::BUBBLESORT): {
            BubbleSort<T> sort;
            auto begin = high_resolution_clock::now();
            sort.ISort(seq, &my_comparator, 0, (seq->GetLength()-1));
            auto end = high_resolution_clock::now();
            auto elapsed = duration_cast<milliseconds>(end - begin);
            cout << BLUE << "Time of sorting by bubblesort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;
            break;
        }
        case static_cast<int>(FUNCS::SEE): {
            cout << "The sorted sequence: " << *seq;
            break;
        }
        default:
            cout << RED << WR << DEF << endl;
            break;
    }
}

int data_type_act(int type, int size){
    switch (type) {
        case static_cast<int>(DATATYPE::EXIT):
        {
            cout << BYE;
            break;
        }
        case static_cast<int>(DATATYPE::INT):
        {
            int* p = new int[size];
            ArraySequence<int> arr(p, size);
            Sequence<int>* seq = &arr;
            seq = seq_generator(seq, size);
            cout << "Generated sequence: " << endl;
            cout << *seq;
            int act = 0;
            menu();
            while(act != 1){
                act = funcs();
                actions_from_menu(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::REAL):
        {
            double* p = new double[size];
            ArraySequence<double> arr(p, size);
            Sequence<double> *seq = &arr;
            seq = seq_generator(seq, size);
            cout << "Generated sequence: " << endl;
            cout << *seq;
            menu();
            int act = 0;
            while(act != 1){
                act = funcs();
                actions_from_menu(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::COMPLEX):
        {
//            auto p = new complex<double>[size];
//            ArraySequence<complex<double>> arr(p, size);
//            Sequence<complex<double>>* seq = &arr;
//            seq = seq_generator(seq, size);
//            cout << "Generated sequence: " << endl;
//            cout << *seq;
//            int act = 0;
//            menu();
//            while(act != 1){
//                act = funcs();
//                actions_from_menu(seq, act, arr.GetFirst());
//            }
            cout << "Complex numbers can't be compared" << endl;
            break;
        }
        case static_cast<int>(DATATYPE::CHAR):
        {
            auto p = new char[size];
            ArraySequence<char> arr(p, size);
            Sequence<char>* seq = &arr;
            seq = seq_generator(seq, size);
            cout << "Generated sequence: " << endl;
            cout << *seq;
            int act = 0;
            menu();
            while(act != 1){
                act = funcs();
                actions_from_menu(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::TESTS):
        {
            TEST_BUBBLESORT();
            TEST_SHAKERSORT();
            TEST_QUICKSORT();
            break;
        }
        default:
        {
            cout << WR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << ">> ";
            cin >> type;
            break;
        }
    }
    return 0;
};

template int check_input_type<int>(int*, int, int);
template int check_input_size<int>(int*);
template int check_input_func<int>(int*);
template int check_input_index<int>(int*, int);

template char check_input_type<char>(char*, int, int);
template char check_input_size<char>(char*);
template char check_input_func<char>(char*);
template char check_input_index<char>(char*, int);

template double check_input_type<double>(double*, int, int);
template double check_input_size<double>(double*);
template double check_input_func<double>(double*);
template double check_input_index<double>(double*, int);

template void actions_from_menu<double>(Sequence<double>*, int, double);
template void actions_from_menu<int>(Sequence<int>*, int, int);
template void actions_from_menu<char>(Sequence<char>*, int, char);