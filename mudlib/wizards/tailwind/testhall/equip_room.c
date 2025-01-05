inherit "/std/locker_room";

void init() {
    ::init();
    add_action("arm", "arm");
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/royal-infantry/tentcamp", "south");
   set("short","The Royal-Infantry Quartermaster");
   set("long",
"While the Royal-Infantry does not possess the funds to lavishly equip  "+
"its members, it can provide minor outfitting for free. To be equipped, "+
"type \"arm me\". There are also various lockers and chests lying around "+
"that you can store things in. REMEMBER TO CLOSE THE CHESTS AND LOCKERS, "+
"OR THINGS MAY BE LOST!");
}

int arm(string str) {

object ob;

if(str != "me"){
  notify_fail("Arm what?\n");
  return 0;
}

if(this_player()->query_class() != "royal-infantry"){
  notify_fail("The quartermaster refuses to serve you.\n");
  return 0;
}

if(this_player()->query("freebiestaken")){
  notify_fail("The quartermaster has already served you.");
  return 0;
}

    write("You are immediately surrounded by a veritable army of men taking measurements and such. After a few moments, they disperse, and bring you back a sword and a tabard.");
    say(this_player()->query_cap_name()+" is surrounded by a bunch of men taking his measurements. They run off, and bring him back a sword and a tabard.", this_player());
    ob=new("/d/damned/virtual/tabard.armour");
    ob->set_short("The Royal Tabard");
    ob->set_long("The Royal Tabard sports a grand golden dragon on the front.");
    ob->move(this_player());
    new("/d/damned/guilds/royal-infantry/royal_sword")->move(this_player());
    this_player()->set("freebiestaken", 1);
    return 1;
}