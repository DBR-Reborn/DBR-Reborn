inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "blur vision");
set_property("skill", "void lore");
set_property("casting time", 3);
set_property("base mp cost", 40);
set_property("dev cost", 40);
set_property("fast dev cost", 120);
set_property("spell level", 7);
set_property("moon", "warzau");
set_property("caster message", "You blur $T's vision.");
set_property("target message", "$C blur your vision!");
set_property("observer message", "$C blur $T's vision!");
set_property("must be present", 1);
set_property("combat spell", 1);
set_property("can resist", 1);
set_property("damage multiplier", 8);
set_property("duration", 30);
set_property("target type", "living");
return;
}

void info() {
message("help", "This spell places a blur on the vision of the target in an attempt to render him/her blind.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;

if(flag) {
message("info", "You inadvertently blur your own vision!", caster);
at = caster;
}
if(at->query_is_blind()) {
message("info", "$T's vision is already blurred.", caster);
remove();
return;
}
seteuid(getuid());
ob = new("/std/spells/shadows/blind_shadow");
ob->set_shadow_name("blur vision");
ob->start_shadow(at);
call_out("remove_blind", props["duration"], ob, at);
if(!flag) {
message("info", "%^BOLD%^%^WHITE%^Your sight is blurred!%^RESET%^", at);
return;
}
}

void remove_blind(object ob, object at) {
if(at) {
message("info", "You are no longer have blurred.", at);
}
if(ob) {
ob->external_destruct(ob);
}
return;
}
