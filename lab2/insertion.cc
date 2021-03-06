#include <iostream>
#include <cstdlib>
#include "insertion.h"

using namespace std;

// insertion sort with several errors

// store command-line arguments in x[] array
void getArgs( int argc, char *argv[] ) {
    x_size = argc - 1;
    for( int i = 0; i < x_size; i++ )
        x[i] = atoi( argv[ i+1 ] );
}

void scootOver( int j ) {
    int k;
    for( k = y_size; k > j; k-- )
        y[k] = y[ k-1 ];
    y_size+=1;
}

void insert( int xx ) {
    int j;

    if( y_size == 0 ) {
        y[0] = xx;
        y_size+=1;
        return;
    }
    // Need to insert just before the first y element that xx is less than
    for( j=0; j< y_size; j++ ) {
        if( xx <= y[j] ) {
            // shift y[j], y[j+1], ... rightward before inserting xx
            scootOver( j );
            for(int i = 0; i < y_size; i++)
                cout<<y[i]<<" ";
            cout<<"\n";
            y[j] = xx;
            for(int i = 0; i < y_size; i++)
                cout<<y[i]<< " ";
            cout<<"\n";
            return;
        }
    }
    for(j=y_size - 1; j<y_size;j++){
	if(xx > y[j]){
	    y[j+1] = xx;
	    y_size++;
	    return;
	}
	else{
	    insert(xx);
	    return;
	}
    }
}

void processData() {
    for( int i = 0; i < x_size; i++ )
        // insert x value in the proper place among y[0],....,y[y_size-1]
        insert(x[i]);
}

void printResults() {
    for( int i=0; i<y_size; i++ )
        cout << y[i] << " ";
    cout << endl;
}

int main( int argc, char * argv[] ) {
    getArgs( argc, argv );
    processData();
    printResults();
}
