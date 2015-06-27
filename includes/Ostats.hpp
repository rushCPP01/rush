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
        unsigned int getMaxSize(void);
        void statsRefresh(void);
        ~OStats(void);
        std::deque<ODatas> m_datas;

    protected:
        unsigned int m_maxsize;

    private:
        OStats(OStats const & src);
        OStats& operator=(OStats const & rhs);
};
#endif
