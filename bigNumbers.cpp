#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::ostream;
using std::string;
using std::vector;

const int DOTS(3);

int charToInt(char c);
char intToChar(int i);

class BigNumber {
    private:
        vector<int> data;
        int size;
    public:
        BigNumber() : data(), size(0) {};
        BigNumber(string s);
        BigNumber(const BigNumber& bn);
        ~BigNumber() {};
        friend ostream& operator <<(ostream& outs, const BigNumber& bn);
        friend BigNumber addNumbers(const BigNumber& numberA, const BigNumber& numberB);
        void reverse();
};

//Parametrized constructror that takes a string to represent the number.
BigNumber::BigNumber(string s) {
    size = s.length();
    data.reserve(size);
    for(auto & c : s) {
        data.push_back(charToInt(c));
    }
}

//Copy constructor.
BigNumber::BigNumber(const BigNumber& bn) {
    data.reserve(bn.size);
    for(int i = 0; i < bn.size; i++) {
        data.push_back(bn.data[i]);
    }
}

//Overloading << to diplay the number with dots.
ostream& operator <<(ostream& outs, const BigNumber& bn) {
    int dotCount = DOTS - (bn.size % DOTS);
    if (dotCount == DOTS) {
        dotCount = 0;
    }
    for(int i = 0; i < bn.size; i++) {
        if(dotCount == DOTS) {
            outs << ".";
            dotCount = 0;
        }
        outs << bn.data[i];
        dotCount ++;
    }
    return outs;
}

void BigNumber::reverse() {
    vector<int> temp;
    temp.reserve(size);
    for(int i = size - 1; i >= 0; i--) {
        temp[i] = data[size - i - 1];
    }
    for(int i = 0; i < size; i++) {
        data[i] = temp[i];
    }
}

//Function to add two big numbers together.
BigNumber addNumbers(const BigNumber& numberA, const BigNumber& numberB) {
    int report(0);
    string temp;
    BigNumber result;
    //Initialize numbers to iterate.
    int endA = numberA.size - 1;
    int endB = numberB.size - 1;
    while(endA >= 0 && endB >= 0) {
        int current = report + numberA.data[endA] + numberB.data[endB];
        if(current >= 10) {
            current = current % 10;
            report = 1;
        } else report = 0;
        result.data.push_back(current);
        result.size ++;
        endA --;
        endB --;
    }
    while(endA >= 0) {
        int current = report + numberA.data[endA];
        if(current >= 10) {
            current = current % 10;
            report = 1;
        } else report = 0;
        result.data.push_back(current);
        result.size ++;
        endA --;
    }
    while(endB >= 0) {
        int current = report + numberB.data[endB];
        if(current >= 10) {
            current = current % 10;
            report = 1;
        } else report = 0;
        result.data.push_back(current);
        result.size ++;
        endB --;
    }
    if(report == 1) {
        result.data.push_back(1);
        result.size ++;
    }
    result.reverse();
    return result;
}

int main() {
    vector<int> test;
    BigNumber bn1("123467812312831902397162497128937918249081273123");
    BigNumber bn2("12381023801270912830128300019280");
    BigNumber bn3 = addNumbers(bn1, bn2);
    cout << bn3 << "\n";
    return 0;
}

int charToInt(char c) {
    return c - '0';
}

char intToChar(int i) {
    return i + '0';
}

//123467812312831902397162497128937918249081273123 + 12381023801270912830128300019280 = 123.467.812.312.831.914.778.186.298.399.850.748.377.381.292.403