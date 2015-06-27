#ifndef OSTATS_HPP
#define OSTATS_HPP
#include <deque>
#include "ODatas.hpp"

class OStats
{
    public:
        OStats(void);
        OStats(unsigned int size);
        void setSize(unsigned int n);
        unsigned int getSize(void);
        void statsRefresh(void);
        ~OStats(void);

    protected:
        std::deque<ODatas> m_datas;
        unsigned int m_maxsize;

    private:
        OStats(OStats const & src);
        OStats& operator=(OStats const & rhs);
};
#endif
