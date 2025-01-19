
inherit "/std/guilds/npc_guildmaster";

//	He is set up identically to a monster.

void create() {
  object ob, ob2;

  ::create();

  //  The one difference is the following line:
  set_join_room("/d/damned/guilds/join_rooms/voidwalker_join");
  //  The above refers the guildmaster to the joining room, which
  //  handles all "book keeping"

  set("short", "[25]The Voidwalker Guildmaster");
  set("long", "The Voidwalker Guildmaster is surrounded by an aura of Darkness. "+
      "He is clad in a black robe with a huge sword in his "+
      "hands.  Forces of chaos have a formidable opponent in this champion" +
      " of void");
  set_level(25);
  set_max_hp(3500);
  set_hp(5000);
  set_max_mp(2000);
  set_mp(2000);
  set_overall_ac(60);
  set_property("base hp regen", 100);
  set_property("base mp regen", 50);
  set_gender("male");
  set("race", "human");
  set_body_type("human");
  set_id(({ "guildmaster", "voidwalker", "voidwalker guildmaster" }));
  //  NOTE:  It is important that, if you set_id, you include
  //  "guildmaster" as one of them.  If you do not set_id, he
  //  will still work.
  set_name("guildmaster");
  set_class("voidwalker");
  set_property("melee damage", ([ "crushing" : 20 ]));
  set_skill("melee", 150);
  set_skill("perception", 150);
  set_skill("concentrate", 150);
  set_skill("darkweaving", 150);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("two handed blade", 200);
  set_stats("strength", 130);
  set_skill("attack", 200);
  set_spell_level("absorption",6);
  add_spell("absorption", "$A");
  set_combat_chance(140);
/*  ob = new("/d/damned/guilds/voidwalker/weapons/gm_voidmaker");
  ob->move(this_object());
  ob2 = new("/d/damned/guilds/voidwalker/gm_item");
  ob2->move(this_object());
  force_me("equip");
*/force_me("use concentrate");
  return;
}

int query_num_rounds() { return 3; }

