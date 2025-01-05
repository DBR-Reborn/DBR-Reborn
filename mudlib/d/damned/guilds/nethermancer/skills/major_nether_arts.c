inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(28);
    set_fast_dev_cost(79);
}

void info() {
    message("help", "This skill indicates a Nethermancer's talent in the considerably powerful nether arts required to make maximum use of a greater nexus, providing assistance to him or her in executing longterms of nether category three (see help file of longterm in question for category listing). Should this skill be applicable to a longterm spell being performed, its base value will decide an overall time deduction for the caster from the normal required time.", this_player());
}
