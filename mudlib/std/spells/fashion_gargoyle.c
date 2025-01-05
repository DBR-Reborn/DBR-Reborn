// Gargoyle - Xavier July2020

inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","fashion gargoyle");
    set_property("skill","enchantment");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",100);
    set_property("dev cost", 115);
    set_property("fast dev cost", 345);
    set_property("spell level", 22);
    set_property("moon","luna");
    set_property("caster message","You begin to mold the metal into a gargoyle.");
    set_property("target message","");
    set_property("observer message","$C begins to magically mold some metal.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    set_property("prereq", "fashion golem");
    return;
}

void info() {
message("help",
"This spell fashions a gargoyle out of a certain metal.  You must have 10 ingots "
"of identical metal (you must be holding all of them), and you must cast the spell "
"at one of them.  The ingots will then meld into one incomplete gargoyle which "
"may be saved until the casting is complete.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  If you wish to continue casting, cast the spell at "
"the incomplete gargoyle.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int ingots, time, mod;
  string mat;
  object ob, *ob_p;
  
  if(!at->id("ingot") && !at->id("incomplete gargoyle")) {
    message("info", "You must cast this spell at an ingot or an incomplete gargoyle.",
	    caster);
	  caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(at->id("ingot")) {
    ob_p = ({});
    ingots = 0;
    mat = (string)at->query_material();
    ob = first_inventory(caster);
    ob_p = ({});
    while(ob) {
      if(ob->id("ingot") && (string)ob->query_material() ==
        (string)at->query_material()) {
        ob_p += ({ ob });
        ingots ++;
      }
      ob = next_inventory(ob);
    }
    if(ingots < 10) {
      message("info", "You must have at least 10 ingots of identical "+
        "material to the one at which the spell is cast.", caster);
      caster->add_mp(props["mp cost"]);
      remove();
      return;
    }
    at = new("/std/obj/misc/inc_creation");
    ingots = 10;
    at->set_material(replace_string((string)ob_p[0]->query_material(),
          "metal/", "", 1));
    at->set_type("gargoyle");
    while(ingots--) ob_p[ingots]->remove();
    message("info", "You meld the ingots into an incomplete gargoyle and "+
      "continue casting.", caster);
    at->move(caster);
  } 
  if(flag) {
    message("info", "You misdirect the summoning energies and shatter "+
	    "the metal!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently shatters the summoning metal.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
  set_work_message("%^CYAN%^You mold the gargoyle.");
  time = 2200 + 400*power;
  mod = 40+2*props["spell level"];
  start_work(at, caster, (time*mod)/caster->query_skill("enchantment"), power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in Elemental spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "The metal transforms into a gargoyle.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "magical incantations, and a gargoyle is formed.",
	  environment(caster), ({ caster }) );
  seteuid(getuid());
  ob = new("/std/obj/pet/gargoyle");
  ob->set_material(replace_string((string)at->query_material(), "/", "", 1));
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  at->remove();
  remove();
  return;
}

