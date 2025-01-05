#include <std.h>
#include "../keep.h"

/* At level 50, this is one of the medium powered monsters in the black keep. They are present both on the first floor of the keep and in the basement level. They were one piece of armour, a blood red robe which covers 5 limbs, and offers the same protection as the bone armour worn by other monsters in the keep. In addition to powerful melee, they also ultilize the ability to drain life from its opponents. They are the first monsters in the keep that are significantly above the monsters in the keeps exterior in power. It is generally recommended to have armour better than steel or mob armour plus a decently powerful weapon before trying to face these guys. */ 

inherit MONSTER;

void create() {
object ob;
::create();
set_name("vampiric demon");
set_level(50);
set_combat_chance(120);
set_property("gang bang", 1);
set_property("no corpse", 1);
set("id", ({ "demon", "vampire", "vampiric demon", "vampire demon" }));
set_short("[50]vampiric demon");
set_long("Pale as a ghost with eyes and features of a demon, the vampiric demon is a powerful cross of an undead spirit and a hell spawn. Covered in a bright blood red robe, and looking you over with its sharp fangs exposed, you can tell almost right away that it is hungry, and is likely considering having you as a snack.");  
set("race", "demon");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-900);
set_skill("melee", 500);
set_skill("martial arts", 250);
set_skill("attack", 400);
set_skill("parry", 350);
set_skill("dodge", 350);
set_skill("perception", 350);
set_skill("shadow lore", 400);
set_skill("concentrate", 100);
add_spell("absorption", "$A");
set_spell_level("absorption", 6);
ob = new(ARMOUR+"red_robe.c");
ob->move(this_object());
force_me("equip");
force_me("use concentrate");
set_overall_ac(500);
set_die("%^CYAN%^As the Vampiric Demon falls to the ground, its corpse transforms into a thick mist and quickly vanishes.%^RESET%^");
return;
}
