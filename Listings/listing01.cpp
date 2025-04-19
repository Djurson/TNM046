// A class that does nothing much useful
class FunAndProfit {
public:
    void fun() {  // public method
        gain += Profit();
    }

    float getGain() const { return gain; }

private:
    float profit() {  // private method
        return 1000000.0f;
    }

    float gain = 0.0f;  // private data member
};
