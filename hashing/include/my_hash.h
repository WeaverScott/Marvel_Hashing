#ifndef INCLUDE_GUARD
#define INCLUDE_GUARD

#include <string>
#include <vector>
#include <iostream>
#include "SuperHero.h"

//Constant value used to set the size of the hash map
#define TABLESIZE 17011

/**********************************************************************
Header file that allows the insertion and retrieval of a SuperHero 
into the hashmap. Also holds 3 hash functions that determine how the 
SuperHeros will be inserted into the hashmap.

@auther Scott Weaver
@version Winter 2018
**********************************************************************/
class my_hash {
	
public:
	
	/**************************************************************
	Constructor for hashmap which sets the initial size to 17011.
	**************************************************************/
	my_hash() {
		hashMap.resize(TABLESIZE);
	}

	/**************************************************************
	Inserts the SuperHero into the hashmap.

	@param SuperHero sh
	An instance of a SuperHero read in from the csv reader.
	**************************************************************/
	bool insert(const SuperHero & sh) {
		bool collision = false;
		int index;
		std::string name = sh.getName();

		if(hashFunction == 1) {
			index = hash1(name);
		} else if (hashFunction == 2) {
			index = hash2(name);
		} else if (hashFunction == 3) {
			index = hash3(name);
		}
		
		if(hashMap[index].size() > 0)
			collision = true;

		hashMap[index].insert(hashMap[index].begin(), sh);

		return collision;
	}

        /**************************************************************
        Gets the reference to a SuperHero given the name as the parameter.

	@param const std::string name
		The name of the SuperHero.
	@return The SuperHero that has the given name.
        **************************************************************/
	SuperHero & get(const std::string name) {
	for (int i = 0; i < hashMap.size(); i++) {
		for (int j = 0; j < hashMap[i].size(); j++)
			if(hashMap[i][j].getName() == name)
				return hashMap[i][j];
	}
	}

	/**************************************************************
	Hashing function 1.
	Figure 5.1 on page 195, Weiss
	**************************************************************/
	int hash1(std::string name) {
		int hashVal = 0;

		for(char ch: name) {
			hashVal += ch;
		}
		
		return hashVal % TABLESIZE;
	}

	/**************************************************************
	Hashing function 2.
	Figure 5.2 on page 195, Weiss
	**************************************************************/
	int hash2(std::string name) {
		
		//char 1 + 27 * char 2 + 729 * char 3
		return (name[0] + 27 * name[1] + 729 * 
		name[2]) % TABLESIZE;
	}

	/**************************************************************
	Hashing function 3.
	Figure 5.3 on page 195, Weiss
	**************************************************************/
	unsigned int hash3(std::string name) {
		unsigned hashVal = 0;

		for(char ch: name) {
			hashVal = 37 * hashVal + ch;
		}

		return hashVal % TABLESIZE;
	}

	/**************************************************************
	Used to determine which hash function is being used.

	@param a
		The desired hash function.
	**************************************************************/	
	void setHashFunction(int a) {
		hashFunction = a;
	}

private:
	
	//Vector array that holds the SuperHeros
	std::vector<std::vector<SuperHero>> hashMap;

	//Variable used to determine which hash function is being used
	int hashFunction = 0;

};

#endif		
