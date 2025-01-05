int vampiric_func(int dice, object who) {
    int res, i, mult;
    int sides = 6;
    object wield = previous_object();

    res = 0;
    if(dice < 0) {
	mult = -1;
	dice *= -1;
    } else
	mult = 1;
    for(i=1; i<=dice; i++) res += 1+random(sides);
    res *= mult;
    who->add_mp(-1 * res/5);
    who->add_hp(-1 * res/5);
    wield = wield->query_wielded();
    if(wield) {
	wield->add_hp(res/5);
	wield->add_mp(res/5);
	message("info", "%^MAGENTA%^%^BOLD%^The blade drains %^RESET%^"+
	  "%^CYAN%^"+sprintf("%d mp and %d hp", res/5, res/5)+"%^RESET%^%^MAGENTA%^"+
	  "%^BOLD%^ from your victim!", wield);
    }
    return 0;
}

