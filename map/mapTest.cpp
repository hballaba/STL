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
				std::cout << G "CONSTRUCTOR\n" D;
			{
				std::cout << Y "My constructor\n" D;

				ft::map<int, int> myMap;
				std::cout << "MyMap size = " << myMap.size() << "\n";

				std::pair<ft::map<int,int>::iterator,bool> ret;

				ret = myMap.insert ( std::pair<int,int>(8,10) );
				std::cout << "Key = " << ret.first->first << " ,";
				std::cout << "value = " << ret.first->second << "\n";
				std::cout << "New key = " << ret.second << "\n";


				ret = myMap.insert ( std::pair<int,int>(8,20) );

				std::cout << "Key = " << ret.first->first << " ,";
				std::cout << "value = " << ret.first->second << "\n";
				std::cout << "New key = " << ret.second << "\n";
				std::cout << "MyMap size after two insert= " << myMap.size() << "\n";

				myMap.insert ( std::pair<int,int>(9,2) );
				myMap.insert ( std::pair<int,int>(10,6) );
				myMap.insert ( std::pair<int,int>(11,7) );
				myMap.insert ( std::pair<int,int>(24,8) );
				myMap.insert ( std::pair<int,int>(13,12) );
				myMap.insert ( std::pair<int,int>(14,15) );


				ft::map<int,int>::iterator myIT1 = myMap.begin();
				ft::map<int,int>::iterator myIT2 = myMap.end();
				int i = 0;
				while (myIT1 != myIT2) {
					i++;
					std::cout << i <<  " Element: key = " << myIT1->first << " ";
					std::cout << "Value = " << myIT1->second << "\n";
					myIT1++;
				}
				std::cout << "MyMap size = " << myMap.size() << "\n";

				myIT1 = myMap.begin();
				myIT1++;
				myIT1++;
				myIT1++;

				ft::map<int,int> myMap2(myIT1, myIT2);

				std::cout << "\nConstruct with iterator\n";
				myIT1 = myMap2.begin();
				myIT2 = myMap2.end();
				i = 0;
				while (myIT1 != myIT2) {
					i++;
					std::cout << i <<  " Element: key = " << myIT1->first << " ";
					std::cout << "Value = " << myIT1->second << "\n";
					myIT1++;
				}
				std::cout << "MyMap2 size = " << myMap2.size() << "\n";

				std::cout << "\nConstruct copy\n";
				myMap2.insert ( std::pair<int,int>(77,88) );
				ft::map<int,int> myMap3(myMap2);
				myIT1 = myMap3.begin();
				myIT2 = myMap3.end();
				i = 0;

				while (myIT1 != myIT2) {
					i++;
					std::cout << i <<  " Element: key = " << myIT1->first << " ";
					std::cout << "Value = " << myIT1->second << "\n";
					myIT1++;
				}
				std::cout << "MyMap3 size = " << myMap3.size() << "\n";

				std::cout << "\nOperator =\n";
				myMap2.insert ( std::pair<int,int>(-111111111111,-111111111111) );
				myMap2.insert ( std::pair<int,int>(111111111111,111111111111) );

				ft::map<int,int> myMap4;
				myMap4 = myMap2;
				myIT1 = myMap4.begin();
				myIT2 = myMap4.end();
				i = 0;
				while (myIT1 != myIT2) {
					i++;
					std::cout << i <<  " Element: key = " << myIT1->first << " ";
					std::cout << "Value = " << myIT1->second << "\n";
					myIT1++;
				}
				std::cout << "OrigMap4 size = " << myMap4.size() << "\n";



				std::cout << Y "\nOriginal constructor\n" D;


				std::map<int, int> origMap;

				std::cout << "OrigMap size = " << origMap.size() << "\n";
				std::pair<std::map<int,int>::iterator,bool> ret1;
				ret1 = origMap.insert ( std::pair<int,int>(8,10) );


				std::cout << "Key = " << ret1.first->first << " ,";
				std::cout << "value = " << ret1.first->second << "\n";
				std::cout << "New key = " << ret1.second << "\n";

				ret1 = origMap.insert ( std::pair<int,int>(8,20) );
				std::cout << "Key = " << ret1.first->first << " ,";
				std::cout << "value = " << ret1.first->second << "\n";
				std::cout << "New key = " << ret1.second << "\n";
				std::cout << "OrigMap size after two insert = " << origMap.size() << "\n";

				origMap.insert ( std::pair<int,int>(9,2));
				origMap.insert ( std::pair<int,int>(10,6));
				origMap.insert ( std::pair<int,int>(11,7));
				origMap.insert ( std::pair<int,int>(24,8));
				origMap.insert ( std::pair<int,int>(13,12));
				origMap.insert ( std::pair<int,int>(14,15));


				std::map<int,int>::iterator origIT1 = origMap.begin();
				std::map<int,int>::iterator origIT2 = origMap.end();
				i = 0;
				while (origIT1 != origIT2) {
					i++;
					std::cout << i <<  " Element: key = " << origIT1->first << " ";
					std::cout << "Value = " << origIT1->second << "\n";
					origIT1++;
				}
				std::cout << "OrigMap size = " << origMap.size() << "\n";

				origIT1 = origMap.begin();
				origIT1++;
				origIT1++;
				origIT1++;
				std::map<int,int> origMap2(origIT1, origIT2);

				std::cout << "\nConstruct with iterator\n";
				origIT1 = origMap2.begin();
				origIT2 = origMap2.end();
				i = 0;
				while (origIT1 != origIT2) {
					i++;
					std::cout << i <<  " Element: key = " << origIT1->first << " ";
					std::cout << "Value = " << origIT1->second << "\n";
					origIT1++;
				}
				std::cout << "OrigMap2 size = " << origMap2.size() << "\n";

				std::cout << "\nConstruct copy\n";
				origMap2.insert ( std::pair<int,int>(77,88) );
				std::map<int,int> origMap3(origMap2);
				origIT1 = origMap3.begin();
				origIT2 = origMap3.end();
				i = 0;
				while (origIT1 != origIT2) {
					i++;
					std::cout << i <<  " Element: key = " << origIT1->first << " ";
					std::cout << "Value = " << origIT1->second << "\n";
					origIT1++;
				}
				std::cout << "OrigMap3 size = " << origMap3.size() << "\n";

				std::cout << "\nOperator =\n";
				origMap2.insert ( std::pair<int,int>(-111111111111,-111111111111) );
				origMap2.insert ( std::pair<int,int>(111111111111,111111111111) );

				std::map<int,int> origMap4;
				origMap4 = origMap2;
				origIT1 = origMap4.begin();
				origIT2 = origMap4.end();
				i = 0;
				while (origIT1 != origIT2) {
					i++;
					std::cout << i <<  " Element: key = " << origIT1->first << " ";
					std::cout << "Value = " << origIT1->second << "\n";
					origIT1++;
				}
				std::cout << "OrigMap4 size = " << origMap4.size() << "\n";
			}

		/****** ITERATOR  ********/
			std::cout << G "ITERATOR\n" D;

		{
			std::cout << Y "My iterator\n" D;

			ft::map<char, std::string> myMap;
			myMap.insert ( std::pair<char,std::string>('z',"World"));
			myMap.insert ( std::pair<char,std::string>('h',"hello"));
			myMap.insert ( std::pair<char,std::string>('2',"Scool"));
			myMap.insert ( std::pair<char,std::string>('W',"21"));

			ft::map<char, std::string>::iterator myIT1 = myMap.begin();
			ft::map<char, std::string>::iterator myIT2 = myMap.end();
			int i = 0;
			while (myIT1 != myIT2) {
				i++;
				std::cout << i <<  " Element: key = '" << myIT1->first << "' ";
				std::cout << "Value = " << myIT1->second << "\n";
				myIT1++;
			}




			std::cout << Y "Original iterator\n" D;

			std::map<char, std::string> origMap;
			origMap.insert ( std::pair<char,std::string>('z',"World"));
			origMap.insert ( std::pair<char,std::string>('h',"hello"));
			origMap.insert ( std::pair<char,std::string>('2',"Scool"));
			origMap.insert ( std::pair<char,std::string>('W',"21"));

			std::map<char, std::string>::iterator origIT1 = origMap.begin();
			std::map<char, std::string>::iterator origIT2 = origMap.end();
			i = 0;
			while (origIT1 != origIT2) {
				i++;
				std::cout << i <<  " Element: key = '" << origIT1->first << "' ";
				std::cout << "Value = " << origIT1->second << "\n";
				origIT1++;
			}

			std::cout << Y "Original reverse iterator\n" D;


			/****** CAPACITY  ********/
			std::cout << G "\nCAPACITY\n" D;


			std::cout << Y "MY capasity\n" D;

			ft::map<char, std::string> newMyMap;

			std::cout << "MyMap empty = " << origMap.empty() << "\n";
			std::cout << "MyMap size = " << origMap.size() << "\n";
			std::cout << "newMyMap empty = " << newMyMap.empty() << "\n";
			std::cout << "newMyMap size = " << newMyMap.size() << "\n";
			std::cout << "MyMap max_size = " << origMap.max_size() << "\n";


			std::cout << Y "Ogiginal capasity\n" D;

			std::map<char, std::string> newOrigMap;

			std::cout << "OrigMap empty = " << origMap.empty() << "\n";
			std::cout << "OrigMap size = " << origMap.size() << "\n";
			std::cout << "newOrigMap empty = " << newOrigMap.empty() << "\n";
			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
			std::cout << "OrigMap max_size = " << origMap.max_size() << "\n";


			/****** ELEMENT ACCESS  ********/
			std::cout << G "\nELEMENT ACCESS\n" D;




			std::cout << Y "Ogiginal element access:\n" D;

			newOrigMap['c'] = "First element";
			std::cout << "Value with key |c| = \"" << newOrigMap['c'] << "\"\n";
			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
			std::cout << "Value with key |d| = \"" << newOrigMap['d'] << "\"\n";
			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";

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
	std::cout << Y"Now you can check memory leaks, with leaks a.out in other terminal" << D"\n";
	std::cout << G"To exit press Enter" << D"\n";
	getchar();
	std::cout << G"Good bye" << D"\n";
		return 0;
	}

