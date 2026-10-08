
#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H

    class Die {
    private:
        int m_dievalue;
    public:
        Die();
        void rollDie();
        int getDieValue() const;
    };



#endif //PIGDICE_DIE_H
