inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "cause weakness");
set_property("skill", "owedquar's will");
set_property("casting time", 25);
set_property("base mp cost", 150);
set_property("dev cost", 115);
set_property("fast dev cost", 345);
set_property("spell level", 22);
set_property("moon", "ankh");
set_property("caster message", "You severely weaken $T's state!");
set_property("target message", "$C severely weakens your state!");
set_property("observer message", "$C severely weakens $T's state.");
set_property("must be present", 1);
set_property("target type", "living");
return;
}

void info() {
message("help", "This spell places a powerful hex on a player, dropping all of their skills significantly by lowering their vitality. The target can only recover if he is cured by the correct magic or waits out the recovery time.", this_player());
}

void spell_func(object caster, object at, int pow, string args, int flag) {

if(!at) {
message("info", "Your spell has no effect. It is only effective against players.", caster);
remove();
return;
}
if(at->query_penalty() > 15000) {
message("info", "This player has over 500 minutes of recovery and cannot recieve anymore from this spell.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}
if(flag) {
message("my_action", "You accidently misdirect the spell and curse your own state!", caster);
caster->add_penalty(7000);
remove();
return;
}
at->add_penalty(300*pow);
remove();
return;
}
