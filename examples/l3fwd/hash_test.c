#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct hash_table {

    int key;
    int id;
    int money;
    UT_hash_handle hh;

};

#define alloc( t , o )											\
	( ( t * )malloc( sizeof( t ) * ( o ) ) )

struct hash_table * hash = NULL;

#define hashPut( key , id , money ) 							\
do { 															\
	struct hash_table * tmp = alloc( struct hash_table , 1 ); 	\
	tmp -> key = ( key );										\
	tmp -> id = ( id );											\
	tmp -> money = ( money );									\
	HASH_ADD_INT( hash , key , tmp );							\
} while( 0 )

#define hashGet( key , result )									\
do {															\
	HASH_FIND_INT( hash , &key , result );						\
} while( 0 )

void main() {

	
	struct hash_table * result;
	int key = 5;
	int id = 5;
	int money = 120;

	hashPut( key , id , money );
	hashGet( key , result );

	printf( "key = %d\n" , result -> key );
	printf( "id = %d\n" , result -> id );
	printf( "money = %d\n" , result -> money );

}