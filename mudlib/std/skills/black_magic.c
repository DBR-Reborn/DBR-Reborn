inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(15);
    set_fast_dev_cost(47);
}

void info() {
message("help",
"This spell casting skill deals with black magic in all its forms.  "+
"This skill covers non-animating spells for necromancers.",
this_player());
}

