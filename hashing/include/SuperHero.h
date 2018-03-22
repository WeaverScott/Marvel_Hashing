#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <string>
#include <iostream>

/**********************************************************************
SuperHero class.

@author Scott Weaver
@version Winter 2018
**********************************************************************/
class SuperHero {

	public:
		//Default constructor.
		SuperHero();
		
		//Setter methods for all instance variables.
		void setPageID(int i);
		void setName(std::string n);
		void setUrlslug(std::string u);
		void setID(std::string i);
		void setAlignment(std::string a);
		void setEyeColor(std::string e);
		void setHairColor(std::string h);
		void setSex(std::string s);
		void setGsm(std::string g);
		void setAlive(std::string a);
		void setAppearances(int a);
		void setFirstAppearance(std::string fa);
		void setYear(int y);

		//Getter methods for all instance variables.
		int getPageID();
		std::string getName() const;
		std::string getUrlslug();
		std::string getID();
		std::string getAlignment();
		std::string getEyeColor();
		std::string getHairColor();
		std::string getSex();
		std::string getGsm();
		std::string getAlive();
		int getAppearances();
		std::string getFirstAppearance();
		int getYear();

	private:
		//Variables that make up a SuperHero.
		//For the sake of the csv reader, bool and char
		//variables have been changed to strings.
		int page_id;
		std::string name;
		std::string urlslug;
		std::string id;
		std::string alignment;
		std::string eye_color;
		std::string hair_color;
		std::string sex;
		std::string gsm;
		std::string alive;
		int appearances;
		std::string first_appearance;
		int year;
};

#endif		
