#include <std.h>

inherit MONSTER;


create() {
	::create();
        set_name("giant two-headed troll");
       set_id( ({"giant", "troll", "monster", "creature"}) );
       set_short("A giant two-headed troll");
        set_long(
"The ferocious troll-ettin crossbread stands 10 feet tall at both "
"heads. His skin is mottled greenish brown and he is dressed "
"in moth-eaten rags." );
        set_level(18);
	set_body_type("human");
        set("race", "troll");
        set_stats("strength", 140);
        set_stats("dexterity", 60);
        set_stats("constitution", 150);
       set_property("melee damage", ([ "cutting" : 30]));
        set_skill("melee", 120);
        set_overall_ac(20);
	set_gender("male");
        set_skill("whirlwind attack", 100);
        set_skill("dodge", 70);
	set_skill("attack", 30);
	set_skill("block", 40);
        set_spell_level("cure serious wounds", 6);
        add_spell("cure serious wounds", "$(ME)");
	set_combat_chance(120);
	set_property("ambidextry", 1);
	set("aggresive", 1);
  set("chase",1);
	set_skill("prayer", 100);
set_languages( ({"trollish"}) );
        set_speech(10, "Trollish", ({"Perfect timing, I'm hungry!"}) );
        set_money("gold", 200);
}
