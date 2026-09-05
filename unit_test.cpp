////////////////////////////////////////////////////////
// ECE 3574 Exercise: Unit Tests with Catch - starter code
//
#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include <cassert>    
#include <cstdlib>


TEST_CASE("multimap unit test1", "[multimap]") {
	std::multimap<std::string, std::string> m;
	
	REQUIRE(m.empty() == true);
	REQUIRE(m.size() == 0);
	
	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE(m.size() == 1);
	REQUIRE(m.empty() == false);

	m.insert(std::pair<std::string, std::string>("Ross", "John"));
	m.insert(std::pair<std::string, std::string>("Kanye", "West"));
	REQUIRE(m.size() == 3);

	REQUIRE(m.count("Ross") == 2);
	REQUIRE(m.count("Kanye") == 1);
	REQUIRE(m.count("Shaan") == 0);

	REQUIRE(m.find("Ross") != m.end());
	REQUIRE(m.find("Kanye") != m.end());
	REQUIRE(m.find("Shaan") == m.end());

	m.erase("Kanye");
	REQUIRE(m.count("Kanye") == 0);
	REQUIRE(m.size() == 2);

	m.clear();
	REQUIRE(m.empty() == true);
	REQUIRE(m.size() == 0);




} 

TEST_CASE("multimap unit test2", "[multimap]") {
	std::multimap<std::string, std::string> m1;
	m1.insert(std::make_pair("Ross", 10));
	m1.insert(std::make_pair("Betsy", 20));
	m1.insert(std::make_pair("Ross", 30));

	std::multimap<std::string, std::string> m2;

	m2 = m1; 
	REQUIRE(m2.size() == m1.size());
	REQUIRE(m2.count("Ross") == 2);
	REQUIRE(m2.count("Betsy") == 1);

	REQUIRE(m2.find("Ross") != m2.end());
	REQUIRE(m2.find("Betsy") != m2.end());

	m2.insert(std::make_pair("Kanye", 40));

	REQUIRE(m2.size() == 4);
	REQUIRE(m1.size() == 3); 
}
