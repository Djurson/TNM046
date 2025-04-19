#pragma once  // ensure this header is included at most once

// A class that does nothing much useful
class FunAndProfit {
public:
    FunAndProfit();
    ~FunAndProfit() = default;

    void fun();

    float getGain() const;

private:
    float profit();

    float gain;  // private data member
};
