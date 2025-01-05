inherit "/std/spells/spell";

object stuff;
 
void create() {
    ::create();
    set_property("name","explosive geometry");
    set_property("skill","geometry");
    set_property("casting time",15);
    set_property("base mp cost",35);
    set_property("dev cost", 27);
    set_property("fast dev cost", 47);
    set_property("spell level", 5);
    set_property("moon","warzau");
    set_property("caster message","You draw a piece of explosive geometry on the floor.");
    set_property("target message","");
    set_property("observer message","$C draws a piece of explosive geometry on the floor.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 122);
    return;
 
}
 
void info() {
message("help",
"This spell draws a piece of explosive geometry on the floor.  "
"Whenever someone (besides you) enters the room, the rune will affect "
"them.  This rune will explode where anyone steps on it, damaging them. "
"This spell requires a magical quill.",
this_player());
}
 
void spell_func(object caster, object at, int power, string args, int flag)
{
  object ob, *inv;
  int i, tot;

  if(!(stuff = present("magic quill", caster))) {
    message("info", "You need a magic quill to cast this spell.",
            caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

    if(random(20)==0){

    message("info", "You press too hard and break the quill.",
            caster);
   stuff->remove();
}

  seteuid(getuid());
  ob = new("/std/tailwind/obj/e_geo");
  ob->set("safe flag", 1);
  ob->move(environment(caster));
  ob->set("safe flag", 0);
  ob->set_dur(props["duration"]); 
  ob->set_property("can resist", 1);
  ob->set_level(power);
  ob->set_caster_level((int)caster->query_level());
  if(flag) {
    message("info", "An explosive geometry goes off!", environment(caster));
    ob->set_caster("asskicker");
    ob->delay_action();
    remove();
    return;
  }
  inv = all_inventory(environment(caster));
  i = sizeof(inv);
  tot = 0;
  while(i--) tot += (int)ob->my_rune_filter(inv[i]);
  if(tot > 3) {
    message("info", "Only three explosive geometries may be in any room.",
caster);
    ob->remove();
    caster->add_mp(props["mp cost"]);
    remove();
    return;
 
  }
  ob->set_caster((string)caster->query_name());
  remove();
  return;
}
