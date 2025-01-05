#include <std.h>
#include "../keep.h"

/* This is a Level 40 mob that is a low to mid power mob for the black keep. They can be found all throughout the keeps first floor. The equipment they carry consists of 3 pieces of bone armour, which is about the same protection of steel armour forged by a mid to high level merchant. They effectively dual wield two stark white bone claws, which powerwise are about the same as the manor chaotic longswords. Despite being the same level as the snakes in the keeps exterior, their offense is higher but as a tradeoff their defense and hit points are lower. A player who can defeat the snakes and zombies outside shouldnt have much trouble at all with these creatures. */

inherit MONSTER;

void create() {
object ob;
::create();
set_name("undead warrior");
set_level(40);
set("id", ({ "warrior", "undead", "undead warrior" }));
set_short("[40]undead warrior");
set_long("Standing six feet tall, the undead warrior gazes upon you with red eyes coming from the holes in his skull mask. Armed with two claws and wearing well crafted bone armour, this soldier of war is indeed a fearsome looking opponent.");
set("race", "undead");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-700);
set_skill("knife", 400);
set_skill("attack", 300);
set_skill("parry", 250);
set_skill("dodge", 250);
set_skill("perception", 250);
set_skill("dual attack", 150);
set_skill("offhand training", 150);
ob = new(WEAP+"bone_claw.c");
ob->move(this_object());
ob = new(WEAP+"bone_claw.c");
ob->move(this_object());
ob = new(ARMOUR+"bone_greaves.c");
ob->move(this_object());
ob = new(ARMOUR+"bone_plate.c");
ob->move(this_object());
ob = new(ARMOUR+"bone_mask.c");
ob->move(this_object());
force_me("equip");
set_overall_ac(300);
return;
}
