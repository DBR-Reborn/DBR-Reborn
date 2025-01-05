#include <std.h>
#include "../ruins.h"

#define DBR "/d/damned/daybreak/rooms/"
#define GUILDS "/d/damned/guilds/join_rooms/" 

inherit MONSTER;


string *locations = ({DBR + "square", DBR + "south_entrance", DBR + "north_entrance", DBR + "ariel3", DBR + "lidfino1", DBR + "ridge3", DBR + "dbshop1", DBR + "dbshop4", DBR + "ridge5", DBR + "ariel6", DBR + "tavern", GUILDS + "elementalist_join", GUILDS + "tinker_join",  GUILDS + "enchanter_join"});

string *mobs = ({MON + "rat_adv_guard", MON + "rat_raider", MON + "rat_demon"});

void create() {
    object ob;

    ::create();
    set_name("rat lord");
    set("id", ({"rat", "lord", "rat_to_start_invasion"}) );
    set_property("extra cash", 4);
    set_level(30);
    set_property("enhance criticals",-5);
    set_max_hp(3000);
    set_hp(3000);
    set("short", "rat-lord");
    set("long", "The horrible creature before you is the most feared of all
rat-man, the rat-lord.  The rat-lord is a powerful magical being who has
all the rat's of the realm under his spells.  All the rat-lord wants is to
take over the world.");
   set("race", "rat");
   set_gender("male");
// set_money("mithril", 100+(random(25)));
   set_body_type("rat");
   set_overall_ac(70);
   set_overall_ac(70);
   set_skill("illusionism", 175);
   set_skill("conjuration", 175);
   set_skill("elementalism", 175);
   set_skill("chaos lore", 175);
   set_skill("necromancy", 175);
   set_skill("blade", 100);
   set_skill("concentrate", 175);
   set_languages( ({"common", "ratish"}) );
   set_combat_chance(90);
   add_spell("elemental bane", "$A");
   set_spell_level("elemental bane", 6);
   add_spell("fireball", "$A");
   set_spell_level("fireball", 6);
   add_spell("greater elemental bolt", "$A");
   set_spell_level("greater elemental bolt", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
   add_spell("decay", "$A");
   set_spell_level("decay", 6);
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   set_emotes(5, ({
               "The rat-lord eyes you suspiciously.",
               "The rat-lord sniffs you up and down.",
               "The rat-lord puts his nose to the air and laughs.",
               "The rat-lord mutters, \"Foolish mortal...\"",
                   }), 0);
   set_achats(20, ({
     "The rat-lord shouts, \"Your death will be like a thousand deaths,
foolish mortal!\"",
     "The rat-lord shouts, \"You will suffer the fate of all who are not
rats!\"",
     "The rat-lord shouts, \"You cannot defeat me!  I am the RAT-LORD!\"",
                   }) );
//   new(ITEM+"poison_sw.c")->move(this_object());
//    force_me("wield sword in right hand");
   force_me("use concentrate");
}

/*
varargs die() {
   object ob1;
   int x,y,z,w;

   message("shout", "Rat-lord shouts: "+ "Curse upon the mortal races. I will get my revenge upon all of you. Go forth my rat-man legions. Infest the cities of the world. Don't leave a single house standing. You shall feel my wrath!", users());
   x=25;
   while(x--){
     reset_eval_cost();
     y=random(sizeof(locations));
     z=random(sizeof(mobs));
     ob1 = new(mobs[z]);
     ob1->set_moving(1);
     ob1->set_speed(10);
     ob1->move(find_object_or_load(locations[y]));
   }
   ::die();

   return;
}
*/
