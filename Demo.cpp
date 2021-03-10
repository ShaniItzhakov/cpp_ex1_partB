/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::snowman(11114411) << endl;   /* Should print:
_===_
(.,.)
( : )
( : )
	*/
	cout << ariel::snowman(33232124) << endl;   /* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/
	cout << ariel::snowman(22222212) << endl;   /* Should print:
  ___ 
 .....
\(o.o)/
 ( : ) 
 (" ")
	*/
	cout << ariel::snowman(41333342) << endl;   /* Should print:
  ___ 
 (_*_)
 (O,O) 
/(   )\
 (" ")
	*/

	cout << ariel::snowman(11111111) << endl;   /* Should print:
 _===_
 (.,.)
<( : )>
 ( : )
	*/
	cout << ariel::snowman(22222222) << endl;   /* Should print:
  ___ 
 .....
\(o.o)/
 (] [)
 (" ")
	*/
	cout << ariel::snowman(33333333) << endl;   /* Should print:
   _ 
  /_\
 (O_O)
/(> <)\ 
 (___)
	*/
	cout << ariel::snowman(44444444) << endl;   /* Should print:
  ___ 
 (_*_)
 (- -) 
 (   )
 (   )
	*/
	try {
		cout << ariel::snowman(5) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	}

	try {
		cout << ariel::snowman(123123123) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '123123123'"
	}

	try {
		cout << ariel::snowman(0) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '0'"
	}
}

