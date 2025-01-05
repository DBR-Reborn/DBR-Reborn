//      Wizard:  Gellor
//      New Firn'Ville Entrance
//      newfirn1.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "A Wide Path");
    set("long", "You have reached a wide road in the forest which leads "
    				 "into the town of New Firn'Ville. Tall trees rise high "
                "around you providing a pleasant environment on the "
                "foliage covered forest floor. Off in the distance, "
                "away from any people, small animals can be heard scurrying "
                "around and searching through the leaves. To the north "
                "the town is spread out providing home for beings of "
                "many races, although mostly elves. Some sort of magical "
                "lantern is attached to a tree and provides ample light to "
                "see everything here. There is also a sign here." );
    add_exit("newfirn2.c","north");
    add_exit("path1.c","south");
    set_items(([
     ({ "forest","trees","tree","woods","floor","environment","leaves" }) :
        "The woods here is a curious blend of maple, pine, oak, and several "
        "other exotic species seen rarely in the realm. The majority of "
        "the trees tower at about one hundred to two hundred feet tall and "
        "form a beautiful canopy above. Down on the forest floor the "
        "temperature remains constantly cool and comfortable. Ferns, "
        "grasses, bushes, and other small plants find refuge here as well as "
        "small animals like squirrels, birds, deer, horses, and rabbits. "
        "Such conditions have made it into a popular hunting ground for "
        "Elven hunters.",
     ({ "animals","animal" }) :
        "There are a variety of small animals which inhabit the area in "
        "and around New Firn'Ville. Deer, rabbits, horses, birds, "
        "squirrels, dogs, cats, and other creatures can be seen by the "
        "eye of the keen observer.",
     ({ "lantern","lamp","light" }) :
        "Attached to a great oak, this lantern shines forth as an infinite "
        "source of light for beings coming to and leaving New Firn'Ville. "
        "It is constructed of the finest copper and glass and is shaped "
        "like a normal lantern. The only difference is that the light comes "
        "not from a wick and oil or kerosene, but rather from a brillant "
        "glowing globe withing the glass encasement.",
     ({ "sign" }) :
        "Welcome to New Firn'Ville \n"
        " Home Of The Wood Elves \n"
        "  Hostel To Travellers \n"
        "Home of King Nallung Akzr",
     ({ "road","path","trail" }) :
     	  "This is a hard packed dirt path which is about ten feet wide "
        "here to allow for movement of carts and other traffic." ]));
    set_smell("default", "The air here is fresh and crisp.");
    set_listen("default", "The sounds of the forest are abundant here.");
}
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("guard")) {
      new("/wizards/gellor/newfirn/mobs/city_guard1.c")->move(this_object());}
   if (!present("guard")) {
      new("/wizards/gellor/newfirn/mobs/city_guard2.c")->move(this_object());}
}
