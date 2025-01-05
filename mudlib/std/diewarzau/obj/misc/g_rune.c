//    Poison Rune
inherit "/std/diewarzau/obj/misc/rune";

void create() {
  ::create();
  set_id(({ "gate rune", "rune" }));
  set_short("%^RESET%^%^BLUE%^%^BOLD%^A gate rune%^RESET%^%^MAGENTA%^%^BOLD%^");
  set_long("This rune is inscribed on the floor in an ancient magical language.");
  set("function", (: call_other, this_object(), "do_gate" :));
  return;
}

void do_gate(object who) {
  who->move("/std/diewarzau/rooms/warp", 0);
  return;
}

int stomp_rune(object who) {
who = this_player();
message("info", "%^GREEN%^%^BOLD%^You stomp on the rune.",
    who);
who->move("/std/diewarzau/rooms/warp", 0);
return 1;
}