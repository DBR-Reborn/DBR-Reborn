inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","summon spider");
    set_property("skill","prayer");
    set_property("casting time", 3);
    set_property("base mp cost",50);
    set_property("dev cost", 24);
    set_property("fast dev cost", 70);
    set_property("spell level", 13);
     set_property("moon","warzau");
     set_property("caster message", "You summon a large spider to do you bidding.");
    set_property("target message","");
    set_property("observer message","$C murmurs some unholy incantations to Lolth the spider goddess, the room grows dark as a spider emerges from the shadows.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", 1500);
    return;
}

void info() {
message("help",
"This spell summons an evil spider from the realms of the spider goddess Lolth."
"The spider comes in different forms and will be under your command the same way you talk to NPC's."
,
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  object ob;

  seteuid(getuid());
  ob = new("/wizards/blial/under/mon/spider");
  ob->set_up(power);
  ob->move(environment(caster));
  if(!flag)
    ob->set_owner((string)caster->query_name());
  ob->set_dur(props["duration"]);
  if(flag) {
    message("info", "You screw up your incantation and forced to spider to "+
	"become hostile!", caster);
     message("info", "The spider becomes aggressive after being summoned from"+
	"the realm of Lolth",
	     environment(caster), ({ caster }) );
    ob->kill_ob(caster, 0);
    remove();
    return;
  }
  ob->set_owner((string)caster->query_name());
  remove();
  return;
}

