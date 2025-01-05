//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      Tailwind 10/28/98

#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_ac(20);
    set("id", ({ "sword", "guildmaster sword", "Xenon" }));
    set_name("xenon");
    set("short", "Xenon, the Sword of the Guildmaster");
    set("long", "Xenon, the Blade of Legends. Whoa. You can't believe you're holding such incredible power in your hands! Supposedly, it was created from the ash of a supernova, and bound together with some of the most powerful magics known to man." );
    set_type("blade");
    set_quality(6);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(32, "cutting");
    set_wc(20, "impaling");
    set_wc(20, "plasma");
    set_wc(20, "electricity");
    set_wc(20, "vacuum");
    set_verb("slice");
    set_parry_bonus(30);
    set_wield( (: call_other, this_object(), "make_me_gm" :) );
    set_property("enchantment",20);
    set_enh_critical(2);
    set_weight(200);
    set_value(60);
    return;
}

int query_always_keep() { return 1; }
int make_me_gm() {
  object ob;

  //  the function below will handle all necessary checking, etc.
  seteuid(getuid());
  ob = new("/d/damned/guilds/alchemist/alchemist_obj");
  ob->make_me_master(this_player());
  return 1;
}


