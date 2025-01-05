#include <std.h>
#include "a1.h"

inherit "/std/guilds/spell_room_any";

void create() {
    ::create();
    set("short", "Global %^YELLOW%^BUFF%^RESET%^ spells");
  set("long", "This is a room that you can train Global %^YELLOW%^BUFF%^RESET%^ spells for all players. You need to join a guild to train spells for a specific guild to learn attack skills or spells.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set_join_room("/d/damned/guilds/join_rooms/child_join");


    add_exit(PATH+"spell_room_blade", "up");
    add_exit(PATH+"spell_room_elemental", "down");

//body alteration
add_spell("lich form", 1);
add_spell("divine transformation", 1);
//increase STR
add_spell("divine might", 1);
add_spell("enlarge", 1);
//haste
add_spell("increase metabolism", 1);
//increase stats
add_spell("blessing of knowledge", 1);
add_spell("blessing of agility", 1);
//harder to hit
add_spell("blur", 1);
//reflect damage but also takes damage
add_spell("scales of justice", 1);
//buff melee damage
add_spell("shocking grasp", 1);
add_spell("flamming grasp", 1);
add_spell("freezing grasp", 1);
//lots of combat in a single round
add_spell("mad rage", 1);
//haste
add_spell("holy fury", 1);
add_spell("battle fury", 1);
add_spell("haste", 1);
add_spell("unholy rage", 1);
add_spell("fury of marghuul", 1);
//shield spells
add_spell("battle aura", 1);
add_spell("energy shield", 1);
add_spell("fire shield", 1);
add_spell("force shield", 1);
add_spell("holy aura", 1);
add_spell("shields of war", 1);
//protection
add_spell("shield of ithian", 1);
add_spell("fire protection", 1);
add_spell("freeze skin", 1);
add_spell("dranaxar's anti-magic field", 1);
add_spell("holy armour", 1);
add_spell("holy ward", 1);
add_spell("unholy armour", 1);
add_spell("armour of oblivion", 1);
add_spell("armour of faith", 1);
add_spell("protection from chaos", 1);
//temp HP buff self cast only
add_spell("call divine strength", 1);
//see invis or see better
add_spell("detection", 1);
add_spell("dark vision", 1);
add_spell("holy awareness", 1);
add_spell("see invisible", 1);
add_spell("nether sight", 1);
//INVIS
add_spell("invisibility", 1);
add_spell("improved invisibility", 1);
//TEMP IMPREG
add_spell("holy mission", 1);
add_spell("vengeance of k'thach", 1);
add_spell("retribution of k'thach", 1);
add_spell("deus ex machina", 1);
add_spell("ceremony of purification", 1);
//immune to stun
add_spell("iron will", 1);
//resist spells
add_spell("strength of will", 1);
//AUTO HEAL
add_spell("combat healing", 1);
//images of self to distract
add_spell("mirror image", 1);
add_spell("strength in numbers", 1);
add_spell("clone", 1);
//OTHER not yet sorted
add_spell("fox's agility", 1);
add_spell("awareness", 1);
add_spell("ranger animal transformation", 1);
add_spell("scry guard", 1);
add_spell("way of the ranger", 1);
add_spell("animal transformation", 1);
add_spell("divine favor", 1);
add_spell("anti-magic field", 1);
add_spell("winged flight", 1);
//assasin spells
add_spell("total vanish", 1);
add_spell("black vision", 1);
add_spell("hawk eyes", 1);



    return;
}

