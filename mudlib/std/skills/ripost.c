inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(12);
    set_fast_dev_cost(29);
}

void info() {
    message("help", 
      "Ripost is heavily dependent on parrying.  "+
      "Riposting is striking back at your oponent on a successfull "+
      "parry.  A higher ripost skill will increase your chance of "+
      "striking back while parrying."
      , this_player());
}

