#include <security.h>
#include <move.h>
#include <std.h>
#include <daemons.h>

//inherit "/std/room";
inherit "/std/spells/shadows/shadow";

object room_shadowed;
object caster;
string expire_message;


void start_shadow(object where, object who, int duration, string message){
    int i;
    object *ob;

    seteuid(UID_SHADOW);
    begin_shadow(where);
    room_shadowed = where;
    caster = who;
    expire_message = message;

    if(duration)
	call_out("remove_field", duration, this_object());

    seteuid(getuid());
    return;
}


int query_no_cast(object ob){ 
    if(ob == caster) return 0;
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

    remove();
    return;
}

