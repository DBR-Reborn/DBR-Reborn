inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(14);
    set_fast_dev_cost(43);
}

void info() {
message("help",
"This is a general magic skill which allows casting of spells dealing "+
"with geometric concepts. ",
this_player());
}
