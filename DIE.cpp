#include <random>
#include "DIE.h"
Die::Die() {
    m_dievalue = 0;
}

void Die::rollDie() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 6);
    m_dievalue = dis(gen);
}
int Die::getDieValue() const {
    return m_dievalue;
}