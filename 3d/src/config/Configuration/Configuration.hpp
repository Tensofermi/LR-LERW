#pragma once
#include <bits/stdc++.h>
#include "../../system/Header.hpp"
#include "Algorithm/BitArray.hpp"
#include <array>
#include <functional>
#include <climits>

struct ArrayHash {
    size_t operator()(const std::array<int, 3>& a) const {
        size_t seed = std::hash<int>{}(a[0]);
        seed ^= std::hash<int>{}(a[1]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<int>{}(a[2]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};


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
    std::array<int, 3> string_head; // Range for the random walk
    std::vector<std::array<int, 3>> string;
    int length_string;
    int complete_length_string; // Total length of the random walk
    
    std::unordered_set<std::array<int, 3>, ArrayHash> visited; // Store visited positions
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

    void randSphere(std::vector<double>& dx);
    // Update Algorithm
    void RandomWalk(); 
    void LERW();
    void LERW_v2();
    void LERW_LR();

};
