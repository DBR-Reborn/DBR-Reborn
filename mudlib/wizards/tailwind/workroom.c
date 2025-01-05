#define OWNER "tailwind"
#define DEST "/d/damned/akkad/ak_center"
#define NAME  (string)this_player()->query_name()
#define LOG "/wizards/tailwind/workroom.log"

#include <std.h>

inherit  ROOM;

string   *guests;
int      room_status;

object   ob;

void create(){
  ::create();
  set_no_clean(1);

  set_short("Tailwind's Workroom!");
  set_property("no scry", 1);
  set_property("no attack", 1);
  set_property("indoors", 1);
  set_property("light", 2);
  set_long(@TEXT
You have entered the workroom of Tailwind, the Speed Coder. There is a large desk in the corner, covered with papers. On it, amidst the mess, is a Celeron 700, running WindowsME. Also, you see a large pile of RPGs - Tailwind's other hobby. You notice no bugs, though - Tailwind must believe in sanitation and good coding. On another desk is a server, running Debian Linux, and a notecard labelling ways to get in touch with Tailwind.
TEXT
);
set_items( (["computer": "It's a Celeron 700, with 192mb of RAM, and a Geforce2 MX graphics card. While not the fastest computer around, it is very respectable." ,
"papers": "Just a bunch of papers from school, computer games, and assorted other things." ,
"desk": "It is really big, and has lots of drawers in cubbies. Incredibly, almost all are in use.",
"RPGs": "D&D 3rd Edition, Twilight 2000, and Warhammer 40,000. Good taste.",
"server": "This is a Pentium 100 with 16mb of RAM running Debian Linux 2.2.",
"notecard": "ICQ: 9730103 Email: erwos@home.com"]) );
set_smell("default", "It smells OK in here. Not too bad, but not all that great.");
set_listen("default", "You hear the fan of the computer, which is a bit loud."); 
  add_exit("/d/damned/guilds/join_rooms/arch-mage_join",    "am");
  add_exit("/d/damned/guilds/join_rooms/demon-master_join", "dm");
  add_exit("/d/damned/guilds/join_rooms/cleric_join",       "cle");
  add_exit("/d/damned/guilds/join_rooms/shaman_join",        "sh");
  add_exit("/d/damned/guilds/join_rooms/elementalist_join", "el");
  add_exit("/d/damned/guilds/join_rooms/enchanter_join",    "en");
  add_exit("/d/damned/guilds/join_rooms/fighter_join",      "fi");
  add_exit("/d/damned/guilds/join_rooms/underlord_join",  "ul");
  add_exit("/d/damned/guilds/join_rooms/invisible-dagger_join",   "id");
  add_exit("/d/damned/guilds/join_rooms/paladin_join",      "pa");
  add_exit("/d/damned/guilds/join_rooms/steel-society_join",   "ss");
  add_exit("/d/damned/guilds/join_rooms/thief_join",        "th");
  add_exit("/d/damned/guilds/join_rooms/tinker_join",       "ti");
  add_exit("/d/damned/guilds/join_rooms/war-priest_join",   "wp");
  add_exit("/d/damned/guilds/join_rooms/mercenary_join",    "me");
  add_exit("/d/damned/guilds/join_rooms/alchemist_join",    "al");
  add_exit("/d/damned/daybreak/rooms/square", "ts");
  add_exit("/d/standard/adv_main", "north");
  add_exit("/wizards/azura/area_rooms", "east");
  set_invis_exits( 
    ({ "am","sh","dm","cle", "el","en","fi","ul",
       "id","pa","se","ss","th","ti","wp","wm","ts", "me", "al"
    }) );

  guests = ({"thrace","traer","glitch"});
  ob = new("/std/sign");
  ob->set_short("Intruder Defense System Manual");
  ob->set_name("tome");
  ob->set_id( ({ "tome", "book", "manual" }) );
  ob->set("long",@TEXT
----------------------------------------------------------------
Commands for Tailwind's Intruder Defense System:
---------------------------

Open Access Commands:
-----------------
[info] ........ Control Room Information
[read log] .... Display Logbook Entries

Owner Only Commands:
-----------------
protect room    raises the alert level of the IDS
unprotect room  lowers the alert level of the IDS
addname <name>  add someone to the guest list
remove <name>   remove someone from the guest list
evict <name>    get rid of an annoying guest
----------------------------------------------------------------
TEXT
);
  ob->move(this_object());
}

void init(){
  string      name;
  ::init();
  name = this_player()->query_true_name();
  if(!previous_object()->is_player()) return;
  if((name != OWNER) && member_array(name, guests) == -1
&& room_status == 1){
    message("info", "You attempt to enter, but are repulsed by gunfire from a system of turrets and automated weapons. The Intruder Defense System must be up.", this_player());
    this_player()->move(DEST);
    return;
  }
    if((name != OWNER) && room_status == 2){
    this_player()->move(DEST);
    message("info", "Even approaching from a distance, you can tell by the high alert level of the robot sentries patrolling this area that no one will get through.",this_player());
    return;
  }
  if(name && (name != OWNER)){
    write_file(LOG, name + " ");
    if(member_array(name, guests) == -1) 
      write_file(LOG, "(non-guest) ");
    else write_file(LOG, "(guest) ");
    write_file(LOG, "entered at " + ctime(time()));
    switch (room_status){
      case 2:
        write_file(LOG, " (LOCKED)\n");
        break;
      case 1:
        write_file(LOG, " (guests only)\n");
        break;
      default:
        write_file(LOG, " (open)\n");
    }
  }
  if(this_player()->query_invis() && name != OWNER){
    say(capitalize(name) + " enters the room.");
    this_player()->set_invis();
    write("Your body tingles as it is scanned.");
  }
  add_action("room_info", "info");
  add_action("clog", "read");
  add_action("yeah_right", "invis");
  if(name == OWNER){
    add_action("lock_room", "protect");
    add_action("unlock_room", "unprotect");
    add_action("remove_guest", "remove");
    add_action("add_guest", "addname");
    add_action("evict", "evict");
  }
}

int lock_room(string str){
  switch(NAME){
    case OWNER:
      if(!str && str != "room") break;
      if(room_status == 2){
        write("The IDS system is already completely active!\n");
        return 1;
      }
      room_status++;
      switch (room_status){



        case 1:
          write("You raise the alert level of the IDS to medium.");
          say(this_player()->query_cap_name() + " raises the alert level of the IDS.");
          break;
        default:
          write("You raise the alert level of the IDS to maximum.");
          say(this_player()->query_cap_name() + " raises the alert level of the IDS.");
      }
      return 1;
    default:
      return 0;
  }
}

int unlock_room(string str){
  switch(NAME){
    case OWNER:
      if(!str && str != "room") return 0;
      if(room_status == 0){
        write("The IDS is not currently active.");
        return 1;
      }
      room_status--;
      switch (room_status){
        case 0:
          write("You lower the alert level of the IDS to off.");
          say(this_player()->query_cap_name() + " turns off the IDS.");
          break;
        default:
          write("You reduce the alert level of the IDS to medium.");
          say(this_player()->query_cap_name() + " lowers the alert level of the IDS.");
      }
      return 1;
    default:
      return 0;
  }
}

int add_guest(string who){
  if(NAME != OWNER) return 0;
  if(!who){
    notify_fail("You must supply a name for the guest addition.\n");
    return 0;
  }
  if(member_array(who, guests) != -1){
    notify_fail(capitalize(who) + " is already on the guest list!\n");
    return 0;
  }
  guests += ({ who });
  write(capitalize(who) + " is now on the guest list.");
  return 1;
}

int remove_guest(string who){
  if(NAME != OWNER) return 0;

  if(!who){
    notify_fail("You must supply a name for the guest removal.\n");
    return 0;
  }
  if(member_array(who, guests) == -1){
    notify_fail(capitalize(who) + " is not on the guest list.\n");
    return 0;
  }
  write(capitalize(who) + " has been removed from the guest list.");
  guests -= ({ who });
  return 1;
}

int evict(string who){
  object    ob;
  if(NAME != OWNER) return 0;
  if(!who){
    notify_fail("Evict who?\n");
    return 0;
  }
  if(!(ob = present(who, this_object()))){
    notify_fail(capitalize(who) + " is not present in the room!\n");
    return 0;
  }
  if(NAME != OWNER) return 0;
  if(!living(ob)){
    notify_fail(capitalize(who) + " isn't a living thing.\n");
    return 0;
  }
  if(member_array(who, guests) != -1){
    write(capitalize(who) + " has been removed from the guest list.");
    guests -= ({ who });
  }
  ob->move(DEST);
  write(capitalize(who) + " has been evicted by robotic security guards!");
  say(capitalize(who) + " has been evicted from the room by robotic security guards!");
  return 1;
}

int room_info(){
  switch (room_status){
    case 2:
      write("Intruder Defense System Status: ACTIVE (Level 2)");
      break;
    case 1:
      write("Intruder Defense System Status: ACTIVE (Level 1)");
      break;
    default:
      write("Intruder Defense System Status: INACTIVE");
      break;
  }
  write("Current guests are:\n-------------------");
  write(format_page(guests, 6));
  return 1;

}

int clog(string str){
  if(!str || str != "log") return 0;
  if(!file_exists(LOG)){
    write("No log on file.");
    return 1;
  }
  write("You glance at a monitor to read the logs: ");
  say(this_player()->query_cap_name() + " reads the room's log entries.");
     this_player()->more("/wizards/tailwind/workroom.log");
  return 1;
}

int yeah_right(){
  if((string) this_player()->query_name() == OWNER) return 0;
  write("Invisibility is not permitted here.");
  return 1;
}

void clean_up(){
return 0;
}

void reset(){
  if(!present("tailwind")) room_status = 0;
  return;
}

int query_room_status() { return room_status; }
