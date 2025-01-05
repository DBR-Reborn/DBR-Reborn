inherit "std/room";

int tower();
int read(string str);

void create() {
   object ob;
  ::create();
    set_property("light",3);
    set_property("night light", 3);
    set_property("no scry",1);
    set("short","Justice Tower Chamber Room");
    set("long","Welcome to the Chamber of the Council of Guildmasters. "+
    "There are 12 chairs around the room of different type and design, one "+
    "for each Guildmaster, though some show more use than others. "+
    "This room is where the Council meets to decide the law of the land "+
    "and to mete out punishment, to set policy and to decide the fate "+
    "of the world.\n");
    add_exit("/d/damned/akkad/council_v_room", "vote");
    ob=new("std/bboard");
    ob->set_name("board");
    ob->set_id ( ({"board", "law board", "law", "council" }) );
    ob->set_board_id("council");
    ob->set_max_posts(50);
    ob->set_location("/d/damned/akkad/ak_chamber");
    ob->set("short", "The Council Board");
    ob->set("long", "This board exists for Council members to voice opinions "+
       "for others to read and comment.\n");
}

void init() {
   ::init();
   add_action("tower","tower");
   add_action("read","read");
}

int tower() {
   if(!this_player()->query_invis()) {
   message("info",this_player()->query_cap_name()+" slowly fades into nothingness."
      ,this_object());
   message("info",this_player()->query_cap_name()+" shimmers into existance."
      ,find_object("/d/damned/akkad/ak_tower"));
   }
   message("info","You are transported to Justice Tower.",this_player());
   this_player()->move("/d/damned/akkad/ak_tower");
   return 1;
}

int read (string str) {
   if(str == "law") {
      message("info","The Law is being written.",this_player());
      return 1;
   }
   else if(str == "warrants") {
      message("info","There are no warrants outstanding.",this_player());
      return 1;
   }
   else if(str == "proposals") {
      message("info","There are no proposals.",this_player());
      return 1;
   }
   return 0;
}

