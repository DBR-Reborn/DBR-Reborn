inherit "/std/Object";

void create()
{
    ::create();
    set_short("jail in a bottle");
    set_long("your screwed");
    set_id( ({"bottle", "jail"}) );
    set_property("no steal", 1);
    call_out("init",2);
}

void init()
{
    ::init();
    if(!living(environment(this_object())))
	remove();
    add_action("all_cmds", "");
}

int all_cmds(string str)
{
    if(!wizardp(this_player()))
    {
	write("Sorry, your confined.");
	return 1;
    }
    return 0;
}


