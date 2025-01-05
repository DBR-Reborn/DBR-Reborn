/*
 [admin : Thrace] Caltrops: caltrops resemble large metal jacks with sharp
pointed ends rahter than balls on the ends of their arms.  They are
essentially iton spikes designed so that one point is always facing up. 
You scatter them on the ground in the hope that your enemies step on them
or are at least forced to slow down to avoid them.  One bag of caltrops
covers an area 5 feet squared.  Each time a creature moves into an area
covered by caltrops, the creature may step on one.  The caltrops make an
attack roll against the creatue.  For this attack, the creatures shield and
armor deflection bonus do no count.  If the creature is wearing shoes or
other footwear however it gets a +2 armor bonus to AC.  If the caltrops
succeed at the attack, the creatue has stepped on one.  The caltrop deals 1
point of damage and the creatures movement is reduced by 1/2.
*/
#include <colors.h>

#define TP this_player()

inherit "/std/Object";

string owner;
string *exits;
object here;
string *ok_people = ({});
int skill = 50;

int get() { return 0; }

void set_skill(int x){ skill = x; }
void set_owner(string str){ owner = str; }

void create()
{
    ::create();
    set_short("caltrops");
    set_long("These spikey things cover the floor.  "+
      "The spikes puncture your boots, and hurt your feet.  "+
      "Movement isnt easy.");
    set_id( ({"trops", "caltrops", "drops", "spikes", "caltrop"}) );
}

void init()
{
    int i;
    ::init();
    if(living(environment(this_object())))
	return;
    here = environment(this_object());
    exits = here->query_exits();
    for(i = 0; i < sizeof(exits); i++)
	add_action("ouch", exits[i]);
}

void add_safe(string str){
    if(member_array(str, ok_people) != -1)
	return;
    ok_people += ({ str });

}

int ouch(string str){
    string name = TP->query_name();
    int dodged, ghost, safe;

    if(random(TP->query_skill("dodge")) > random(skill))
	dodged = 1;
    if(member_array(name, ok_people) != -1)
	safe = 1;
    if(TP->query_ghost())
	ghost = 1;

    if(owner == name)
	return 0;

    if(dodged || safe){
	write( CBOLD + CMAGENTA + 
	  "There were some caltrops here, but you kick them out of the way");
	message("info",
	  TP->query_cap_name() + " nimbly kicks some spikes out of the way.",
	  all_inventory(environment(TP)), TP);
	remove();
	return 0;
    }
    if(ghost){
	remove();
	return 0;
    }

    write(
      CBOLD + CRED + "Ouch, spikes are all over the floor!  "+
      "You start searching for a way through them.  ");
    message("info", CBOLD + CRED + 
      TP->query_cap_name() + " screams in pain after "+
      "stepping on sharp spikes on the floor.",
      all_inventory(environment(TP)), TP);

    if(random(skill) > random(TP->query_stats("dexterity")))
	TP->knock_down();

    if(random(skill) > random(TP->query_stats("strength")))
	TP->set_property("bleeding", 2 + (int)TP->query_property("bleeding"));

    if(random(skill) > random(TP->query_stats("constitution")))
	TP->set_paralyzed(1);

    if(random(100) > 90)
	TP->do_damage("left foot", skill / 10);
    if(random(100) > 90)
	TP->do_damage("right foot", skill / 10);
    if(random(100) == 88)
	TP->do_damage("left foot", skill / 5);
    if(random(100) > 86)
	TP->do_damage("right foot", skill / 5);

    call_out("add_safe", 5, name);
    return 1;
}


