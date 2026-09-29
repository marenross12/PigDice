#include <random>
#include "DIE.h"
Die::Die() {
    m_value = 0;
    m_numSides = 6;
}
void Die::setNumSides(int numSides) {
    switch (numSides) {
        case 4: m_numSides = 4; break;
        case 6: m_numSides = 6; break;
        case 8: m_numSides = 8; break;
        default: m_numSides = 6; break;
    }
    // m_numSides = numSides;
}
int Die::getNumSides() {
    return m_numSides;
}
void Die::setValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, m_numSides);
    m_value = dis(gen);
}
int Die::getValue() {
    return m_value;
}