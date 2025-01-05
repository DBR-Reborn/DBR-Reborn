
inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","call robe of taul");
    set_property("skill","worship of taul");
    set_property("casting time",10);
    set_property("base mp cost",12);
    set_property("dev cost", 5);
    set_property("fast dev cost", 14);
    set_property("spell level", 1);
    set_property("moon","luna");
    set_property("caster message",
      "You the robe of taul.");
    set_property("target message","");
    set_property("observer message",
      "$C calls a divine robe into existance.");
    set_property("spell type",({ }));
    set_property("no target", 1);
    set_property("duration", "permanent");
    return;
}

void info() {
    message("help",
      "Taul provides for those who need it.  Initiates first learn "+
      "to call a robe for protection against the elements.",
      this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
    object ob;
    object *armours;

    if(flag) {
	message("info", "The fumble causes you to be drained of "
	  "half of your remaining mp!", caster);
	caster->add_mp(-1 * (int)caster->query_mp() / 2);
	remove();
	return;
    }
    ob = new("/std/glen/obj/armour/taul_robe");
    ob->move(caster);
    caster->force_me("equip");
    return;
}

