inherit "/std/skills/skill.c";

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(18);
    set_fast_dev_cost(55);
}

void info() {
    message("help", "This is a latent indication skill that gives a determination for a Nethermancer in his or her talents in learning from the middling long-term spells they perform throughout their existence. This skill is effective for category two long-term castings (see help files for guild longterms to find their category rating), and its base value directly figures into the amount of experience gained after each slightly over one minute tick that the long-term in question is being carried out.", this_player());
}
