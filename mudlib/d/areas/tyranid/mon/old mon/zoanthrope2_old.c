#include "../a1.h"

// Wizard: Avatar
// Monster: Zoanthrope
// /wizards/avatar/tyranid/mon/zoanthrope2.c
// October 15th, 1996

inherit "/std/monster";

object vic;
int cd;

void init() {
    :: init();
    add_action("no","up");
    add_action("no","down");
    if(!this_player()->is_player()) { return ; }
    vic = this_player();
    return ;
}

void create()
{
    ::create();
    set_name("zoanthrope");
    set("id",({"zoanthrope","tyranid"}));
    set_level(24);
    //set_exp(365030);
    set("aggressive",0);
    set("gang bang", 0);
    add_money("silver",random(20)+10);
    set("short","[24]Zoanthrope");
    set("long",
      "This strange creature looks as if it began life as a Tyranid warrior.\n"
      +"Clearly something has happened to the creature though...it is grossly\n"
      +"fat, so huge that it can barely drag is bloated body around with its\n"
      +"oddly atrophied limbs.  For a Tyranid to be in this state though, you\n"
      +"can be asured that there is a potent reason.  The baleful light shining\n"
      +"from its eyes and its oddly blurred outline probably have something to\n"
      +"do with it though...\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",550,0,7);
    add_limb("torso","FATAL",650,0,7);
    add_limb("atrophied arm one","",65,0,0);
    add_limb("atrophied arm two","",65,0,0);
    add_limb("atrophied leg one","",65,0,0);
    add_limb("atrophied leg two","",65,0,0);
    add_limb("atrophied leg three","",65,0,0);
    add_limb("atrophied leg four","",65,0,0);
    set_overall_ac(240);
}

void do_damage(string str, int arg)
{
    if (random(100) < 30) {
	message("combat",
	  "The Zoanthrope glares balefully as your blow passes completely\n"
	  +"through its body without having the slightest effect!\n",
	  all_inventory(environment()));
	return;
    }
    ::do_damage(str,arg);
}

void flash(object tp)
{
    if (!tp || !present(tp,environment())) return;
    if (cd > 0) {
	cd--;
	return;
    }
    /*
	message("combat",
	  "A bolt of brilliant violet energy lances out from the Zoanthrope's\n"
	  +"eyes, transfixing "+vic->query_name()+"!\n",
	  all_inventory(environment()),
	  vic);
	message("combat",
	  "A bolt of brilliant violet energy lances out from the Zoanthrope's\n"
	  +"eyes, transfixing you with its unearthly chill!\n",
	  vic);
    */
    tp->kill_ob(this_object(), 0);
    tp->do_damage((string)tp->return_target_limb(),3 * random(10)+2);
    do_critical(this_object(),tp,"aether C");      
    cd = 2;
    return;
}

heart_beat()
{
    ::heart_beat();
    catch(flash(vic));
}
int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The Zoanthrope hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Zoanthrope blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
