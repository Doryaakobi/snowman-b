/**
 * AUTHOR: Dor Yaakobi
 * 
 * Date: 10-03-2021
 */


#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>
using namespace std;
using namespace ariel;



string nospaces(string input) {
	input.erase(' ');
	input.erase('\t');
	input.erase('\n');
	input.erase('\r');
	return input;
}


TEST_CASE("Test No. 1") {
    
	cout << "Good Snowman input" << endl;


	//check all Hats 
    CHECK(snowman(11111111) == string("      \n _===_\n (.,.) \n <( : )> \n ( : )"));
    CHECK(snowman(21111111) == string("  ___ \n (_*_)\n (.,.) \n <( : )> \n ( : )"));
    CHECK(snowman(31111111) == string("   _  \n  /_\\ \n (.,.) \n <( : )> \n ( : )"));
    CHECK(snowman(41111111) == string("  ___ \n .....\n (.,.) \n <( : )> \n ( : )"));

	// HLNRXYTB
    



}



TEST_CASE("Test No. 2") {

	cout << "Bad snowman input - too short" << endl;

	int j = 10;
	for (int i = 0; i < 8; i++){
		CHECK_THROWS(snowman(i*j));
		j*=10;
	}

}

TEST_CASE("Test No. 3") {

	cout << "indexs out of range for constructing" << endl;
	int ll = 10000000;
	for (int i = 1; i < 10; i++){
		int j = rand() % 9 + 2; // generate numbers between 2-9
		CHECK_THROWS(snowman(ll+j));
		j*=10*i;
		ll+=j;
	}
}

TEST_CASE("Test No. 4") {

	cout << "invalid input must be positive integer" << endl;
	int ll = -10000000;
	for (int i = 1; i < 10; i++){
		int j = rand() % 9 + 2; // generate numbers between 2-9
		CHECK_THROWS(snowman(ll+j));
		j*=10*i;
		ll+=j;
	}

    

}

