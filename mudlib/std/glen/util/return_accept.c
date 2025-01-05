inherit "/std/Object";

object ob, ob2;
string func;

void create()
{
    set_name("accept");
    set_weight(1);
    set_value(0);
    set_property("no save",1);
    delayed_call("decline", 90);
}
void init()
{
    add_action("consent", "accept");
    add_action("decline", "decline");
}

void set_accept(object obj, string funct, object obj2)
{
    ob = obj;
    func = funct;
    ob2 = obj2;
}

int consent()
{
    call_other(ob, func, ob2);
    remove();
    return 1;
}

int decline()
{
    call_other(ob, func);
    remove();
    return 1;
}


