#include <std.h>
#include "../keep.h"

/* The Large Snake is a Level 40 monster, which is present only in the outside of the black keep. In strength, it is comparable to that of a shard demon. It fights with good offense, and it also packs a powerful defense which requires those who fight it to use more powerful weapons than they would for zombies. They are basically considered the testing mob for those who wish to enter the black keep and not have huge fears of not coming out alive */

inherit MONSTER;

void create() {
::create();
set_name("snake");
set_level(40);
set_short("[40]large drooling snake");
set_long("Venom drips from the long fangs of this large snake. At a length of about fifteen feet, a thickness of a little over a foot, and protected by tough skin, it is more than prepared to feast on what it pleases.");
set("race", "reptile");
set_gender("neuter");
set_body_type("serpent");
set_max_hp(15000);
set_hp(15000);
set_overall_ac(500);
set_property("gang bang", 1);
set_alignment(-50);
set_skill("melee", 400);
set_skill("attack", 250);
set_skill("parry", 250);
set_skill("dodge", 250);
set_skill("perception", 300);
}
