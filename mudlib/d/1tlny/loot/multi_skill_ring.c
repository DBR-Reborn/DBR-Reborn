#include <std.h>
#include <clock.h>
#include <def.h>

inherit "/std/armour";

string zstat;
string mtlname;
string skill1;
int CLR;
//string skill2;

int last_used;

void init() {
   ::init();
   add_action("fun_ring","ring");
}

void set_znum(int x) { set_property("znum", x); }

void create() {
	::create();

switch(random(14)){
      case 0:mtlname="iron";break;
      case 1:mtlname="steel";break;
      case 2:mtlname="boernerine";break;
      case 3:mtlname="mcgrail";break;
      case 4:mtlname="neorolite";break;
      case 5:mtlname="catoetine";break;
      case 6:mtlname="raysorite";break;
      case 7:mtlname="inniculmoid";break;
      case 8:mtlname="elrodnite";break;
      case 9:mtlname="mithril";break;
      case 10:mtlname="platnite";break;
      case 11:mtlname="mabril";break;
      case 12:mtlname="iysaughton";break;
      case 13:mtlname="laen";break;
    }
switch(random(6)){
      case 0:zstat="strength";break;
      case 1:zstat="constitution";break;
      case 2:zstat="dexterity";break;
      case 3:zstat="charisma";break;
      case 4:zstat="intelligence";break;
      case 5:zstat="wisdom";break;
    }

    switch(random(12)){
      case 0:skill1="axe";break;
      case 1:skill1="blade";break;
      case 2:skill1="blunt";break;
      case 3:skill1="knife";break;
      case 4:skill1="flail";break;
      case 5:skill1="melee";break;
      case 6:skill1="attack";break;
      case 7:skill1="two handed blade";break;
      case 8:skill1="two handed blunt";break;
      case 9:skill1="two handed flail";break;
      case 10:skill1="two handed polearm";break;
      case 11:skill1="two handed staff";break;
    }

CLR= 20+random(199);

	set_name(mtlname+" ring");
	set("id",({mtlname+" ring","ring"}) );
   set_short("A %^COLOR"+CLR+"%^rare%^RESET%^ ring of supreme "+zstat+" and increased "+skill1+" skill");
	//set("long","This steel ring seems finely crafted and glows with some magical aura. Maybe if you did the commad %^YELLOW%^'ring summon bear'%^RESET%^ somthing might happen\n");
   set("long","This "+mtlname+" ring seems finely crafted and glows with some magical aura\n");
	set_type("ring");
	set_ac(4);
	set_limbs( ({"finger"}) );
	set_weight( 7 );
	set_value( 2000 );
   set_material("metal/"+mtlname);
   set_wear( (: call_other, this_object(), "extra_worn" :) );
   set_remove( (: call_other, this_object(), "extra_remove" :) );
   set_znum(1);
}


int extra_worn(){
   write("You feel the energy of the ring surge through your body. You feel a sensation of increaased skill in "+skill1+" as you wear this ring");
  //this_player()->add_stat_bonus(zstat, query_property("znum"));
    TP->add_skill_bonus(skill1, query_property("znum"));
  return 1;
}

int extra_remove(){
   write("You feel the energy of the ring releases from your body. You feel drained as your skill in "+skill1+" is decreased");
  //this_player()->add_stat_bonus(zstat, -(query_property("znum")));
    TP->add_skill_bonus(skill1, -(query_property("znum")));
  return 1;
}

/*
int fun_ring(string mesg) {
   object ob;

   if(!mesg) {
      notify_fail("ring what?\n");
      return 0;
   }
     if(mesg != "summon bear" && mesg != "Summon Bear") {
      notify_fail("Nothing appears to happen.\n");
      return 0;
   }

   if(time() - last_used < HOUR*12) {
     notify_fail("The ring is still recovering from massive energy drain.\n");
     return 0;
   }
   if(time() - last_used >= HOUR*12 || !last_used) {
      last_used = time();
       message("info", "You invoke the power of the ring "
            "A mystical cloud enshourds the area and a creature"
			"emerges which immediately walks up to its "
			"new master.", this_player());
		message("info", (string)this_player()->query_cap_name()+
			"Invokes the power of thr ring.  A pet emerges from "
			"the ring.", environment(this_player()),
			({ this_player() }) );
		seteuid(getuid());
      //ob = new("/d/1tlny/loot/summon/rabbit");
      ob = new("/d/1tlny/loot/summon/bear");
      //ob = new("/d/damned/guilds/nethermancer/pets/dark_knight");
		//ob = new("/d/damned/guilds/nethermancer/pets/eternal_darkness");
		//ob = new("/d/damned/guilds/nethermancer/pets/death_dragon");
		//ob = new("/d/damned/guilds/nethermancer/pets/nether_lord");
		//ob = new("/d/damned/guilds/nethermancer/pets/undead_beast");
		//ob = new("/daemon/db/crit/mon/a11");
		ob->set_up();
		ob->set_owner((string)this_player()->query_name());
		ob->move(environment(this_player()));
      return 1;
   }

}
*/
