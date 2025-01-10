#include "/adm/include/std.h"

inherit "/std/save_room";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no scry", 1);

    set("short", "The workroom of a new immortal");
set( "day long", @EndText
It is %^YELLOW%^DAY%^RESET%^ outside.

main    [takes you to main workroom]
portal  [Daybreak TS takes you to all current working areas]

Level 0               [newbie]
Level 1-10+ areas     [goblin, kobold, fir, bandits, caravan, ancient]
level 10-20+          [catacombs, mansion, faeriedust, forest]
level 5-15+ cities    [kuril, vo, akkad]
Level 15-25+ areas    [tyranid, canyon, gorge%^YELLOW%^(N)%^RESET%^]
level 25-30+ areas    [quarry, dwarf]
level 30-38+ areas    [chaos]  
level 40-60++         [keep, dragon]
level 80-100++        [ork]  

level 25-100++        [zoo]

level 150+ aggressive [doom]

* Other areas pending fixing/sorting [hive, bir, castle]

SAVE ROOM
EndText);

set( "night long", @EndText
It is %^BOLD%^BLUE%^NIGHT%^RESET%^ outside.

main    [takes you to main workroom]
portal  [Daybreak TS takes you to all current working areas]

Level 0               [newbie]
Level 1-10+ areas     [goblin, kobold, fir, bandits, caravan, ancient]
level 10-20+          [catacombs, mansion, faeriedust, forest]
level 5-15+ cities    [kuril, vo, akkad]
Level 15-25+ areas    [tyranid, canyon, gorge%^YELLOW%^(N)%^RESET%^]
level 25-30+ areas    [quarry, dwarf]
level 30-38+ areas    [chaos]  
level 40-60++         [keep, dragon]
level 80-100++        [ork]  

level 25-100++        [zoo]

level 150+ aggressive [doom]

* Other areas pending fixing/sorting [hive, bir, castle]

SAVE ROOM
EndText);

    add_exit("/std/obj/workroom.c", "main");
    add_exit("/d/daybreak/room/N1", "portal");


    add_exit("/wizards/tlny/workroom.c", "west");

  //level 0
    add_exit("/d/damned/virtual/room_10_10.world", "newbie");
//Low level areas 1-10
    add_exit("/d/damned/virtual/room_9_7.world", "goblin");
    add_exit("/d/damned/virtual/room_4_13.world", "kobold");
    add_exit("/d/damned/virtual/room_6_7.world", "fir");
    add_exit("/d/damned/virtual/room_5_12.world", "bandits");
    add_exit("/d/damned/virtual/room_13_14.world", "caravan");
    add_exit("/d/damned/virtual/room_5_3.world", "ancient");
//10-20+
    add_exit("/d/damned/virtual/room_13_6.world", "faeriedust");
    add_exit("/d/damned/virtual/room_4_23.world", "catacombs");
    add_exit("/d/damned/virtual/room_4_5.world", "mansion");
//Cities and level 5-15+ areas
    add_exit("/d/damned/virtual/room_8_12.world", "kuril"); 
    add_exit("/d/damned/virtual/room_4_9.world", "akkad");
    add_exit("/d/damned/virtual/room_13_9.world", "vo");
//Level 15-25+ areas
    add_exit("/d/damned/virtual/room_12_4.world", "tyranid");
    add_exit("/d/damned/virtual/room_25_15.world", "canyon");
    add_exit("/d/damned/virtual/room_22_15.world", "gorge");
//level 25-30+
    add_exit("/d/damned/virtual/room_16_26.world", "dwarf");
    add_exit("/d/damned/virtual/room_8_22.world", "quarry");
//level 30-38+
    add_exit("/d/damned/virtual/room_43_10.world", "chaos");
//Level 40-60+ Needs to scale down majorly
    add_exit("/d/damned/virtual/room_24_6.world", "keep");
    add_exit("/d/damned/virtual/room_73_13.world", "dragon");
//Level 80-100++
    add_exit("/d/damned/virtual/room_37_7.world", "ork");
//level 25-100+
    add_exit("/d/damned/virtual/room_8_56.world", "zoo");
//level 150+
    add_exit("/d/damned/virtual/room_23_52.world", "doom");
//Not yet sorted or in need of fixing
    add_exit("/d/damned/virtual/room_6_35.world", "forest");
    add_exit("/d/damned/virtual/room_27_25.world", "hive");
    add_exit("/d/damned/virtual/room_50_25.world", "bir");
    add_exit("/d/damned/virtual/room_8_5.world", "castle");

        add_exit("/d/daybreak/room/db_square", "out");


}
