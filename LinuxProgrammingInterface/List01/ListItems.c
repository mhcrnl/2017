/**
	@Author:	Mihai Cornel	Romania			mhcrnl@gmail.com
	@System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                	Fedora 24	Code::Blocks 16.01	gcc 5.3.1
	@Copyright:	2017
	@file:	ListItems.c
*/
#include <stdlib.h>
#include "ListItems.h"
/**
    1. Allocates new memory for a ListItem_t then returns a pointer to it.
 */
ListItem_t * list_item_initialize(){
	ListItem_t * li = (ListItem_t *) malloc( sizeof(ListItem_t) );
	li->next = 0;

	return(li);
}

/**
    2. Removes ListItem_t data and returns if successful or not.
 */
int list_item_remove(ListItem_t * li, list_item_remove_callback_func cb){
	return( cb(li->data) );
}

/**
    3. Add ListItem_t data and returns if successful or not.
 */
int list_item_add(ListItem_t * li, void * data){
	li->data = data;
	return(1);
}
