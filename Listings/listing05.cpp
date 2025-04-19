#include "funAndProfit.hpp"

FunAndProfit::FunAndProfit() : gain(0.0f) {}

void FunAndProfit::fun() {  // public method
    gain += Profit();
}

float FunAndProfit::getGain() const { return gain; }

float FunAndProfit::profit() {  // private method
    return 1000000.0f;
}
