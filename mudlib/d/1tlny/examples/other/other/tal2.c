  //           Arctic --Teacher Mob - 7/2/97
  //           
  //             Taken from:
  //     An example skill training room for the fighter's guild.
  //     DarkeLIB 0.1
  //     -Diewarzau 8/8/95
  //                        &&
  //            Maxwell's Underground Mud Library
  //                Thief Trainer


#include <std.h>
#include <under.h>

inherit "/wizards/arctic/test/skill_mon2";
inherit UNEQP;

  object money;
  create() {
      ::create();
     set_name("tal");
     set_id( ({ "tal","Tal","trainer" }) );
     set_short("Tal the multi-talented Trainer");
     set_level(20);
     set_max_hp(2500);
     set_hp(2500);
     set("long", "Tal is kneeling before you in all his glory.");
     set_gender("male");
     set("race", "dwarf");
     set_alignment(0);
     set_wielding_limbs( ({"right hand","left hand"}) );
     set_body_type("human");
     set_emotes(2,
        ({ "Tal lets you know he is alive.",}),0 );
      set_achats(25,
        ({ "Tal falls to his knees begging you to make him work.",}) );
  // Spell Code
  //    set_combat_chance(80);
  //    add_spell("heal","$(ME)"); 
  //    set_spell_level("heal",6);
  //    add_spell("harm","$A");
  //    set_spell_level("harm",6);
  //    add_spell("internal flame","$A");
  //    set_spell_level("internal flame",2); 
  //
  // Skills For Spells and Combat
  //
  //  All the rest is adding the skills.  The add_skill lines are of the
    //  following form:
    //   add_skill(string skill, int level, int flag)
    //   skill           The name of the skill which is being added
    //   level           The level at which the player may begin
    //                   developing the skill.
    //   flag            (optional)  If a non-zero number is supplied,
    //                   the skill will be considered "secondary" to
    //                   the guild and cost double to develop.
      add_skill("conjuration",95);
      add_skill("magery",1);
      add_skill("prayer",1,1);
      set_skill("resist stun",115);
      set_skill("blade",100);
      set_skill("two handed polearm",1,1);
      set_skill("two handed blade",1);
      set_skill("parry",115);
      set_skill("defense",115);
      set_skill("dodge",120);  
  // Money Code
      money=new("std/obj/coins");
      money->set_money("gold",(random(50)+200));
      money->move(this_object());
  //Equipment Code
      mob = this_object();
      wield_hand = "right hand";
  //Misc
      set("aggressive",0 );
      set_languages( ({ "dwarvish","elvish" }) );
     
  }

  void die(object who) {
    ::die(who);
    return;
  }

void directed_message(object from,string str) {
string req,skill;
write("first directed function started, write");
force_me("say directed function started, force");
say("first directed function started, say");
force_me("tell "+getuid(this_player())+" you wann train force tell");
force_me("tell "+getuid(from)+" you wann train force tell");
force_me("tell "+getuid(from)+" you wann train force tell2");

       if( sscanf(str,"%s %s",req,skill) == 2){
force_me("say first sscanf statement started, forced");
say("first sscanf statement starte, say");
write("first sscanf statement started, write");
         if(req == "train"){  
force_me("say first if statement started, forced");
write("first if statement started, write");
say("first if statement starte, say");
           if(present(from)) force_me("say You wanna train eh?");     
// Test remark
force_me("tell "+getuid(this_player())+" You wanna train eh?");
force_me("tell "+getuid(from)+" You wanna train too eh?");
           train_skill(skill, from);
  //       call_other(environment(this_object()),"train_skill",skill,from);
       }
        else if(req == "list" && skill == "skills"){
// Test remark
write("You have asked to list the skills");
say("You have asked to list the skills");
              force_me("say These are the skills I can train you in, ");
  //         call_other(environment(this_object()),"list_skills","skills");
            list_skills("skills");
           }
        else
     {
           force_me("say eh? I'm here to help "
           "you train your skills! Not to listen to you babble!");
        return;
     }
       }
       if(str == "train") {
      force_me("say What do you want to do?");
     }
       else if(str == "help")
          force_me("tell "+getuid(this_player())+" I'm here to help you "
           "train new skills. Just tell me what you want to train or "
           "you can ask to see the list of skills.");
       else
          force_me("tell "+getuid(this_player())+" If you're totally "
           "clueless you could try asking me for help!");    
       return;
  }

