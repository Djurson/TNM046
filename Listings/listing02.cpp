// A class that does nothing much useful
class FunAndProfit {
public:
    // constructor (initialize gain)
    FunAndProfit() : gain(0.0f) {}

    // constructor with arguments
    FunAndProfit(float funds) : gain(funds) {}

    // default destructor, since it doesn't do anything
    ~FunAndProfit() = default;

    void fun() {  // public method
        gain += Profit();
    }

    float getGain() const { return gain; }

private:
    float profit() {  // private method
        return 1000000.0f;
    }

    float gain;  // private data member
};
