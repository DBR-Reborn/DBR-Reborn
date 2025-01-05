#include <security.h>
#include <move.h>
#include <std.h>
#include <daemons.h>

//inherit "/std/room";
inherit "/std/spells/shadows/shadow";

object room_shadowed;
object caster;
string expire_message;


void initiate(object ob){
	add_action("try_casting", "cast");
}


void init(){
	add_action("try_casting", "cast");
}


void start_shadow(object where, object who, int duration, string message){
	int i;
	object *ob;

	seteuid(UID_SHADOW);
	begin_shadow(where);
	room_shadowed = where;
	caster = who;
	expire_message = message;

	ob = all_inventory(where);
	i = sizeof(ob);
	while(i--){
	if(living(ob[i])){
	initiate(ob[i]);
	environment(ob[i])->init();
	environment(ob[i])->initiate();
}
}
	

	if(duration)
	call_out("remove_field", duration, this_object());

	seteuid(getuid());
	return;
}


int query_anti_magic(){ return 1; }


int try_casting(string str){
	if(this_player() == caster ||
		member_array(this_player(), find_object(PARTY_D)->query_party_members(caster->query_party())) > -1){
	return 0;
}
	message("info", "You cannot cast here, an anti-magic field is present.", room_shadowed);
	return 1;
}


void remove_field(object me){
	int i;
	object *ob;

	if(me != this_object()){
	next_shadow()->remove_field(me);
	return;
}
	if(expire_message)
	message("info", expire_message, room_shadowed);

	ob = all_inventory(room_shadowed);
	i = sizeof(ob);
	while(i--)
	ob[i]->init();

	remove();
	return;
}
