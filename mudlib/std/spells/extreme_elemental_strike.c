inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","extreme elemental strike");
    set_property("skill","elementalism");
    set_property("casting time",13);
    set_property("base mp cost",320);
    set_property("dev cost",220);
    set_property("fast dev cost",564);
    set_property("spell level", 40);
    set_property("moon","warzau");
    set_property("caster message","You cast a extreme elemental strike!");
    set_property("target message","");
    set_property("observer message","$C casts a extreme elemental strike.");
    set_property("spell type",({ "damage", "damage" }));
    set_property("elemental spell", 1);
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("ele damage", 80+(this_player()->query_level())*8);
    set_property("damage multiplier", 8+(this_player()->query_level()/8));
    set_property("no target", 1);
    set_property("prereq", "greater elemental strike");
    return;
}

void info() {
message("help",
"This spell is the equivalent of firing 5*2 extreme elemental bolts see 'help "
"spell elemental bolt' at any number of targets.  You may fire all "
"at one target or distribute them.  You must separate the targets by a "
"comma.  If any one of the targets is not found, the spell will fail, and "
"the magic point cost will be returned.  If fewer than 5 targets are supplied, "
"all remaining bolts will strike the last target supplied.\n"
"Syntax: cast *3 lesser elemental strike at beggar, guard, warrior\n"
"In the above,beggar and guard get one bolt, while the warrior gets 2.  "
"DO NOT use 'and' in the list.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object *inv;
  int i, j;
  string *targs, curr;

  if(!args) {
    message("info", "You must supply 1-5 targets for this spell!", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  targs = explode(args, ",");
  i = sizeof(targs);
  inv = ({});
  while(i--) {
    curr = targs[i];
    while(strlen(curr) && curr[0] == ' ') curr = replace_string(curr, " ", "", 1);
    while((j = strlen(curr)) >= 2 && curr[j-1] == ' ')
      curr = curr[0..j-2];
    curr = lower_case(curr);
    if(present(curr, environment(caster)))
      inv += ({ present(curr, environment(caster)) });
    else {
      message("info", "There is no '"+curr+"' here.  Your spell fails.", caster);
      caster->add_mp(props["mp cost"]);
      remove();
      return;
    }
  }
  while(sizeof(inv) > 5) inv = exclude_array(inv, sizeof(inv)-1);
  while(sizeof(inv) < 5) inv += ({ inv[sizeof(inv)-1] });
  i = sizeof(inv);
  while(i--)
    if(objectp(inv[i])) {
      inv[i]->kill_ob(caster, 0);
      ::spell_func(caster, inv[i], power, 0, flag);
    }
  remove();
  return;
}

