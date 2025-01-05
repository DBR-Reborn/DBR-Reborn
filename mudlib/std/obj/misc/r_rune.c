//    Rotten Rune - Xavier July2020
inherit "/std/obj/misc/rune";

void create() {
  ::create();
  set_id(({ "rune", "rotten rune" }));
  set_short("%^RESET%^%^COLOR240%^A rotten rune%^RESET%^%^MAGENTA%^%^BOLD%^");
  set_long("This rune is inscribed on the floor in an ancient magical language.");
  set("function", (: call_other, this_object(), "do_gate" :));
  return;
}

void do_gate(object who) {
  object ob;

  seteuid(getuid());
  if(who->is_pet() || wizardp(this_player()) || (who->query_flying()
     && (query_level() > 3) ) ) return;
  ob = new("/std/obj/pet/dracolich");
  ob->set_owner("asskicker");
  ob->set_up(query_level());
  ob->set_dur(query_level() * 60);
  message("info", "%^GREEN%^%^BOLD%^A Dracolich appears!",
    environment(who));
  ob->move(environment(who));
  ob->kill_ob(who, 0);
  message("info", "%^RED%^%^BOLD%^The Dracolich attacks "+
      (string)who->query_cap_name()+"!", environment(who), ({ who }));
  message("info", "%^RED%^%^BOLD%^The Dracolich attacks you!", who);
  return;
}

