//	An example skill training room for the fighter's guild.
//
//	DarkeLIB 0.1
//	-Diewarzau 8/8/95
//
//      Edited by Tailwind
//
//      dbrLIB
//      Tailwind 01/25/01

#include <std.h>

inherit "/std/guilds/spell_room";

void create() {
  ::create();
  set("short", "The Shaman Training Room");
  set("long", "This is the room where shamen come to practice their natural spells.");
  //  "\n" important here, too.
  set_property("light", 2);
  set_property("indoors", 1);
  
  //  The following line is VERY, VERY important.
  set_join_room("/d/damned/guilds/join_rooms/shaman_join");

  set_exits( ([ "east" : "/d/damned/guilds/shaman/shaman_train_room" ]));
  
  //  All the rest is adding the skills.  The add_skill lines are of the
  //  following form:
  //  	add_skill(string skill, int level, int flag)
  //	skill 		The name of the skill which is being added
  // 	level		The level at which the player may begin
  //			developing the skill.
  //	flag		(optional)  If a non-zero number is supplied,
  //			the skill will be considered "secondary" to
  //			the guild and cost double to develop.

   add_spell("create jewel");
   add_spell("create natural sphere");
   add_spell("create orb");  
   add_spell("elemental ray");
   add_spell("gaia blast");
   add_spell("natural body armour");
   add_spell("natural boots");
   add_spell("essence capture");
//Broken spell FIXME   //add_spell("walk of the planes");
   add_spell("natural gauntlet");  
   add_spell("natural helmet");
   add_spell("natural leggings");
   add_spell("natural weapon");
   add_spell("nature's fury");
   add_spell("power of nature");
   add_spell("strength of nature");
   add_spell("summon aido-hwendo");
   add_spell("summon alan");
   add_spell("summon alicanto");
   add_spell("summon alu");
   add_spell("summon amarok");
   add_spell("summon ammut");
   add_spell("summon anka");
add_spell("spirit of nature");
//missing spell   //add_spell("summon baku");
   add_spell("summon bo");
   add_spell("summon brownie");
   add_spell("summon bunyip");
//missing spell   //add_spell("summon calygrehound");
   add_spell("summon chimera");
   add_spell("summon cockatrice");
   add_spell("summon crocotta");
   add_spell("summon dracae");
   add_spell("summon dryad");
   add_spell("summon ent");
   add_spell("summon feng-huang");
   add_spell("summon fire spirit");
   add_spell("summon garuda");
   add_spell("summon griffin");
   add_spell("summon harpy");
   add_spell("summon hippocampus");
   add_spell("summon hydra");
   add_spell("summon jinn");
   add_spell("summon kludde");
   add_spell("summon ky-lin");
   add_spell("summon leprechaun");
   add_spell("summon makara");
   add_spell("summon mermaid");
   add_spell("summon phoenix");
   add_spell("summon pixie");
   add_spell("summon pterippus");
   add_spell("summon shony");
   add_spell("summon unicorn");
   add_spell("summon valraven");
   add_spell("summon will o' the wisp");
return;
}
  
