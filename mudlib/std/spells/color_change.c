// Color Change spell
// -Tailwind  6/28/99

inherit "/std/spells/long_term_spell";

string colorname;
object stuff;

void create() {
    ::create();
    set_property("name","color change");
    set_property("skill","alchemy");
    set_property("duration", "permanent");
    set_property("casting time",8);
    set_property("base mp cost",37);
    set_property("dev cost", 22);
    set_property("fast dev cost", 56);
    set_property("spell level", 4);
    set_property("moon","luna");
    set_property("caster message","You break out some dyes and begin to
change the liquid's color.");
    set_property("target message","");
    set_property("observer message","$C begins to dye a liquid.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell allows the alchemist to change the color of his potions  "
"or poisons. Higher power levels  "
"will shorten the casting time on this spell. "
"The format for this spell is as follows: "
"cast <pow> color change at <vial> with <color>. "
"Example: cast *6 color change at vial with blood red "
"This is a long-term spell (see help long-term), and may take much real "
"time to cast.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag)
{
  int time,mod;
  object ob;

  if ((!at->query_is_potion(1)) && (!at->query_is_poison(1))) {
    message("info", "You cannot change the color of anything but a potion
or a poison!", caster);
          caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if(!(stuff = present("color dyes", caster))) {
    message("info", "You need color dyes to cast this spell.",
            caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

  if (!args) {
    message("info", "You break off the dyeing process, as you have not
figured out what color you want the potion to become.", caster);
          caster->add_mp(props["mp cost"]);
    remove();
    return;
  }

    message("info", "You use some color dyes while casting the spell.",
            caster);
   stuff->remove();
  


  if(flag) {
    message("info", "You screw up big time and ruin the potion! The vial
shatters! ", caster);
            at->remove();
        return;
  }
//  at->set_property("new desc", args);
  set_work_message("You change the color of the potion.");
  time = 1200/power;
  colorname=args;
  mod = 30+2*props["spell level"];


  if(wizardp(caster))
      time = 1;

  start_work(at, caster, (time*mod)/caster->query_skill("alchemy"),
power);
  return;
}

void finish_work(object caster, object at, int power) {
  int ench, i, idx;
  mixed tmp;

  if(power <= 0) {
    message("info", "BUG in Alchemy spell....unable to complete.",
            environment(caster));
    remove();
    return;
  }

  message("info", "You are finished dyeing the potion!", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
          "alchemistic incantations.",
          environment(caster), ({ caster }) );

  at->set_color(colorname);
 
  remove();
  return;
}

