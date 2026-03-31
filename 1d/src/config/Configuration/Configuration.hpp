#pragma once
#include <bits/stdc++.h>
#include "../../system/Header.hpp"
#include "Algorithm/BitArray.hpp"

class Configuration
{
    Clock& ck;
    IOControl& io;
    RandomNumGen& rn;
    Parameter& para;
    Observable& obs;
    Histogram& his;

public:
    //--- Configuration
    int L_max;
    int Dim;
    double Sigma;
    int string_head; // Range for the random walk
    std::vector<int> string;
    int length_string;
    int complete_length_string; // Total length of the random walk
    
    // std::unordered_set<std::array<int, 2>, ArrayHash> visited; // Store visited positionsZ
    BitArray visited_bit; // BitArray to track visited positions

    //--- Basic Observables


public:
std::string infoConfig()
{
    return 
        "====================\n"
        "This program simulates the random walk model.\n"
        "====================\n";
};


    Configuration(Clock& _ck, IOControl& _io, RandomNumGen& rn, Parameter& _para, Observable& _obs, Histogram& _his);
    void initialConf();
    void initialMeas();
    void initialObsr();

    void updateCnf();
    bool measureOrNot();
    void measure();
    void writeCnf();

    void printConfig(int _index);
    void squarePrint();
    // void corrFunPrint();

    void checkCnf();
    
    // Update Algorithm
    void RandomWalk(); 
    void LERW_v2();
    void LERW_LR();

};
