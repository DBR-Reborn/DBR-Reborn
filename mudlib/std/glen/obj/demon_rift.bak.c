#include <move.h>
#include <rooms.h>
#include <daemons.h>
#include <colors.h>

inherit "/std/Object";

string caster = "rogue";
int    power = 100;
int    duration   = 100;

string where_to = "/std/glen/rooms/room_50_50.demon_plane";

string query_owner(){
    return caster;
}

void init() {
    ::init();
    add_action("go_exit", "enter");
}

void set_to(string str){
    where_to = str;
}

string query_to(){ return where_to; }

int go_exit(string str){
    if(str != "rift")
	return 0;
    message("info", CBOLD + CGREEN + 
      "You step through the rift!",
      this_player());
    message("info", CBOLD + CGREEN + 
      this_player()->query_cap_name() +
      " steps through a rift!",
      all_inventory(environment(this_player())), this_player());
    this_player()->move(where_to);
    this_player()->force_me("look");
}

void remove_me() {
    message("info", CBOLD + CBLUE + "A planar rift closes." +
      CRESET,
      environment());
    remove();
    return;
}

void spawn_demon(){
    int i, j;
    int role;
    int demon_level = 0;
    object ob;
    int aggro = 0;
    int circle_power = 0;
    int buff;
    object circle;
    object owner;
    string *demons = ({
      "/std/glen/pet/small_demon",
      "/std/glen/pet/normal_demon",
      "/std/glen/pet/greater_demon",
      "/std/glen/pet/lord_demon",
      "/std/glen/pet/prince_demon"});

    role = (random(power) + random(power)) / 2;
    while(random(power) > 100)
	role += 25;

    switch(role){
    case -10..40:
	demon_level = 0;
	break;    
    case 41..70:
	demon_level = 1;
	break;    
    case 71..140:
	demon_level = 2;
	break;    
    case 151..200:
	demon_level = 3;
	break;    
    case 201..100000:
	demon_level = 4;
	break;    
    }

    circle = present("blood circle", environment());
    owner  = present(query_owner(), environment());
    if(circle)
	circle_power = circle->query_power();

    ob = new(demons[demon_level]);

    ob->set_dur(duration * 4);

    if( random(10) == 3)
	aggro = 1;
    if (
      random(power) > 
      random(circle_power)
    )
	aggro = 1;
    if(!owner)
	aggro = 1;

    while(random(power) > 75)
	buff += 25;

    ob->set_up(random(power) + random(20) + buff);
    if(!aggro){
	ob->move(environment());
	ob->materialize();
	ob->set_owner(query_owner());
	ob->force_me("speak common");
	ob->force_me("say Yes Master.");
    }
    if(aggro){
	ob->set_aggr_status(random(2));
	ob->set_owner("rogue");
	ob->move(environment());

	if(owner && random(100) > 70){
	    ob->materialize();
	    owner->add_follower(ob);
	    ob->kill_ob(owner, 0);
	}else{
	    ob->set_speed(60+random(30));
	    while(random(2) == 1)
		ob->run_away();
	    ob->materialize();
	}
	//ob->spawn(70+random(30));
    }
}

int start_up(int x, int chance){
    chance++;
    if(chance >= random(5)){
	spawn_demon();
	while(random(3) == 1)
	    spawn_demon();
	chance = 0;
    }
    call_out("start_up", x, x, chance);
    return 1;  
}

int move(mixed dest) {
    if(objectp(dest) && living(dest)) return MOVE_NOT_ALLOWED;
    return ::move(dest);
}

void create() {
    ::create();
    set_name("rift");
    set_short(CBOLD + CBLUE + "A planar rift");
    set_long("A rift between planes of some sort");
    set_id(({ "rift", "demon rift" }));
    return;
}


void set_power(int x){
    power = x;
}

int query_power(){
    return power;
}

void set_dur(int dur) {
    duration = dur;
    call_out("remove_me", dur);
}

void set_caster(string str) { 
    caster = str; 
}

