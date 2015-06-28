#ifndef A_DATAS_HPP
#define A_DATAS_HPP
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "OStats.hpp"
#include "IMonitorModule.hpp"

#define CGREEN 39, 174, 96
#define CRED 192, 57, 43
#define CORANGE 230, 126, 34
#define CBLUE 41, 128, 185
#define CYELLOW 241, 196, 15
#define CMAGENTA 142, 68, 173
#define CGREY 127, 140, 141

class ADatas: public IMonitorModule
{
public:
	ADatas(OStats& datas);
	void				refreshDatas(void);
	void				setInterval(unsigned int n);
	unsigned int 			getInterval(void);
	std::string const &		getHostname(void);
	std::string const &		getUsername(void);
	std::string const &		getSysname(void);
	std::string const &		getRelease(void);
	std::string const &		getVersion(void);
	std::string const &		getMachine(void);
	std::string const &		getTime(void);
	std::string	getProcessString(void);
	std::string getLoadAvgString(void);
	std::string getCPUsageString(void);
	virtual ~ADatas(void);
	OStats& m_stats;
	sf::RenderWindow 		*window;
	sf::ContextSettings 	settings;
	sf::Font 				font;

private:	
	ADatas(void);
	ADatas& operator=(ADatas const & rhs);
	ADatas(ADatas const & src);
};
#endif