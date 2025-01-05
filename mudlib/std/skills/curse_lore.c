inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(20);
    set_fast_dev_cost(60);
}

void info() {
message("help",
"This spell casting skill deals with curses in all its forms.  "+
"This skill can only be obtained thru orb sacrifice.",
this_player());
}

