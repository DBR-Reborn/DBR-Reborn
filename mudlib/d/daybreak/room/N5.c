//TLNY2025
#include <config.h>
#include "../daybreak.h"
//ADD
#include <std.h>
#include <daemons.h>
#include <security.h>
//END
inherit "std/room";

int cmd_reinc(string str) {
  object who = this_player();
  object join_room, *inv;
  int lev, i;
  string *langs;

/*
 if (who->query_money("gold") < 100) {
        message("info", "You do not have enough money to reincarnate.", who);
        return 1;
    }

    who->add_money("gold", -100);
    message("info", "You have paid 100 gold for the reincarnation service.", who);
*/

  who->remove_property("luck");
  who->remove_property("limb regen");
  who->remove_property("ambidextry");
  who->remove_property("flying");
  who->remove_property("natural ac");
  who->remove_property("extra hbeat");
  who->remove_property("extra hp regen");
  who->remove_property("extra mp regen");
  who->remove_property("sp points");
  who->remove_property("sp skills");
  who->remove_property("sp spells");
//ADD TLNY2025
  who->remove_property("dev cost");
  who->remove_property("xp mod");
  who->remove_property("magic resistance");
  who->remove_property("stat_points");
//END
  
  who->reset_quests();
  langs = (string *)who->query_all_languages();
  if(langs && pointerp(langs) && (i=sizeof(langs))) {
    while(i--) who->remove_language(langs[i]);
  }
  inv = filter_array(all_inventory(who), (: call_other :),
    "query_auto_load");
  if(inv && sizeof(inv)) {
    i = sizeof(inv);
    while(i--)
      if(!inv[i]->id("clan symbol")) inv[i]->remove();
  }
  who->init_skills();
  who->set_property("reincarnate", 1);
  who->init_spells();
  if(who->query_class() && (string)who->query_class() != "child") {
    join_room = find_object_or_load("/d/damned/guilds/join_rooms/"+
          (string)who->query_class() + "_join");
    join_room->kick_member((string)who->query_name());
  }
 
  //HONSPRON cross training
  if(who->query_property("cross guild")){
    join_room = find_object_or_load("/d/damned/guilds/join_rooms/"+
          (string)who->query_property("cross guild") + "_join");
    join_room->kick_member((string)who->query_name());
    who->remove_property("cross guild");
  }
//end
  who->set_property("xp mod", 0);
  lev = (int)who->query_level();
  if(lev < 1) lev = 1;

    //who->set_property("old exp", (int)ADVANCE_D->get_exp(lev) + 150);
//ADD //TLNY2025 Keep original EXP for the level
who->set_property("old exp", (int)ADVANCE_D->get_exp(lev) + (who->query_exp() - (int)ADVANCE_D->get_exp(who->query_level())));
//END
  who->set_level(1);
  who->add_exp(-1 * (int)who->query_exp());
  who->reset_max_exp();
  who->move_player("/d/standard/setterreinc", 0);
  seteuid(UID_LOG);
  //log_file("reinc", sprintf("FREE reinc: %s to %s on %s.\n", (string)previous_object()->query_name(), (string)who->query_name(), ctime(time())));
  message("info", "%^CYAN%^%^BOLD%^You have been reincarnated!",who);
  message("info",
  "\n     You may re-create your character now.  Afterward, you may "
  "join a guild as usual.  All of your former exp has been transferred "
  "into a 'exp bank,' and you may access it by typing 'advance'.  That "
  "will advance your level by 1 each time you type it, until you "
  "are out of exp.  If you advance your level naturally, you will "
  "forfeit ALL REMAINING EXP in the bank!", who);
  write((string)who->query_cap_name() + " has been reincarnated.");
  return 1;
}



void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);

    set_property("no scry", 1);
    set_property("no summon", 1);
	set_property("no teleport",1);
    set_property("no attack", 1);
    set_property("no cast", 1);



 
set("short", "Reincarnate Room");
set("long", @EndText
Welcome to the Reincarnate Room!

You’ve been invited here by TLNY to explore the opportunity for growth and balance in your character's development. It seems you've acquired skills, spells, or abilities that are not in alignment with our updated MUD rules and regulations.

To embrace a fresh start and optimize your journey, simply type '%^YELLOW%^reincarnate%^RESET%^'. This process will help you refine your character and enhance your gameplay experience.

If you believe there has been a misunderstanding regarding your skills, you’re welcome to appeal your case directly to TLNY. However, please keep in mind that if your appeal is not successful, you may find yourself needing to reincarnate, along with a temporary adjustment to your levels.

This is a chance for you to evolve and create a more balanced character. We appreciate your understanding and cooperation as we strive to maintain a fair and enjoyable environment for all players!
EndText
);
}

void init() {
    ::init();
    add_action("cmd_reinc", "reincarnate");
}

