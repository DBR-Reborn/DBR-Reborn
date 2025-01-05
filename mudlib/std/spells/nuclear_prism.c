inherit "/std/spells/spell";
 
void create() {
    ::create();
    set_property("name","nuclear prism");
set_property("skill","geometry");
    set_property("casting time",15);
    set_property("base mp cost",35);
    set_property("dev cost", 27);
    set_property("fast dev cost", 47);
    set_property("spell level", 5);
    set_property("moon","warzau");
    set_property("caster message","You create a floating nuclear prism.");
    set_property("target message","");
    set_property("observer message","$C creates a floating nuclear prism.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 122);
    return;
 
}
 
void info() {
message("help",
"This spell creates a floating nuclear prism, which acts as a rune.  "
"Whenever someone (besides you) enters the room, the rune will affect "
"them.  This rune will explode where anyone steps on it, damaging them.",
this_player());
}
 
void spell_func(object caster, object at, int power, string args, int flag)
{
  object ob, *inv;
  int i, tot;
 
  seteuid(getuid());
  ob = new("/std/tailwind/obj/nukeprism");
  ob->set("safe flag", 1);
  ob->move(environment(caster));
  ob->set("safe flag", 0);
  ob->set_dur(props["duration"]); 
  ob->set_property("can resist", 1);
  ob->set_level(power);
  ob->set_caster_level((int)caster->query_level());
  if(flag) {
    message("info", "An exploding rune goes off!", environment(caster));
    ob->set_caster("asskicker");
    ob->delay_action();
    remove();
    return;
  }
  inv = all_inventory(environment(caster));
  i = sizeof(inv);
  tot = 0;
  while(i--) tot += (int)ob->my_rune_filter(inv[i]);
  if(tot > 1) {
    message("info", "Only one nuclear prism may exist in a room at once.",
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
