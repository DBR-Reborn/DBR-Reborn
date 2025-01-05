#include <std.h>
#include <security.h>
inherit OBJECT;

int transport(string str);
void moving(mixed *inf);

void init() {
	::init();
    add_action("transport", "transport");
}

void create() {
	set_name("scroll");
	set_id( ({"scroll", "scroll of daybreak", "scroll of Daybreak" }) );
	set_short("A scroll of Daybreak");
	set("long",
		"This is a scroll with many magical words on it. You can type %^YELLOW%^transport home%^RESET%^, %^YELLOW%^guild%^RESET%^, or %^YELLOW%^church%^RESET%^ to use it and it will transport you to the location requested."
	);
	set_weight(30);
	set_value(100);
  set_property("no steal", 1);
}

//ADD
int transport(string str) {
   mixed *inf;
   if( this_player()->query_property("UNPURE") )
      return notify_fail("Your knowledge of life has been contaminated. "+
        "You may not use this power.\n");
   if(sizeof(this_player()->query_attackers()))
      return notify_fail("You may not transport during combat.");
   if(!str) return notify_fail("You must specify home, guild, or church.\n");
   if(str == "guild" ) {
      str = "/d/damned/guilds/join_rooms/"+(string)this_player()->query_class()+
         "_join.c";
    }
  else if(str == "church") 
      str = "/d/standard/square";
   else if(str == "home")
      str = "/d/daybreak/room/db_square.c";
   else return notify_fail("You must specify a destination of home or guild.\n");
   message("info","You use your scroll of Daybreak prepare to %^YELLOW%^transport%^RESET%^.",
      this_player());
   inf = ({ (str), (this_player()) });
   call_out("moving",15,inf);
   return 1;
}

void moving(mixed *inf) {
   object who;
   who = inf[1];
   if(!who->query_invis()) {
      message("info",who->query_cap_name()+" begins to glow brightly "+
         "and is gone when the glow fades.",environment(who));
      message("info",who->query_cap_name()+" shimmers into existance.",
         find_object((string)inf[0]));
   }
   message("info","You are %^YELLOW%^transported%^RESET%^ elsewhere.",who);
   who->move((string)inf[0]);
    this_object()->remove();
   return;
}

//END
