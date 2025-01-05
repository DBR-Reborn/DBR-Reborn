inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "owedquar's eyes");
set_property("skill", "empowerment");
set_property("casting time", 10);
set_property("base mp cost", 32);
set_property("dev cost", 25);
set_property("fast dev cost", 75);
set_property("spell level", 3);
set_property("moon", "warzau");
set_property("caster message", "You greatly empower $T's vision!");
set_property("target message", "$C greatly empowers your vision!");
set_property("observer message", "$C greatly empowers $T's vision!");
set_property("must be present", 1);
set_property("target type", "living");
set_property("duration", 270);
set_property("stack key", "oweeyes #");
set_property("stack num", 1);
return;
}

void info() {
message("help", "This spell grants a significant boost to the targets vision, which allows him/her to see various things not normally visible by the naked eye.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
object ob;

if(at->query("see invis")) {
write("You can already see the invisible.");
return;
}

at->set("oweeyes #", (int)at->query("oweeyes #") + 1);
call_out("remove_stack", props["duration"], at);

seteuid(getuid());
ob = new("/std/spells/shadows/dvision_shadow");
ob->set_max(power * 2);
at->set("see invis", 1);
at->set_shadow_name("owedquar's eyes");
ob->start_shadow(at, props["duration"], "Your vision returns to normal.");
call_out("expire_me", props["duration"], at);
return;
}

void expire_me(object at) {
at->set("see invis", 0);
return;
}

void remove_stack(object at) {
  if(!objectp(at)) return;
  at->set("oweeyes #", (int)at->query("oweeyes #") - 1);
  remove();
  return;
}
