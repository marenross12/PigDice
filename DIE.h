//
// Created by rossmn on 9/29/2026.
//

#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H



    class Die {
    private:
        int m_value;
        int m_numSides;
    public:
        Die();
        void setNumSides(int numSides); //you can set to values 4, 6, or 8
        int getNumSides();
        void setValue();
        int getValue();
    };



#endif //PIGDICE_DIE_H
