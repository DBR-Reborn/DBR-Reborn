/*
Controller to allow enemies of a 
town to be declared and traced
by that town's guards.
*/

#include <security.h>
#include <daemons.h>

#define ENEMY_LIST "/d/damned/guilds/nethermancer/misc/owners.o"
#define MIN (60)
#define HOUR (MIN*60)
#define DAY (HOUR*24)
#define WEEK (DAY*7)

mapping enemies;

void filter_old();
void add_enemy(string name);
void save_enemies();
void restore_enemies();
string *query_enemies();

void create(){

    enemies = ([ ]);
    restore_enemies();
    filter_old();
}

void filter_old(){
    string *keys;
    int i;
    int ctime = time();

    keys = keys(enemies);

    for(i = 0; i < sizeof(keys); i++)
	if(ctime - enemies[keys[i]] > DAY*2)
	    map_delete(enemies, keys[i]);
    save_enemies();
}

void add_enemy(string name){
    int date = time();

    if(enemies){
	enemies += ([ name : date ]);
    }
    else
    {
	enemies = ([ name : date ]);
    }
    filter_old();
    save_enemies();
}

void remove_enemy(string name){
    int date = time();

    if(enemies){
	if(enemies[name]);
	map_delete(enemies, name);
    }

    filter_old();
    save_enemies();
}

string *query_enemies(){
    string name;
    if(this_player())
	name = this_player()->query_name();
    filter_old();

    // guards hunt fugitives too
    if(LAW_D->is_fugitive(name))
	return ({ name }) + keys(enemies);

    return keys(enemies);
}

void save_enemies(){
    save_object(ENEMY_LIST);
}

void restore_enemies() {
    restore_object(ENEMY_LIST);
}

