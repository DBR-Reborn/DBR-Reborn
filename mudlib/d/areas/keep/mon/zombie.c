#include <std.h>
#include "../keep.h"

/* This is a Level 35 mob designed as a lower mob for the black keep area. They reside only in the misty field surrounding the keep. They carry two pieces of armour which are both worthless, both in defense and for selling purposes, and use melee to fight. Powerwise they are roughly the same as a thief from the thieves den, maybe slightly tougher. */

inherit MONSTER;

void create() {
object ob;
::create();
set_name("zombie");
set_level(35);
set_short("[35]moaning zombie");
set_long("This is an ugly zombie, with dark green skin and extremely old tattered clothing. It appears to have no eyes in its sockets and it constantly lets out depressing moans.");
set("race", "zombie");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-600);
set_skill("melee", 300);
set_skill("attack", 200);
set_skill("parry", 200);
set_skill("dodge", 200);
set_skill("perception", 200);
ob = new(ARMOUR+"shredded_pants.c");
ob->move(this_object());
ob = new(ARMOUR+"tattered_shirt.c");
ob->move(this_object());
force_me("equip");
return;
}
