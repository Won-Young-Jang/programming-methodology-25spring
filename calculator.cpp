#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if ((b > 0) && (a > std::numeric_limits<int>::max() - b)) {
        throw std::overflow_error("Integer overflow on addition");
    }
    if ((b < 0) && (a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("Integer underflow on addition");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0) && (a > std::numeric_limits<int>::max() + b)) {
        throw std::overflow_error("Integer overflow on subtraction");
    }
    if ((b > 0) && (a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("Integer underflow on subtraction");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            if (a > std::numeric_limits<int>::max() / b) {
                throw std::overflow_error("Integer overflow on multiplication");
            }
        } else if (b < 0) {
            if (b < std::numeric_limits<int>::min() / a) {
                throw std::overflow_error("Integer underflow on multiplication");
            }
        }
    } else if (a < 0) {
        if (b > 0) {
            if (a < std::numeric_limits<int>::min() / b) {
                throw std::overflow_error("Integer underflow on multiplication");
            }
        } else if (b < 0) {
            if (a < std::numeric_limits<int>::max() / b) {
                throw std::overflow_error("Integer overflow on multiplication");
            }
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    // Special case: INT_MIN / -1 causes overflow
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Integer overflow on division");
    }
    return a / b;
}
