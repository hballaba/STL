#include <iostream>
#include "map.hpp"
#include <map>


# define G "\e[92m\e[1m"
# define D "\e[39m\e[0m"
# define R "\e[91m"
# define Y "\e[93m"

int     main() {
	try {
//			/****** CONSTRUCTOR  ********/
//				std::cout << G "CONSTRUCTOR\n" D;
//			{
//				std::cout << Y "My constructor\n" D;
//
//				ft::map<int, int> myMap;
//				std::cout << "MyMap size = " << myMap.size() << "\n";
//
//				std::pair<ft::map<int,int>::iterator,bool> ret;
//
//				ret = myMap.insert ( std::pair<int,int>(8,10) );
//				std::cout << "Key = " << ret.first->first << " ,";
//				std::cout << "value = " << ret.first->second << "\n";
//				std::cout << "New key = " << ret.second << "\n";
//
//
//				ret = myMap.insert ( std::pair<int,int>(8,20) );
//
//				std::cout << "Key = " << ret.first->first << " ,";
//				std::cout << "value = " << ret.first->second << "\n";
//				std::cout << "New key = " << ret.second << "\n";
//				std::cout << "MyMap size after two insert= " << myMap.size() << "\n";
//
//				myMap.insert ( std::pair<int,int>(9,2) );
//				myMap.insert ( std::pair<int,int>(10,6) );
//				myMap.insert ( std::pair<int,int>(11,7) );
//				myMap.insert ( std::pair<int,int>(24,8) );
//				myMap.insert ( std::pair<int,int>(13,12) );
//				myMap.insert ( std::pair<int,int>(14,15) );
//
//
//				ft::map<int,int>::iterator myIT1 = myMap.begin();
//				ft::map<int,int>::iterator myIT2 = myMap.end();
//				int i = 0;
//				while (myIT1 != myIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << myIT1->first << " ";
//					std::cout << "Value = " << myIT1->second << "\n";
//					myIT1++;
//				}
//				std::cout << "MyMap size = " << myMap.size() << "\n";
//
//				myIT1 = myMap.begin();
//				myIT1++;
//				myIT1++;
//				myIT1++;
//
//				ft::map<int,int> myMap2(myIT1, myIT2);
//
//				std::cout << "\nConstruct with iterator\n";
//				myIT1 = myMap2.begin();
//				myIT2 = myMap2.end();
//				i = 0;
//				while (myIT1 != myIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << myIT1->first << " ";
//					std::cout << "Value = " << myIT1->second << "\n";
//					myIT1++;
//				}
//				std::cout << "MyMap2 size = " << myMap2.size() << "\n";
//
//				std::cout << "\nConstruct copy\n";
//				myMap2.insert ( std::pair<int,int>(77,88) );
//				ft::map<int,int> myMap3(myMap2);
//				myIT1 = myMap3.begin();
//				myIT2 = myMap3.end();
//				i = 0;
//
//				while (myIT1 != myIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << myIT1->first << " ";
//					std::cout << "Value = " << myIT1->second << "\n";
//					myIT1++;
//				}
//				std::cout << "MyMap3 size = " << myMap3.size() << "\n";
//
//				std::cout << "\nOperator =\n";
//				myMap2.insert ( std::pair<int,int>(-1111111111,-1111111111) );
//				myMap2.insert ( std::pair<int,int>(1111111111,1111111111) );
//
//				ft::map<int,int> myMap4;
//				myMap4 = myMap2;
//				myIT1 = myMap4.begin();
//				myIT2 = myMap4.end();
//				i = 0;
//				while (myIT1 != myIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << myIT1->first << " ";
//					std::cout << "Value = " << myIT1->second << "\n";
//					myIT1++;
//				}
//				std::cout << "OrigMap4 size = " << myMap4.size() << "\n";
//
//
//
//				std::cout << Y "\nOriginal constructor\n" D;
//
//
//				std::map<int, int> origMap;
//
//				std::cout << "OrigMap size = " << origMap.size() << "\n";
//				std::pair<std::map<int,int>::iterator,bool> ret1;
//				ret1 = origMap.insert ( std::pair<int,int>(8,10) );
//
//
//				std::cout << "Key = " << ret1.first->first << " ,";
//				std::cout << "value = " << ret1.first->second << "\n";
//				std::cout << "New key = " << ret1.second << "\n";
//
//				ret1 = origMap.insert ( std::pair<int,int>(8,20) );
//				std::cout << "Key = " << ret1.first->first << " ,";
//				std::cout << "value = " << ret1.first->second << "\n";
//				std::cout << "New key = " << ret1.second << "\n";
//				std::cout << "OrigMap size after two insert = " << origMap.size() << "\n";
//
//				origMap.insert ( std::pair<int,int>(9,2));
//				origMap.insert ( std::pair<int,int>(10,6));
//				origMap.insert ( std::pair<int,int>(11,7));
//				origMap.insert ( std::pair<int,int>(24,8));
//				origMap.insert ( std::pair<int,int>(13,12));
//				origMap.insert ( std::pair<int,int>(14,15));
//
//
//				std::map<int,int>::iterator origIT1 = origMap.begin();
//				std::map<int,int>::iterator origIT2 = origMap.end();
//				i = 0;
//				while (origIT1 != origIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << origIT1->first << " ";
//					std::cout << "Value = " << origIT1->second << "\n";
//					origIT1++;
//				}
//				std::cout << "OrigMap size = " << origMap.size() << "\n";
//
//				origIT1 = origMap.begin();
//				origIT1++;
//				origIT1++;
//				origIT1++;
//				std::map<int,int> origMap2(origIT1, origIT2);
//
//				std::cout << "\nConstruct with iterator\n";
//				origIT1 = origMap2.begin();
//				origIT2 = origMap2.end();
//				i = 0;
//				while (origIT1 != origIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << origIT1->first << " ";
//					std::cout << "Value = " << origIT1->second << "\n";
//					origIT1++;
//				}
//				std::cout << "OrigMap2 size = " << origMap2.size() << "\n";
//
//				std::cout << "\nConstruct copy\n";
//				origMap2.insert ( std::pair<int,int>(77,88) );
//				std::map<int,int> origMap3(origMap2);
//				origIT1 = origMap3.begin();
//				origIT2 = origMap3.end();
//				i = 0;
//				while (origIT1 != origIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << origIT1->first << " ";
//					std::cout << "Value = " << origIT1->second << "\n";
//					origIT1++;
//				}
//				std::cout << "OrigMap3 size = " << origMap3.size() << "\n";
//
//				std::cout << "\nOperator =\n";
//				origMap2.insert ( std::pair<int,int>(-1111111111,-1111111111) );
//				origMap2.insert ( std::pair<int,int>(1111111111,1111111111) );
//
//				std::map<int,int> origMap4;
//				origMap4 = origMap2;
//				origIT1 = origMap4.begin();
//				origIT2 = origMap4.end();
//				i = 0;
//				while (origIT1 != origIT2) {
//					i++;
//					std::cout << i <<  " Element: key = " << origIT1->first << " ";
//					std::cout << "Value = " << origIT1->second << "\n";
//					origIT1++;
//				}
//				std::cout << "OrigMap4 size = " << origMap4.size() << "\n";
//			}
//
//		/****** ITERATOR  ********/
//			std::cout << G "ITERATOR\n" D;
//
//		{
//			std::cout << Y "My iterator\n" D;
//
//			ft::map<char, std::string> myMap;
//			myMap.insert(std::pair<char, std::string>('z', "World"));
//			myMap.insert(std::pair<char, std::string>('h', "hello"));
//			myMap.insert(std::pair<char, std::string>('2', "Scool"));
//			myMap.insert(std::pair<char, std::string>('W', "21"));
//
//			ft::map<char, std::string>::iterator myIT1 = myMap.begin();
//			ft::map<char, std::string>::iterator myIT2 = myMap.end();
//			int i = 0;
//			while (myIT1 != myIT2) {
//				i++;
//				std::cout << i << " Element: key = '" << myIT1->first << "' ";
//				std::cout << "Value = " << myIT1->second << "\n";
//				myIT1++;
//			}
//
//			ft::map<char, std::string>::reverse_iterator myITrev = myMap.rbegin();
//			ft::map<char, std::string>::reverse_iterator myITrev2 = myMap.rend();
//			i = 0;
//			std::cout << "\nMy Reverse iterator\n";
//			while (myITrev != myITrev2) {
//				i++;
//				std::cout << i << " Element: key = '" << myITrev->first << "' ";
//				std::cout << "Value = " << myITrev->second << "\n";
//				myITrev++;
//			}
//
//
//			std::cout << Y "Original iterator\n" D;
//
//			std::map<char, std::string> origMap;
//			origMap.insert(std::pair<char, std::string>('z', "World"));
//			origMap.insert(std::pair<char, std::string>('h', "hello"));
//			origMap.insert(std::pair<char, std::string>('2', "Scool"));
//			origMap.insert(std::pair<char, std::string>('W', "21"));
//
//			std::map<char, std::string>::iterator origIT1 = origMap.begin();
//			std::map<char, std::string>::iterator origIT2 = origMap.end();
//			i = 0;
//			while (origIT1 != origIT2) {
//				i++;
//				std::cout << i << " Element: key = '" << origIT1->first << "' ";
//				std::cout << "Value = " << origIT1->second << "\n";
//				origIT1++;
//			}
//
//			std::map<char, std::string>::reverse_iterator origITrev = origMap.rbegin();
//			std::map<char, std::string>::reverse_iterator origITrev2 = origMap.rend();
//			i = 0;
//			std::cout << "\nOriginal Reverse iterator\n";
//			while (origITrev != origITrev2) {
//				i++;
//				std::cout << i << " Element: key = '" << origITrev->first << "' ";
//				std::cout << "Value = " << origITrev->second << "\n";
//				origITrev++;
//			}
//
//
//
//
//			/****** CAPACITY  ********/
//			std::cout << G "\nCAPACITY\n" D;
//
//
//			std::cout << Y "MY capasity\n" D;
//
//			ft::map<char, std::string> newMyMap;
//
//			std::cout << "MyMap empty = " << myMap.empty() << "\n";
//			std::cout << "MyMap size = " << myMap.size() << "\n";
//			std::cout << "newMyMap empty = " << newMyMap.empty() << "\n";
//			std::cout << "newMyMap size = " << newMyMap.size() << "\n";
//			std::cout << "MyMap max_size = " << myMap.max_size() << "\n";
//
//
//			std::cout << Y "Original capasity\n" D;
//
//			std::map<char, std::string> newOrigMap;
//
//			std::cout << "OrigMap empty = " << origMap.empty() << "\n";
//			std::cout << "OrigMap size = " << origMap.size() << "\n";
//			std::cout << "newOrigMap empty = " << newOrigMap.empty() << "\n";
//			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
//			std::cout << "OrigMap max_size = " << origMap.max_size() << "\n";
//
//
//			/****** ELEMENT ACCESS  ********/
//			std::cout << G "\nELEMENT ACCESS\n" D;
//
//
//			std::cout << Y "My element access:\n" D;
//
//			newMyMap['c'] = "First element";
//			std::cout << "Value with key |c| = \"" << newMyMap['c'] << "\"\n";
//			std::cout << "newMyMap size = " << newMyMap.size() << "\n";
//			std::cout << "Value with key |d| = \"" << newMyMap['d'] << "\"\n";
//			std::cout << "newMyMap size = " << newMyMap.size() << "\n";
//
//
//			std::cout << Y "Original element access:\n" D;
//
//			newOrigMap['c'] = "First element";
//			std::cout << "Value with key |c| = \"" << newOrigMap['c'] << "\"\n";
//			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
//			std::cout << "Value with key |d| = \"" << newOrigMap['d'] << "\"\n";
//			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
//		}
//
//
//			/********* MODIFIERS  **************/
//		{
//
//			std::cout << G "\nMODIFIERS\n" D;
//			std::cout << G "Insert:\n" D;
//			std::cout << Y "My insert:\n" D;
//
//
//
//			int i = 1;
//			ft::map<char, float> myMap;
//
//			myMap.insert(std::pair<char, float>('a', 11.11));
//			myMap.insert(std::pair<char, float>('b', 22.22));
//			std::cout << "OrigMap size after insert pair = " << myMap.size() << "\n";
//			ft::map<char, float>::iterator myIT = myMap.begin();
//			i = 1;
//			while (myIT != myMap.end()) {
//				std::cout << i << " Element: key = '" << myIT->first << "' ";
//				std::cout << "Value = " << myIT->second << "\n";
//				myIT++;
//				i++;
//			}
//
//			myMap.insert(std::pair<char, float>('3', 33.33));
//			myMap.insert(std::pair<char, float>('4', 44.44));
//			myMap.insert(std::pair<char, float>('*', 999999999.999999999));
//			myIT = myMap.begin();
//			i = 1;
//			std::cout << "\nOrigMap size after inset with position = " << myMap.size() << "\n";
//			while (myIT != myMap.end()) {
//				std::cout << i << " Element: key = '" << myIT->first << "' ";
//				std::cout << "Value = " << myIT->second << "\n";
//				myIT++;
//				i++;
//			}
//
//			ft::map<char, float> myMap2;
//			myMap2.insert(std::pair<char, float>('A', -555.555));
//			myIT = myMap.begin();
//			myIT++;
//
//			myMap2.insert(myIT, myMap.end());
//			myIT = myMap2.begin();
//			i = 1;
//			std::cout << "\nOrigMap2 size after inset with iterators = " << myMap2.size() << "\n";
//			while (myIT != myMap2.end()) {
//				std::cout << i << " Element: key = '" << myIT->first << "' ";
//				std::cout << "Value = " << myIT->second << "\n";
//				myIT++;
//				i++;
//			}
//
//			std::cout << Y "Original insert:\n" D;
//
//			std::map<char, float> origMap;
//
//			origMap.insert(std::pair<char, float>('a', 11.11));
//			origMap.insert(std::pair<char, float>('b', 22.22));
//			std::cout << "OrigMap size after insert pair = " << origMap.size() << "\n";
//			std::map<char, float>::iterator origIT = origMap.begin();
//			i = 1;
//			while (origIT != origMap.end()) {
//				std::cout << i << " Element: key = '" << origIT->first << "' ";
//				std::cout << "Value = " << origIT->second << "\n";
//				origIT++;
//				i++;
//			}
//
//			origMap.insert(std::pair<char, float>('3', 33.33));
//			origMap.insert(std::pair<char, float>('4', 44.44));
//			origMap.insert(std::pair<char, float>('*', 999999999.999999999));
//			origIT = origMap.begin();
//			i = 1;
//			std::cout << "\nOrigMap size after inset with position = " << origMap.size() << "\n";
//			while (origIT != origMap.end()) {
//				std::cout << i << " Element: key = '" << origIT->first << "' ";
//				std::cout << "Value = " << origIT->second << "\n";
//				origIT++;
//				i++;
//			}
//
//			std::map<char, float> origMap2;
//			origMap2.insert(std::pair<char, float>('A', -555.555));
//			origIT = origMap.begin();
//			origIT++;
//
//			origMap2.insert(origIT, origMap.end());
//			origIT = origMap2.begin();
//			i = 1;
//			std::cout << "\nOrigMap2 size after inset with iterators = " << origMap2.size() << "\n";
//			while (origIT != origMap2.end()) {
//				std::cout << i << " Element: key = '" << origIT->first << "' ";
//				std::cout << "Value = " << origIT->second << "\n";
//				origIT++;
//				i++;
//			}


			std::cout << Y "my erase:\n" D;
			/****** erase  posision ***/

			int i;
			ft::map<int, int> er;
			for (i = 1; i <= 559; i++ )
				er[i] = 0;
			i = 0;

			ft::map<int, int>::iterator it = er.begin();

			for (int a = 1; a != 4; a++)
				it++;
			std::cout << "Key = '" << it->first << "' \n";

			er.erase(it);

			it = er.begin();
			for (size_t a = 0; a < er.size(); a++) {
				std::cout << ++i << " Element: key = '" << it->first << "' \n";
				it++;
			}

		std::cout << "\n";






			/********* erase key  ***********/
//			for (size_t a = 0; a < er.size(); a=a) {
//				it = er.begin();
//				std::cout << ++i << " Element: key = '" << it->first << "' \n";
//				er.erase(er.begin());
//			}


//			it = er.begin();
//			it++;
//			it++;
//			it++;
//			it++;
//			it++;
//		std::cout << "\n";
//
//			er.erase(5);
//			it = er.begin();
//			i = 0;
//			for (size_t a = 0; a < er.size(); a++) {
//				std::cout << ++i << " Element: key --= '" << it->first << "' \n";
//				it++;
//			}
//		std::cout << "\n";


			/***** erase iterators ****/
//		it = er.begin();
//		it++;
//		it++;
//		it++;
//		er.erase(it, er.end());
//
//		it = er.begin();
//		i = 0;
//		for (size_t a = 0; a < er.size(); a++) {
//			std::cout << ++i << " Element: key --= '" << it->first << "' \n";
//			it++;
//		}
//		std::cout << "\n";


			std::map<int, int> er1;
			er1[1] = 1;
			er1[2] = 2;
			er1[3] = 3;
			er1[4] = 4;
			er1[5] = 5;
			er1[6] = 6;
			er1[7] = 7;
			er1[8] = 7;
			er1[9] = 7;
			er1[10] = 7;
			er1[11] = 7;
//			er1[12] = 7;
//			er1[13] = 7;

//			std::map<int, int>::iterator it1 = er1.begin();
//			it1++;
//			it1++;
//			it1++;
//			it1++;
//			it1++;
//
//			er1.erase(it1);
//			it1 = er1.begin();
//			i = 0;
//			while (it1 != er1.end()) {
//				std::cout << ++i << " Element: key = '" << it1->first << "' ";
//				std::cout << "Value = " << it1->second << "\n";
//				it1++;
//			}




//			myMap2.erase(myMap2.begin());
//			myMap2.erase(myMap2.begin());
//			myIT = myMap2.begin();
//			i = 1;
//			std::cout << "\nMyMap2 size after erase position = " << myMap2.size() << "\n";
//			while (myIT != myMap2.end()) {
//				std::cout << i << " Element: key = '" << myIT->first << "' ";
//				std::cout << "Value = " << myIT->second << "\n";
//				myIT++;
//				i++;
//			}


//			std::cout << Y "Original erase:\n" D;
//
//
//			origMap2.erase(origMap2.begin());
//			origMap2.erase(origMap2.begin());
//			origIT = origMap2.begin();
//			i = 1;
//			std::cout << "\nOrigMap2 size after erase position = " << origMap2.size() << "\n";
//			while (origIT != origMap2.end()) {
//				std::cout << i << " Element: key = '" << origIT->first << "' ";
//				std::cout << "Value = " << origIT->second << "\n";
//				origIT++;
//				i++;
//			}





			/****** OPERATION  ********/
//			std::cout << G "\nOPERATION\n" D;
//
//			std::cout << Y "My find:\n" D;
//
//			myIT1 = myMap.find('2');
//			std::cout << " Element: key = '" << myIT1->first << "' ";
//			std::cout << "Value = " << myIT1->second << "\n";
//			myIT1++;
//			std::cout << " Element: key = '" << myIT1->first << "' ";
//			std::cout << "Value = " << myIT1->second << "\n";
//
//
//
//			std::cout << Y "Original find:\n" D;
//
//			origIT1 = origMap.find('2');
//			std::cout << " Element: key = '" << origIT1->first << "' ";
//			std::cout << "Value = " << origIT1->second << "\n";
//			origIT1++;
//			std::cout << " Element: key = '" << origIT1->first << "' ";
//			std::cout << "Value = " << origIT1->second << "\n";

//		}


		}
		catch(const char * e)
		{
			std::cerr << e << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
//	std::cout << Y"Now you can check memory leaks, with leaks a.out in other terminal" << D"\n";
//	std::cout << G"To exit press Enter" << D"\n";
//	getchar();
//	std::cout << G"Good bye" << D"\n";
		return 0;
	}

