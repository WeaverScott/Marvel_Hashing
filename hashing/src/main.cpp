#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "SuperHero.h"
#include "csv.h"
#include "my_hash.h"

int main(int argc, char const *argv[]) {

	/** hashmap 1 **/
	my_hash hashMap1;
	//Uses function 1
	hashMap1.setHashFunction(1);
	//Number of collisions from hash function 1
	int collisions1 = 0;

	/** hashmap 2 **/
	my_hash hashMap2;
	//Uses function 2
	hashMap2.setHashFunction(2);
	//Number of collisions from hash function 2
	int collisions2 = 0;

	/** hashmap 3  **/
	my_hash hashMap3;
	//Uses function 3
	hashMap3.setHashFunction(3);
	//Number of collisions from hash function 3
	int collisions3 = 0;

	/** instance of a SuperHero **/
	SuperHero sh;
	
	/** Holds page_id **/
	int page_id;

	/** Holds name **/
	std::string name;

	/** Holds urlslug **/
	std::string urlslug;

	/** Holds id **/
	std::string id;

	/** Holds alignment **/
	std::string alignment;

	/** Holds eye_color **/
	std::string eye_color;

	/** Holds hair_color **/
	std::string hair_color;

	/** Holds sex **/
	std::string sex;

	/** Holds gsm **/
	std::string gsm;

	/** Holds alive **/
	std::string alive;

	/** Holds appearances **/
	int appearances;

	/** Holds first_appearance **/
	std::string first_appearance;

	/** Holds year **/
	int year;

	/**************************************************************
	CSV reader that parses the marvel-wikia-data.csv file.
	**************************************************************/
	io::CSVReader<13, io::trim_chars<' '>, 
	io::double_quote_escape<',','\"'> >in
	("src/marvel-wikia-data.csv");

	//Reads in the collumns.
	in.read_header(io::ignore_extra_column, "page_id", "name", 
	"urlslug", "ID", "ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", 
	"APPEARANCES", "FIRST APPEARANCE", "Year");

	//Loops through the marvel.csv file and inserts a SuperHero 
	//into the hashMap.
	while(in.read_row(page_id, name, urlslug, id, alignment, 
	eye_color, hair_color, sex, gsm, alive, appearances, 
	first_appearance, year)) {
	
	//Sets the retrieved attributes to the SuperHero.
	sh.setPageID(page_id);
	sh.setName(name);
	sh.setUrlslug(urlslug);
	sh.setID(id);
	sh.setAlignment(alignment);
	sh.setEyeColor(eye_color);
	sh.setHairColor(hair_color);
	sh.setSex(sex);
	sh.setGsm(gsm);
	sh.setAlive(alive);
	sh.setAppearances(appearances);
	sh.setFirstAppearance(first_appearance);
	sh.setYear(year);

	//Inserts according to what hash function was used 
	if(hashMap1.insert(sh) == false)
		collisions1++;
	
	if(hashMap2.insert(sh) == false)
		collisions2++;

	if(hashMap3.insert(sh) == false)
		collisions3++;

	}

	//Writes the number of collisions to file
	std::ofstream output("RESULTS.md");

	output << "Collisions in hash function 1: " << collisions1 << std::endl;
	output << "Collisions in hash function 2: " << collisions2 << std::endl;
	output << "Collisions in hash function 3: " << collisions3 << std::endl;
	
	output.close();
	return 0;
}
