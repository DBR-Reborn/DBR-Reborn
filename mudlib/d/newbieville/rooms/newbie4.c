#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
//if (!present("rat")) {
	  //new("/d/newbieville/mon/rat.c")->move(this_object());
	//}

}


void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Lower Level of The Castle of Tailwind");
    set("long", @ext If you have not already done so I recommend typing 'help guilds' and read up on each guild and what best suits your play style. Below are exits to each guild that are not secret as well as  a brief summary of advanced hidden guilds. The listing is arranged by the recommended level of knowledge of the game.

(HIDDEN GUILDS require you to explore the Mud to find them and join them)
thief, assassin, nethermancer, elemental-mage

(PRO PLAYERS)
elementalist :  Spell casters with lots of cool elemental spells
arch-mage :     All powerful spell casters

(ADVANCED PLAYERS)
cleric :        Healers, holy buffs, can summon angels and resurrect people
enchanter:      Can enchant weapons and armour to make gear stronger.
necromancer :   Can summon many undead minions that will do your bidding
nightblade :    Think of as assassin like person but can cast spells

(INTERMEDIATE PLAYERS)
chaotic-lord :  Demon summons and self demon binds
dark-paladin :  Think of a Unholy knight but with spells and self buffs
paladin :       Think of a Holy knight but with spells and self buffs
sword-mage :    Self buffing spells for weapons and unique weapon spell ups
war-priest :    A holy warrior much like a cleric but more combat spells 

(BEGINNER PLAYERS)
fighter :   Has many cool combat skills and lots of HP and HP regen
tinker :    Can make weapons and armour and magical runes on weapons
ext);

    add_exit("/d/newbieville/rooms/newbie3_u", "down");

    add_exit("/d/damned/guilds/join_rooms/arch-mage_join", "arch-mage");
    add_exit("/d/damned/guilds/join_rooms/chaotic-lord_join", "chaotic-lord");
    add_exit("/d/damned/guilds/join_rooms/cleric_join", "cleric");
    add_exit("/d/damned/guilds/join_rooms/dark-paladin_join", "dark-paladin");
    add_exit("/d/damned/guilds/join_rooms/elementalist_join", "elementalist");
    add_exit("/d/damned/guilds/join_rooms/enchanter_join", "enchanter");
    add_exit("/d/damned/guilds/join_rooms/fighter_join", "fighter");
    add_exit("/d/damned/guilds/join_rooms/necromancer_join", "necromancer");
    add_exit("/d/damned/guilds/join_rooms/nightblade_join", "nightblade");
    add_exit("/d/damned/guilds/join_rooms/paladin_join", "paladin");
    add_exit("/d/damned/guilds/join_rooms/sword-mage_join", "sword-mage");
    add_exit("/d/damned/guilds/join_rooms/tinker_join", "tinker");
    add_exit("/d/damned/guilds/join_rooms/war-priest_join", "war-priest");

        add_exit("/d/daybreak/room/db_square", "daybreak");

//Hidden guilds
    //add_exit("/d/damned/guilds/join_rooms/theif_join", "thief");
    //add_exit("/d/damned/guilds/join_rooms/assassin_join", "assassin");
    //add_exit("/d/damned/guilds/join_rooms/nethermancer_join", "nethermancer");
//broken guild
    //add_exit("/d/damned/guilds/join_rooms/elemental-mage_join", "elemental-mage");



set_items( (["sign": (: call_other, this_object(), "read_sign" :)]) );
return;
}

int read_sign() {
string msg;

  msg = @ext
Welcome new player. Your adventure begins here.

Please type '%^YELLOW%^help guilds%^RESET%^' and read up on a guild that intrests you or based on the room and recommends choose a guild that best suits you and your play style.

As a new player of Daybreak Ridge you can also use the newbie channel by typeing '%^YELLOW%^newbie %^RESET%^<%^YELLOW%^MSG%^RESET%^>'

before you go 1 more thing once you reach daybreak type '%^YELLOW%^help daybreak%^RESET%^' for a static map to help you go through that city. A very important spot is '%^YELLOW%^T%^RESET%^' this is Daybreak town square it has a portal to every known area I recommend you start at %^YELLOW%^Goblin town%^RESET%^ and kill snotlings or goblins to start leveling. Also you have a EXP buffer known as mind status once you are full of facts Daybreak town square gives you double exp drain and allows you to socalize with other players come back to here often.

If you would like to learn the game further and in more detail on your own you can type '%^YELLOW%^help commands%^RESET%^' for a list of commands you can be used we have help topics for each command by typing help <command name>. I also recommend that you type '%^YELLOW%^help topics%^RESET%^' and read those as well

ext;
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",200,this_player());
  add_action("exit_tutorial","end");
  return;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
} 


int exit_tutorial(string str){
    if(str == "tutorial"){
      write("You say the words 'open sesame' and the room changes before a portal appears and as you look through it's shimmer you see the townsquare of daybreak type 'portal' to leave the tutorial. %^B_RED%^Be warned once you leave you are not allowed to come back herel%^RESET%^\n");
      say(this_player()->query_cap_name()+"says 'open sesame' and a portal appears");
        add_exit("/d/daybreak/room/db_square", "exit");
        delayed_call("close_door",30);
      return 1;
    }
}
void close_door(){
   remove_exit("exit");
   tell_room(this_object(),"The portal vanishes before you.\n");
   return;
}

