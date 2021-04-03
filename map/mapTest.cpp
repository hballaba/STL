#include <iostream>
#include "map.hpp"
#include <map>


# define G "\e[92m\e[1m"
# define D "\e[39m\e[0m"
# define R "\e[91m"
# define Y "\e[93m"

int     main() {
	try {
			/****** CONSTRUCTOR  ********/
			{
				std::cout << Y "My constructor\n" D;

				ft::map<int, int> myMap;
				std::cout << "MyMap size = " << myMap.size() << "\n";

				std::cout << "MyMap max_size = " << myMap.max_size() << "\n";
				std::pair<ft::map<int,int>::iterator,bool> ret;
				ret = myMap.insert ( std::pair<int,int>(10,10) );
				ret = myMap.insert ( std::pair<int,int>(2,2) );
				ret = myMap.insert ( std::pair<int,int>(6,6) );
				ret = myMap.insert ( std::pair<int,int>(7,7) );
				ret = myMap.insert ( std::pair<int,int>(8,8) );
				ret = myMap.insert ( std::pair<int,int>(12,12) );
				ret = myMap.insert ( std::pair<int,int>(15,15) );



				std::cout << Y "Original constructor\n" D;

				std::map<int, int> origMap;

				std::cout << "OrigMap size = " << origMap.size() << "\n";
				std::cout << "OrigMap max_size = " << origMap.max_size() << "\n";

				std::pair<std::map<int,int>::iterator,bool> ret1;
				ret1 = origMap.insert ( std::pair<int,int>(3,300) );
				ret1 = origMap.insert ( std::pair<int,int>(1,200) );
				ret1 = origMap.insert ( std::pair<int,int>(1,100) );

				std::cout << "OrigMap size = " << origMap.size() << "\n";




			}
		}
		catch(const char * e)
		{
			std::cerr << e << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return 0;
	}

