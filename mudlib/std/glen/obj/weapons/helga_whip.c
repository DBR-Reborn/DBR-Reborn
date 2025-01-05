#include <std.h>
#include <move.h>
#include <colors.h>

inherit "/std/weapon";

int last_snap;

void init(){
    ::init();
    add_action("snap","snap");
}

int snap(string str){
    object ob;
    string limb;

    if(!str || !stringp(str) || !present(str, environment(this_player()))){
	write("snap who?");
	return 0;
    }
    ob = present(str, environment(this_player()));
    if(!ob || !living(ob)){
	write("that is not a living creature");
	return 0;
    }
    if(this_player() != environment(this_object())){
	write("you must be holding the whip to snap people.");
	return 0;
    }
    if(time() - last_snap < 8){
	write("You may not snap the whip again yet, it is unwilling.");
	return 1;
    }
    this_player()->kill_ob(ob, 1);
    write(CBOLD + "You snap " + ob->query_name());
    message("info", CBOLD + this_player()->query_cap_name() + " snaps you, damn that hurts!", ob);
    message("info", CBOLD + this_player()->query_cap_name() + " snaps " + ob->query_name() + 
      " with " + this_object()->query_short(), 
      all_inventory(environment(ob)), ({ob, this_player()}) );
    limb = ({ "left hand", "right hand", "left foot", "right foot"})[random(4)];
    ob->cripple_limb(limb, "sever");
    last_snap = time();
    return 1;
}

void create() {
    ::create();
    set("id", ({ "whip", "helga's whip", "flail" }));
    set_name("whip");
    set("short", CMAGENTA + "Helga's Whip" + CRESET);
    set("long",
      "Torturous little whip looks as if it has shed the blood of a hundred victims.  "+
      "It is made of woven leather, and looks like it could rather hurt.  "
      "You may 'snap' it at a victim.");
    set_weight(70);
    set_type("flail");
    set_wc(25, "cutting");
    set_wc(25, "crushing");
    set_wc(25, "impact");
    set_ac(40);
    set_parry_bonus(2);
    set_quality(6);
    set_property("no add quality", 1);
    set_property("no decay", 1);
    set_decay_rate(1500);
    set_auto_critical(([ "cutting C" : 40 ]));
    set_property("enchantment", 30);
    set_value(0);
    set_property("brittle", 25);
    set_material("metal/inniculmoid");
    return;
}


