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
				std::cout << Y "My default constructor\n" D;

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
					std::cout << ++i <<  " Element: key = " << myIT1->first << " ";
					std::cout << "Value = " << myIT1->second << "\n";
					myIT1++;
				}
				std::cout << "MyMap size = " << myMap.size() << "\n";



				std::cout << Y "\nOriginal default constructor\n" D;


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



				std::cout << Y"\n My construct with iterator\n"D;

				myIT1 = myMap.begin();
				myIT1++;
				myIT1++;
				myIT1++;

				ft::map<int,int> myMap2(myIT1, myIT2);


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



				std::cout << Y"\n Original construct with iterator\n"D;

				origIT1 = origMap.begin();
				origIT1++;
				origIT1++;
				origIT1++;
				std::map<int,int> origMap2(origIT1, origIT2);

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


				std::cout << Y"\nMy construct copy\n"D;

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


				std::cout << Y"\nOriginal construct copy\n"D;
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

				std::cout << Y "\nOperator =\n"D;
				myMap2.insert ( std::pair<int,int>(-1111111111,-1111111111) );
				myMap2.insert ( std::pair<int,int>(1111111111,1111111111) );

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




				std::cout << Y"\nOperator =\n"D;
				origMap2.insert ( std::pair<int,int>(-1111111111,-1111111111) );
				origMap2.insert ( std::pair<int,int>(1111111111,1111111111) );

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
			myMap.insert(std::pair<char, std::string>('z', "World"));
			myMap.insert(std::pair<char, std::string>('h', "hello"));
			myMap.insert(std::pair<char, std::string>('2', "Scool"));
			myMap.insert(std::pair<char, std::string>('W', "21"));

			ft::map<char, std::string>::iterator myIT1 = myMap.begin();
			ft::map<char, std::string>::iterator myIT2 = myMap.end();
			int i = 0;
			while (myIT1 != myIT2) {
				i++;
				std::cout << i << " Element: key = '" << myIT1->first << "' ";
				std::cout << "Value = " << myIT1->second << "\n";
				myIT1++;
			}

			ft::map<char, std::string>::reverse_iterator myITrev = myMap.rbegin();
			ft::map<char, std::string>::reverse_iterator myITrev2 = myMap.rend();
			i = 0;
			std::cout << "\nMy Reverse iterator\n";
			while (myITrev != myITrev2) {
				i++;
				std::cout << i << " Element: key = '" << myITrev->first << "' ";
				std::cout << "Value = " << myITrev->second << "\n";
				myITrev++;
			}


			std::cout << Y "Original iterator\n" D;

			std::map<char, std::string> origMap;
			origMap.insert(std::pair<char, std::string>('z', "World"));
			origMap.insert(std::pair<char, std::string>('h', "hello"));
			origMap.insert(std::pair<char, std::string>('2', "Scool"));
			origMap.insert(std::pair<char, std::string>('W', "21"));

			std::map<char, std::string>::iterator origIT1 = origMap.begin();
			std::map<char, std::string>::iterator origIT2 = origMap.end();
			i = 0;
			while (origIT1 != origIT2) {
				i++;
				std::cout << i << " Element: key = '" << origIT1->first << "' ";
				std::cout << "Value = " << origIT1->second << "\n";
				origIT1++;
			}

			std::map<char, std::string>::reverse_iterator origITrev = origMap.rbegin();
			std::map<char, std::string>::reverse_iterator origITrev2 = origMap.rend();
			i = 0;
			std::cout << "\nOriginal Reverse iterator\n";
			while (origITrev != origITrev2) {
				i++;
				std::cout << i << " Element: key = '" << origITrev->first << "' ";
				std::cout << "Value = " << origITrev->second << "\n";
				origITrev++;
			}




			/****** CAPACITY  ********/
			std::cout << G "\nCAPACITY\n" D;


			std::cout << Y "MY capasity\n" D;

			ft::map<char, std::string> newMyMap;

			std::cout << "MyMap empty = " << myMap.empty() << "\n";
			std::cout << "MyMap size = " << myMap.size() << "\n";
			std::cout << "newMyMap empty = " << newMyMap.empty() << "\n";
			std::cout << "newMyMap size = " << newMyMap.size() << "\n";
			std::cout << "MyMap max_size = " << myMap.max_size() << "\n";


			std::cout << Y "Original capasity\n" D;

			std::map<char, std::string> newOrigMap;

			std::cout << "OrigMap empty = " << origMap.empty() << "\n";
			std::cout << "OrigMap size = " << origMap.size() << "\n";
			std::cout << "newOrigMap empty = " << newOrigMap.empty() << "\n";
			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
			std::cout << "OrigMap max_size = " << origMap.max_size() << "\n";


			/****** ELEMENT ACCESS  ********/
			std::cout << G "\nELEMENT ACCESS\n" D;


			std::cout << Y "My element access:\n" D;

			newMyMap['c'] = "First element";
			std::cout << "Value with key |c| = \"" << newMyMap['c'] << "\"\n";
			std::cout << "newMyMap size = " << newMyMap.size() << "\n";
			std::cout << "Value with key |d| = \"" << newMyMap['d'] << "\"\n";
			std::cout << "newMyMap size = " << newMyMap.size() << "\n";


			std::cout << Y "Original element access:\n" D;

			newOrigMap['c'] = "First element";
			std::cout << "Value with key |c| = \"" << newOrigMap['c'] << "\"\n";
			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
			std::cout << "Value with key |d| = \"" << newOrigMap['d'] << "\"\n";
			std::cout << "newOrigMap size = " << newOrigMap.size() << "\n";
		}


			/********* MODIFIERS  **************/
		{

			std::cout << G "\nMODIFIERS\n" D;
			std::cout << G "Insert:\n" D;
			std::cout << Y "My insert:\n" D;


			int i = 1;
			ft::map<char, float> myMap;

			myMap.insert(std::pair<char, float>('a', 11.11));
			myMap.insert(std::pair<char, float>('b', 22.22));
			std::cout << "myMap size after insert pair = " << myMap.size() << "\n";
			ft::map<char, float>::iterator myIT = myMap.begin();
			i = 1;
			while (myIT != myMap.end()) {
				std::cout << i << " Element: key = '" << myIT->first << "' ";
				std::cout << "Value = " << myIT->second << "\n";
				myIT++;
				i++;
			}

			myMap.insert(std::pair<char, float>('3', 33.33));
			myMap.insert(std::pair<char, float>('4', 44.44));
			myMap.insert(std::pair<char, float>('*', 999999999.999999999));
			myIT = myMap.begin();
			i = 1;
			std::cout << "\nmyMap size after inset with position = " << myMap.size() << "\n";
			while (myIT != myMap.end()) {
				std::cout << i << " Element: key = '" << myIT->first << "' ";
				std::cout << "Value = " << myIT->second << "\n";
				myIT++;
				i++;
			}

			ft::map<char, float> myMap2;
			myMap2.insert(std::pair<char, float>('A', -555.555));
			myIT = myMap.begin();
			myIT++;

			myMap2.insert(myIT, myMap.end());
			myIT = myMap2.begin();
			i = 1;
			std::cout << "\nmyMap2 size after inset with iterators = " << myMap2.size() << "\n";
			while (myIT != myMap2.end()) {
				std::cout << i << " Element: key = '" << myIT->first << "' ";
				std::cout << "Value = " << myIT->second << "\n";
				myIT++;
				i++;
			}

			std::cout << Y "Original insert:\n" D;

			std::map<char, float> origMap;

			origMap.insert(std::pair<char, float>('a', 11.11));
			origMap.insert(std::pair<char, float>('b', 22.22));
			std::cout << "OrigMap size after insert pair = " << origMap.size() << "\n";
			std::map<char, float>::iterator origIT = origMap.begin();
			i = 1;
			while (origIT != origMap.end()) {
				std::cout << i << " Element: key = '" << origIT->first << "' ";
				std::cout << "Value = " << origIT->second << "\n";
				origIT++;
				i++;
			}

			origMap.insert(std::pair<char, float>('3', 33.33));
			origMap.insert(std::pair<char, float>('4', 44.44));
			origMap.insert(std::pair<char, float>('*', 999999999.999999999));
			origIT = origMap.begin();
			i = 1;
			std::cout << "\nOrigMap size after inset with position = " << origMap.size() << "\n";
			while (origIT != origMap.end()) {
				std::cout << i << " Element: key = '" << origIT->first << "' ";
				std::cout << "Value = " << origIT->second << "\n";
				origIT++;
				i++;
			}

			std::map<char, float> origMap2;
			origMap2.insert(std::pair<char, float>('A', -555.555));
			origIT = origMap.begin();
			origIT++;

			origMap2.insert(origIT, origMap.end());
			origIT = origMap2.begin();
			i = 1;
			std::cout << "\nOrigMap2 size after inset with iterators = " << origMap2.size() << "\n";
			while (origIT != origMap2.end()) {
				std::cout << i << " Element: key = '" << origIT->first << "' ";
				std::cout << "Value = " << origIT->second << "\n";
				origIT++;
				i++;
			}
		}

		{
			/****** erase  posision ***/

			std::cout << Y "My erase posision:\n" D;

			int i;
			ft::map<int, int> erase;
			for (i = 1; i <= 21; i++)
				erase[i] = i;


			ft::map<int, int>::iterator it = erase.begin();

			for (int a = 1; a != 4; a++)
				it++;
			std::cout << "Delete key = '" << it->first << "' \n";
			erase.erase(it);
			it = erase.begin();
			i = 0;
			for (size_t a = 0; a < erase.size(); a++) {
				std::cout << ++i << " Element: key = '" << it->first << "' " "value = '" << it->second << "'\n";
				it++;
			}
			std::cout << "\n";


			std::cout << Y "Origin erase posision:\n" D;


			std::map<int, int> erase1;
			for (i = 1; i <= 21; i++)
				erase1[i] = i;


			std::map<int, int>::iterator it1 = erase1.begin();

			for (int a = 1; a != 4; a++)
				it1++;
			std::cout << "Delete key = '" << it1->first << "' \n";
			erase1.erase(it1);
			it1 = erase1.begin();
			i = 0;
			for (size_t a = 0; a < erase.size(); a++) {
				std::cout << ++i << " Element: key = '" << it1->first << "' " "value = '" << it1->second << "'\n";
				it1++;
			}
			std::cout << "\n";

		}

		{

			/********* erase key  ***********/


			std::cout << Y "My erase key:\n" D;
			int i;
			ft::map<int, int> erase;
			for (i = 1; i <= 15; i++)
				erase[i] = i;

			erase.erase(1);
			erase.erase(14);
			erase.erase(9);
			erase.erase(10);

			ft::map<int, int>::iterator it = erase.begin();
			i = 0;
			std::cout << "Delete key = |1, 14, 9, 10|\n";
			while (it != erase.end()) {
				std::cout << ++i << " Element: key = '" << it->first << "' " "value = '" << it->second << "'\n";
				it++;
			}
			std::cout << "\n";


			std::cout << Y "Original erase key:\n" D;

			std::map<int, int> erase1;
			for (i = 1; i <= 15; i++)
				erase1[i] = i;


			erase1.erase(1);
			erase1.erase(14);
			erase1.erase(9);
			erase1.erase(10);

			std::map<int, int>::iterator it1 = erase1.begin();
			i = 0;
			std::cout << "Delete key = |1, 14, 9, 10|\n";
			while (it1 != erase1.end()) {
				std::cout << ++i << " Element: key = '" << it1->first << "' " "value = '" << it1->second << "'\n";
				it1++;
			}
			std::cout << "\n";

		}

		{

			/***** erase iterators ****/
			std::cout << Y "My erase iterators:\n" D;

			int i;
			ft::map<int, int> erase;
			for (i = 1; i <= 10; i++)
				erase[i] = i;
			ft::map<int, int>::iterator it;
			ft::map<int, int>::iterator fin;

			it = erase.find(3);
			fin = erase.find(8);
			std::cout << "Delete key from 3 to 8\n";

			erase.erase(it, fin);

			it = erase.begin();
			fin = erase.end();
			i = 0;

			while (it != fin) {
				std::cout << ++i << " Element: key = '" << it->first << "' " "value = '" << it->second << "'\n";
				it++;
			}
			std::cout << "\n";


			std::cout << Y "Original erase iterators:\n" D;

			std::map<int, int> erase1;
			for (i = 1; i <= 10; i++)
				erase1[i] = i;

			std::map<int, int>::iterator it1;
			std::map<int, int>::iterator fin1;

			it1 = erase1.find(3);
			fin1 = erase1.find(8);
			std::cout << "Delete key from 3 to 8\n";

			erase1.erase(it1, fin1);

			it1 = erase1.begin();
			fin1 = erase1.end();
			i = 0;

			while (it1 != fin1) {
				std::cout << ++i << " Element: key = '" << it1->first << "' " "value = '" << it1->second << "'\n";
				it1++;
			}
			std::cout << "\n";

		}

		{

			std::cout << Y "My swap:\n" D;

			ft::map<char, std::string> myMap1;
			ft::map<char, std::string> myMap2;

			myMap1['*'] = "myMap";
			myMap1['H'] = "HELLO";
			myMap1['P'] = "PEER";

			myMap2['*'] = "myMap2";
			myMap2['S'] = "SCOOL";
			myMap2['2'] = "21 KAZAN";

			myMap1.swap(myMap2);

			ft::map<char, std::string>::iterator myIT;
			ft::map<char, std::string>::iterator myIT2;

			std::cout << "myMap1 \n";
			myIT = myMap1.begin();
			myIT2 = myMap1.end();
			int i = 0;
			while (myIT != myIT2) {
				std::cout << ++i << " Element: key = '" << myIT->first << "' " "value = '" << myIT->second << "'\n";
				myIT++;
			}
			std::cout << "\n";

			std::cout << "myMap2 \n";
			myIT = myMap2.begin();
			myIT2 = myMap2.end();
			i = 0;
			while (myIT != myIT2) {
				std::cout << ++i << " Element: key = '" << myIT->first << "' " "value = '" << myIT->second << "'\n";
				myIT++;
			}
			std::cout << "\n";




			std::cout << Y "Original swap:\n" D;

			std::map<char, std::string> origMap1;
			std::map<char, std::string> origMap2;

			origMap1['*'] = "origMap";
			origMap1['H'] = "HELLO";
			origMap1['P'] = "PEER";

			origMap2['*'] = "origMap2";
			origMap2['S'] = "SCOOL";
			origMap2['2'] = "21 KAZAN";

			origMap1.swap(origMap2);

			std::map<char, std::string>::iterator origIT;
			std::map<char, std::string>::iterator origIT2;

			std::cout << "origMap1 \n";
			origIT = origMap1.begin();
			origIT2 = origMap1.end();
			i = 0;
			while (origIT != origIT2) {
				std::cout << ++i << " Element: key = '" << origIT->first << "' " "value = '" << origIT->second << "'\n";
				origIT++;
			}
			std::cout << "\n";

			std::cout << "origMap2 \n";
			origIT = origMap2.begin();
			origIT2 = origMap2.end();
			i = 0;
			while (origIT != origIT2) {
				std::cout << ++i << " Element: key = '" << origIT->first << "' " "value = '" << origIT->second << "'\n";
				origIT++;
			}
			std::cout << "\n";


			std::cout << Y "My clear:\n" D;

			myMap1.clear();
			myMap2.clear();
			std::cout << "Size myMap1 = " << myMap1.size() << ", myMap empty1 = " << myMap1.empty() << "\n";
			std::cout << "Size myMap2 = " << myMap2.size() << ", myMap2 empty = " << myMap2.empty() << "\n";


			std::cout << Y "Original clear:\n" D;

			origMap1.clear();
			origMap2.clear();
			std::cout << "Size origMap1 = " << origMap1.size() << ", origMap1 empty = " << origMap1.empty() << "\n";
			std::cout << "Size origMap2 = " << origMap2.size() << ", origMap2 empty = " << origMap2.empty() << "\n";

		}

			/********** Observers ***************/
		{

			std::cout << Y"\nMy observers\n"D;


			ft::map<char, int> myMap;

			ft::map<char, int>::key_compare mycomp = myMap.key_comp();


			myMap['a'] = 100;
			myMap['b'] = 200;
			myMap['c'] = 300;

			std::cout << "myMap contains:\n";

			char highest = myMap.rbegin()->first;     // key value of last element

			ft::map<char, int>::iterator it = myMap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while (mycomp((*it++).first, highest));

			std::cout << '\n';

			myMap.clear();

			myMap['x'] = 1001;
			myMap['y'] = 2002;
			myMap['z'] = 3003;

			std::cout << "myMap contains:\n";

			std::pair<char, int> myHighest = *myMap.rbegin(); // last element
			it = myMap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while ( myMap.value_comp()(*it++, myHighest) );



			std::cout << Y"\nOriginal observers\n"D;


			std::map<char, int> origMap;

			std::map<char, int>::key_compare mycomp1 = origMap.key_comp();


			origMap['a'] = 100;
			origMap['b'] = 200;
			origMap['c'] = 300;

			std::cout << "origMap contains:\n";

			char highest1 = origMap.rbegin()->first;     // key value of last element

			std::map<char, int>::iterator it1 = origMap.begin();
			do {
				std::cout << it1->first << " => " << it1->second << '\n';
			} while (mycomp1((*it1++).first, highest1));

			std::cout << '\n';
			origMap.clear();


			origMap['x'] = 1001;
			origMap['y'] = 2002;
			origMap['z'] = 3003;

			std::cout << "origMap contains:\n";

			std::pair<char, int> origHighest = *origMap.rbegin(); // last element

			it1 = origMap.begin();
			do {
				std::cout << it1->first << " => " << it1->second << '\n';
			} while (origMap.value_comp()(*it1++, origHighest));



			/****** OPERATION  ********/


			std::cout << G "\nOPERATION\n" D;

			std::cout << Y "My find:\n" D;

			it = myMap.find('x');
			std::cout << "Find element with key 'x': key = '" << it->first << "' ";
			std::cout << "Value = " << it->second << "\n";
			it = myMap.find('a');
			std::cout << "Find element with key 'a': key = '" << it->first << "' ";
			std::cout << "Value = " << it->second << "\n";
			std::cout << "Size myMap = " << myMap.size() << "\n";


			std::cout << Y "Original find:\n" D;

			it1 = origMap.find('x');
			std::cout << "Find element with key 'x': key = '" << it1->first << "' ";
			std::cout << "Value = " << it1->second << "\n";
			it1 = origMap.find('a');
			std::cout << "Find element with key 'a': key = '" << it1->first << "' ";
			std::cout << "Value = " << it1->second << "\n";
			std::cout << "Size origMap = " << origMap.size() << "\n";


			std::cout << Y "My count:\n" D;

			std::cout << "Count element 'z' in myMap = " << myMap.count('z') << "\n";
			std::cout << "Count element 'a' in myMap = " << myMap.count('a') << "\n";


			std::cout << Y "Original count:\n" D;

			std::cout << "Count element 'z' in origMap = " << origMap.count('z') << "\n";
			std::cout << "Count element 'a' in origMap = " << origMap.count('a') << "\n";
		}


		{

			std::cout << Y "My lower_bound:\n" D;

			ft::map<char,int> myMap;
			ft::map<char,int>::iterator itlow,itup;

			myMap['a']=20;
			myMap['b']=40;
			myMap['c']=60;
			myMap['d']=80;
			myMap['e']=100;

			itlow=myMap.lower_bound ('b');  // itlow points to b
			itup=myMap.upper_bound ('d');   // itup points to e (not d!)

			myMap.erase(itlow,itup);        // erases [itlow,itup)

			// print content:
			for (ft::map<char,int>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';



			std::cout << Y "Original lower_bound:\n" D;

			std::map<char,int> origMapap;
			std::map<char,int>::iterator itlow1,itup1;

			origMapap['a']=20;
			origMapap['b']=40;
			origMapap['c']=60;
			origMapap['d']=80;
			origMapap['e']=100;

			itlow1=origMapap.lower_bound ('b');  // itlow points to b
			itup1=origMapap.upper_bound ('d');   // itup points to e (not d!)

			origMapap.erase(itlow1,itup1);        // erases [itlow,itup)

			// print content:
			for (std::map<char,int>::iterator it1 = origMapap.begin(); it1 !=origMapap.end(); ++it1)
				std::cout << it1->first << " => " << it1->second << '\n';

		}

		{

			std::cout << Y "My equal_range\n" D;
			ft::map<char,int> myMap;
			myMap['a']=10;
			myMap['b']=20;
			myMap['c']=30;

			std::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
			ret = myMap.equal_range('b');
			std::cout << "lower bound points to: ";
			std::cout << ret.first->first << " => " << ret.first->second << '\n';

			std::cout << "upper bound points to: ";
			std::cout << ret.second->first << " => " << ret.second->second << '\n';


			std::cout << Y "Original equal_range\n" D;

			std::map<char,int> origMap;

			origMap['a']=10;
			origMap['b']=20;
			origMap['c']=30;

			std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret1;
			ret1 = origMap.equal_range('b');

			std::cout << "lower bound points to: ";
			std::cout << ret1.first->first << " => " << ret1.first->second << '\n';

			std::cout << "upper bound points to: ";
			std::cout << ret1.second->first << " => " << ret1.second->second << '\n';
		}


		std::cout << Y"Now you can check memory leaks, with leaks a.out in other terminal" << D"\n";
		std::cout << G"To exit press Enter" << D"\n";
		getchar();
		std::cout << G"Good bye" << D"\n";

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

