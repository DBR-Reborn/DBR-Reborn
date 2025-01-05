
//    by Glen
//    derived from diewarzaus spell scroll

inherit "/std/Object";

string spell;
int spell_pow;
static object ele_shad;
static object skill_shad;

void create() {
    ::create();
    spell = 0;
    spell_pow = 0;
    ele_shad = 0;
    set_property("self power", 1);
    set_short("A prismatic potion");
    set_long("This potion is used by alchemist.");
    set_id(({ "potion", "prismatic potion", "spell potion" }));
    set_name("potion");
    set_weight(4);
    set_value(200);
    return;
}

string query_long(string null) {
    string res;

    res = ::query_long(null);
    if(!spell || !spell_pow) return res;
    res += "\n\n";
    res += "This potion has the spell: "+sprintf("%s *%-d", spell,
      spell_pow)+
    " inscribed upon it.  Cast it with 'drink potion'.  ";
    return res;
}

void init() {
    ::init();
    add_action("cast_spell", "drink");
    return;
}

void set_spell(string sp, int pow) {
    spell = sp;
    spell_pow = pow;
    return;
}

string query_spell() { return spell; }

int cast_spell(string str) {
    string name, me, file, args, ele;
    object spell_ob, tmp;
    int cost;

    args = 0;
    me = this_player()->query_true_name();
    name = spell;
    args = me;

    if(!id(str))
	return 0;

    file = "/std/spells/"+replace_string(name, " ", "_");
    if(!file_exists(file+".c")) {
	write("Cannot find spell file...BUG");
	return 1;
    }
    seteuid(getuid());
    spell_ob = new(file);
    spell_ob->set_property("casting time", 2);
    cost = (int)spell_ob->query_proeprty("base mp cost");
    cost /= query_property("self power");
    if(cost < 1) cost = 1;
    spell_ob->set_property("base mp cost", cost);
    spell_ob->set_property("skill", "tmp skill");
    this_player()->set_skill("tmp skill", 110);
    call_out("remove_skill", 5, this_player());
    if(spell_ob->query_property("elemental spell") &&
      !objectp(this_player()->query("ele shadow"))) {
	ele = query_property("element");
	if(!ele) {
	    write("You must use an elemental lore skill to "+
	      "read this potion.");
	    return 1;
	}
	tmp = new("/std/spells/shadows/ele_shadow");
	tmp->set_element(ele);
	tmp->start_shadow(this_player());
	ele_shad = tmp;
    }
    tmp = new("/std/spells/shadows/skill_shadow");
    tmp->add_spell(spell, spell_pow);
    tmp->start_shadow(this_player());
    skill_shad = tmp;
    tmp = (object)this_player()->query_casting();
    this_player()->set_casting(0);
    spell_ob->begin_casting(this_player(), args, spell_pow);
    if(tmp) this_player()->set_casting(tmp);
    return 1;
}

void remove_skill(object who) {
    if(!who) return;
    who->delete_skill("tmp skill");
    if(ele_shad) ele_shad->external_destruct(ele_shad);
    if(skill_shad) skill_shad->external_destruct(skill_shad);
    message("info", "A potion crumbles to dust.", who);
    remove();
    return;
}


