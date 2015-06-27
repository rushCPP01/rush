#ifndef OSTATS_HPP
#define OSTATS_HPP
#include <deque>
#include "ODatas.hpp"

class Ostats
{
    public:
        Ostats(void);
        Ostats(unsigned int size);
        void setSize(unsigned int n);
        unsigned int getSize(void);
        void statsRefresh(void);
        ~Ostats(void);

    protected:
        std::deque<ODatas> m_datas;
        unsigned int m_maxsize;

    private:
        Ostats(Ostats const & src);
        Ostats& operator=(Ostats const & rhs);
};
#endif