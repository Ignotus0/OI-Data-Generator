#include <bits/stdc++.h>
#include "randlib.h"

using namespace std;

// File Config
const bool has_subtasks = 1;
const int subtasks = 4;
const int test_cases = 30;
const int subtask_end[] = {4, 10, 17, 30};
const int subtask_score[] = {10, 15, 25, 50};
const string pre = "plus";
const string PATH = "D:\\";
const int TL = 1;
const int ML = 128;
const string comp = "ncmp";
#define GENERATE_AND_SOLVE
#define GENERATE_CONFIG

// Misc Variables
double startTime, endTime;
char t[50];
string s;

// Main Generator

void gen(int Testid){
    int a, b;
    if(Testid <= subtask_end[0]) a = randomInt(1, 10), b = randomInt(1, 10);
    else if(Testid <= subtask_end[1]) a = randomInt(1, 10000), b = randomInt(1, 10000);
    else if(Testid <= subtask_end[2]) a = randomInt(1, 1e9), b = randomInt(1, 1e9);
    else if(Testid <= subtask_end[3]) a = randomInt(-1e9, 1e9), b = randomInt(-1e9, 1e9);
    printf("%d %d\n", a, b);
}

// Compile Standard Program to get the Answer

void solve(){
    system("g++ std.cpp -o std -std=c++14 -O2 -Wl,--stack=1073741824");
    cerr << "Successfully Compiled." << endl;
    for(int i = 1; i <= test_cases; ++i){
        sprintf(t, "%d", i);
        s = t;
        startTime = system_clock;
        system(("std.exe < \"" + PATH + "\\" + pre + "\\" + pre + s + ".in" + "\" > \"" + PATH + "\\" + pre + "\\" + pre + s + ".ans" + "\"").c_str());
        endTime = system_clock;
        cerr << "Test #" << i << ": ";
        cerr << setprecision(4) << (endTime - startTime) / 1e9;
        cerr << " seconds.\n";
    }
}

void config(){
    freopen((PATH + "\\" + pre + "\\" + "problem.conf").c_str(), "w", stdout);
    std::cout << "use_builtin_judger on\n";
    std::cout << "use_builtin_checker " << comp << '\n';
    std::cout << "n_tests " << test_cases << '\n';
    std::cout << "n_ex_tests 0\nn_sample_tests 0\n";
    if(has_subtasks){
        std::cout << "n_subtasks " << subtasks << '\n';
        for(int i = 1; i <= subtasks; ++i) std::cout << "subtask_end_" << i << " " << subtask_end[i - 1] << '\n';
        for(int i = 1; i <= subtasks; ++i) std::cout << "subtask_score_" << i << " " << subtask_score[i - 1] << '\n';
    }
    std::cout << "input_pre " << pre << '\n';
    std::cout << "input_suf in\n";
    std::cout << "output_pre " << pre << '\n';
    std::cout << "output_suf ans\n";
    std::cout << "time_limit " << TL << '\n';
    std::cout << "memory_limit " << ML << '\n';
    std::cerr << "problem.conf generated.\n";
}

int main(){
    system(("cd " + PATH + " && del " + pre).c_str());
    system(("cd " + PATH + " && mkdir " + pre).c_str());
    
    startTime = system_clock;
    for(int i = 1; i <= test_cases; ++i){
        sprintf(t, "%d", i);
        s = t;
        freopen((PATH + "\\" + pre + "\\" + pre + s + ".in").c_str(), "w", stdout);
        gen(i);
    }
    endTime = system_clock;

    cerr << test_cases << " test cases generated in ";
    cerr << fixed << setprecision(4) << (endTime - startTime) / 1e9;
    cerr << " seconds.\n";
    
    #ifdef GENERATE_AND_SOLVE
        solve();
    #endif

    #ifdef GENERATE_CONFIG
        config();
    #endif

    cerr << "Data Successfully Generated." << endl;
    return 0;
}