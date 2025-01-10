inherit "/std/spells/spell";

void create() {
::create();
set_property("name", "soul crush");
set_property("skill", "oberon's will");
set_property("casting time", 12);
set_property("base mp cost", 500);
set_property("dev cost", 180);
set_property("fast dev cost", 540);
set_property("spell level", 35);
set_property("moon", "warzau");
set_property("caster message", "You unleash incredible power upon $T attempting to crush the soul!");
set_property("target message", "$C unleashes incredible power upon you attempting to crush your soul!");
set_property("observer message", "$C unleashes incredible power upon $T attempting to crush the soul.");
set_property("must be present", 1);
set_property("can resist", 0);
set_property("no borrow", 1);
set_property("combat spell", 1);
set_property("target type", "living");
set_property("prereq", "power of void");
return;
}

void info() {
message("help", "This is the highest level spell available to a Voidwalker, and without a doubt one of the most powerful. This spell attempts to crush the very soul of the target and cause instant non preventable death, even if the target is immersed in a holy war. To cast this spell, ALL of the casters mp is used up. The more mp that is put into the spell, the greater chance it has of working against its target. Higher power of the spell also increases the chance of success, but regardless of either boost this spell will NEVER work against targets of higher level than the caster.", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
int a;
int b;
int c;

if(flag) {
message("info", "%^RED%^You misdirect the power and crush your own soul!%^RESET%^", caster);
caster->set_hp(-1);
remove();
return;
}
a = caster->query_mp();
caster->add_mp(-a);
b = random(100);
c = ((a/250)+(power*2));
if(at->query_level() > caster->query_level()) {
message("info", "Your attempt to instantly kill "+(string)at->query_cap_name()+" was unsuccessful.", caster);
message("info", (string)caster->query_cap_name() +" unsuccessfully attempted to instantly kill you.", at);
remove();
return;
}
if(b < c) {
message("info", "%^RED%^You fall over dead without suffering.%^RESET%^", at);
at->set_hp(-1);
if((string)at->query_gender() == "male") {
message("info", "You successfully crush "+(string)at->query_cap_name()+"'s soul and kill him!", caster);
remove();
return;
}
if((string)at->query_gender() == "female") {
message("info", "You successfully crush "+(string)at->query_cap_name()+"'s soul and kill her!", caster);
remove();
return;
}
if((string)at->query_gender() == "neuter") {
message("info", "You successfully crush "+(string)at->query_cap_name()+"'s soul and kill it!", caster);
remove();
return;
}
}
if(b >= c) {
message("info", "Your attempt to instantly kill "+(string)at->query_cap_name()+" was unsuccessful.", caster);
message("info", (string)caster->query_cap_name() +" unsuccessfully attempted to instantly kill you.", at);
remove();
return;
}
}
