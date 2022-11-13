/*
 */


#include <iostream>

using namespace std;

typedef int ARRAY[8] ; 

void setNumbers ( ARRAY numbers ) ; 

void checkVertical ( ARRAY numbers ) ;

int main(int argc, char **argv)
{
	
	ARRAY numbers ; 
	int times = 1000000 ;
	
	srand(time(NULL)) ;
	
	for ( int x = 0 ; x < times ; x++ ) {
		setNumbers ( numbers ) ;
		checkVertical ( numbers ) ;
	}
	
	return 0;
}

void setNumbers ( ARRAY numbers ) {
	int avInts[8] ;
	
	for ( int x = 0 ; x < 8 ; x++ ) {
		numbers[x] = -10 ;
	}
	
	for ( int x = 0 ; x < 8 ; x++ ) {
		avInts [x] = x ;
	}

	for ( int x = 0 ; x < 8 ; x++ ) {
		bool valid = false ;
		while ( !valid ) {
			numbers[x] = rand() %10 ;
			for ( int y = 0 ; y < 8 ; y++ ) {
				if ( numbers[x] == avInts[y] ) {
					avInts[y] = -2 ;
					valid = true ;
				}
			}
		}
	}
	
}

void checkVertical ( ARRAY numbers ) {
	bool validSolution = true ;

	for ( int x = 0 ; x < 8 ; x++ ) {
		for ( int i = 1 ; i < 8 ; i++ ) {
			if ( ( x - i ) >= 0 ) {
				if ( ( numbers[x] == numbers[x-i]+i ) || ( numbers[x] == numbers[x-i]-i ) ) {
					//cout << "something" << endl ;
					//cout << " x - " << x << " , i - " << i << endl ;
					//cout << numbers [x] << " , " << numbers [x-i]+i << " , " << numbers[x-i]-i << endl ; 
					validSolution = false ;
				}
			} 
			if ( ( x + i ) < 8 ) {
				if ( ( numbers[x] == numbers[x+i]+i ) || ( numbers[x] == numbers[x+i]-i ) ) {
					//cout << "something 2" << endl ;
					//cout << " x - " << x << " , i - " << i << endl ;
					//cout << numbers [x] << " , " << numbers [x+i]+i << " , " << numbers[x+i]-i << endl ; 
					validSolution = false ; 
				}
			}
		}
	}
		
	if ( !validSolution ) {
		//for (int x = 0 ; x < 8 ; x++ ) {
			//cout << numbers[x] << ' ' ;
		//}
		//cout << endl << "INVALID" << endl ;
	} else {
		for (int x = 0 ; x < 8 ; x++ ) {
			cout << numbers[x] << ' ' ;
		}
		cout << endl << "^^^^    VALID    *************************************  " << endl << endl ;
	}
}

void saveValid ( ) {
	
}
