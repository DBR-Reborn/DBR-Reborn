//  Made by Tailwind for RI Guildhall.
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Center of the Camp");
    set("long", "Many tents housing the elite Royal-Infantry are scattered about here. Many tired men are sleeping in them, and still more are moving around from place to place. You see especially large tents to the north, south, and east. A path to the northwest leads out of the camp.");
    add_exit("/d/damned/guilds/royal-infantry/start", "northwest");
    add_exit("/d/damned/guilds/royal-infantry/train_room", "east");
    add_exit("/d/damned/guilds/royal-infantry/equip_room", "north");
    add_exit("/d/damned/guilds/royal-infantry/command_room", "south");
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/damned/guilds/royal-infantry/guard")->move(this_object());
    new("/d/damned/guilds/royal-infantry/guard")->move(this_object());
    new("/d/damned/guilds/royal-infantry/guard")->move(this_object());
  }
}