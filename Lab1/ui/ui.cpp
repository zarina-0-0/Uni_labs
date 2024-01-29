#include "ui.h"

using namespace std;

int* input = new int(0);
int* the_size = new int(0);
int* input_func = new int(0);

int mini_main(){
    int type = 0;
    int* my_size = unq_ptr<int>(new int(0)).Get();

    if((type = data()) == 1){
        cout << BYE;
        return 0;
    };
    *my_size = size();
    data_type_act(type, *my_size);
    return 0;
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

template<typename T>
T check_input_elem(T* res){
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

int seq_type(){
    cout << (DATA_STRUCT) << endl;
    cout << ">> ";
    cin >> *input;
    return *input;
}

int data() {
    int flag = 0;
    cout << endl << BLUE << HELLO << DEF;
    cout << (DATA_TYPE) << endl;
    cout << BLUE_BG << RED << " 1 " << DEF << DEF_BG << BLUE << EXIT << DEF << endl;
    cout << BLUE_BG << RED << " 2 " << DEF << DEF_BG << BLUE << INT << DEF << endl;
    cout << BLUE_BG << RED << " 3 " << DEF << DEF_BG << BLUE << REAL << DEF << endl;
    cout << BLUE_BG << RED << " 4 " << DEF << DEF_BG << BLUE << COMPLEX << DEF;
    cout << BLUE_BG << RED << " 5 " << DEF << DEF_BG << BLUE << CHAR << DEF << endl;
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
    cout << (funcsy) << endl;
    cout << BLUE_BG << RED << " 1 " << DEF << DEF_BG<< BLUE << EXIT << DEF << endl;
    cout << BLUE_BG << RED << " 2 " << DEF << DEF_BG<< BLUE << GETLENGTH << DEF << endl;
    cout << BLUE_BG << RED << " 3 " << DEF << DEF_BG<< BLUE << GETFIRST << endl;
    cout << BLUE_BG << RED << " 4 " << DEF << DEF_BG<< BLUE << GETLAST << DEF << endl;
    cout << BLUE_BG << RED << " 5 " << DEF << DEF_BG<< BLUE << GET << DEF << endl;
    cout << BLUE_BG << RED << " 6 " << DEF << DEF_BG<< BLUE << SUBSEQ << DEF << endl;
    cout << BLUE_BG << RED << " 7 " << DEF << DEF_BG<< BLUE << APP << DEF << endl;
    cout << BLUE_BG << RED << " 8 " << DEF << DEF_BG<< BLUE << PREP << DEF << endl;
    cout << BLUE_BG << RED << " 9 " << DEF << DEF_BG<< BLUE << AT << DEF << endl;
    cout << BLUE_BG << RED << " 10 " << DEF << DEF_BG<< BLUE << SET << DEF << endl;
    cout << BLUE_BG << RED << " 11 " << DEF << DEF_BG<< BLUE << CONCAT << DEF << endl;
    cout << BLUE_BG << RED << " 12 " << DEF << DEF_BG<< BLUE << CLEAR << DEF << endl;
    cout << BLUE_BG << RED << " 13 " << DEF << DEF_BG<< BLUE << SEE << DEF << endl;
}

int funcs(){
    cout << endl << ">> ";
    return check_input_func(input_func);
}

template<typename T>
void actions_from_menu(Sequence<T>* seq, int act, T elem){
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
            cout << INDEX;
            int i = check_input_size<int>(input);
            cout << "The element at " << *input << " : " << seq->Get(i);
            break;
        }
        case static_cast<int>(FUNCS::GETSUBSEQ):
        {
            cout << INDEX;
            int i = check_input_index<int>(input, seq->GetLength());
            cout << INDEX;
            int j = check_input_index<int>(input, seq->GetLength());
            cout << "The subsequence: " << seq->GetSubSequence(i, j);
            break;
        }
        case static_cast<int>(FUNCS::APPEND):
        {
            cout << ENTER;
            T* element = unq_ptr<T>(new T(elem)).Get();
            auto a = check_input_elem<T>(element);
            seq->Append(a);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::PREPEND):
        {
            cout << ENTER;
            T* element = unq_ptr<T>(new T(elem)).Get();
            auto a = check_input_elem<T>(element);
            seq->Prepend(a);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::INSERTAT):
        {
            cout << ENTER;
            T* element = unq_ptr<T>(new T(elem)).Get();
            auto a = check_input_elem<T>(element);
            cout << INDEX;
            int i = check_input_index<int>(input, seq->GetLength());
            seq->InsertAt(a, i);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::SET):
        {
            cout << ENTER;
            T* element = unq_ptr<T>(new T(elem)).Get();
            auto a = check_input_elem<T>(element);
            cout << INDEX;
            int i = check_input_index<int>(input, seq->GetLength());
            seq->Set(a, i);
            cout << "Done!" << endl;
            break;
        }
        case static_cast<int>(FUNCS::CONCAT):
        {
            cout << "Concated: " << *(seq->Concat(seq));
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
            delete input;
            delete the_size;
            delete input_func;
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
                actions_from_menu(seq, act, arr.GetFirst());
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
                actions_from_menu(seq, act, arr.GetFirst());
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
                actions_from_menu(seq, act, arr.GetFirst());
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
                actions_from_menu(seq, act, arr.GetFirst());
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


template int check_input_type<int>(int*, int, int);
template int check_input_size<int>(int*);
template int check_input_func<int>(int*);
template int check_input_index<int>(int*, int);
template int check_input_elem<int>(int*);

template char check_input_type<char>(char*, int, int);
template char check_input_size<char>(char*);
template char check_input_func<char>(char*);
template char check_input_index<char>(char*, int);
template char check_input_elem<char>(char*);

template double check_input_type<double>(double*, int, int);
template double check_input_size<double>(double*);
template double check_input_func<double>(double*);
template double check_input_index<double>(double*, int);
template double check_input_elem<double>(double*);

template void actions_from_menu<double>(Sequence<double>*, int, double);
template void actions_from_menu<int>(Sequence<int>*, int, int);
template void actions_from_menu<char>(Sequence<char>*, int, char);
template void actions_from_menu<complex<double>>(Sequence<complex<double>>*, int, complex<double>);
