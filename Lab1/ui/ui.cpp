#include "ui.h"
#include "../containers_with_myptrs/arrseq_myptrs.h"
#include "../containers_with_myptrs/Sequence_container_interface.h"
#include "../tests/test_derived.h"
#include "../tests/test_ptr_container.h"
#include "../tests/test_ptr_no_containers.h"
#include "../tests/heavy_tests_ptr_no_container.h"

using namespace std;

int mini_main(){
    int type = 0;
    int* my_size = unq_ptr<int>(new int(0)).get();

    if((type = actions_from_menu()) == 1){
        cout << BYE;
        return 0;
    };
    *my_size = size();
    data_type_act(type, *my_size);
    return 0;
}

template<typename T>
T& check_input_type(T* res){
    (cin >> *res);
    while(cin.fail() || (*res > 6) || (*res <= 0)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << WR << DEF << endl;
        cout << ">>";
        cin >> *res;
    }
    return *res;
}



template<typename T>
T& check_input_size(T* res){
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
T& check_input_func(T* res){
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
T& check_input_index(T* res, int the_seq_size){
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

template<typename T>
T& check_input_elem(T* res){
    (cin >> *res);
    while(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << RED << WR << DEF << endl;
        cout << ">>";
        cin >> *res;
    }
    return *res;
}

int& seq_type(){
    cout << (DATA_STRUCT) << endl;
    cout << ">> ";
    cin >> *input;
    return *input;
}

int& data() {
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
    return check_input_type<int>(input);
}

int& size(){
    cout << SIZE << endl;
    cout << ">> ";
    return check_input_size<int>(the_size);
}

void menu(){
    cout << (FUNCSY) << endl;
    cout << BLUE_BG << RED << " 1 " << DEF << DEF_BG<< BLUE << EXIT_ << DEF << endl;
    cout << BLUE_BG << RED << " 2 " << DEF << DEF_BG<< BLUE << GETLENGTH_ << DEF << endl;
    cout << BLUE_BG << RED << " 3 " << DEF << DEF_BG<< BLUE << GETFIRST_ << endl;
    cout << BLUE_BG << RED << " 4 " << DEF << DEF_BG<< BLUE << GETLAST_ << DEF << endl;
    cout << BLUE_BG << RED << " 5 " << DEF << DEF_BG<< BLUE << GET_ << DEF << endl;
    cout << BLUE_BG << RED << " 6 " << DEF << DEF_BG<< BLUE << SUBSEQ_ << DEF << endl;
    cout << BLUE_BG << RED << " 7 " << DEF << DEF_BG<< BLUE << APP_ << DEF << endl;
    cout << BLUE_BG << RED << " 8 " << DEF << DEF_BG<< BLUE << PREP_ << DEF << endl;
    cout << BLUE_BG << RED << " 9 " << DEF << DEF_BG<< BLUE << AT_ << DEF << endl;
    cout << BLUE_BG << RED << " 10 " << DEF << DEF_BG<< BLUE << SET_ << DEF << endl;
    cout << BLUE_BG << RED << " 11 " << DEF << DEF_BG<< BLUE << CONCAT_ << DEF << endl;
    cout << BLUE_BG << RED << " 12 " << DEF << DEF_BG<< BLUE << CLEAR_ << DEF << endl;
    cout << BLUE_BG << RED << " 13 " << DEF << DEF_BG<< BLUE << SEE_ << DEF << endl;
}

int& funcs(){
    cout << "\n>> ";
    return check_input_func(input_func);
}

template<typename T>
void actions_from_menu(Sequence<T>* seq, int& act, T& elem){
    switch (act) {
        case static_cast<int>(FUNCS::EXIT):
        {
            cout << BYE;
            break;
        }
        case static_cast<int>(FUNCS::GETLENGTH):
        {
            cout << "The length: ";
            cout << seq->GetLength();
            break;
        }
        case static_cast<int>(FUNCS::GETFIRST):
        {
            cout << "The first element: ";
            cout << seq->GetFirst();
            break;
        }
        case static_cast<int>(FUNCS::GETLAST):
        {
            cout << "The last element: ";
            cout << seq->GetLast();
            break;
        }
        case static_cast<int>(FUNCS::GET):
        {
            cout << I;
            int& i = check_input_size<int>(input);
            cout << "The element at " << *input << " : " << seq->Get(i);
            break;
        }
        case static_cast<int>(FUNCS::GETSUBSEQ):
        {
            cout << I;
            int& i = check_input_index<int>(input, seq->GetLength());
            cout << I;
            int& j = check_input_index<int>(input, seq->GetLength());
            cout << "The subsequence: " << seq->GetSubSequence(i, j);
            break;
        }
        case static_cast<int>(FUNCS::APPEND):
        {
            cout << E;
            T* element = unq_ptr<T>(new T(elem)).get();
            auto a = check_input_elem<T>(element);
            seq->Append(a);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::PREPEND):
        {
            cout << E;
            T* element = unq_ptr<T>(new T(elem)).get();
            auto a = check_input_elem<T>(element);
            seq->Prepend(a);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::INSERTAT):
        {
            cout << E;
            T* element = unq_ptr<T>(new T(elem)).get();
            auto a = check_input_elem<T>(element);
            cout << I;
            int& i = check_input_index<int>(input, seq->GetLength());
            seq->InsertAt(a, i);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::SET):
        {
            cout << E;
            T* element = unq_ptr<T>(new T(elem)).get();
            auto a = check_input_elem<T>(element);
            cout << I;
            int& i = check_input_index<int>(input, seq->GetLength());
            seq->Set(a, i);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::CONCAT):
        {
            cout << "Concated: " << seq->Concat(seq);
            break;
        }
        case static_cast<int>(FUNCS::CLEAR):
        {
            seq->Clear();
            break;
        }
        case static_cast<int>(FUNCS::SEE):
        {
            cout << "The sequence: " << *seq;
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
            int a;
            cout << "Enter the sequence of size " << size << ": "<< endl;
            for(int i = 0; i < size; i++){
                cout << ">> ";
                cin >> a;
                p[i] = a;
            }
            ArraySequence<int> arr(p, size);
            Sequence<int>* seq = &arr;
            cout << THE_SEQ;
            cout << *seq;
            int act = 0;
            menu();
            while(act != 1){
                act = funcs();
                func(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::REAL):
        {
            double* p = new double[size];
            double a;
            cout << "Enter the sequence of size " << size << ": "<< endl;
            for(int i = 0; i < size; i++){
                cout << ">> ";
                cin >> a;
                p[i] = a;
            }
            ArraySequence<double> arr(p, size);
            Sequence<double> *seq = &arr;
            cout << THE_SEQ;
            cout << *seq;
            menu();
            int act = 0;
            while(act != 1){
                act = funcs();
                func(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::COMPLEX):
        {
            auto p = new complex<double>[size];
            complex<double> a;
            cout << "Enter the sequence of size " << size << ": "<< endl;
            for(int i = 0; i < size; i++){
                cout << ">> ";
                cin >> a;
                p[i] = a;
            }
            ArraySequence<complex<double>> arr(p, size);
            Sequence<complex<double>>* seq = &arr;
            cout << THE_SEQ;
            cout << *seq;
            int act = 0;
            menu();
            while(act != 1){
                act = funcs();
                func(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::CHAR):
        {
            auto p = new char[size];
            char a;
            cout << "Enter the sequence of size " << size << ": "<< endl;
            for(int i = 0; i < size; i++){
                cout << ">> ";
                cin >> a;
                p[i] = a;
            }
            ArraySequence<char> arr(p, size);
            Sequence<char>* seq = &arr;
            cout << THE_SEQ;
            cout << *seq;
            int act = 0;
            menu();
            while(act != 1){
                act = funcs();
                func(seq, act, arr.GetFirst());
            }
            break;
        }
        case static_cast<int>(DATATYPE::TESTS):
        {
            ARRAY_SEQUENCE_TEST();
            CONSTRUCTORS_TESTS_SHRD();
            CONSTRUCTORS_TESTS_UNQ();
            FUNCS_TESTS_UNQ();
            FUNCS_TESTS_SHRD();
            OPERATOR_TESTS_SHRD();
            OPERATOR_TESTS_UNQ();
            HEAVY_FUNCS_TESTS_SHRD();
            HEAVY_FUNCS_TESTS_UNQ();
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
}
