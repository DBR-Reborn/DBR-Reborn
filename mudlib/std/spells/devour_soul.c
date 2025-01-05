inherit "/std/spells/spell";

int sp_pow;
object cas;

void create() {
    ::create();
    set_property("name","devour soul");
    set_property("skill","spiritmancy");
    set_property("casting time",10);
    set_property("base mp cost",125);
    set_property("dev cost", 165);
    set_property("fast dev cost", 495);
    set_property("spell level", 32);
    set_property("moon","luna");
    set_property("caster message","You cast devour soul at $T.");
    set_property("target message","$C begins to devour your soul!");
    set_property("observer message","$C casts devour soul at $T.");
    set_property("spell type",({ }));
    set_property("target type", "living");
    set_property("must be present", 1);
    set_property("combat spell", 1);
    set_property("prereq", "orb sacrifice");
    set_property("duration", 15);
    set_property("stack key", "syphon");
    set_property("stack num", 1);
    set_property("can resist", 2);
    return;
}

void info() {
message("help",
"This spell, when cast upon the target, steals some of their hp/mp "
"at gives it to you. "
"For the length of the duration, you devour some of the targets hp/mp.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  sp_pow = power;
  if(flag) {
    message("info", "%^GREEN%^You accidentally devour away a good deal of your hit points and mana points!",
      caster);
    caster->add_hp(-1 * (int)caster->query_hp()/4);
    caster->add_mp(-1 * (int)caster->query_mp()/4);
    remove();
    return;
  }
  
   if((int)at->query("syphon #") >= 1) {
    message("info", (string)at->query_cap_name() +
	    "’s soul is already linked.", caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  
  at->set("syphon #", (int)at->query("syphon #") + 1);	
  call_out("damage_dude", 5, at, props["duration"]/5);
  cas = caster;
}

void damage_dude(object at, int times) {
//  int i;
	int roll;
	int roll2;

  if(!at) {
    remove();
    return;
  }
  times--;
    if((at->query_ghost()) || !cas){
    message("info", at->query_cap_name()+" has died." , cas);
    at->set("syphon #", (int)at->query("syphon #") - 1);
  remove();
  return;
  }
  roll = random(15) + random(15) + 10;
  at->add_hp(-1*(sp_pow * roll));
  cas->add_hp(sp_pow * roll);
  roll2 = random(15) + random(15) + 10;
  at->add_mp(-1*(sp_pow * roll2));
  cas->add_mp(sp_pow * roll2);
  message("info", "%^COLOR160%^%^BOLD%^You lose " +(sp_pow * roll)+ "HP and "+(sp_pow * roll2)+"MP." , at);
  message("info", "%^COLOR160%^%^BOLD%^You gain " +(sp_pow * roll)+ "HP and "+(sp_pow * roll2)+"MP." , cas);
  if(times <= 0) {
    at->set("syphon #", (int)at->query("syphon #") - 1);   
    message("info", "%^CYAN%^%^BOLD%^A devour soul spell wears off.",
        at); 
    remove();
    return;
  }
  call_out("damage_dude", 5, at, times);
  return;
}

//int can_exceed_max_mp() { return 1; }
//int can_exceed_max_hp() { return 1; }


