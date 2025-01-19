#include "move.h"
#include <std.h>

inherit DAEMON;

int cmd_aspells() {
	//object ob;

    write("\n%^BOLD%^Active Spells:");

      if(this_player()->query("long term") == 1) {
        write("%^RED%^long term");
      }
    
	if(this_player()->query("disguise shad")) {
     write("%^CYAN%^alter visage");
      }
      if(this_player()->query("anger charge #") == 1) {
     write("%^CYAN%^anger charge");
      }
      if(this_player()->query("anger charge #") == 2) {
     write("%^CYAN%^anger charge (2)");
      }
     /* if(this_player()->query("a trans shadow")) {
     write("%^CYAN%^animal transformation");
      }*/
      if(this_player()->query("faith armour #") == 1) {
        write("%^CYAN%^armour of faith");
      }
      if(this_player()->query("faith armour #") == 2) {
        write("%^CYAN%^armour of faith (2)");
      }
      if(this_player()->query("faith armour #") == 3) {
        write("%^CYAN%^armour of faith (3)");
      }
      if(this_player()->query("faith armour #") == 4) {
        write("%^CYAN%^armour of faith (4)");
      }
      if(this_player()->query("faith armour #") == 5) {
        write("%^CYAN%^armour of faith (5)");
      }
      if(this_player()->query("faith armour #") == 6) {
        write("%^CYAN%^armour of faith (6)");
      }
      if(this_player()->query_stack("ram") == 1) {
        write("%^CYAN%^armour of oblivion");
      }
      if(this_player()->query_stack("ram") >= 2) {
        write("%^CYAN%^armour of oblivion (2)");
      }
      if(this_player()->query("awares #")) {
     write("%^CYAN%^awareness");
     }
     if(this_player()->query_battle_aura()) {
        write("%^CYAN%^battle aura");
      }
     if(this_player()->query("bfury #")) {
      write("%^CYAN%^battle fury");
      }
      if(this_player()->query_stack("ldemon armour") == 1) {
      write("%^CYAN%^bind lesser demon");
     }
      if(this_player()->query_stack("ldemon armour") == 2) {
      write("%^CYAN%^bind lesser demon (2)");
     }
      if(this_player()->query_stack("ldemon armour") == 3) {
      write("%^CYAN%^bind lesser demon (3)");
     }
     if(this_player()->query_stack("demon armour") == 1) {
      write("%^CYAN%^bind demon");
     }
      if(this_player()->query_stack("demon armour") == 2) {
      write("%^CYAN%^bind demon (2)");
     }
      if(this_player()->query_stack("demon armour") == 3) {
      write("%^CYAN%^bind demon (3)");
     }
     if(this_player()->query_stack("gdemon armour") == 1) {
      write("%^CYAN%^bind greater demon");
     }
      if(this_player()->query_stack("gdemon armour") == 2) {
      write("%^CYAN%^bind greater demon (2)");
     }
      if(this_player()->query_stack("gdemon armour") == 3) {
      write("%^CYAN%^bind greater demon (3)");
     }
     if(this_player()->query_stack("demonl armour") == 1) {
      write("%^CYAN%^bind demon lord");
     }
      if(this_player()->query_stack("demonl armour") == 2) {
      write("%^CYAN%^bind demon lord (2)");
     }
      if(this_player()->query_stack("demonl armour") == 3) {
      write("%^CYAN%^bind demon lord (3)");
     }
     if(this_player()->query("mass bind")) {
      write("%^CYAN%^bind mass");
      }
      if(this_player()->query("blckvision #")) {
      write("%^CYAN%^black vision");
      }
     if(this_player()->query("a bless num") >= 2) {
        write("%^CYAN%^blessing of agility (2)");
      }
      if(this_player()->query("a bless num") == 1) {
        write("%^CYAN%^blessing of agility");
      }
      if(this_player()->query("k bless num") >= 2) {
        write("%^CYAN%^blessing of knowledge (2)");
      }
      if(this_player()->query("k bless num") == 1) {
        write("%^CYAN%^blessing of knowledge");
      }

     if(this_player()->query_blurred()) {
     write("%^CYAN%^blur");
     } 
     if(this_player()->query_black_vision()) {
     write("%^CYAN%^black vision");
     }
      if(this_player()->query("bofe #")) {
     write("%^CYAN%^body of elements");
     }
     if(this_player()->query("chaos prot #") == 1) {
      write("%^CYAN%^chaos bane");
     }
      if(this_player()->query("chaos prot #") == 2) {
      write("%^CYAN%^chaos bane (2)");
     }
      if(this_player()->query("chaos prot #") == 3) {
      write("%^CYAN%^chaos bane (3)");
     }
     if(this_player()->query("c bless num") >= 2) {
        write("%^CYAN%^chaos power (2)");
      }
      if(this_player()->query("c bless num") == 1) {
        write("%^CYAN%^chaos power");
      }
     if(this_player()->query("com_heal #")) {
      write("%^CYAN%^combat healing");
     }
	 if(this_player()->query("drkvision #")) {
      write("%^CYAN%^dark vision");
      }
      if(this_player()->query("demonhaste #")) {
        write("%^CYAN%^demon haste");
      }
      if(this_player()->query("deusex #")) {
        write("%^CYAN%^deus ex machina");
      }
      if(this_player()->query("daware #")) {
        write("%^CYAN%^demonic awareness");
      }
     if(this_player()->query_favor_num() >= 1) {
      write("%^CYAN%^divine favor");
     }
   	 if(this_player()->query("divine might #") == 1) {
      write("%^CYAN%^divine might");
     }
/*
      if(this_player()->query("divine might #") == 2) {
      write("%^CYAN%^divine might (2)");
     }
      if(this_player()->query("divine might #") == 3) {
      write("%^CYAN%^divine might (3)");
     }
*/

     if(this_player()->query_etrans()) {
     write("%^CYAN%^elemental transformation");
     }
     if(this_player()->query_d_trans()) {
     write("%^CYAN%^divine transformation");
     }
     if(this_player()->query_stack("eshield") == 1) {
      write("%^CYAN%^energy shield");
     }
      if(this_player()->query_stack("eshield") == 2) {
      write("%^CYAN%^energy shield (2)");
     }
      if(this_player()->query_stack("eshield") == 3) {
      write("%^CYAN%^energy shield (3)");
     }
     if(this_player()->query_fire_shield()) {
     write("%^CYAN%^fire shield");
     }
     if(this_player()->query_f_grasp()) {
     write("%^CYAN%^flamming grasp");
     }
     if(this_player()->query_stack("fshield") == 1) {
      write("%^CYAN%^force shield");
     }
      if(this_player()->query_stack("fshield") == 2) {
      write("%^CYAN%^force shield (2)");
     }
      if(this_player()->query_stack("fshield") == 3) {
      write("%^CYAN%^force shield (3)");
     }
     if(this_player()->query("f bless num") >= 2) {
        write("%^CYAN%^fox’s agility (2)");
      }
      if(this_player()->query("f bless num") == 1) {
        write("%^CYAN%^fox’s agility");
      }
      if(this_player()->query("freeze skin #") == 1) {
     write("%^CYAN%^freeze skin");
     }
    if(this_player()->query("freeze skin #") == 2) {
     write("%^CYAN%^freeze skin (2)");
     }
     if(this_player()->query("fzgrasp #")) {
     write("%^CYAN%^freezing grasp");
     }
     if(this_player()->query("flgrasp #")) {
     write("%^CYAN%^flamming grasp");
     }
     if(this_player()->query("fofm #")) {
     write("%^CYAN%^fury of marghuul");
     }
    if(this_player()->query("gasform #")) {
     write("%^CYAN%^gaseous form");
     }
     if(this_player()->query("hste #")) {
     write("%^CYAN%^haste");
     }
     if(this_player()->query("hawkeye #")) {
     write("%^CYAN%^hawk eyes");
     }
     if(this_player()->query("holy armour #") == 1) {
        write("%^CYAN%^holy armour");
      }
/*
      if(this_player()->query("holy armour #") == 2) {
        write("%^CYAN%^holy armour (2)");
      }
      if(this_player()->query("holy armour #") == 3) {
        write("%^CYAN%^holy armour (3)");
      }
      if(this_player()->query("holy armour #") == 4) {
        write("%^CYAN%^holy armour (4)");
      }
      if(this_player()->query("holy armour #") == 5) {
        write("%^CYAN%^holy armour (5)");
      }
      if(this_player()->query("holy armour #") == 6) {
        write("%^CYAN%^holy armour (6)");
      }
*/
      if(this_player()->query_holy_aura()) {
        write("%^CYAN%^holy aura");
      }
      if(this_player()->query("haware #")) {
        write("%^CYAN%^holy awareness");
      }
      if(this_player()->query("holyfury #")) {
        write("%^CYAN%^holy fury");
      }
      if(this_player()->query_mission()) {
        write("%^CYAN%^holy mission");
      }
      if(this_player()->query_stack("holy ward") == 1) {
        write("%^CYAN%^holy ward");
      }
      if(this_player()->query_stack("holy ward") == 2) {
        write("%^CYAN%^holy ward (2)");
      }
      if(this_player()->query_stack("holy ward") == 3) {
        write("%^CYAN%^holy ward (3)");
      }
      if(this_player()->query("imp invis #")) {
        write("%^CYAN%^improved invisibility");
      }
      if(this_player()->query("metab #")) {
     write("%^CYAN%^increase metabolism");
     }
     if(this_player()->query("ind spirit #")) {
     write("%^CYAN%^indomitable spirit");
     }
     if(this_player()->query("infravision #")) {
     write("%^CYAN%^infravision");
     }
     if(this_player()->query("invisibility #")) {
        write("%^CYAN%^invisibility");
      }
      if(this_player()->query("iron will #")) {
        write("%^CYAN%^iron will");
      }
      if(this_player()->query("kdetect #")) {
        write("%^CYAN%^keen detection");
      }
      if(this_player()->query_stack("lshadow field")) {
        write("%^CYAN%^lesser shadow field");
      }
      if(this_player()->query("lev #")) {
        write("%^CYAN%^levitation");
      }
      if(this_player()->query_lichform()) {
        write("%^CYAN%^lich form");
      }
      if(this_player()->query("nether sight #")) {
        write("%^CYAN%^nether sight");
      }
      if(this_player()->query("oweeyes #")) {
        write("%^CYAN%^owedquar’s eyes");
      }
      if(this_player()->query("fury charge #") == 1) {
     write("%^CYAN%^owedquar’s fury");
      }
      if(this_player()->query("fury charge #") == 2) {
     write("%^CYAN%^owedquar’s fury (2)");
      }
      if(this_player()->query("owedquar's wrath #")) {
        write("%^CYAN%^owedquar’s wrath");
      }
   	  	 if(this_player()->query("chaos prote #") == 1) {
        write("%^CYAN%^protection from chaos");
      }
      if(this_player()->query("chaos prote #") == 2) {
        write("%^CYAN%^protection from chaos (2)");
      }
      if(this_player()->query("chaos prote #") == 3) {
        write("%^CYAN%^protection from chaos (3)");
      }
      if(this_player()->query("ret_kthach # #")) {
        write("%^CYAN%^retribution of k’thach");
      }
      if(this_player()->query("justice #")) {
        write("%^CYAN%^scales of justice");
      }
      if(this_player()->query("scryguard")) {
        write("%^CYAN%^scry guard");
      }
      if(this_player()->query("see invis")) {
        write("%^CYAN%^see invisible");
      }
   	 if(this_player()->query_stack("shadow field")) {
        write("%^CYAN%^shadow field");
      }
      if(this_player()->shadow_form()) {
        write("%^CYAN%^shadow form");
      }

	 if(this_player()->query_stack("rap") >= 2) {
        write("%^CYAN%^shield of ithian (2)");
      }
     if(this_player()->query_stack("rap") == 1) {
        write("%^CYAN%^shield of ithian");
      } 
	if(this_player()->query_shields_of_war()) {
        write("%^CYAN%^shields of war");
      }
      if(this_player()->query_s_grasp()) {
        write("%^CYAN%^shocking grasp");
      }
      if(this_player()->query_mag_stealth()) {
        write("%^CYAN%^silent walk");
      }
      if(this_player()->query("sofw #")) {
        write("%^CYAN%^strength of will");
      }
      if(this_player()->query("totalvanish #")) {
        write("%^CYAN%^total vanish");
      }
       if(this_player()->query("transmutation")) {
        write("%^CYAN%^transmutation");
      }
       if(this_player()->query_stack("unholy armour") == 1) {
        write("%^CYAN%^unholy armour");
      }
      if(this_player()->query_stack("unholy armour") == 2) {
        write("%^CYAN%^unholy armour (2)");
      }
      if(this_player()->query("un_rage #")) {
        write("%^CYAN%^unholy rage");
      }
      if(this_player()->query("unholy will #")) {
        write("%^CYAN%^unholy will");
      }
      if(this_player()->query("ven_kthach #")) {
        write("%^CYAN%^vengeance of k’thach");
      }
      if(this_player()->query("wotr #")) {
        write("%^CYAN%^way of the ranger");
      }
      if(this_player()->query("wflight #")) {
        write("%^CYAN%^winged flight");
      }
      
      if(this_player()->query("concentrate") == 1) {
      	write("%^COLOR56%^%^BOLD%^concentrate");
      }
      /*if(this_player()->query_last_use("fast attack") <= 0) {
      	write("%^COLOR56%^%^BOLD%^fast attack");
      }*/
      
      if(this_player()->query("syphon #") >= 1) {
      	write("%^RED%^%^BOLD%^syphon soul");
      }
      if(this_player()->query("decay #") >= 1) {
      	write("%^RED%^%^BOLD%^decay");
      }
      if(this_player()->query_curse_num() >= 1) {
      	write("%^RED%^%^BOLD%^curse");
      }

      write("\n");
      return 1;
}

int
help() {
   write("Command: aspells\nSyntax: aspells\n"+
      "This command gives you a list of active spells\n"+
      "if your lucky.\n"
   );
   return 1;
}
/* EOF 

*/


