#include "/adm/include/move.h"

inherit "/std/skills/long_term";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(9);
    set_fast_dev_cost(26);
    set_property("target type", "any");
    set_property("must be present", 1);
}

void info() {
    message("help",
      "This skill is used to prepare corpses for summoning a demon prince.  "
      "You must prepare a corpse of equal or greater level that the "
      "spell you wish to summon.  A higher skill level lets you "
      "prepare the corpse more quickly.\n"
      "Example: use demonic preparation at corpse 1\n",
      this_player());
}

void skill_func(object from, object at, string arg) {
    int time;
    if(!at->id("corpse")) {
        message("info", "You must use this skill at a corpse.",
          from);
        remove();
        return;
    }
    if(at->id("embalmed corpse") || at->id("desecrated corpse")) {
        message("info", "That corpse is already prepared.",
          from);
        remove();
        return;
    }
    if(props["skill level"] > 125) props["skill level"] = 125;
    time = 130-props["skill level"];
    set_work_message("%^CYAN%^You desecrate the corpse for demonic riturals.");
    start_work(at, from, time);
    return;
}

void finish_work(object from, object at) {
    object ob, *inv, a;
    int i;
    seteuid(getuid());
    if(!at){
       message("info", "The corpse decayed before you were finished.", from);
       remove();
       return;
    }
    if(from)
        message("info", "You have finished desecrating the corpse.\n"+
          "It is sufficient to cast a level "+(int)at->query_level()+
          " summon spell.", from);
    message("info", ""+(string)from->query_cap_name() +
      " finishes desecrating a corpse.", environment(from),
      ({ from }));
    ob = new("/std/obj/desecrated_corpse");
    ob->set_level((int)at->query_level());
    ob->set_short(sprintf("a level %d descrated corpse", at->query_level()));
    inv=all_inventory(at);
    for (i=0;i<sizeof(inv);i++){
        a=inv[i];
        a->remove();
    }
    at->set("prepared",1);
    at->remove();
    if((int)ob->move(from) != MOVE_OK) {
        message("info", "Unable to carry the corpse, you drop it.",
          from);
        message("info", (string)from->query_cap_name() +
          " drops the desecrated corpse on the ground.", environment(from),
          ({ from }));
        ob->move(environment(from));
    }
    remove();
    return;
}
