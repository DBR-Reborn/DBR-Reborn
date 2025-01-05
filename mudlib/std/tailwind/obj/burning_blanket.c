#include <std.h>

inherit OBJECT;

int burn() {
    call_out("extinguish", 60);
    return 1;
}

void create() {
  ::create();
    set_name("blanket");
    set_id( ({ "blanket"}) );
    set_short("A burning blanket");
    set_long("This blanket is _burning_. It's on _fire_. It's going to be consumed in flame soon - better smother someone with it fast!");
    set_weight(1);
    set_value(0);
    call_out("burn", 1);
}

void init() {
    ::init();
    add_action("smother_bastard", "smother");
}

int extinguish() {
    write("The blanket burns away completely.");
    this_object()->remove();
    return 1;
}

int smother_bastard(string str) {
    object ob;
    object tp;
    ob=present(str, environment(this_player()));
    tp=this_player();
    if(!ob){
	write("You don't have that!");
	return 1;
    }
    if(!ob->is_player() && !ob->query_npc()) {
	write("You can only smother animate (also known as 'living') things.");
	return 1;
    }
    write("You shove the blanket over "+ob->query_cap_name()+"'s head and smother away!");
//    message("local_message",""+(string)tp->query_cap_name()+" shoves a burning blanket over "+(string)ob->query_cap_name()+"'s head!",environment(tp),tp);
    message("local_message",""+(string)tp->query_cap_name()+" shoves a burning blanket over your head!",ob);
    ob->add_hp(-25);
    this_object()->remove();
    return 1;
}
