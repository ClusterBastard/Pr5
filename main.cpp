// Единственная точка входа: оба задания линкуются в один exe (иначе LNK2005: два main).
#include <iostream>

#ifdef _WIN32
extern "C" __declspec(dllimport) int __stdcall SetConsoleOutputCP(unsigned int wCodePageID);
extern "C" __declspec(dllimport) int __stdcall SetConsoleCP(unsigned int wCodePageID);
#ifndef CP_UTF8
#define CP_UTF8 65001u
#endif
#endif

void demo_zadanie1_rectangle();
void demo_zadanie2_person();

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    demo_zadanie1_rectangle();
    std::cout << "\n";
    demo_zadanie2_person();

    return 0;
}
