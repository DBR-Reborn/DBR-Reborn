// Wizard: Avatar
// Monster: Carnifex
// /wizards/avatar/tyranid/mon/carnifex1.c
// October 15th, 1996

inherit "/std/monster";

int cd;

void create()
{
    ::create();
    set_name("carnifex");
    set("id",({"carnifex","tyranid"}));
    cd = 3;
    set_level(26);
    //set_exp(489308);
    set("aggressive",1);
    set("gang bang", 0);
    add_money("silver",random(20)+10);
    set("short","[26]Carnifex");
    set("long",
      "This monstrous creature is an incredibly advanced biowarrior used by the\n"
      +"Tyranids as a combination tank and artillery piece.  Its huge body is\n"
      +"massively plated with chitin armour, bony plates and underneith it all\n"
      +"is heavy muscle.  Four heavily plated scythe-like arms lash around the\n"
      +"abomination, cutting apart anything foolish enough to get close to it.\n"
      +"A special opening, where its mouth would be if it was primitive enough\n"
      +"to have to eat, shines with ugly green plasma, which the Carnifex can\n"
      +"project apalling distances for use as a bombardment weapon.\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",500,0,7);
    add_limb("torso","FATAL",700,0,7);
    add_limb("upper right striking arm","",400,0,7);
    add_limb("upper left striking arm","",400,0,7);
    add_limb("lower right striking arm","",400,0,7);
    add_limb("lower left striking arm","",400,0,7);
    add_limb("right leg","right hoof",600,0,7);
    add_limb("left leg","left hoof",600,0,7);
    add_limb("right hoof","",300,0,7);
    add_limb("left hoof","",300,0,7);
    set_melee_damage("cutting");
    set_wielding_limbs(({"upper right striking arm","upper left striking arm","lower right striking arm","lower left striking arm"}));
    set_overall_ac(1500);
}

void do_damage(string str, int arg)
{
    if (random(100) < 25) {
	message("combat",
	  "Your blow rings harmlessly off the Carnifex's thick chitin armour!\n",
	  all_inventory(environment()));
	return;
    }
    ::do_damage(str,arg);
}

void flash()
{
    int i;
    object *vic;
    if (cd > 0) {
	switch(cd) {
	case 5:
	    message(
	      "combat",
	      "Rasping plates on the Carnifex's torso begin to move against each other,\n"
	      +"emitting a metal-on-metal grinding sound.\n",
	      all_inventory(environment()));
	    break;
	case 4:
	    message(
	      "combat",
	      "The rasping plates more faster and faster, the grinding sound rising in\n"
	      +"pitch with every second.\n",
	      all_inventory(environment()));
	    break;
	case 3:
	    message(
	      "combat",
	      "The rasping plates on the Carnifex's chest are a near invisible blur and\n"
	      +"the earsplitting shriek causes the very air to shimmer.\n",
	      all_inventory(environment()));
	    break;
	case 2:
	    message(
	      "combat",
	      "The deafening shriek of the Carnifex's rasping plates fills the air as a\n"
	      +"faint emerald glow begins to fill the opening in its chest.\n",
	      all_inventory(environment()));
	    break;
	case 1:
	    message(
	      "combat",
	      "The Carnifex's unholy scream seems to fill your soul as a blinding green\n"
	      +"light glares from the opening in its chest, casting demonic shifting\n"
	      +"shadows behind you.\n",
	      all_inventory(environment()));
	    break;
	}
	cd--;
	return;
    }
    message(
      "combat",
      "With a clap of thunder that nearly blasts you from your feet, a star bright\n"
      +"sphere of emerald plasma vomits forth from the Carnifex to assault its\n"
      +"foes!\n",
      all_inventory(environment()));
    vic = all_inventory(environment());
    i = sizeof(vic);
    while(i--)
    {
	if (vic[i]->is_player()) {
	    vic[i]->kill_ob(this_object(),0);
	    vic[i]->do_damage((string)vic[i]->return_target_limb(),20+random(20));
	    do_critical(this_object(),vic[i],"plasma D");
	}
    }
    cd = 5;
    return;
}

heart_beat()
{
    ::heart_beat();
    catch(flash());
}
void init()
{
    ::init();
    add_action("no","up");
    add_action("no","down");
}

int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The Carnifex hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Carnifex blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
