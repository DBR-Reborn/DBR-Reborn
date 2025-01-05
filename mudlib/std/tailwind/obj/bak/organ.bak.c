inherit "/std/Object";

int level;

void create() {
    ::create();
    set_name("organ");
    switch(random(12)) {
    case 0:
	set_id( ({ "organ", "spleen" }) );
	set_short("A bloody spleen");
	break;
    case 1:
	set_id( ({ "organ", "heart" }) );
	set_short("A bleeding heart");
	break;
    case 2:
	set_id( ({ "organ", "kidney" }) );
	set_short("A disgusting kidney");
	break;
    case 3:
	set_id( ({ "organ", "liver" }) );
	set_short("A dissected liver");
	break;
    case 4:
	set_id( ({ "organ", "testicles" }) );
	set_short("Some ripped-out testicles");
	break;
    case 5:
	set_id( ({ "organ", "lung" }) );
	set_short("A single lung");
	break;
    case 6:
	set_id( ({ "organ", "brain" }) );
	set_short("A removed brain");
	break;
    case 7:
	set_id( ({ "organ", "stomach" }) );
	set_short("An empty stomach");
	break;
    case 8:
	set_id( ({ "organ", "bladder" }) );
	set_short("A smelly bladder");
	break;
    case 9:
	set_id( ({ "organ", "eye", "eyeball" }) );
	set_short("A slippery eyeball");
	break;
    case 10:
	set_id( ({ "organ", "appendix" }) );
	set_short("A surgically-removed appendix");
	break;
    case 11:
	set_id( ({ "organ", "gland" }) );
	set_short("A large and mysterious gland");
	break;
    }

    set_long("This is an organ from a corpse which will be used in an
alchemist oil or a flesh golem.");
  set_weight(5);
  set_value(1);
  return;
}

int query_organ_level() { return level; }

void set_level(int x){level=x;}

